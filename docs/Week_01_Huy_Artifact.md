# Week 01 Artifact - Le Doan Nhat Huy

## Scope Hoan Thanh

- Hoan thien entry point trong `main.cpp`.
- Hoan thien state machine trong `src/core/GameState.hpp`.
- Dung game loop co ban va mo cua so SFML trong `src/core/Game.hpp` va `src/core/Game.cpp`.
- Dung UI theo state trong `src/ui/UI.hpp` va `src/ui/UI.cpp`.
- Hoan thien score scaffold trong `src/systems/Score.hpp` va `src/systems/Score.cpp`.
- Them `CMakeLists.txt` de build duoc ban scaffold.
- Cap nhat `README.md` va `docs/Program_Overview.md` theo trang thai moi.

## Build Va Run Command

```bash
cmake -S . -B build
cmake --build build --config Release
```

Ghi chu: May hien tai chua co `cmake` trong PATH va chua co SFML headers, nen chua the xac nhan compile local tai thoi diem cap nhat artifact nay.

## Hanh Vi Scaffold Hien Tai

- Chay duoc cua so SFML va loop on dinh.
- State flow: `Start -> Playing -> Paused -> Playing -> GameOver -> Playing`.
- Co UI text cho tung state va HUD diem o muc scaffold.

## Hand-off Sang Tuan 2

- Tich hop `Bird` vao loop Playing (input, gravity, render).
- Giu logic state/loop hien tai lam khung khong pha vo API core.