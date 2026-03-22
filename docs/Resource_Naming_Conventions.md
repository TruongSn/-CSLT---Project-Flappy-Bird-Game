# Quy ước Đặt Tên Tài Nguyên (Resource Naming Conventions)

Tài liệu này quy định cách đặt tên cho tất cả các file tài nguyên trong thư mục `assets/` của dự án Flappy Bird. Mục tiêu là để đảm bảo tính nhất quán, dễ tìm kiếm và dễ bảo trì.

## 1. Cấu trúc thư mục `assets/`
Thư mục `assets/` nên được chia thành các thư mục con theo loại tài nguyên:
- `assets/images/`: Chứa sprite, hình nền, UI (PNG, JPG).
- `assets/audio/`: Chứa âm thanh (WAV, OGG).
- `assets/fonts/`: Chứa font chữ (TTF, OTF).

## 2. Quy tắc chung
- Tất cả thư mục và tên file phải viết **thường hoàn toàn** (lowercase).
- Các từ nối với nhau bằng **dấu gạch dưới** (snake_case).
- Tên file nên mang tính mô tả rõ ràng, bắt đầu bằng loại đối tượng phân loại.

## 3. Quy ước cụ thể theo từng loại

### 3.1 Hình ảnh (`assets/images/`)
Cú pháp: `[thành phần]_[trạng thái/kiểu].png`

**Ví dụ:**
- `bird_upflap.png`
- `bird_midflap.png`
- `bird_downflap.png`
- `pipe_green_top.png`
- `pipe_green_bottom.png`
- `pipe_red_top.png` (nếu có loại ống đỏ)
- `bg_day.png` (background ban ngày)
- `bg_night.png` (background ban đêm)
- `base.png` (mặt đất)
- `ui_start_game.png`
- `ui_game_over.png`
- `ui_score_panel.png`

### 3.2 Âm thanh (`assets/audio/`)
Cú pháp: `sfx_[hành động/sự kiện].wav` hoặc `.ogg`

**Ví dụ:**
- `sfx_wing.wav` (hoặc `sfx_flap.wav`)
- `sfx_point.wav` (khi qua ống)
- `sfx_hit.wav` (khi chạm ống hoặc đất)
- `sfx_die.wav` (khi chết rơi xuống đất)
- `sfx_swoosh.wav` (khi chuyển màn)

### 3.3 Font chữ (`assets/fonts/`)
Cú pháp: `font_[tên_font].ttf`

**Ví dụ:**
- `font_flappy.ttf`
- `font_main.ttf`

## 4. Quản lý trong Code
Các tài nguyên này sẽ được refer tới thông qua các file cấu hình hoặc trực tiếp trong các manager/hệ thống quản lý tài nguyên. Việc tuân thủ quy tắc sẽ giúp dùng macro, dùng chung logic load resource một cách dễ dàng và tránh "file not found" giữa các hệ điều hành khác nhau (đặc biệt là Linux phân biệt hoa thường).
