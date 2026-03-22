#include "Pipe.hpp"

Pipe::Pipe(float x, float gapY, float gapSize, float speed)
    : position(x, gapY), gapSize(gapSize), speed(speed), passedFlag(false),
      pipeWidth(52.f), pipeHeight(320.f) // Các kích thước hardcode tạm, sẽ đổi khi tích hợp assets
{
    // Khởi tạo các Sprite hoặc shape biểu diễn sau
}

void Pipe::update(float dt) {
    // Di chuyển ống sang trái
    position.x -= speed * dt;
}

void Pipe::render(sf::RenderTarget& target) const {
    // TODO: Vẽ ống trên (bottom edge tại position.y - gapSize/2)
    // TODO: Vẽ ống dưới (top edge tại position.y + gapSize/2)
}

bool Pipe::isOffscreen() const {
    // Nếu toàn bộ ống đã đi qua mép trái màn hình (x < -pipeWidth)
    return (position.x + pipeWidth < 0);
}

bool Pipe::checkPassed(float birdX) {
    // Nếu bird vượt qua tâm ngang của ống và chưa đánh dấu
    if (!passedFlag && birdX > position.x + (pipeWidth / 2.0f)) {
        passedFlag = true;
        return true; // Trả về true để ScoreSystem cộng điểm
    }
    return false;
}

sf::FloatRect Pipe::getBoundsTop() const {
    // Bounding box cho ống phía trên
    // X = position.x
    // Bottom Y = position.y - gapSize / 2
    // Top Y = (position.y - gapSize / 2) - pipeHeight
    return sf::FloatRect(
        position.x, 
        position.y - (gapSize / 2.0f) - pipeHeight, 
        pipeWidth, 
        pipeHeight
    );
}

sf::FloatRect Pipe::getBoundsBottom() const {
    // Bounding box cho ống phía dưới
    // X = position.x
    // Top Y = position.y + gapSize / 2
    return sf::FloatRect(
        position.x, 
        position.y + (gapSize / 2.0f), 
        pipeWidth, 
        pipeHeight
    );
}

bool Pipe::isPassed() const {
    return passedFlag;
}
