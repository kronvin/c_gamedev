
#include "Vector.h"

int Vector2d::instanceCount = 0;

Vector2d::Vector2d() : x(0.0f), y(0.0f) { instanceCount++; }

Vector2d::Vector2d(float xVal, float yVal) : x(xVal), y(yVal) { instanceCount++; }

Vector2d::Vector2d(const Vector2d& other) : x(other.x), y(other.y) { instanceCount++; }

Vector2d::~Vector2d() { instanceCount--; }

Vector2d& Vector2d::operator=(const Vector2d& other)
{
    if (this != &other)
    {
        x = other.x;
        y = other.y;
    }
    return *this;
}

Vector2d operator+(const Vector2d& leftVector, const Vector2d& rightVector)
{
    return Vector2d(leftVector.x + rightVector.x, leftVector.y + rightVector.y);
}

Vector2d operator-(const Vector2d& leftVector, const Vector2d& rightVector)
{
    return Vector2d(leftVector.x - rightVector.x, leftVector.y - rightVector.y);
}

void Vector2d::operator*=(float scalar)
{
    x *= scalar;
    y *= scalar;
}

float Vector2d::operator()() const
{
    return std::sqrt(x * x + y * y);
}

std::ostream& operator<<(std::ostream& os, const Vector2d& vec)
{
    os << "{" << vec.x << "; " << vec.y << "}";
    return os;
}

std::istream& operator>>(std::istream& is, Vector2d& vec)
{
    is >> vec.x >> vec.y;
    return is;
}

int Vector2d::getInstanceCount()
{
    return instanceCount;
}