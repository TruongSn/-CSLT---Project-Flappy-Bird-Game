#pragma once

#include <SFML/Graphics.hpp>

/**
 * @brief Đại diện cho một cặp ống (Pipe Pair) gồm ống trên và ống dưới.
 * 
 * Responsibilities:
 * - Lưu giữ vị trí, kích thước khe hở (gap), và cờ báo hiệu đã đi qua hay chưa.
 * - Cung cấp getBoundsTop() và getBoundsBottom() dùng cho việc phát hiện va chạm.
 * - Render cả 2 phần ống ra màn hình.
 */
class Pipe {
public:
    /**
     * @brief Khởi tạo một cặp ống
     * @param x Vị trí X ban đầu của cặp ống
     * @param gapY Vị trí Y (tâm của khe hở)
     * @param gapSize Chiều cao khe hở để con chim bay qua
     * @param speed Tốc độ di chuyển của ống (pixels/second)
     */
    Pipe(float x, float gapY, float gapSize, float speed);

    /**
     * @brief Cập nhật trạng thái ống (vị trí X)
     * @param dt Delta time (thời gian trôi qua giữa 2 frame)
     */
    void update(float dt);

    /**
     * @brief Vẽ ống lên màn hình
     * @param target Render target (window) của SFML
     */
    void render(sf::RenderTarget& target) const;

    /**
     * @brief Kiểm tra ống đã ra khỏi mép trái màn hình chưa
     * @return true nếu khoảng bounding box không còn nằm trong màn hình hiển thị
     */
    bool isOffscreen() const;

    /**
     * @brief Cập nhật cờ tính điểm khi chim vượt qua
     * @param birdX Hoành độ X hiện tại của con chim
     * @return true nếu bắt đầu đi ngang qua và cờ được bật (ghi nhận tính điểm 1 lần duy nhất)
     */
    bool checkPassed(float birdX);

    // Getters cho logic va chạm (SFML Rect)
    sf::FloatRect getBoundsTop() const;
    sf::FloatRect getBoundsBottom() const;

    // Getters
    bool isPassed() const;

private:
    sf::Vector2f position; // (X, gapY)
    float gapSize;
    float speed;
    bool passedFlag; // Cờ báo đã tính điểm hay chưa

    // Placeholder: Kích thước thật của visual ống để xây dựng Rect
    float pipeWidth;
    float pipeHeight;
};
