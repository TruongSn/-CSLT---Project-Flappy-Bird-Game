#include "PipeManager.hpp"
#include <cstdlib> // Cho rand() ngẫu nhiên

PipeManager::PipeManager() 
    : spawnTimer(0.0f), spawnInterval(2.0f), pipeSpeed(150.0f), pipeGap(120.0f) 
{
    // Khởi tạo ban đầu
}

void PipeManager::update(float dt) {
    // 1. Cập nhật đếm ngược spawn
    spawnTimer += dt;
    if (spawnTimer >= spawnInterval) {
        spawnPipe();
        spawnTimer = 0.0f;
    }

    // 2. Cập nhật từng ống
    for (auto& pipe : pipes) {
        pipe.update(dt);
    }

    // 3. Xóa các ống ra khỏi màn hình
    // Sử dụng std::erase_if (C++20) hoặc thủ công (C++11/14/17 remove_if)
    auto it = pipes.begin();
    while (it != pipes.end()) {
        if (it->isOffscreen()) {
            it = pipes.erase(it);
        } else {
            ++it;
        }
    }
}

void PipeManager::render(sf::RenderTarget& target) const {
    for (const auto& pipe : pipes) {
        pipe.render(target);
    }
}

void PipeManager::reset() {
    pipes.clear();
    spawnTimer = 0.0f;
}

std::vector<Pipe>& PipeManager::getPipes() {
    return pipes;
}

void PipeManager::spawnPipe() {
    // Kích thước chuẩn màn hình tạo hằng số tạm (sau lấy từ config)
    float windowWidth = 800.0f; 
    
    // Khoảng cho khe hở ngẫu nhiên (chỉ sinh khe trong vùng an toàn)
    // Ví dụ tâm khe hở dao động từ 150 đến 450
    float minY = 150.0f;
    float maxY = 450.0f;
    float randomY = minY + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (maxY - minY)));

    pipes.emplace_back(windowWidth, randomY, pipeGap, pipeSpeed);
}

const std::vector<Pipe>& PipeManager::getPipes() const {
    return pipes;
}
