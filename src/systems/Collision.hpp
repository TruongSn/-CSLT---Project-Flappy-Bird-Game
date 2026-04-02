/*
Mục đích
- Nơi dự kiến khai báo các kiểm tra va chạm trong trò chơi.

Trách nhiệm dự kiến
- Phát hiện va chạm giữa chim và các ống.
- Phát hiện va chạm với mặt đất.
- Phát hiện va chạm với trần nếu thiết kế giữ giới hạn phía trên.
- Trả về kết quả rõ ràng cho vòng lặp lõi của game.

API public dự kiến
- TODO: khai báo các hàm truy vấn va chạm.
- TODO: khai báo kiểu kết quả hoặc giao diện dạng boolean đơn giản.
- TODO: khai báo hàm hỗ trợ cho bird vs pipe và bird vs world bounds.

Dữ liệu đầu vào dự kiến
- Bounds hoặc dữ liệu vị trí của Bird.
- Bounds của ống đang hoạt động từ PipeManager.
- Giá trị biên của mặt đất và màn hình.

Ghi chú cho lần hiện thực sau
- Nếu có thể, giữ hệ thống này ở dạng không lưu trạng thái.
- Hệ thống này nên báo va chạm, không quyết định hành vi UI trực tiếp.
*/
#pragma once

#include <SFML/Graphics.hpp>

class Bird;
class Pipe;
class PipeManager;

enum class CollisionType {
    None,
    Pipe,
    Ground,
    Ceiling
};

struct CollisionResult {
    bool collided = false;
    CollisionType type = CollisionType::None;
};

class Collision {
public:
    static bool checkBirdPipe(const Bird& bird, const Pipe& pipe);
    static bool checkBirdGround(const Bird& bird, float groundY);
    static bool checkBirdCeiling(const Bird& bird);
    static CollisionResult checkAll(
        const Bird& bird,
        const PipeManager& pipeManager,
        float groundY
    );
};
