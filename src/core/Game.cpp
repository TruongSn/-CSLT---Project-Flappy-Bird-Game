/*
Mục đích
- File hiện thực dự kiến cho bộ điều phối Game.

Trách nhiệm dự kiến
- Định nghĩa cấu trúc vòng lặp game chính.
- Điều hướng sự kiện và input đến đúng hệ thống.
- Cập nhật entity và hệ thống theo thứ tự ổn định.
- Vẽ frame hiện tại theo trạng thái đang hoạt động.

Luồng logic dự kiến
- Khởi động và khởi tạo tài nguyên.
- Xử lý màn hình bắt đầu.
- Chuỗi cập nhật khi đang chơi.
- Luồng tạm dừng và thua cuộc.
- Dọn dẹp và tắt ứng dụng.

Phụ thuộc có thể dùng
- Các mô-đun cửa sổ, đồ họa, âm thanh của SFML.
- src/core/GameState.hpp
- src/entities/Bird.hpp
- src/managers/PipeManager.hpp
- src/systems/Collision.hpp
- src/systems/Score.hpp
- src/systems/HighScore.hpp
- src/ui/UI.hpp

Ghi chú cho lần hiện thực sau
- Giữ thứ tự cập nhật rõ ràng và dễ rà soát.
- Tránh trộn code vẽ vào các hệ thống không liên quan.
*/
