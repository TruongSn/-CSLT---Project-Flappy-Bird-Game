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
