#pragma once

#include "defines.h"
#include "raylib.h"
#include <vector>

class Ball {
  private:
    Vector2 pos;
    Vector2 velocity;
    f32 r;
    f32 mass;
    Color col;

    void handleBorderCollisions();

  public:
    Ball(Vector2 p, f32 r, Vector2 v, f32 m, Color c) : pos(p), r(r), velocity(v), mass(m), col(c) {}
    ~Ball() {};

    void update();
    void draw();

    Vector2 getPos() const;
    void setPos(Vector2 npos);
    Vector2 getVelocity() const;
    void setVelocity(Vector2 nvel);
    f32 getRadius() const;
    void setRadius(f32 r);
    f32 getMass() const;
    void setMass(f32 m);
};
