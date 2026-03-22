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
