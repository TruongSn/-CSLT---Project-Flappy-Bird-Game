# Timeline Phân Công Và Tiến Độ Dự Án Flappy Bird

## 1. Mục đích tài liệu

Tài liệu này dùng để:

- Theo dõi timeline 8 tuần của dự án.
- Khóa phân công nhiệm vụ theo từng thành viên.
- Ghi nhận tiến độ hoàn thành công việc theo từng tuần.
- Làm căn cứ để review tiến độ, handoff và báo cáo.

## 2. Quy ước cập nhật tiến độ

### 2.1. Trạng thái

- `Chưa bắt đầu`
- `Đang thực hiện`
- `Chờ tích hợp`
- `Hoàn thành`
- `Chậm tiến độ`

### 2.2. Cách điền cột tiến độ

- `0%`: chưa bắt đầu
- `25%`: đã có khung ban đầu
- `50%`: đã hoàn thành phần lớn logic chính
- `75%`: đã xong chức năng, đang test và fix
- `100%`: đã bàn giao và có thể tích hợp

### 2.3. Lưu ý

- Trạng thái trong file này mặc định được đặt là `Chưa cập nhật`.
- Nhóm cần cập nhật vào cuối mỗi tuần sau khi tổng hợp commit, test và artifact bàn giao.

## 3. Tổng quan timeline 8 tuần

| Tuần | Thời gian | Chủ đề | Kết quả chính |
| --- | --- | --- | --- |
| Tuần 1 | 12/03 - 18/03 | Lên kế hoạch và thiết lập dự án | Hoàn tất repo, môi trường, cấu trúc thư mục, scaffold và README bản đầu |
| Tuần 2 | 19/03 - 25/03 | Nhân vật và vật lý | Bird có thể flap, rơi tự nhiên, được tích hợp vào gameplay loop cơ bản |
| Tuần 3 | 26/03 - 01/04 | Ống cản và va chạm | Pipe được sinh và di chuyển đúng, collision hoạt động đúng logic |
| Tuần 4 | 02/04 - 08/04 | Điểm số và trạng thái game | Có score, game over, restart, reset và high score cục bộ cơ bản |
| Tuần 5 | 09/04 - 15/04 | Đồ họa và âm thanh | Có UI rõ ràng hơn, animation nhẹ, âm thanh cơ bản, asset trình bày được |
| Tuần 6 | 16/04 - 22/04 | Hoàn thiện gameplay | Cân bằng thông số, pause/resume, tune tốc độ và độ khó |
| Tuần 7 | 23/04 - 29/04 | Kiểm thử và sửa lỗi | Playtest, sửa bug, dọn kiến trúc, chốt hướng dẫn build/chạy/test |
| Tuần 8 | 30/04 - 06/05 | Đóng gói và hoàn thiện | Bản demo cuối, tài liệu báo cáo, video hoặc hình minh họa, release candidate |

## 4. Phân công cố định theo thành viên

| Thành viên | Phụ trách chính | Phạm vi file ưu tiên |
| --- | --- | --- |
| Lê Đoàn Nhật Huy | Kiến trúc tổng, game loop, state, UI, score, README, docs | `main.cpp`, `src/core/*`, `src/ui/*`, `src/systems/Score*`, `README.md`, `docs/*` |
| Trần Vũ Anh Kiệt | Bird, vật lý, input feel, collision, gameplay config, manual test cơ học | `src/entities/Bird*`, `src/systems/Collision*`, `src/config/GameplayConfig*`, `tests/manual/mechanics/*` |
| Nguyễn Trường Sơn | Pipe, PipeManager, asset, audio, high score, persistence | `src/entities/Pipe*`, `src/managers/PipeManager*`, `src/systems/HighScore*`, `assets/*` |

## 5. Phân công chi tiết từng tuần

## Tuần 1 - Lên kế hoạch và thiết lập dự án

