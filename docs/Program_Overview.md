# Tổng quan chương trình

## Mục đích

Tài liệu này mô tả cấu trúc và hành vi dự kiến của dự án Flappy Bird 2D desktop offline trước khi bắt đầu hiện thực trò chơi. Đây là artifact dùng để đồng bộ kiến trúc, khóa phạm vi phụ trách và chốt thứ tự triển khai.

## Luồng người chơi dự kiến

Luồng chạy mục tiêu:

1. Bắt đầu (Start)
2. Đang chơi (Playing)
3. Thua cuộc (GameOver)
4. Chơi lại (Restart)

Kỳ vọng chi tiết:

- `Bắt đầu (Start)`: hiển thị tiêu đề, hướng dẫn và chờ người chơi thao tác.
- `Đang chơi (Playing)`: cập nhật chim, ống, va chạm, điểm và vẽ frame hiện tại.
- `Thua cuộc (GameOver)`: dừng tiến trình chơi bình thường, hiển thị điểm cuối và gợi ý chơi lại.
- `Chơi lại (Restart)`: đặt lại trạng thái trò chơi và trở lại một lượt chơi sạch.

Trạng thái tùy chọn về sau:

- `Tạm dừng (Paused)`: tạm dừng cập nhật trò chơi nhưng vẫn giữ phiên chơi để có thể tiếp tục.

## Trách nhiệm từng mô-đun

### `main.cpp`

- Điểm vào cho quá trình khởi động ứng dụng.
- Sau này sẽ tạo game object cấp cao nhất.
- Sẽ bàn giao quyền điều khiển cho vòng lặp lõi của game.

### `src/core/Game.*`

- Bộ điều phối chạy trung tâm.
- Quản lý cấu trúc vòng lặp chính.
- Gọi input, cập nhật, vẽ và đặt lại theo đúng thứ tự.
- Tích hợp toàn bộ mô-đun trò chơi.

### `src/core/GameState.hpp`

- Định nghĩa các trạng thái game hợp lệ.
- Cung cấp hợp đồng trạng thái dùng chung cho toàn bộ project.

### `src/entities/Bird.*`

- Lưu dữ liệu nhân vật người chơi.
- Xử lý chuyển động chim, lực flap, gravity, đặt lại trạng thái và dữ liệu hiển thị.

### `src/entities/Pipe.*`

- Biểu diễn từng chướng ngại vật hoặc dữ liệu cặp ống.
- Lưu trạng thái chuyển động và cờ liên quan đến tính điểm.

### `src/managers/PipeManager.*`

- Quản lý toàn bộ ống đang hoạt động.
- Sinh chướng ngại vật theo bộ đếm thời gian.
- Cập nhật và xóa các ống hiện có.
- Cung cấp dữ liệu ống cho va chạm và điểm số.

### `src/systems/Collision.*`

- Kiểm tra chồng lấp giữa chim và bounds của ống.
- Kiểm tra va chạm với biên thế giới như mặt đất và trần.
- Báo về việc trò chơi có nên chuyển sang trạng thái thua cuộc hay không.

### `src/systems/Score.*`

- Theo dõi điểm của lượt chơi hiện tại.
- Tăng điểm khi chim vượt qua chướng ngại vật hợp lệ.

### `src/systems/HighScore.*`

- Đọc và ghi điểm cao nhất vào file cục bộ.
- Giữ dữ liệu qua nhiều lần mở ứng dụng mà không cần dịch vụ bên ngoài.

### `src/ui/UI.*`

- Vẽ hướng dẫn màn hình bắt đầu, HUD điểm, overlay tạm dừng và thông báo thua cuộc.
- Giữ phần trình bày tách khỏi các hệ thống của trò chơi.

### `src/config/GameplayConfig.hpp`

- Nơi tập trung các giá trị tinh chỉnh trò chơi và thiết lập vùng chơi.
- Tránh để hằng số bị rải rác trong codebase.

## Hướng phụ thuộc dự kiến

Mô hình phụ thuộc ở mức cao:

- `main.cpp` phụ thuộc vào `src/core/Game.*`
- `src/core/Game.*` phụ thuộc vào entities, managers, systems, config và UI
- `src/ui/UI.*` phụ thuộc vào game state và dữ liệu điểm do core truyền vào
- `src/systems/Collision.*` phụ thuộc vào dữ liệu Bird và Pipe
- `src/systems/Score.*` phụ thuộc vào dữ liệu chạy của trò chơi, đặc biệt là sự kiện vượt ống
- `src/systems/HighScore.*` phụ thuộc vào file I/O cục bộ và giá trị điểm
- `src/managers/PipeManager.*` phụ thuộc vào `src/entities/Pipe.*`
- `src/entities/*` nên càng tự chứa càng tốt trong phạm vi hợp lý

