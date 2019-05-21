#pragma once
#include <iostream>

#include "vectors.h"

// 2x2 Matrix
typedef struct Matrix2 {
    union {
        struct {
            float   _11, _12,
                    _21, _22;
        };
        float asArray[4];
    };

    inline Matrix2() {
        _11 = _22 = 1.0f;
        _12 = _21 = 0.0f;
    }

    inline Matrix2(float f11, float f12,
                   float f21, float f22) {
        _11 = f11; _12 = f12;
        _21 = f21; _22 = f22;
    }

    inline float* operator[](int i) {
        return &(asArray[i * 2]);
    }
} Matrix2;

// 3x3 Matrix
typedef struct Matrix3 {
    union {
        struct {
            float   _11, _12, _13,
                    _21, _22, _23,
                    _31, _32, _33;
        };
        float asArray[9];
    };

    inline Matrix3() {
        _11 = _22 = _33 = 1.0f;
        _12 = _13 = 0.0f;
        _21 = _23 = 0.0f;
        _31 = _32 = 0.0f;
    }

    inline Matrix3(float f11, float f12, float f13,
                   float f21, float f22, float f23,
                   float f31, float f32, float f33) {
        _11 = f11; _12 = f12; _13 = f13;
        _21 = f21; _22 = f22; _23 = f23;
        _31 = f31; _32 = f32; _33 = f33;
    }

    inline float* operator[](int i) {
        return &(asArray[i * 3]);
    }
} Matrix3;

// 4x4 Matrix
typedef struct Matrix4 {
    union {
        struct {
            float   _11, _12, _13, _14,
                    _21, _22, _23, _24,
                    _31, _32, _33, _34,
                    _41, _42, _43, _44;
        };
        float asArray[16];
    };

    inline Matrix4() {
        _11 = _22 = _33 = _44 = 1.0f;
        _12 = _13 = _14 = 0.0f;
        _21 = _23 = _24 = 0.0f;
        _31 = _32 = _34 = 0.0f;
        _41 = _42 = _43 = 0.0f;
    }

    inline Matrix4(float f11, float f12, float f13, float f14,
                   float f21, float f22, float f23, float f24,
                   float f31, float f32, float f33, float f34,
                   float f41, float f42, float f43, float f44) {
        _11 = f11; _12 = f12; _13 = f13; _14 = f14;
        _21 = f21; _22 = f22; _23 = f23; _24 = f24;
        _31 = f31; _32 = f32; _33 = f33; _34 = f34;
        _41 = f41; _42 = f42; _43 = f43; _44 = f44;
    }

    inline float* operator[](int i) {
        return &(asArray[i * 4]);
    }
} Matrix4;

// Overload stream operators
std::ostream& operator << (std::ostream& out, const Matrix2& mat2);
std::ostream& operator << (std::ostream&out, const Matrix3& mat3);
std::ostream& operator << (std::ostream&out, const Matrix4& mat4);

// Transpose of a matrix
void Transpose(const float* src_mat, float* dst_mat, int src_rows, int src_cols);
Matrix2 Transpose(const Matrix2& mat);
Matrix3 Transpose(const Matrix3& mat);
Matrix4 Transpose(const Matrix4& mat);

// Multipication of a matrix with a scalar
Matrix2 operator* (const Matrix2& mat, float scalar);
Matrix3 operator* (const Matrix3& mat, float scalar);
Matrix4 operator* (const Matrix4& mat, float scalar);

// Multipication of two compatible matrices
bool Multiply(const float* matrix_a, int rows_a, int cols_a,
              const float* matrix_b, int rows_b, int cols_b,
              float* result);
Matrix2 operator* (const Matrix2& matrix_a, const Matrix2& matrix_b);
Matrix3 operator* (const Matrix3& matrix_a, const Matrix3& matrix_b);
Matrix4 operator* (const Matrix4& matrix_a, const Matrix4& matrix_b);

// Determinant of 2x2 matrix
float Determinant(const Matrix2& mat);

// Cut and Minor functions for 2x2 and 3x3 matrices
Matrix2 Cut(const Matrix3& mat, int row, int col);
Matrix2 Minor(const Matrix2& mat);
Matrix3 Minor(const Matrix3& mat);

// Cofactor of 2x2 and 3x3 matrix
void Cofactor(float* result, const float* minor, int rows, int cols);
Matrix2 Cofactor(const Matrix2& mat);
Matrix3 Cofactor(const Matrix3& mat);

// Determinant of 3x3 matrix
float Determinant(const Matrix3& mat);

// Cut and Minor functions for 4x4 matrix
Matrix3 Cut(const Matrix4& mat, int row, int col);
Matrix4 Minor(const Matrix4& mat);
Matrix4 Cofactor(const Matrix4& mat);
float Determinant(const Matrix4& mat);

// Adjugate matrix (Adjoint matrix)
// The Adjugate matrix of any order matrix is the transpose of its cofactor matrix
Matrix2 Adjugate(const Matrix2& mat);
Matrix3 Adjugate(const Matrix3& mat);
Matrix4 Adjugate(const Matrix4& mat);

// Matrix inverse
// If the inverse of matrix M is non-zero, then the matrix inverse is given by:
// component wise scalar multipication of the inverse determinant and the adjugate of the matrix
Matrix2 Inverse(const Matrix2& mat);
Matrix3 Inverse(const Matrix3& mat);
Matrix4 Inverse(const Matrix4& mat);

// Traslation of a matrix
Matrix4 Translation(float x, float y, float z);
Matrix4 Translation(const Vector3D& pos);
Vector3D GetTranslation(const Matrix4& mat);

// Scale of a matrix
Matrix4 Scale(float x, float y, float z);
Matrix4 Scale(const Vector3D& vec);
Vector3D GetScale(const Matrix4& mat);

// Rotation of a matrix
Matrix4 Rotation(float pitch, float yaw, float roll);
Matrix3 Rotation3x3(float pitch, float yaw, float roll);

// helper functions for rotation of a matrix
Matrix4 XRotation(float angle);
Matrix3 XRotation3x3(float angle);
Matrix4 YRotation(float angle);
Matrix3 YRotation3x3(float angle);
Matrix4 ZRotation(float angle);
Matrix3 ZRotation3x3(float angle);

// Rotation matrix around an arbitrary axis
// We can combine yaw, pitch and roll using matrix multipication to create a complete
// rotation matrix. Creating a rotation matrix by performing each rotation sequentially
// introduces the possibility of a Gimble lock.
// To avoid Gimble lock, use an arbitrary axis and some angle to rotate around that axis
// instead of using three Euler angles to represent a rotation
Matrix4 RotationAxisAngle(const Vector3D& axis, float angle);
Matrix3 RotationAxisAngle3x3(const Vector3D& axis, float angle);

// Vector matrix multipication