| Thành viên | Nhiệm vụ chính | Đầu ra cần bàn giao | Trạng thái | % hoàn thành | Ghi chú |
| --- | --- | --- | --- | --- | --- |
| Lê Đoàn Nhật Huy | Tạo skeleton project, mở cửa sổ SFML rỗng, dựng `GameState`, khóa cấu trúc thư mục, viết README build/run bản đầu | Scaffold repo, cửa sổ rỗng build được, README hướng dẫn cơ bản | Chưa cập nhật | 0% | |
| Trần Vũ Anh Kiệt | Thiết kế API cho `Bird`, mô tả flap, gravity, reset, tạo `GameplayConfig.hpp` bản đầu | Contract cho `Bird`, nhóm thông số vật lý bản đầu | Chưa cập nhật | 0% | |
| Nguyễn Trường Sơn | Thiết kế API cho `Pipe` và `PipeManager`, dựng asset folder, thống nhất quy ước tên file tài nguyên | Contract cho pipe, asset folder và quy ước đặt tên | Hoàn thành | 100% | Đã thiết kế xong `Pipe` & `PipeManager` class, định nghĩa doc `Resource_Naming_Conventions.md` |

## Tuần 2 - Nhân vật và vật lý

| Thành viên | Nhiệm vụ chính | Đầu ra cần bàn giao | Trạng thái | % hoàn thành | Ghi chú |
| --- | --- | --- | --- | --- | --- |
| Lê Đoàn Nhật Huy | Tích hợp `Bird` vào game loop tổng, hoàn thành chuyển state từ bắt đầu sang đang chơi | Bird được gọi update/render trong luồng chơi | Chưa cập nhật | 0% | |
| Trần Vũ Anh Kiệt | Hiện thực `Bird`: flap, gravity, velocity, reset, render placeholder | Bird bay lên khi nhấn phím/click, rơi tự nhiên, reset được | Chưa cập nhật | 0% | |
| Nguyễn Trường Sơn | Chuẩn bị tài nguyên tạm cho bird, background, ground, pipe, font | Bộ asset tối thiểu để chạy MVP | Chưa cập nhật | 0% | |

## Tuần 3 - Ống cản và va chạm

| Thành viên | Nhiệm vụ chính | Đầu ra cần bàn giao | Trạng thái | % hoàn thành | Ghi chú |
| --- | --- | --- | --- | --- | --- |
| Lê Đoàn Nhật Huy | Tích hợp `PipeManager` vào gameplay loop theo thứ tự input -> bird -> pipes -> collision -> score -> render | Game loop tổng chạy đúng thứ tự | Chưa cập nhật | 0% | |
| Trần Vũ Anh Kiệt | Hiện thực `Collision` giữa bird với pipe, ground, ceiling và trả kết quả để game over | Module collision và checklist test tay cho các trường hợp biên | Chưa cập nhật | 0% | |
| Nguyễn Trường Sơn | Hiện thực `Pipe` và `PipeManager`: spawn theo timer, random gap, move trái, remove offscreen | Ống sinh liên tục, di chuyển ổn định, không phồng bộ nhớ | Chưa cập nhật | 0% | |

## Tuần 4 - Điểm số và trạng thái game

| Thành viên | Nhiệm vụ chính | Đầu ra cần bàn giao | Trạng thái | % hoàn thành | Ghi chú |
| --- | --- | --- | --- | --- | --- |
| Lê Đoàn Nhật Huy | Hiện thực `Score`, HUD điểm, `GameOver`, restart, `resetGame()` | Điểm tăng đúng, thua hiện game over, chơi lại reset sạch state | Chưa cập nhật | 0% | |
| Trần Vũ Anh Kiệt | Xử lý reset phía `Bird`, rà soát edge case collision sau restart | Restart không giữ velocity hoặc trạng thái cũ | Chưa cập nhật | 0% | |
| Nguyễn Trường Sơn | Hiện thực `HighScore` local file và cờ `passed` cho pipe pair | High score đọc/ghi được, mỗi cặp ống chỉ tính điểm một lần | Chưa cập nhật | 0% | |

## Tuần 5 - Đồ họa và âm thanh

