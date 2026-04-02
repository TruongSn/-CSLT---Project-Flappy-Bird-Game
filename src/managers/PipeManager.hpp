#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "../entities/Pipe.hpp"

/**
 * @brief Quản lý tập hợp các ống (Pipe Pair) trong game.
 * 
 * Responsibilities:
 * - Khởi tạo ống mới dựa trên timer.
 * - Cập nhật vị trí của tất cả ống đang active.
 * - Dọn dẹp (xóa) những ống đã đi qua khỏi màn hình để giải phóng bộ nhớ.
 * - Cung cấp danh sách ống để hệ thống khác (Collision, Score, Rendering) duyệt và kiểm tra.
 */
class PipeManager {
public:
    /**
     * @brief Khởi tạo PipeManager
     */
    PipeManager();

    /**
     * @brief Cập nhật trạng thái các ống và sinh ống mới nếu đến lượt
     * @param dt Delta time (thời gian trôi qua)
     */
    void update(float dt);

    /**
     * @brief Render tất cả ống đang active
     * @param target Render target của SFML
     */
    void render(sf::RenderTarget& target) const;

    /**
     * @brief Đặt lại trạng thái (xóa hết ống, reset timer) khi chơi lại
     */
    void reset();

    /**
     * @brief Lấy danh sách ống hiện tại (đọc/ghi để kiểm tra va chạm, cộng điểm)
     * @return Reference tới vector các Pipe
     */
    std::vector<Pipe>& getPipes();
    const std::vector<Pipe>& getPipes() const;

private:
    /**
     * @brief Sinh một cặp ống mới tại cạnh phải màn hình
     */
    void spawnPipe();

    std::vector<Pipe> pipes;

    float spawnTimer;
    float spawnInterval; // Bao lâu thì sinh 1 ống mới (giây)
    float pipeSpeed;
    float pipeGap;       // Kích thước khe hở
};
