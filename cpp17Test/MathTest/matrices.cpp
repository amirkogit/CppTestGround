#include "matrices.h"
#include "utils.h"
#include <iomanip>

std::ostream& operator << (std::ostream& out, const Matrix2& mat2)
{
    out << "[";
    out << std::setprecision(2) << std::fixed << mat2.asArray[0] << "," << mat2.asArray[1] << ",\n";
    out << std::setprecision(2) << std::fixed << mat2.asArray[2] << "," << mat2.asArray[3] << "]\n";
    return out;
}

std::ostream& operator << (std::ostream& out, const Matrix3& mat3)
{
    out << "[";
    out << std::setprecision(2) << std::fixed << mat3.asArray[0] << "," << mat3.asArray[1] << "," << mat3.asArray[2] << ",\n";
    out << std::setprecision(2) << std::fixed << mat3.asArray[3] << "," << mat3.asArray[4] << "," << mat3.asArray[5] << ",\n";
    out << std::setprecision(2) << std::fixed << mat3.asArray[6] << "," << mat3.asArray[7] << "," << mat3.asArray[8] << "]\n";
    return out;
}

std::ostream& operator << (std::ostream& out, const Matrix4& mat4)
{
    out << "[";
    out << std::setprecision(2) << std::fixed << mat4.asArray[0] << "," << mat4.asArray[1] << "," << mat4.asArray[2] << "," << mat4.asArray[3] << ",\n";
    out << std::setprecision(2) << std::fixed << mat4.asArray[4] << "," << mat4.asArray[5] << "," << mat4.asArray[6] << "," << mat4.asArray[7] << ",\n";
    out << std::setprecision(2) << std::fixed << mat4.asArray[8] << "," << mat4.asArray[9] << "," << mat4.asArray[10] << "," << mat4.asArray[11] << ",\n";
    out << std::setprecision(2) << std::fixed << mat4.asArray[12] << "," << mat4.asArray[13] << "," << mat4.asArray[14] << "," << mat4.asArray[15] << "]\n";
    return out;
}

void Transpose(const float* src_mat, float* dst_mat, int src_rows, int src_cols)
{
    for (int i = 0; i < src_rows * src_cols; i++ ) {
        int row = i / src_rows;
        int col = i % src_rows;
        dst_mat[i] = src_mat[src_cols * col + row];
    }
}

Matrix2 Transpose(const Matrix2& mat)
{
    Matrix2 result;
    Transpose(mat.asArray, result.asArray, 2, 2);
    return result;
}

Matrix3 Transpose(const Matrix3& mat)
{
    Matrix3 result;
    Transpose(mat.asArray, result.asArray, 3, 3);
    return result;
}

Matrix4 Transpose(const Matrix4& mat)
{
    Matrix4 result;
    Transpose(mat.asArray, result.asArray, 4, 4);
    return result;
}

Matrix2 operator* (const Matrix2& mat, float scalar)
{
    Matrix2 result;
    for ( int i = 0; i < 4; ++i ) {
        result.asArray[i] = mat.asArray[i] * scalar;
    }
    return result;
}

Matrix3 operator* (const Matrix3& mat, float scalar)
{
    Matrix3 result;
    for ( int i = 0; i < 9; ++i ) {
        result.asArray[i] = mat.asArray[i] * scalar;
    }
    return result;
}

Matrix4 operator* (const Matrix4& mat, float scalar)
{
    Matrix4 result;
    for ( int i = 0; i < 16; ++i ) {
        result.asArray[i] = mat.asArray[i] * scalar;
    }
    return  result;
}

bool Multiply(const float* matrix_a, int rows_a, int cols_a,
              const float* matrix_b, int rows_b, int cols_b,
              float* result)
{
    if ( cols_a != rows_b ) {
        return false;
    }

    for ( int i = 0; i < rows_a; ++i ) {
        for ( int j = 0; j < cols_b; ++j ) {
            result[cols_b * i + j] = 0.0f;
            for ( int k = 0; k < rows_b; ++k ) {
                int a = cols_a * i + k;
                int b = cols_b * k + j;
                result[cols_b * i + j] += matrix_a[a] * matrix_b[b];
            }
        }
    }
    return true;
}

Matrix2 operator* (const Matrix2& matrix_a, const Matrix2& matrix_b)
{
    Matrix2 result;
    Multiply(matrix_a.asArray, 2, 2, matrix_b.asArray, 2, 2, result.asArray);
    return result;
}

Matrix3 operator* (const Matrix3& matrix_a, const Matrix3& matrix_b)
{
    Matrix3 result;
    Multiply(matrix_a.asArray, 3, 3, matrix_b.asArray, 3, 3, result.asArray);
    return result;
}

Matrix4 operator* (const Matrix4& matrix_a, const Matrix4& matrix_b)
{
    Matrix4 result;
    Multiply(matrix_a.asArray, 4, 4, matrix_b.asArray, 4, 4, result.asArray);
    return result;
}

float Determinant(const Matrix2& mat)
{
    return mat._11 * mat._22 - mat._12 * mat._21;
}