| Thành viên | Nhiệm vụ chính | Đầu ra cần bàn giao | Trạng thái | % hoàn thành | Ghi chú |
| --- | --- | --- | --- | --- | --- |
| Lê Đoàn Nhật Huy | Polish UI: start screen, HUD, game over overlay, canh lề text | Giao diện đủ rõ để người mới nhìn vào hiểu cách chơi | Chưa cập nhật | 0% | |
| Trần Vũ Anh Kiệt | Thêm animation hoặc rotation nhẹ cho bird theo velocity mà không phá physics | Bird trông có hồn hơn nhưng input feel vẫn ổn định | Chưa cập nhật | 0% | |
| Nguyễn Trường Sơn | Tích hợp audio flap/score/hit, thay asset tạm bằng asset demo được | Có âm thanh cơ bản và tài nguyên đủ cho demo | Chưa cập nhật | 0% | |

## Tuần 6 - Hoàn thiện gameplay

| Thành viên | Nhiệm vụ chính | Đầu ra cần bàn giao | Trạng thái | % hoàn thành | Ghi chú |
| --- | --- | --- | --- | --- | --- |
| Lê Đoàn Nhật Huy | Thêm state `Paused`, hoàn thiện flow `Start / Playing / Paused / GameOver` | Pause/resume ổn định, UI trạng thái rõ ràng | Chưa cập nhật | 0% | |
| Trần Vũ Anh Kiệt | Tune gravity, flap force, collision feel, input responsiveness | Gameplay không quá nặng tay và không quá lơ lửng | Chưa cập nhật | 0% | |
| Nguyễn Trường Sơn | Tune pipe speed, spawn interval, gap size; nếu còn thời gian thì làm F10 ở mức nhẹ | Ống cân bằng về nhạc độ và độ khó | Chưa cập nhật | 0% | |

## Tuần 7 - Kiểm thử và sửa lỗi

| Thành viên | Nhiệm vụ chính | Đầu ra cần bàn giao | Trạng thái | % hoàn thành | Ghi chú |
| --- | --- | --- | --- | --- | --- |
| Lê Đoàn Nhật Huy | Hợp nhất branch, dọn kiến trúc, hoàn thiện README, checklist test tay | Repo sạch, tài liệu dễ đọc, hướng dẫn build/chạy/test rõ | Chưa cập nhật | 0% | |
| Trần Vũ Anh Kiệt | Fix bug liên quan bird, physics, collision, restart | Các bug gameplay nghiêm trọng được khóa | Chưa cập nhật | 0% | |
| Nguyễn Trường Sơn | Fix bug liên quan pipe, đường dẫn tài nguyên, audio, high score, file not found | Bản chạy ổn định trên nhiều máy trong nhóm | Chưa cập nhật | 0% | |

## Tuần 8 - Đóng gói và hoàn thiện sản phẩm

| Thành viên | Nhiệm vụ chính | Đầu ra cần bàn giao | Trạng thái | % hoàn thành | Ghi chú |
| --- | --- | --- | --- | --- | --- |
| Lê Đoàn Nhật Huy | Chốt release candidate, README cuối, docs demo, ảnh hoặc video minh họa | Bản demo cuối ổn định cho báo cáo | Chưa cập nhật | 0% | |
| Trần Vũ Anh Kiệt | Regression cuối cho gameplay, khóa thông số vật lý bản final | Mechanics final được chốt, không thay đổi lung tung nữa | Chưa cập nhật | 0% | |
| Nguyễn Trường Sơn | Kiểm tra package tài nguyên, đường dẫn resource, high score file, clean clone run | Clone mới vẫn chạy được theo README | Chưa cập nhật | 0% | |

## 6. Bảng theo dõi tiến độ tổng hợp theo thành viên

## Lê Đoàn Nhật Huy

| Tuần | Công việc chính | Trạng thái | % hoàn thành | Minh chứng | Ghi chú |
| --- | --- | --- | --- | --- | --- |
| 1 | Scaffold, cấu trúc thư mục, `GameState`, README bản đầu | Chưa cập nhật | 0% | | |
| 2 | Tích hợp `Bird` vào game loop | Chưa cập nhật | 0% | | |
| 3 | Tích hợp `PipeManager` vào gameplay loop | Chưa cập nhật | 0% | | |
| 4 | `Score`, HUD, `GameOver`, restart | Chưa cập nhật | 0% | | |
| 5 | Polish UI | Chưa cập nhật | 0% | | |
| 6 | `Paused` và flow state đầy đủ | Chưa cập nhật | 0% | | |
| 7 | Merge, dọn kiến trúc, README, checklist test | Chưa cập nhật | 0% | | |
| 8 | Release candidate, docs demo, media minh họa | Chưa cập nhật | 0% | | |

