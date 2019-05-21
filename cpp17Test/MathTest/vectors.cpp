#include "vectors.h"
#include "utils.h"

std::ostream& operator << (std::ostream& out, const Vector2D& vec)
{
    out << "[" << vec.x << "," << vec.y << "]";
    return out;
}

std::ostream& operator << (std::ostream& out, const Vector3D& vec)
{
    out << "[" << vec.x << "," << vec.y << "," << vec.z << "]";
    return out;
}

Vector2D operator+(const Vector2D& lhs, const Vector2D& rhs)
{
    return { lhs.x + rhs.x, lhs.y + rhs.y};
}

Vector3D operator+(const Vector3D& lhs, const Vector3D& rhs)
{
    return { lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z};
}

Vector2D operator-(const Vector2D& lhs, const Vector2D& rhs)
{
    return { lhs.x - rhs.x, lhs.y - rhs.y};
}

Vector3D operator-(const Vector3D& lhs, const Vector3D& rhs)
{
    return { lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z};
}

Vector2D operator*(const Vector2D& lhs, const Vector2D& rhs)
{
    return { lhs.x * rhs.x, lhs.y * rhs.y};
}

Vector3D operator*(const Vector3D& lhs, const Vector3D& rhs)
{
    return { lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z};
}

Vector2D operator*(const Vector2D& lhs, float rhs)
{
    return { lhs.x * rhs, lhs.y * rhs};
}

Vector3D operator*(const Vector3D& lhs, float rhs)
{
    return { lhs.x * rhs, lhs.y * rhs, lhs.z * rhs};
}

bool operator==(const Vector2D& lhs, const Vector2D& rhs)
{
    return (CMP(lhs.x, rhs.x) && CMP(lhs.y, rhs.y));
}

bool operator==(const Vector3D& lhs, const Vector3D& rhs)
{
    return (CMP(lhs.x, rhs.x) && CMP(lhs.y, rhs.y) && CMP(lhs.z, rhs.z));
}

bool operator!=(const Vector2D& lhs, const Vector2D& rhs)
{
    return !(lhs == rhs);
}

bool operator!=(const Vector3D& lhs, const Vector3D& rhs)
{
    return !(lhs == rhs);
}

float Dot(const Vector2D& lhs, const Vector2D& rhs)
{
    return lhs.x * rhs.x + lhs.y * rhs.y;
}

float Dot(const Vector3D& lhs, const Vector3D& rhs)
{
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

float Magnitude(const Vector2D& vec)
{
    return sqrtf(Dot(vec, vec));
}

float Magnitude(const Vector3D& vec)
{
    return sqrtf(Dot(vec, vec));
}

float MagnitudeSquare(const Vector2D& vec)
{
    return Dot(vec, vec);
}

float MagnitudeSquare(const Vector3D& vec)
{
    return Dot(vec, vec);
}

float Distance(const Vector2D& p1, const Vector2D& p2)
{
    Vector2D result = p1 - p2;
    return Magnitude(result);
}

float Distance(const Vector3D& p1, const Vector3D& p2)
{
    Vector3D result = p1 - p2;
    return Magnitude(result);
}

void Normalize(Vector2D& vec)
{
    vec = vec * (1.0f / Magnitude(vec));
}

void Normalize(Vector3D& vec)
{
    vec = vec * (1.0f / Magnitude(vec));
}

Vector2D Normalized(const Vector2D& vec)
{
    return vec * (1.0f / Magnitude(vec));
}

Vector3D Normalized(const Vector3D& vec)
{
    return vec * (1.0f / Magnitude(vec));
}

Vector3D Cross(const Vector3D& lhs, const Vector3D& rhs)
{
    Vector3D result;
    result.x = lhs.y * rhs.z - lhs.z * rhs.y;
    result.y = lhs.z * rhs.x - lhs.x * rhs.z;
    result.z = lhs.x * rhs.y - lhs.y * rhs.x;

    return result;
}

// returns angle in radians because acos() returns radians, not degrees
float Angle(const Vector2D& lhs, const Vector2D& rhs)
{
    //float magnitude = Magnitude(lhs) * Magnitude(rhs); // involves double sqrtf() calls
    float magnitude = sqrtf(MagnitudeSquare(lhs) * MagnitudeSquare(rhs)); // involves only one sqrtf() call
    return acos(Dot(lhs, rhs) / magnitude);
}

float Angle(const Vector3D& lhs, const Vector3D& rhs)
{
    //float magnitude = Magnitude(lhs) * Magnitude(rhs); // involves double sqrtf() calls
    float magnitude = sqrtf(MagnitudeSquare(lhs) * MagnitudeSquare(rhs)); // involves only one sqrtf() call
    return acos(Dot(lhs, rhs) / magnitude);
}

float AngleInDegree(const Vector2D& lhs, const Vector2D& rhs)
{
    return RAD2DEG(Angle(lhs,rhs));
}

float AngleInDegree(const Vector3D& lhs, const Vector3D& rhs)
{
    return RAD2DEG(Angle(lhs, rhs));
}

Vector2D Project(const Vector2D& length, const Vector2D& direction)
{
    float dot = Dot(length, direction);
    float magnitude_square = MagnitudeSquare(direction);
    return direction * (dot / magnitude_square);
}

Vector3D Project(const Vector3D& length, const Vector3D& direction)
{
    float dot = Dot(length, direction);
    float magnitude_square = MagnitudeSquare(direction);
    return  direction * (dot / magnitude_square);
}

Vector2D Perpendicular(const Vector2D& length, const Vector2D& direction)
{
    return length - Project(length, direction);
}

Vector3D Perpendicular(const Vector3D& length, const Vector3D& direction)
{
    return length - Project(length, direction);
}
