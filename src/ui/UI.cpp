/*
Mục đích
- File hiện thực dự kiến cho mô-đun UI.

Trách nhiệm dự kiến
- Vẽ chữ và overlay cho từng trạng thái chính.
- Căn vị trí điểm số và các phần hướng dẫn rõ ràng.
- Dùng font và tài nguyên hiển thị từ thư mục assets cục bộ của project.

Các vùng logic dự kiến
- Tải font và hành vi dự phòng.
- Vẽ overlay theo từng trạng thái.
- Helper căn chỉnh và giãn cách.

Phụ thuộc có thể dùng
- Mô-đun đồ họa của SFML.
- src/core/GameState.hpp
- src/systems/Score.hpp
- src/systems/HighScore.hpp

Ghi chú cho lần hiện thực sau
- Giữ code vẽ dễ đọc và dễ hoàn thiện.
- Tránh nhúng logic chuyển trạng thái vào các lệnh gọi UI.
*/