Quy tắc phụ thuộc:

- Core có thể biết mọi mô-đun cần thiết để điều phối.
- Các mô-đun tính năng không nên tự giành phần việc của chuyển trạng thái hoặc hành vi UI.

## Thứ tự triển khai gợi ý

1. Dựng khung và khóa cấu trúc thư mục
2. Định nghĩa `GameState`
3. Khai báo API điều phối của `Game`
4. Khai báo contract của Bird và GameplayConfig
5. Khai báo contract của Pipe và PipeManager
6. Hiện thực vòng lặp chạy cơ bản
7. Hiện thực vật lý Bird
8. Hiện thực việc sinh và chuyển động của ống
9. Hiện thực phát hiện va chạm
10. Hiện thực logic điểm số
11. Hiện thực trạng thái thua cuộc và luồng chơi lại
12. Hiện thực overlay giao diện
13. Bổ sung lưu điểm cao nhất cục bộ
14. Bổ sung âm thanh và hoàn thiện thêm nếu còn thời gian

## Phạm vi MVP

Phần bắt buộc của MVP:

- Màn hình bắt đầu
- Bird flap và gravity
- Ống sinh và di chuyển
- Va chạm với ống và mặt đất
- Điểm hiện tại
- Màn hình thua cuộc
- Luồng chơi lại

Nên có sau MVP:

- Lưu điểm cao nhất cục bộ
- Bố cục UI tốt hơn
- Tài nguyên tạm gọn hơn

Có thể làm nếu còn thời gian:

- Tạm dừng và tiếp tục
- Hiệu ứng âm thanh
- Tăng độ khó nhẹ
- Hoàn thiện thêm chuyển động

## Rủi ro kỹ thuật

### Thiết lập và liên kết SFML

- Rủi ro: cấu hình cục bộ giữa các máy không đồng nhất có thể làm chậm quá trình vào việc.
- Giảm thiểu: ghi lại chính xác các bước compiler và linkage SFML trong README khi đã chốt đường build.

### Đường dẫn tài nguyên

- Rủi ro: giả định về vị trí executable và đường dẫn tài nguyên có thể khác nhau giữa IDE hoặc giữa các máy.
- Giảm thiểu: chuẩn hóa sớm vị trí chạy và kỳ vọng về thư mục tài nguyên.

### Tinh chỉnh vật lý

- Rủi ro: chuyển động của chim có thể quá nặng, quá lơ lửng hoặc thiếu ổn định.
- Giảm thiểu: gom toàn bộ giá trị tinh chỉnh vào `GameplayConfig` và chỉnh bằng kiểm thử tay tập trung.

### Cộng điểm trùng

- Rủi ro: điểm có thể tăng nhiều hơn một lần cho cùng một cặp ống.
- Giảm thiểu: giữ cờ passed rõ ràng trong mô-đun liên quan đến ống.

### Độ sạch của chơi lại

- Rủi ro: trạng thái của lượt trước có thể rò sang lượt chơi mới.
- Giảm thiểu: mô tả rõ trách nhiệm đặt lại theo từng mô-đun và xác minh bằng kiểm thử tay.

### Chồng lấn phạm vi phụ trách

- Rủi ro: nhiều thành viên có thể cùng sửa những mô-đun kết nối chặt với nhau.
- Giảm thiểu: khóa phạm vi file và yêu cầu artifact bàn giao ngắn cho mỗi task.

## Ghi chú về tài liệu và kiểm thử

- `README.md` là tài liệu setup và quy trình làm việc cho cả nhóm.
- `tests/manual/mechanics/` dành cho checklist hành vi và ghi chú QA.
- Mỗi giai đoạn tính năng nên kết thúc bằng artifact ngắn:
  - đã đổi gì
  - đã đổi file nào
  - đã test gì
  - còn rủi ro gì

## Ràng buộc của bộ khung hiện tại

Sau mốc Tuần 1, một phần scaffold đã được hiện thực ở phạm vi core:

- `main.cpp` có thể khởi chạy ứng dụng.
- `GameState`, `Game`, `UI`, `Score` đã có code tối thiểu để chạy flow trạng thái.
- `CMakeLists.txt` đã cho phép build bản scaffold.

Các mô-đun Bird, Pipe, PipeManager, Collision và HighScore vẫn là contract khung và sẽ hoàn thiện theo timeline tuần tiếp theo.

