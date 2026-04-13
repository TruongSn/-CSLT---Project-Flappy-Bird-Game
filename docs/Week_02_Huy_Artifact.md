# Week 02 Artifact - Le Doan Nhat Huy

## Scope Hoan Thanh

- Tich hop Bird vao game loop trong core.
- Hoan thien state transition Start -> Playing voi input ban phim va chuot.
- Ho tro flap trong Playing bang Space hoac click chuot.
- Cap nhat dieu kien game over khi bird cham tran hoac mat dat.
- Cap nhat UI text phu hop behavior tuan 2.
- Cap nhat CMake target cho week 2.

## File Da Cap Nhat

- `src/core/Game.hpp`
- `src/core/Game.cpp`
- `src/entities/Bird.cpp`
- `src/ui/UI.cpp`
- `CMakeLists.txt`
- `README.md`
- `Timeline_PhanCong_TienDo.md`

## Build Va Run Command

```bash
cmake -S . -B build
cmake --build build --config Release
```

Run:

```bash
./build/Release/flappy_bird_week2.exe
```

## Hanh Vi Ban Tuan 2

- Start bang Enter, Space, hoac click chuot.
- Dang choi: Space/click de flap.
- Cham tran hoac mat dat se game over.
- Tu game over co the Enter/Space/click de choi lai.

## Hand-off Sang Tuan 3

- Tich hop PipeManager vao loop theo thu tu input -> bird -> pipes -> collision -> score -> render.
- Ket noi Collision module de thay dieu kien game over tam thoi bang va cham voi ong.
