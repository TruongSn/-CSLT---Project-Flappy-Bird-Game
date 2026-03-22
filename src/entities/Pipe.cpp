/*
Mục đích
- File hiện thực dự kiến cho entity Pipe.

Trách nhiệm dự kiến
- Di chuyển các ống qua màn hình.
- Chuẩn bị bounds của ống trên và ống dưới.
- Hỗ trợ hành vi vẽ và thay đổi trạng thái passed.

Các vùng logic dự kiến
- Khởi tạo lúc sinh ra.
- Di chuyển theo từng frame.
- Phát hiện khi ra khỏi màn hình.
- Cách vẽ cho phần tạm và asset thật.

Phụ thuộc có thể dùng
- Các kiểu đồ họa của SFML.
- src/config/GameplayConfig.hpp hoặc thiết lập do manager cung cấp.

Ghi chú cho lần hiện thực sau
- Nếu có thể, giữ quyết định sinh ngẫu nhiên ở ngoài file này.
- Tránh đặt logic điểm ở đây, ngoại trừ việc lưu trạng thái cặp ống đã được vượt qua.
*/
