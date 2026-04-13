# Week 04 Artifact - Le Doan Nhat Huy

## Scope Hoan Thanh

- Hoan thien flow diem so trong tran choi va ket thuc tran.
- Cap nhat HUD hien thi current score va best score trong phien choi.
- Cap nhat game over overlay hien thi final score, best score va huong dan restart.
- Chuan hoa restart/reset flow cho Start, GameOver va Pause.
- Tang cuong resetGame de dam bao luot choi moi sach trang thai.

## File Da Cap Nhat

- src/core/Game.hpp
- src/core/Game.cpp
- src/ui/UI.hpp
- src/ui/UI.cpp
- CMakeLists.txt
- README.md
- Timeline_PhanCong_TienDo.md
- docs/Program_Overview.md

## Build Va Run Command

```bash
cmake -S . -B build
cmake --build build --config Release
```

Run:

```bash
./build/Release/flappy_bird_week4.exe
```

## Hanh Vi Ban Tuan 4

- Trong Playing: HUD hien current score va best score.
- Khi va cham: vao GameOver va hien final score.
- Tu GameOver: Enter, Space, click chuot hoac R de choi lai.
- resetGame dat lai score, bird va pipes ve trang thai dau luot.

## Hand-off Sang Tuan 5

- Dong bo voi team asset/audio de polish giao dien va am thanh.
- Tich hop high score luu file khi module HighScore san sang.
