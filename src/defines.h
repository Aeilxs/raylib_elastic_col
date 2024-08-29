#pragma once

#include <cstdint>

// ----------------------------------------------------------------------------------------------------
// TYPES
// ----------------------------------------------------------------------------------------------------

// SIGNED
typedef std::int8_t i8;
typedef std::int16_t i16;
typedef std::int32_t i32;
typedef std::int64_t i64;

// UNSIGNED
typedef std::uint8_t u8;
typedef std::uint16_t u16;
typedef std::uint32_t u32;
typedef std::uint64_t u64;

// FLOATS
typedef float f32;
typedef double f64;

// ----------------------------------------------------------------------------------------------------
// DEFINES
// ----------------------------------------------------------------------------------------------------

#define FAILURE -1
#define SUCCESS 0

#define SCREEN_WIDTH (1920)
#define SCREEN_HEIGHT (1080)

#define WINDOW_TITLE "Ball bounce"

#define BALL_COUNT 500

#define GRAVITY 5.f
#define FRICTION 0.001f

// e > 1 => impossible ! (kinetyc energy gain on impact)
// e = 1 => perfect elastic collision ke = ke after collision
// e < 1 => total ke decrease after impact
// e = 0 => after impact ke = 0
#define RESTITUTION 1.f

#define MIN_SPEED 1
#define MAX_SPEED 5

#define MIN_RADIUS 5
#define MAX_RADIUS 8