## Trần Vũ Anh Kiệt

| Tuần | Công việc chính | Trạng thái | % hoàn thành | Minh chứng | Ghi chú |
| --- | --- | --- | --- | --- | --- |
| 1 | API `Bird`, `GameplayConfig`, note cơ học | Chưa cập nhật | 0% | | |
| 2 | Hiện thực `Bird` và vật lý cơ bản | Chưa cập nhật | 0% | | |
| 3 | `Collision` và test tay | Chưa cập nhật | 0% | | |
| 4 | Reset `Bird` và edge case sau restart | Chưa cập nhật | 0% | | |
| 5 | Animation hoặc rotation nhẹ cho Bird | Chưa cập nhật | 0% | | |
| 6 | Tune gravity, flap, collision feel | Chưa cập nhật | 0% | | |
| 7 | Fix bug bird/physics/collision | Chưa cập nhật | 0% | | |
| 8 | Regression cuối và khóa thông số final | Chưa cập nhật | 0% | | |

## Nguyễn Trường Sơn

| Tuần | Công việc chính | Trạng thái | % hoàn thành | Minh chứng | Ghi chú |
| --- | --- | --- | --- | --- | --- |
| 1 | API `Pipe`, `PipeManager`, quy ước tài nguyên | Hoàn thành | 100% | File `Pipe.hpp`, `Pipe.cpp`, `PipeManager.hpp`, `PipeManager.cpp`, và `Resource_Naming_Conventions.md` | |
| 2 | Tài nguyên tạm cho MVP | Chưa cập nhật | 0% | | |
| 3 | Hiện thực `Pipe` và `PipeManager` | Chưa cập nhật | 0% | | |
| 4 | `HighScore` và cờ `passed` cho pipe pair | Chưa cập nhật | 0% | | |
| 5 | Audio và thay asset demo | Chưa cập nhật | 0% | | |
| 6 | Tune ống và độ khó nhẹ | Chưa cập nhật | 0% | | |
| 7 | Fix bug pipe/resource/audio/high score | Chưa cập nhật | 0% | | |
| 8 | Kiểm tra package tài nguyên và clean clone run | Chưa cập nhật | 0% | | |

## 7. Mốc kiểm tra nội bộ theo tuần

| Tuần | Điều kiện được xem là đạt | Người chốt |
| --- | --- | --- |
| 1 | Scaffold đủ cấu trúc và mở được cửa sổ rỗng | Huy |
| 2 | Bird flap, rơi tự nhiên, reset được | Kiệt |
| 3 | Pipe spawn ổn định, collision trả kết quả đúng | Huy + Kiệt + Sơn |
| 4 | Score, game over, restart, high score cơ bản hoạt động | Huy + Sơn |
| 5 | UI rõ ràng, âm thanh cơ bản, demo trình bày được | Huy + Sơn |
| 6 | Gameplay cân bằng, pause/resume ổn định | Huy + Kiệt + Sơn |
| 7 | Bug nghiêm trọng đã được xử lý, README đầy đủ | Cả nhóm |
| 8 | Bản demo cuối chạy ổn định để nộp và báo cáo | Cả nhóm |

## 8. Hướng dẫn cập nhật hàng tuần

Cuối mỗi tuần, nhóm nên cập nhật tối thiểu các thông tin sau:

1. Trạng thái và phần trăm hoàn thành cho từng dòng công việc.
2. Minh chứng đã có: commit, pull request, video, hình ảnh, checklist test.
3. Rủi ro còn lại của từng thành viên.
4. Việc gì cần handoff sang thành viên khác ở tuần tiếp theo.
5. Nếu chậm tiến độ, cần ghi rõ nguyên nhân và phương án cắt giảm phạm vi.
