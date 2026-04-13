# Week 03 Artifact - Le Doan Nhat Huy

## Scope Hoan Thanh

- Tich hop PipeManager vao core gameplay loop.
- Dam bao thu tu update: input -> bird -> pipes -> collision check -> score check -> render.
- Noi logic va cham co ban voi ong, tran va mat dat de dua game ve GameOver.
- Noi logic cong diem theo su kien vuot qua cap ong.
- Cap nhat huong dan UI va tai lieu theo milestone tuan 3.

## File Da Cap Nhat

- src/core/Game.hpp
- src/core/Game.cpp
- src/ui/UI.cpp
- CMakeLists.txt
- README.md
- Timeline_PhanCong_TienDo.md

## Build Va Run Command

```bash
cmake -S . -B build
cmake --build build --config Release
```

Run:

```bash
./build/Release/flappy_bird_week3.exe
```

## Hanh Vi Ban Tuan 3

- Enter, Space hoac click de bat dau.
- Khi dang choi: Space hoac click de flap.
- Ong duoc cap nhat lien tuc boi PipeManager.
- Va cham voi ong, tran hoac mat dat se GameOver.
- Di qua cap ong duoc cong diem.

## Hand-off Sang Tuan 4

- Dong bo voi module Collision chinh thuc cua thanh vien phu trach.
- Dong bo voi module HighScore va logic restart day du cho game over flow.
