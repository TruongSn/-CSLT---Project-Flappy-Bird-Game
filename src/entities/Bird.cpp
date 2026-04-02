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

Bird::Bird()
    : startPosition(GameplayConfig::BirdSpawnX, GameplayConfig::BirdSpawnY),
      verticalVelocity(0.0f),
      rotationDegrees(0.0f) {
    shape.setSize(
        sf::Vector2f(GameplayConfig::BirdWidth, GameplayConfig::BirdHeight));
    shape.setOrigin(shape.getSize().x * 0.5f, shape.getSize().y * 0.5f);
    shape.setPosition(startPosition);

    // Placeholder appearance for early development
    shape.setFillColor(sf::Color::Yellow);
    shape.setOutlineThickness(2.0f);
    shape.setOutlineColor(sf::Color::Black);
}

void Bird::reset() {
    shape.setPosition(startPosition);
    verticalVelocity = 0.0f;
    rotationDegrees = 0.0f;
    shape.setRotation(rotationDegrees);
}

void Bird::flap() {
    verticalVelocity = GameplayConfig::BirdFlapVelocity;
}

void Bird::update(float dt) {
    verticalVelocity += GameplayConfig::BirdGravity * dt;

    verticalVelocity = std::clamp(
        verticalVelocity,
        GameplayConfig::BirdMaxRiseSpeed,
        GameplayConfig::BirdMaxFallSpeed
    );

    shape.move(0.0f, verticalVelocity * dt);

    if (verticalVelocity < 0.0f) {
        rotationDegrees = -20.0f;
    } else if (verticalVelocity < 200.0f) {
        rotationDegrees = 5.0f;
    } else {
        rotationDegrees = 25.0f;
    }

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
