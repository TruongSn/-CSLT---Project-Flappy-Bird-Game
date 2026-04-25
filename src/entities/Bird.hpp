/*
Mục đích
- Nơi dự kiến khai báo entity chim do người chơi điều khiển.

Trách nhiệm dự kiến
- Biểu diễn vị trí, vận tốc và trạng thái hiển thị của chim.
- Cung cấp các thao tác flap, cập nhật, vẽ và đặt lại.
- Cung cấp bounds hoặc dữ liệu liên quan va chạm cho hệ thống Collision.

Dữ liệu chính dự kiến có ở đây
- Vị trí.
- Vận tốc.
- Trạng thái xoay hoặc ảnh động.
- Dữ liệu sprite hoặc phần hiển thị tạm.

API public dự kiến
- TODO: khai báo constructor và reset().
- TODO: khai báo flap().
- TODO: khai báo update().
- TODO: khai báo render().
- TODO: khai báo getBounds() hoặc hàm tương đương.
- TODO: khai báo hàm truy cập cho vị trí hoặc trạng thái nếu cần.

Ghi chú cho lần hiện thực sau
- Phần chỉnh vật lý của Bird nên dựa vào GameplayConfig.
- Giữ cảm giác điều khiển tách khỏi điều phối trạng thái game.
*/
#pragma once

#include <SFML/Graphics.hpp>

class Bird {
public:
    Bird();

    void reset();
    void flap();
    void update(float dt);
    void render(sf::RenderTarget& target) const;

    sf::FloatRect getBounds() const;
    sf::Vector2f getPosition() const;
    float getVerticalVelocity() const;

private:
    sf::RectangleShape shape;
    sf::Vector2f startPosition;
    float verticalVelocity;
    float rotationDegrees;
    bool wasResetThisFrame;
};

