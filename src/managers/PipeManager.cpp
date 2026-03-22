/*
Mục đích
- File hiện thực dự kiến cho bộ quản lý PipeManager.

Trách nhiệm dự kiến
- Xử lý sinh chướng ngại vật theo thời gian.
- Cập nhật toàn bộ ống đang hoạt động theo đúng thứ tự.
- Xóa các ống rời khỏi vùng nhìn thấy.
- Cung cấp giao diện tập dữ liệu rõ ràng cho các hệ thống khác.

Các vùng logic dự kiến
- Tích lũy bộ đếm sinh.
- Chọn ngẫu nhiên vị trí khe hở trong giới hạn an toàn.
- Cập nhật và dọn dẹp tập ống.
- Hành vi đặt lại khi chơi lại.

Phụ thuộc có thể dùng
- Các tiện ích container của STL.
- Công cụ ngẫu nhiên trong standard library.
- src/entities/Pipe.hpp
- src/config/GameplayConfig.hpp hoặc cấu hình nội bộ của bộ quản lý.

Ghi chú cho lần hiện thực sau
- Giữ quyền quản lý bộ nhớ đơn giản và tường minh.
- Tránh tác động phụ ẩn khi hệ thống khác duyệt ống đang hoạt động.
*/



