#pragma once

#include "Ball.h"
#include "defines.h"
#include "raylib.h"
#include <vector>

class Balls {
  public:
    Balls();
    void createBalls(i32 n);
    void update();
    void draw();

  private:
    std::vector<Ball> balls;

    bool checkCollision(const Ball &b1, const Ball &b2);
    void resolveCollision(Ball &b1, Ball &b2);
};
