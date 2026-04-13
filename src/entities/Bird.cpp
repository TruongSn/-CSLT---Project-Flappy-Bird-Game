#include "Bird.hpp"

#include <algorithm>

#include "../config/GameplayConfig.hpp"

namespace {
constexpr float kRiseRotationDegrees = -22.0f;
constexpr float kFallRotationDegrees = 68.0f;
const sf::Color kBirdColor(255, 220, 70);
}  // namespace

Bird::Bird()
	: shape(sf::Vector2f(GameplayConfig::BirdWidth, GameplayConfig::BirdHeight)),
	  startPosition(GameplayConfig::BirdSpawnX, GameplayConfig::BirdSpawnY),
	  verticalVelocity(0.0f),
	  rotationDegrees(0.0f) {
	shape.setFillColor(kBirdColor);
	shape.setOrigin(GameplayConfig::BirdWidth * 0.5f, GameplayConfig::BirdHeight * 0.5f);
	reset();
}

void Bird::reset() {
	shape.setPosition(startPosition);
	verticalVelocity = 0.0f;
	rotationDegrees = 0.0f;
	shape.setRotation(rotationDegrees);
}

void Bird::flap() {
	verticalVelocity = GameplayConfig::BirdFlapVelocity;
}

void Bird::update(float dt) {
	if (dt <= 0.0f) {
		return;
	}

	verticalVelocity += GameplayConfig::BirdGravity * dt;
	verticalVelocity = std::clamp(
		verticalVelocity,
		GameplayConfig::BirdMaxRiseSpeed,
		GameplayConfig::BirdMaxFallSpeed);

	shape.move(0.0f, verticalVelocity * dt);

	const float normalizedFallSpeed = std::clamp(
		verticalVelocity / GameplayConfig::BirdMaxFallSpeed,
		-1.0f,
		1.0f);

	rotationDegrees =
		kRiseRotationDegrees +
		((normalizedFallSpeed + 1.0f) * 0.5f) * (kFallRotationDegrees - kRiseRotationDegrees);
	shape.setRotation(rotationDegrees);
}

void Bird::render(sf::RenderTarget& target) const {
	target.draw(shape);
}

sf::FloatRect Bird::getBounds() const {
	return shape.getGlobalBounds();
}

sf::Vector2f Bird::getPosition() const {
	return shape.getPosition();
}

float Bird::getVerticalVelocity() const {
	return verticalVelocity;
}
