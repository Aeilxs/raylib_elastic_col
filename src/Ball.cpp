#include "Ball.h"
#include "raymath.h"

void Ball::handleBorderCollisions() {
    // TODO: refactor
    if (pos.x - r <= 0) {
        pos.x = r;
        velocity.x = -velocity.x * RESTITUTION;
    } else if (pos.x + r >= SCREEN_WIDTH) {
        pos.x = SCREEN_WIDTH - r;
        velocity.x = -velocity.x * RESTITUTION;
    }

    if (pos.y - r <= 0) {
        pos.y = r;
        velocity.y = -velocity.y * RESTITUTION;
    } else if (pos.y + r >= SCREEN_HEIGHT) {
        pos.y = SCREEN_HEIGHT - r;
        velocity.y = -velocity.y * RESTITUTION;
    }
}

void Ball::update() {
    handleBorderCollisions();

    // Apply physic
    // if (r + pos.y <= SCREEN_HEIGHT) velocity.y += GRAVITY * GetFrameTime();
    // velocity.x *= (1.0f - FRICTION);
    // velocity.y *= (1.0f - FRICTION);

    pos = Vector2Add(pos, velocity);

    // If velocity too slow, we stop.
    if (fabs(velocity.x) < 0.1f && fabs(velocity.y) < 0.1f) {
        velocity.x = 0;
        velocity.y = 0;
    }
}

void Ball::draw() { DrawCircle((int)pos.x, (int)pos.y, r, col); }

// ----------------------------------------------------------------------------------------------------
// ACCESSORS
// ----------------------------------------------------------------------------------------------------

Vector2 Ball::getPos() const { return pos; }
void Ball::setPos(Vector2 npos) { pos = npos; }
Vector2 Ball::getVelocity() const { return velocity; }
void Ball::setVelocity(Vector2 nvel) { velocity = nvel; }
f32 Ball::getRadius() const { return r; }
void Ball::setRadius(f32 r) { this->r = r; }
f32 Ball::getMass() const { return r; }
void Ball::setMass(f32 m) { mass = m; }