// zero based index
Matrix2 Cut(const Matrix3& mat, int row, int col)
{
    Matrix2 result;
    int index = 0;

    for ( int i = 0; i < 3; ++i ) {
        for ( int j = 0; j < 3; ++j ) {
            if ( i == row || j == col ) {
                continue;
            }
            int target = index++;
            int source = 3 * i + j;
            result.asArray[target] = mat.asArray[source];
        }
    }

    return result;
}

Matrix2 Minor(const Matrix2& mat)
{
    return Matrix2(mat._22, mat._21, mat._12, mat._11);
}

Matrix3 Minor(const Matrix3& mat)
{
    Matrix3 result;

    for ( int i = 0; i < 3; ++i ) {
        for ( int j = 0; j < 3; ++j ) {
            result[i][j] = Determinant(Cut(mat,i,j));
        }
    }

    return result;
}

void Cofactor(float* result, const float* minor, int rows, int cols)
{
    for ( int i = 0; i < rows; ++i ) {
        for ( int j = 0; j < cols; ++j ) {
            int target_idx = cols * j + i;
            int source_idx = cols * j + i;
            float sign = powf(-1.0f, i + j);
            result[target_idx] = minor[source_idx] * sign;
        }
    }
}

Matrix2 Cofactor(const Matrix2& mat)
{
    Matrix2 result;
    Cofactor(result.asArray, Minor(mat).asArray, 2, 2);
    return result;
}

Matrix3 Cofactor(const Matrix3& mat)
{
    Matrix3 result;
    Cofactor(result.asArray, Minor(mat).asArray, 3, 3);
    return result;
}

float Determinant(const Matrix3& mat)
{
    float result = 0.0f;
    Matrix3 cofactor = Cofactor(mat);

    for ( int i = 0; i < 3; ++i ) {
        int index = 3 * 0 + i;
        result += mat.asArray[index] * cofactor[0][i];
    }

    return result;
}

// zero based index
Matrix3 Cut(const Matrix4& mat, int row, int col)
{
    Matrix3 result;
    int index = 0;

    for ( int i = 0; i < row; ++i ) {
        for ( int j = 0; j < col; ++j ) {
            if ( i == row || j == col ) {
                continue;
            }

            int target = index++;
            int source = 4 * i + j;
            result.asArray[target] = mat.asArray[source];
        }
    }

    return  result;
}

Matrix4 Minor(const Matrix4& mat)
{
    Matrix4 result;

    for ( int i = 0; i < 4; ++i ) {
        for ( int j = 0; j < 4; ++j ) {
            result[i][j] = Determinant(Cut(mat, i , j));
        }
    }

    return result;
}

Matrix4 Cofactor(const Matrix4& mat)
{
    Matrix4 result;
    Cofactor(result.asArray, Minor(mat).asArray, 4, 4);
    return result;
}

float Determinant(const Matrix4& mat)
{
    float result = 0.0f;

    Matrix4 cofactor = Cofactor(mat);

    for ( int i = 0; i < 4; ++i ) {
        result += mat.asArray[i] * cofactor[0][i];
    }

    return result;
}

Matrix2 Adjugate(const Matrix2& mat)
{
    return Transpose(Cofactor(mat));
}

Matrix3 Adjugate(const Matrix3& mat)
{
    return Transpose(Cofactor(mat));
}

Matrix4 Adjugate(const Matrix4& mat)
{
    return Transpose(Cofactor(mat));
}

Matrix2 Inverse(const Matrix2& mat)
{
    float det = Determinant(mat);

    if ( CMP(det, 0.0f) ) {
        return Matrix2();
    }

    return Adjugate(mat) * (1.0f / det);
}

Matrix3 Inverse(const Matrix3& mat)
{
    float det = Determinant(mat);

    if ( CMP(det, 0.0f) ) {
        return Matrix3();
    }

    return Adjugate(mat) * (1.0f / det);
}

Matrix4 Inverse(const Matrix4& mat)
{
    float det = Determinant(mat);

    if ( CMP(det, 0.0f) ) {
        return Matrix4();
    }

    return Adjugate(mat) * (1.0f / det);
}

Matrix4 Translation(float x, float y, float z)
{
    return Matrix4 ( 1.0f, 0.0f, 0.0f, 0.0f,
                    0.0f, 1.0f, 0.0f, 0.0f,
                    0.0f, 0.0f, 1.0f, 0.0f,
                    x,    y,    z,    1.0f );
}

Matrix4 Translation(const Vector3D& pos)
{
    return Matrix4 ( 1.0f, 0.0f, 0.0f, 0.0f,
                    0.0f, 1.0f, 0.0f, 0.0f,
                    0.0f, 0.0f, 1.0f, 0.0f,
                    pos.x, pos.y, pos.z,1.0f );
}

Vector3D GetTranslation(const Matrix4& mat)
{
    return Vector3D(mat._41, mat._42, mat._43);
}

Matrix4 Scale(float x, float y, float z)
{
    return Matrix4 ( x, 0.0f, 0.0f, 0.0f,
                     0.0f, y, 0.0f, 0.0f,
                     0.0f, 0.0f, z, 0.0f,
                     0.0f, 0.0f, 0.0f, 1.0f );
}

