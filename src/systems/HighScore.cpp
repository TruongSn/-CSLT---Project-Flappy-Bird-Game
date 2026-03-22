/*
Mục đích
- File hiện thực dự kiến cho quản lý điểm cao nhất cục bộ.

Trách nhiệm dự kiến
- Đọc điểm đã lưu từ ổ đĩa.
- Ghi điểm tốt nhất mới xuống ổ đĩa.
- Xử lý an toàn các trường hợp thiếu file.

Các vùng logic dự kiến
- Mở file và phân tích dữ liệu.
- Kiểm tra hợp lệ và giá trị mặc định dự phòng.
- Ghi lại khi đạt kỷ lục mới.

Phụ thuộc có thể dùng
- fstream và các tiện ích STL liên quan.
- src/systems/Score.hpp

Ghi chú cho lần hiện thực sau
- Giữ lỗi lưu trữ ở mức không làm sập chương trình.
- Tránh ghép chặt logic lưu trữ với phần vẽ hoặc chuyển cảnh.
*/
