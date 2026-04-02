# Checklist va chạm

## TC01 - Bird hits top pipe
- Start game
- Fly upward into the upper pipe
- Expected: collision is detected and game should transition to game over

## TC02 - Bird hits bottom pipe
- Start game
- Drop or fly into the lower pipe
- Expected: collision is detected and game should transition to game over

## TC03 - Bird hits ground
- Start game
- Do not flap and let bird fall
- Expected: collision with ground is detected

## TC04 - Bird hits ceiling
- Start game
- Spam flap until bird reaches top boundary
- Expected: collision with ceiling is detected

## TC05 - Bird passes safely through pipe gap
- Start game
- Fly through the center gap
- Expected: no collision is detected
Đây là ghi chú kiểm thử tay tạm thời cho việc xác minh trò chơi trong tương lai.

## Khu vực test dự kiến

- Chim chạm ống trên và game chuyển sang trạng thái thua cuộc.
- Chim chạm ống dưới và game chuyển sang trạng thái thua cuộc.
- Chim chạm mặt đất và game chuyển sang trạng thái thua cuộc.
- Chim chạm trần, nếu luật trần được bật.
- Chim đi qua khe an toàn mà không phát sinh va chạm giả.
- Chơi lại xóa sạch trạng thái va chạm của lượt trước.

## Ghi chú cho QA về sau

- Ghi lại đúng thiết lập được dùng cho từng ca kiểm thử tay.
- Ghi rõ kết quả là đúng kỳ vọng hay bất thường.
- Lưu ý các tình huống biên ở góc ống và thời điểm chơi lại.
