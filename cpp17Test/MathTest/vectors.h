#pragma once
#include <iostream>

// 2D vector
typedef struct Vector2D {
    union {
        struct {
            float x;
            float y;
        };
        float asArray[2];
    };

    Vector2D() : x(0.0f), y(0.0f) {}
    Vector2D(float xp, float yp) : x(xp), y(yp) {}

    float& operator[](int i) {
        return asArray[i];
    }
} Vector2D;

// 3D vector
typedef struct Vector3D {
    union {
        struct {
            float x;
            float y;
            float z;
        };
        float asArray[3];
    };

    Vector3D() : x(0.0f), y(0.0f), z(0.0f) {}
    Vector3D(float xp, float yp, float zp) : x(xp), y(yp), z(zp) {}

    float& operator[](int i) {
        return asArray[i];
    }
} Vector3D;

// overloade stream operators
std::ostream& operator << (std::ostream& out, const Vector2D& vec);
std::ostream& operator << (std::ostream& out, const Vector3D& vec);

// common operators for the vector class
Vector2D operator+(const Vector2D& lhs, const Vector2D& rhs);
Vector3D operator+(const Vector3D& lhs, const Vector3D& rhs);
Vector2D operator-(const Vector2D& lhs, const Vector2D& rhs);
Vector3D operator-(const Vector3D& lhs, const Vector3D& rhs);
Vector2D operator*(const Vector2D& lhs, const Vector2D& rhs);
Vector3D operator*(const Vector3D& lhs, const Vector3D& rhs);
Vector2D operator*(const Vector2D& lhs, float rhs);
Vector3D operator*(const Vector3D& lhs, float rhs);
bool operator==(const Vector2D& lhs, const Vector2D& rhs);
bool operator==(const Vector3D& lhs, const Vector3D& rhs);
bool operator!=(const Vector2D& lhs, const Vector2D& rhs);
bool operator!=(const Vector3D& lhs, const Vector3D& rhs);

// Dot product
float Dot(const Vector2D& lhs, const Vector2D& rhs);
float Dot(const Vector3D& lhs, const Vector3D& rhs);

// Magnitude
float Magnitude(const Vector2D& vec);
float Magnitude(const Vector3D& vec);

// Square Magnitude
float MagnitudeSquare(const Vector2D& vec);
float MagnitudeSquare(const Vector3D& vec);

// Distance
float Distance(const Vector2D& p1, const Vector2D& p2);
float Distance(const Vector3D& p1, const Vector3D& p3);

// Normalize - changes input vector to have a length 1
void Normalize(Vector2D& vec);
void Normalize(Vector3D& vec);

// Normalized - return a new vector with a length 1
Vector2D Normalized(const Vector2D& vec);
Vector3D Normalized(const Vector3D& vec);

// Cross Product
Vector3D Cross(const Vector3D& lhs, const Vector3D& rhs);

// Angle in radians
float Angle(const Vector2D& lhs, const Vector2D& rhs);
float Angle(const Vector3D& lhs, const Vector3D& rhs);

// Angle in degrees
float AngleInDegree(const Vector2D& lhs, const Vector2D& rhs);
float AngleInDegree(const Vector3D& lhs, const Vector3D& rhs);

// Projection
Vector2D Project(const Vector2D& length, const Vector2D& direction);
Vector3D Project(const Vector3D& length, const Vector3D& direction);

// Perpendicular
Vector2D Perpendicular(const Vector2D& length, const Vector2D& direction);
Vector3D Perpendicular(const Vector3D& length, const Vector3D& direction);


