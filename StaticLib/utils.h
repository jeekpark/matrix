#pragma once


#include <limits>

#include "Matrix.h"
#include "Vector.h"

namespace tk3
{
    f32 sqrtf(const f32 value)
    {
        assert(value >= 0);
        const f32 epsilon = 1e-5f;
        f32 guess = value / 2.f;
        while (true)
        {
            f32 newGuess = 0.5f * (guess + value / guess);
            if (abs(newGuess - guess) < epsilon)
            {
                return newGuess;
            }
            guess = newGuess;
        }
    }

    f64 sqrt(const f64 value)
    {
        assert(value >= 0);
        const f64 epsilon = 1e-10f;
        f64 guess = value / 2.f;
        while (true)
        {
            f64 newGuess = 0.5f * (guess + value / guess);
            if (abs(newGuess - guess) < epsilon)
            {
                return newGuess;
            }
            guess = newGuess;
        }
    }

    f32 abs(const f32 num)
    {
        return num < 0 ? -num : num;
    }

    f64 abs(const f64 num)
    {
        return num < 0 ? -num : num;
    }
}
