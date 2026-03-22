/*
Mục đích
- Nơi dự kiến khai báo bộ điều phối Game chính.
- Mô-đun này sẽ điều phối toàn bộ vòng đời game.

Trách nhiệm dự kiến
- Quản lý cửa sổ chính và tài nguyên dùng chung khi chạy.
- Điều phối input, cập nhật, vẽ và chuyển trạng thái.
- Kết nối Bird, PipeManager, Collision, Score, HighScore và UI.

Dữ liệu chính dự kiến có ở đây
- Trạng thái game hiện tại.
- Đối tượng cửa sổ và thời gian.
- Các đối tượng mô-đun lõi của trò chơi.
- Các cờ dùng chung cho chạy, tạm dừng và đặt lại.

API public dự kiến
- TODO: khai báo constructor và destructor nếu cần.
- TODO: khai báo run().
- TODO: khai báo processInput().
- TODO: khai báo update().
- TODO: khai báo render().
- TODO: khai báo resetGame().
- TODO: khai báo hàm hỗ trợ chuyển trạng thái.

Ghi chú cho lần hiện thực sau
- Giữ phần điều phối ở đây, không nhét vào class entity.
- Tôn trọng ranh giới phần việc khi tích hợp các mô-đun khác.
*/