Matrix4 Scale(const Vector3D& vec)
{
    return Matrix4 ( vec.x, 0.0f, 0.0f, 0.0f,
                     0.0f, vec.y, 0.0f, 0.0f,
                     0.0f, 0.0f, vec.z, 0.0f,
                     0.0f, 0.0f, 0.0f, 1.0f );
}

Vector3D GetScale(const Matrix4& mat)
{
    return Vector3D(mat._11, mat._22, mat._33);
}

Matrix4 Rotation(float pitch, float yaw, float roll)
{
    return ZRotation(roll) * XRotation(pitch) * YRotation(yaw);
}

Matrix3 Rotation3x3(float pitch, float yaw, float roll)
{
    return ZRotation3x3(roll) * XRotation3x3(pitch) * YRotation3x3(yaw);
}

Matrix4 XRotation(float angle)
{
    angle = DEG2RAD(angle);

    float cos_theta = cosf(angle);
    float sin_theta = sinf(angle);

    return Matrix4 ( 1.0f, 0.0f, 0.0f, 0.0f,
                     0.0, cos_theta, sin_theta, 0.0f,
                     0.0f, -sin_theta, cos_theta, 0.0f,
                     0.0f, 0.0f, 0.0f, 1.0f );
}

Matrix3 XRotation3x3(float angle)
{
    angle = DEG2RAD(angle);

    float cos_theta = cosf(angle);
    float sin_theta = sinf(angle);

    return Matrix3 ( 1.0f, 0.0f, 0.0f,
                     0.0f, cos_theta, sin_theta,
                     0.0f, -sin_theta, cos_theta);
}

Matrix4 YRotation(float angle)
{
    angle = DEG2RAD(angle);

    float cos_theta = cosf(angle);
    float sin_theta = sinf(angle);

    return Matrix4 ( cos_theta, 0.0f, -sin_theta, 0.0f,
                     0.0f, 1.0f, 0.0f, 0.0f,
                     sin_theta, 0.0f, cos_theta, 0.0f,
                     0.0f, 0.0f, 0.0f, 1.0f );
}

Matrix3 YRotation3x3(float angle)
{
    angle = DEG2RAD(angle);

    float cos_theta = cosf(angle);
    float sin_theta = sinf(angle);

    return Matrix3 ( cos_theta, 0.0f, -sin_theta,
                     0.0f, 1.0f, 0.0f,
                     sin_theta, 0.0f, cos_theta);
}

Matrix4 ZRotation(float angle)
{
    angle = DEG2RAD(angle);

    float cos_theta = cosf(angle);
    float sin_theta = sinf(angle);

    return Matrix4 ( cos_theta, sin_theta, 0.0f, 0.0f,
                     -sin_theta, cos_theta, 0.0f, 0.0f,
                     0.0f, 0.0f, 1.0f, 0.0f,
                     0.0f, 0.0f, 0.0f, 1.0f );
}

Matrix3 ZRotation3x3(float angle)
{
    angle = DEG2RAD(angle);

    float cos_theta = cosf(angle);
    float sin_theta = sinf(angle);

    return Matrix3 ( cos_theta, sin_theta, 0.0f,
                     -sin_theta, cos_theta, 0.0f,
                     0.0f, 0.0f, 1.0f);
}

Matrix4 RotationAxisAngle(const Vector3D& axis, float angle)
{
    angle = DEG2RAD(angle);
    float c = cosf(angle);
    float s = sinf(angle);
    float t = 1 - c;

    float x = axis.x;
    float y = axis.y;
    float z = axis.z;

    if ( CMP(MagnitudeSquare(axis), 1.0f) ) {
        float inv_length = 1.0f / Magnitude(axis);
        x *= inv_length; // normalize x
        y *= inv_length; // normalize y
        z *= inv_length; // normalize z
    }

    return Matrix4(
                t*(x*x) + c, t*x*y + s*z, t*x*z - s*y, 0.0f,
                t*x*y - s*z, t*(y*y) + c, t*y*z + s*x, 0.0f,
                t*x*z + s*y, t*y*z - s*x, t*(z*z) + c, 0.0f,
                0.0f, 0.0f, 0.0f, 1.0f
                );
}

Matrix3 RotationAxisAngle3x3(const Vector3D& axis, float angle)
{
    angle = DEG2RAD(angle);
    float c = cosf(angle);
    float s = sinf(angle);
    float t = 1 - c;

    float x = axis.x;
    float y = axis.y;
    float z = axis.z;

    if ( CMP(MagnitudeSquare(axis), 1.0f) ) {
        float inv_length = 1.0f / Magnitude(axis);
        x *= inv_length; // normalize x
        y *= inv_length; // normalize y
        z *= inv_length; // normalize z
    }

    return Matrix3(
                t*(x*x) + c, t*x*y + s*z, t*x*z - s*y,
                t*x*y - s*z, t*(y*y) + c, t*y*z + s*x,
                t*x*z + s*y, t*y*z - s*x, t*(z*z) + c
                );
}


