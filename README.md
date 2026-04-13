# Dự án Flappy Bird 2D Desktop Offline

Đây là dự án game Flappy Bird chạy trên desktop bằng C++17 và SFML. Repository đã hoàn thành mốc Tuần 4 cho phần score/state flow: HUD điểm trong lúc chơi, game over hiển thị điểm cuối, lưu best score trong phiên chạy, restart và reset game rõ ràng.

## Mục tiêu dự án

Xây dựng một bản MVP Flappy Bird offline trên desktop với luồng cốt lõi sau:

- Màn hình bắt đầu
- Chim flap và chịu gravity
- Ống sinh ra và di chuyển
- Va chạm với ống và mặt đất
- Điểm số cập nhật theo thời gian thực
- Trạng thái thua cuộc
- Luồng chơi lại

Phần mở rộng sau MVP:

- Tạm dừng và tiếp tục
- Âm thanh cơ bản
- Lưu điểm cao nhất cục bộ
- Tăng độ khó nhẹ

## Trạng thái hiện tại

Repository hiện ở trạng thái sau khi chốt milestone Tuần 4.

- Đã có entry point chạy được từ `main.cpp`.
- Đã có `GameState` và game loop trong `src/core/Game.*`.
- Đã có scaffold UI trong `src/ui/UI.*` và scaffold điểm trong `src/systems/Score.*`.
- Đã tích hợp `Bird` vào luồng `Start -> Playing -> GameOver`.
- Đã tích hợp `PipeManager` vào gameplay loop và stage cộng điểm theo pipe pass.
- Đã hoàn thiện flow game over, restart và reset cho vòng chơi mới.
- Đã có best score theo phiên chạy để hỗ trợ demo gameplay.
- Đã có cấu hình build CMake trong `CMakeLists.txt`.
- Module `Collision` và `HighScore` vẫn chờ hoàn thiện theo timeline tuần tiếp theo.

## Stack công nghệ

- Ngôn ngữ: C++17
- Thư viện: SFML
- Standard Library: chỉ dùng STL
- Lưu trữ: file cục bộ cho điểm cao nhất
- Loại ứng dụng: game desktop 2D offline
- Tài liệu: Markdown

Không nằm trong phạm vi:

- Database
- API ngoài
- Web backend
- Engine hoặc framework khác như Unity, Unreal, Godot, SDL hoặc raylib

## Cấu trúc thư mục dự kiến

