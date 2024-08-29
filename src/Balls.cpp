#include "Balls.h"
#include "defines.h"
#include "raymath.h"
#include <cmath>
#include <iostream>

Balls::Balls() { createBalls(BALL_COUNT); }

void Balls::createBalls(i32 n) {
    for (i32 i = 0; i < n; i++) {
        Vector2 center{(f32)GetRandomValue(0, SCREEN_WIDTH), (f32)GetRandomValue(0, SCREEN_HEIGHT)};
        Color col = {static_cast<unsigned char>(GetRandomValue(1, 255)),
                     static_cast<unsigned char>(GetRandomValue(1, 255)),
                     static_cast<unsigned char>(GetRandomValue(1, 255)), 200};

        Vector2 vel{(f32)GetRandomValue(MIN_SPEED, MAX_SPEED), (f32)GetRandomValue(MIN_SPEED, MAX_SPEED)};

        f32 radius = (f32)GetRandomValue(MIN_RADIUS, MAX_RADIUS);
        f32 k = 1.0f / (radius * radius); // k = 1 / r² to get some fake mass depending on the radius
        f32 mass = k * radius * radius;
        mass = fmax(mass, 1.0f);

        Ball b = Ball(center, radius, vel, mass, col);
        balls.push_back(b);
    }
}

void Balls::update() {
    for (i32 i = 0; i < BALL_COUNT; i++) {
        for (i32 j = i + 1; j < BALL_COUNT; j++) {
            if (checkCollision(balls[i], balls[j])) resolveCollision(balls[i], balls[j]);
        }
        balls[i].update();
    }
}

void Balls::draw() {
    for (i32 i = 0; i < BALL_COUNT; i++) {
        balls[i].draw();
    }
}

bool Balls::checkCollision(Ball const &b1, Ball const &b2) {
    Vector2 pos1 = b1.getPos();
    Vector2 pos2 = b2.getPos();
    f32 dx = pos2.x - pos1.x;
    f32 dy = pos2.y - pos1.y;
    f32 dist = std::sqrt(dx * dx + dy * dy);
    return dist < b1.getRadius() + b2.getRadius();
}

void Balls::resolveCollision(Ball &b1, Ball &b2) {
    Vector2 v1 = b1.getVelocity();
    Vector2 v2 = b2.getVelocity();
    f32 m1 = b1.getMass();
    f32 m2 = b2.getMass();

    Vector2 normalizedCollVec = Vector2Normalize(Vector2Subtract(b1.getPos(), b2.getPos()));
    Vector2 relativeSpeed = Vector2Subtract(v1, v2);

    f32 projection = Vector2DotProduct(relativeSpeed, normalizedCollVec);

    if (projection > 0) return;

    f32 j = -(1 + RESTITUTION) * projection;
    j /= (1 / m1 + 1 / m2);

    Vector2 impulse = Vector2Scale(normalizedCollVec, j);
    b1.setVelocity(Vector2Add(v1, Vector2Scale(impulse, 1 / m1)));
    b2.setVelocity(Vector2Subtract(v2, Vector2Scale(impulse, 1 / m2)));
}