/*
Mục đích
- File hiện thực dự kiến cho xử lý điểm của lượt chơi hiện tại.

Trách nhiệm dự kiến
- Chỉ cập nhật điểm khi chim vượt qua chướng ngại vật hợp lệ.
- Đặt lại điểm khi bắt đầu lượt chơi mới.
- Hỗ trợ lấy dữ liệu cho UI và so sánh điểm cao nhất.

Các vùng logic dự kiến
- Luật tăng điểm.
- Luồng đặt lại.
- Helper tùy chọn để đánh giá sự kiện vượt ống từ tập ống đang hoạt động.

Phụ thuộc có thể dùng
- src/managers/PipeManager.hpp
- src/entities/Bird.hpp

Ghi chú cho lần hiện thực sau
- Giữ trạng thái điểm độc lập với phần vẽ.
- Tránh lưu file ở đây; lưu trữ cục bộ thuộc về HighScore.
*/