```text
project-root/
|-- main.cpp
|-- src/
|   |-- core/
|   |   |-- Game.hpp
|   |   |-- Game.cpp
|   |   `-- GameState.hpp
|   |-- entities/
|   |   |-- Bird.hpp
|   |   |-- Bird.cpp
|   |   |-- Pipe.hpp
|   |   `-- Pipe.cpp
|   |-- managers/
|   |   |-- PipeManager.hpp
|   |   `-- PipeManager.cpp
|   |-- systems/
|   |   |-- Collision.hpp
|   |   |-- Collision.cpp
|   |   |-- Score.hpp
|   |   |-- Score.cpp
|   |   |-- HighScore.hpp
|   |   `-- HighScore.cpp
|   |-- ui/
|   |   |-- UI.hpp
|   |   `-- UI.cpp
|   `-- config/
|       `-- GameplayConfig.hpp
|-- assets/
|   |-- images/
|   |-- audio/
|   `-- fonts/
|-- docs/
|   `-- Program_Overview.md
|-- tests/
|   `-- manual/
|       `-- mechanics/
|           `-- Collision_Checklist.md
`-- README.md
```

## Mô tả ngắn các mô-đun

- `main.cpp`: điểm vào của ứng dụng; sau này tạo đối tượng `Game` và khởi động vòng đời chương trình.
- `src/core/Game.*`: điều phối input, cập nhật, vẽ và chuyển trạng thái.
- `src/core/GameState.hpp`: định nghĩa trạng thái dùng chung như Start, Playing, Paused và GameOver.
- `src/entities/Bird.*`: dữ liệu chim, chuyển động, hiển thị và đặt lại.
- `src/entities/Pipe.*`: biểu diễn từng chướng ngại vật và trạng thái passed.
- `src/managers/PipeManager.*`: sinh, cập nhật, dọn dẹp và cung cấp danh sách ống đang hoạt động.
- `src/systems/Collision.*`: kiểm tra va chạm giữa chim, ống, mặt đất và trần.
- `src/systems/Score.*`: quản lý điểm của lượt chơi hiện tại.
- `src/systems/HighScore.*`: lưu điểm cao nhất cục bộ.
- `src/ui/UI.*`: màn hình bắt đầu, HUD, overlay tạm dừng và thua cuộc.
- `src/config/GameplayConfig.hpp`: nơi gom các giá trị tinh chỉnh và cấu hình trò chơi.
- `docs/`: ghi chú thiết kế và định hướng hiện thực ở cấp dự án.
- `tests/manual/`: checklist kiểm thử tay và ghi chú QA.

## Hướng dẫn build và chạy (Tuần 4)

Các bước bên dưới dùng để chạy bản scaffold hiện tại.

### Yêu cầu trước khi build

- Compiler hỗ trợ C++17
- CMake 3.16+
- SFML đã được cài và để CMake tìm thấy (qua system path hoặc cấu hình `SFML_DIR`)

### Build với CMake

Từ thư mục project root, chạy:

```bash
cmake -S . -B build
cmake --build build --config Release
```

### Chạy chương trình

Với generator nhiều cấu hình (Visual Studio):

```bash
./build/Release/flappy_bird_week4.exe
```

Với generator một cấu hình (Ninja/MinGW Makefiles):

```bash
./build/flappy_bird_week4.exe
```

Điều khiển ở bản Tuần 4:

- `Enter` / `Space` / click chuột: bắt đầu hoặc chơi lại
- `Space` / click chuột khi đang chơi: flap
- `Esc`: pause hoặc resume
- Va chạm trần, mặt đất hoặc ống: game over
- Ở game over: `R` cũng có thể chơi lại

## Quy trình làm việc nhóm

Luồng cộng tác được khuyến nghị:

1. Khóa phạm vi phụ trách file trước mỗi giai đoạn làm việc.
2. Mỗi người làm trên branch cá nhân.
3. Chỉ sửa trong đúng mô-đun được giao.
4. Build hoặc kiểm tra đúng phạm vi liên quan trước khi bàn giao.
5. Đính kèm artifact ngắn gồm file đã đổi, test đã chạy và rủi ro còn lại.
6. Chỉ merge khi ranh giới phần việc và handoff đã rõ.

Gợi ý tên branch:

- `huy/tuan-01-bo-khung`
- `kiet/tuan-03-va-cham`
- `son/tuan-04-diem-cao-nhat`

## Quy ước phạm vi phụ trách mô-đun

### Thành viên 1: Le Doan Nhat Huy

Owner chính:

- Kiến trúc tổng
- Vòng lặp game
- Trạng thái game
- UI
- Score
- README và docs
- Đóng gói demo

Được sửa:

- `main.cpp`
- `src/core/*`
- `src/ui/*`
- `src/systems/Score*`
- `README.md`
- `docs/*`

Không sửa:

- `src/entities/Bird*`
- `src/systems/Collision*`
- `src/entities/Pipe*`
- `src/managers/PipeManager*`
- `src/systems/HighScore*`
- `assets/audio/*`
- `assets/images/*`

### Thành viên 2: Tran Vu Anh Kiet

Owner chính:

- Bird
- Physics
- Input feel
- Collision
- Cấu hình gameplay

Được sửa:

- `src/entities/Bird*`
- `src/systems/Collision*`
- `src/config/GameplayConfig*`
- `tests/manual/mechanics/*`

Không sửa:

- `main.cpp`
- `src/core/*`
- `src/ui/*`
- `src/systems/Score*`
- `src/managers/PipeManager*`
- `src/systems/HighScore*`
- `assets/*`

### Thành viên 3: Nguyen Truong Son

Owner chính:

- Pipe
- Pipe manager
- Asset pipeline
- Audio
- Điểm cao nhất cục bộ
- Lưu trữ

Được sửa:

- `src/entities/Pipe*`
- `src/managers/PipeManager*`
- `src/systems/HighScore*`
- `assets/*`

Không sửa:

- `main.cpp`
- `src/core/*`
- `src/ui/*`
- `src/entities/Bird*`
- `src/systems/Collision*`
- `src/systems/Score*`

## Checklist phần còn phải hiện thực

Phần MVP lõi còn lại:

- [x] Định nghĩa `GameState`
- [x] Khai báo lớp `Game` và vòng lặp khi chạy
- Hợp đồng Bird và vật lý
- Hợp đồng Pipe và PipeManager
- Phát hiện va chạm
- Luật tăng điểm
- Xử lý file điểm cao nhất
- [x] Chữ giao diện và overlay ở mức scaffold
- Chiến lược nạp tài nguyên
- Ca kiểm thử tay cho luồng trò chơi

Phần hỗ trợ dự án còn lại:

- [x] Chọn và thêm cấu hình build (CMake)
- Thêm tài nguyên tạm
- Định nghĩa chính sách đường dẫn file điểm cao nhất
- Ghi rõ các bước compiler và SFML setup
- Bổ sung ảnh chụp hoặc ghi chú demo sau khi có bản chơi được

## Quy tắc khóa cho repository này

- Giữ C++17 + SFML + STL là stack duy nhất.
- Không thêm database.
- Không thêm API ngoài.
- Không đưa engine hoặc framework khác vào dự án.
- Không thay đổi ranh giới mô-đun nếu chưa có đồng thuận của nhóm.
- Giữ file mã nguồn rõ trách nhiệm và dễ đọc.

## Tài liệu liên quan

- Tổng quan chương trình: `docs/Program_Overview.md`
- Tệp kiểm thử tay tạm: `tests/manual/mechanics/Collision_Checklist.md`

## Bước tiếp theo

Dùng bộ khung này làm điểm xuất phát đã được khóa, sau đó hiện thực dần từng mô-đun theo phạm vi phụ trách và quy tắc bàn giao của nhóm.




