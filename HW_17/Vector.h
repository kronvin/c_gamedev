#pragma once

#include <iostream>
#include <vector>
#include <cmath>

class Vector2d
{
private:
    float x, y;
    static int instanceCount;

public:
    Vector2d();
    Vector2d(float xVal, float yVal);
    Vector2d(const Vector2d& other);
    ~Vector2d();

    Vector2d& operator=(const Vector2d& other);

    friend Vector2d operator+(const Vector2d& leftVector, const Vector2d& rightVector);
    friend Vector2d operator-(const Vector2d& leftVector, const Vector2d& rightVector);
    void operator*=(float scalar);
    float operator()() const;

    friend std::ostream& operator<<(std::ostream& os, const Vector2d& vec);
    friend std::istream& operator>>(std::istream& is, Vector2d& vec);

    static int getInstanceCount();
};

