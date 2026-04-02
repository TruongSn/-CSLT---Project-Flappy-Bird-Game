/*
Mục đích
- File hiện thực dự kiến cho logic phát hiện va chạm.

Trách nhiệm dự kiến
- So sánh bounds của chim với bounds của ống.
- Kiểm tra ràng buộc với mặt đất và trần.
- Cung cấp kết quả ổn định cho chuyển trạng thái thua cuộc.

Các vùng logic dự kiến
- Bird va chạm ống trên.
- Bird va chạm ống dưới.
- Bird va chạm mặt đất.
- Bird va chạm trần.

Phụ thuộc có thể dùng
- Kiểu hình chữ nhật hoặc float-bounds của SFML.
- src/entities/Bird.hpp
- src/entities/Pipe.hpp
- src/managers/PipeManager.hpp

Ghi chú cho lần hiện thực sau
- Giữ phần kiểm tra dễ test và dễ đọc.
- Tránh trộn logic điểm vào xử lý va chạm.
*/
#include "Collision.hpp"

#include "../entities/Bird.hpp"
#include "../entities/Pipe.hpp"
#include "../managers/PipeManager.hpp"

bool Collision::checkBirdPipe(const Bird& bird, const Pipe& pipe) {
    const sf::FloatRect birdBounds = bird.getBounds();

    return birdBounds.intersects(pipe.getBoundsTop()) ||
           birdBounds.intersects(pipe.getBoundsBottom());
}

bool Collision::checkBirdGround(const Bird& bird, float groundY) {
    const sf::FloatRect birdBounds = bird.getBounds();
    return (birdBounds.top + birdBounds.height) >= groundY;
}

bool Collision::checkBirdCeiling(const Bird& bird) {
    const sf::FloatRect birdBounds = bird.getBounds();
    return birdBounds.top <= 0.0f;
}

CollisionResult Collision::checkAll(
    const Bird& bird,
    const PipeManager& pipeManager,
    float groundY
) {
    CollisionResult result;

    if (checkBirdCeiling(bird)) {
        result.collided = true;
        result.type = CollisionType::Ceiling;
        return result;
    }

    if (checkBirdGround(bird, groundY)) {
        result.collided = true;
        result.type = CollisionType::Ground;
        return result;
    }

    for (const Pipe& pipe : pipeManager.getPipes()) {
        if (checkBirdPipe(bird, pipe)) {
            result.collided = true;
            result.type = CollisionType::Pipe;
            return result;
        }
    }

    return result;
}
