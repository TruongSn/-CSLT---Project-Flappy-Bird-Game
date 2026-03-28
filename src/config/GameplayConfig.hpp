/*
Mục đích
- Nơi dự kiến khai báo các giá trị tinh chỉnh trò chơi tập trung.

Nhóm cấu hình dự kiến
- Thiết lập cửa sổ.
- Thiết lập gravity.
- Thiết lập lực flap.
- Tốc độ di chuyển của ống.
- Khoảng thời gian sinh.
- Kích thước khe.
- Chiều cao mặt đất.
- Luật tính điểm.

Nội dung sẽ có sau này
- TODO: định nghĩa tên cho chiều rộng và chiều cao cửa sổ.
- TODO: định nghĩa tên cho các giá trị vật lý của Bird.
- TODO: định nghĩa tên cho giá trị thời gian và khoảng cách của ống.
- TODO: định nghĩa tên cho ngưỡng hoặc luật liên quan đến điểm nếu cần.

Ví dụ chỉ ở dạng comment
- Ví dụ: giá trị chiều rộng và chiều cao cửa sổ sẽ được đặt ở đây.
- Ví dụ: hằng số gravity và flap force sẽ được chỉnh tại đây.
- Ví dụ: tốc độ ống, khoảng thời gian sinh và kích thước khe sẽ được gom nhóm ở đây.

Ghi chú cho lần hiện thực sau
- Giữ các giá trị tinh chỉnh được tập trung.
- Tránh rải hằng số của trò chơi ra nhiều mô-đun không liên quan.
*/
#pragma once

namespace GameplayConfig {

// Window
inline constexpr unsigned int WindowWidth = 800;
inline constexpr unsigned int WindowHeight = 600;
inline constexpr const char* WindowTitle = "Flappy Bird Game";

// Bird
inline constexpr float BirdSpawnX = 180.f;
inline constexpr float BirdSpawnY = 260.f;
inline constexpr float BirdWidth = 34.f;
inline constexpr float BirdHeight = 24.f;

inline constexpr float BirdGravity = 1200.f;
inline constexpr float BirdFlapVelocity = -360.f;
inline constexpr float BirdMaxFallSpeed = 520.f;
inline constexpr float BirdMaxRiseSpeed = -420.f;

// Pipe
inline constexpr float PipeMoveSpeed = 180.f;
inline constexpr float PipeSpawnInterval = 1.8f;
inline constexpr float PipeGapSize = 170.f;
inline constexpr float PipeWidth = 52.f;

// Ground / scoring
inline constexpr float GroundHeight = 100.f;
inline constexpr int ScorePerPipePair = 1;

} // namespace GameplayConfig