/*
Mục đích
- File hiện thực dự kiến cho entity Bird.

Trách nhiệm dự kiến
- Áp dụng gravity và lực flap.
- Cập nhật chuyển động, góc xoay và dữ liệu hiển thị.
- Đặt lại trạng thái chim sạch sẽ khi chơi lại.

Các vùng logic dự kiến
- Khởi tạo và thiết lập phần hiển thị tạm.
- Cập nhật vật lý theo từng frame.
- Gọi lệnh vẽ bằng primitive của SFML hoặc sprite asset.
- Đặt lại trạng thái cho luồng Start và Restart.

Phụ thuộc có thể dùng
- Các kiểu đồ họa của SFML.
- src/config/GameplayConfig.hpp

Ghi chú cho lần hiện thực sau
- Giữ vật lý đủ ổn định để dễ tinh chỉnh.
- Không xử lý giải va chạm ở đây; chỉ nên cung cấp dữ liệu.
*/
#include "Bird.hpp"
#include "../config/GameplayConfig.hpp"

#include <algorithm>

namespace {
constexpr float UpwardTiltDegrees = -22.0f;
constexpr float NeutralTiltDegrees = 4.0f;
constexpr float DownwardTiltDegrees = 28.0f;
constexpr float RotationLerpSpeed = 10.0f;
}

Bird::Bird()
    : startPosition(GameplayConfig::BirdSpawnX, GameplayConfig::BirdSpawnY),
      verticalVelocity(0.0f),
      rotationDegrees(0.0f),
      wasResetThisFrame(false) {
    shape.setSize(
        sf::Vector2f(GameplayConfig::BirdWidth, GameplayConfig::BirdHeight));
    shape.setOrigin(shape.getSize().x * 0.5f, shape.getSize().y * 0.5f);
    shape.setPosition(startPosition);

    shape.setFillColor(sf::Color::Yellow);
    shape.setOutlineThickness(2.0f);
    shape.setOutlineColor(sf::Color::Black);
    shape.setRotation(rotationDegrees);
}

void Bird::reset() {
    shape.setPosition(startPosition);
    verticalVelocity = 0.0f;
    rotationDegrees = 0.0f;
    wasResetThisFrame = true;
    shape.setRotation(rotationDegrees);
}

void Bird::flap() {
    verticalVelocity = GameplayConfig::BirdFlapVelocity;
    wasResetThisFrame = false;
}

void Bird::update(float dt) {
    if (wasResetThisFrame) {
        wasResetThisFrame = false;
        return;
    }

    verticalVelocity += GameplayConfig::BirdGravity * dt;

    verticalVelocity = std::clamp(
        verticalVelocity,
        GameplayConfig::BirdMaxRiseSpeed,
        GameplayConfig::BirdMaxFallSpeed
    );

    shape.move(0.0f, verticalVelocity * dt);

    float targetRotation = NeutralTiltDegrees;

    if (verticalVelocity < -60.0f) {
        targetRotation = UpwardTiltDegrees;
    } else if (verticalVelocity > 180.0f) {
        targetRotation = DownwardTiltDegrees;
    }

    const float blend = std::min(1.0f, RotationLerpSpeed * dt);
    rotationDegrees += (targetRotation - rotationDegrees) * blend;
    shape.setRotation(rotationDegrees);
}

void Bird::render(sf::RenderTarget& target) const {
    target.draw(shape);
}

sf::FloatRect Bird::getBounds() const {
    return shape.getGlobalBounds();
}

sf::Vector2f Bird::getPosition() const {
    return shape.getPosition();
}

float Bird::getVerticalVelocity() const {
    return verticalVelocity;
}