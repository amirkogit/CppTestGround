#include <QCoreApplication>
#include <iostream>

// project includes
#include "vectors.h"
#include "matrices.h"

using namespace std;

#define NEWLINE cout<<"\n"

void TestVectors()
{
    Vector2D vec2 = {1.0f, 2.0f};
    cout << "vec2 = " << vec2 << "\n";
    cout << "vec2[0]: " << vec2.x << "\n";
    cout << "vec2[0]: " << vec2.asArray[0] << "\n";
    cout << "vec2[0]: " << vec2[0] << "\n";
    NEWLINE;

    Vector3D vec3 = {3.0, 5.0, 4.5};
    cout << "vec3 = " << vec3 << "\n";
    cout << "vec3[2]: " << vec3.z << "\n";
    cout << "vec3[2]: " << vec3.asArray[2] << "\n";
    cout << "vec3[2]: " << vec3[2] << "\n";
    NEWLINE;

    // Testing operators for Vector2D
    Vector2D v1(1.0f, 3.0f);
    Vector2D v2(2.2f, 3.3f);
    cout << "v1 = " << v1 << "\n";
    cout << "v2 = " << v2 << "\n";
    cout << "v1 + v2 = " << (v1 + v2) << "\n";
    cout << "v1 - v2 = " << (v1 - v2) << "\n";
    cout << "v1 * v2 = " << (v1 * v2) << "\n";
    cout << "v1 == v2: " << boolalpha << (v1 == v2) << "\n";
    cout << "v1 != v2: " << boolalpha << (v1 != v2) << "\n";
    cout << "Dot(v1,v2): " << Dot(v1,v2) << "\n";
    cout << "Magnitude(v1): " << Magnitude(v1) << "\n";
    cout << "SquareMagnitude(v1): " << MagnitudeSquare(v1) << "\n";
    NEWLINE;

    // Testing operators for Vector3D
    Vector3D v3(1.0f,2.0f,3.0f);
    Vector3D v4(3.0f,4.0f,6.0f);
    cout << "v3 = " << v3 << "\n";
    cout << "v4 = " << v4 << "\n";
    cout << "v3 + v4 = " << (v3 + v4) << "\n";
    cout << "v3 - v4 = " << (v3 - v4) << "\n";
    cout << "v3 * v4 = " << (v3 * v4) << "\n";
    cout << "v3 == v4: " << boolalpha << (v3 == v4) << "\n";
    cout << "v3 != v4: " << boolalpha << (v3 != v4) << "\n";
    cout << "Dot(v3,v4): " << Dot(v3,v4) << "\n";
    cout << "Magnitude(v4): " << Magnitude(v4) << "\n";
    cout << "SquareMagnitude(v4): " << MagnitudeSquare(v4) << "\n";
}

void TestMatrices()
{
    Matrix2 m2 = {  1.0f, 2.0f,
                    3.0f, 4.0f };
    NEWLINE;

    // accessing elements directly using overloaded [] operator
    cout << "m2[0][0]: " << m2[0][0] << "\n";
    cout << "m2[0][1]: " << m2[0][1] << "\n";
    cout << "m2[1][0]: " << m2[1][0] << "\n";
    cout << "m2[1][1]: " << m2[1][1] << "\n";
    NEWLINE;

    Matrix4 m4 = {  1.0f, 2.0f, 3.0f, 4.0f,
                    5.0f, 6.0f, 7.0f, 8.0f,
                    9.0f, 10.0f, 11.0f, 12.0f,
                    13.0f, 14.0f, 15.0f, 16.0f };

    cout << "content of m4 (method 1): " << "\n";
    cout << "[";
    cout << m4[0][0] << "," << m4[0][1] << "," << m4[0][2] << "," << m4[0][3] << "\n";
    cout << m4[1][0] << "," << m4[1][1] << "," << m4[1][2] << "," << m4[1][3] << "\n";
    cout << m4[2][0] << "," << m4[2][1] << "," << m4[2][2] << "," << m4[2][3] << "\n";
    cout << m4[3][0] << "," << m4[3][1] << "," << m4[3][2] << "," << m4[3][3] << "]\n";
    NEWLINE;

    cout << "content of m4 (method 2): " << "\n";
    cout << "[";
    cout << m4.asArray[0] << "," << m4.asArray[1] << "," << m4.asArray[2] << "," << m4.asArray[3] << "\n";
    cout << m4.asArray[4] << "," << m4.asArray[5] << "," << m4.asArray[6] << "," << m4.asArray[7] << "\n";
    cout << m4.asArray[8] << "," << m4.asArray[9] << "," << m4.asArray[10] << "," << m4.asArray[11] << "\n";
    cout << m4.asArray[12] << "," << m4.asArray[13] << "," << m4.asArray[14] << "," << m4.asArray[15] << "]\n";
    NEWLINE;

    cout << "content of m4 (method 3) << operator: " << "\n";
    cout << m4;
    NEWLINE;

    cout << "content of m2 using << operator: " << "\n";
    cout << m2;
    NEWLINE;

    Matrix3 m3 = {  1.0f, 2.0f, 3.0f,
                    4.0f, 5.0f, 6.0f,
                    7.0f, 8.0f, 9.0f };
    cout << "content of m3 using << operator: " << "\n";
    cout << m3;
    NEWLINE;

    cout << "Transpose of m2: " << "\n";
    m2 = Transpose(m2);
    cout << m2;
    NEWLINE;

    cout << "Transpose of m3: " << "\n";
    m3 = Transpose(m3);
    cout << m3;
    NEWLINE;

    cout << "Transpose of m4: " << "\n";
    m4 = Transpose(m4);
    cout << m4;
    NEWLINE;

    // multipication of two matrices - part 1
    {
        Matrix4 m1 = {  1.0f, 2.0f, 3.0f, 4.0f,
                        5.0f, 6.0f, 7.0f, 8.0f,
                        9.0f, 10.0f, 11.0f, 12.0f,
                        13.0f, 14.0f, 15.0f, 16.0f };
        Matrix4 m2 = {  1.0f, 2.0f, 3.0f, 4.0f,
                        5.0f, 6.0f, 7.0f, 8.0f,
                        9.0f, 10.0f, 11.0f, 12.0f,
                        13.0f, 14.0f, 15.0f, 16.0f };
        Matrix4 result = m1 * m2;

        cout << "m1: \n" << m1; NEWLINE;
        cout << "m2: \n" << m2; NEWLINE;
        cout << "Result of m1 * m2: \n";
        cout << result;
        NEWLINE;
    }

    // multipication of two matrices - part 2
    {
        Matrix4 m1 = {  -1.0f, 2.0f, 3.0f, 4.0f,
                        5.0f, 6.0f, 7.0f, 8.0f,
                        -9.0f, 10.0f, 11.0f, 12.0f,
                        13.0f, -14.0f, 15.0f, 16.0f };
        Matrix4 m2 = {  -1.0f, 2.0f, 3.0f, 4.0f,
                        5.0f, -6.0f, 7.0f, 8.0f,
                        9.0f, 10.0f, -11.0f, 12.0f,
                        13.0f, 14.0f, 15.0f, -16.0f };
        Matrix4 result = m1 * m2;

        cout << "m1: \n" << m1; NEWLINE;
        cout << "m2: \n" << m2; NEWLINE;
        cout << "Result of m1 * m2: \n";
        cout << result;
        NEWLINE;
    }

    // multipication of two matrices - part 3
    {
        Matrix3 m1 = {  -1.0f, 2.0f, 3.0f,
                        5.0f, 6.0f, 7.0f,
                        -9.0f, 10.0f, 11.0f };
        Matrix3 m2 = {  -5.0f, 2.0f, 3.0f,
                        5.0f, -16.0f, 8.0f,
                        9.0f, -1.0f, 6.0f };
        Matrix3 result = m1 * m2;

        cout << "m1: \n" << m1; NEWLINE;
        cout << "m2: \n" << m2; NEWLINE;
        cout << "Result of m1 * m2: \n";
        cout << result;
        NEWLINE;
    }

    // identity matrix test
    {
        Matrix2 m1;
        Matrix3 m2;
        Matrix4 m3;

        cout << "2x2 identity matrix: \n";
        cout << m1;
        NEWLINE;

        cout << "3x3 identity matrix: \n";
        cout << m2;
        NEWLINE;

        cout << "4x4 identity matrix: \n";
        cout << m3;
        NEWLINE;
    }

    // multipication test with identity matrix
    {
        Matrix4 m1;
        Matrix4 m2 = {  -1.0f, 2.0f, 3.0f, 4.0f,
                        5.0f, -6.0f, 7.0f, 8.0f,
                        9.0f, 10.0f, -11.0f, 12.0f,
                        13.0f, 14.0f, 15.0f, -16.0f };
        Matrix4 result = m1 * m2;
        cout << "m1: \n" << m1; NEWLINE;
        cout << "m2: \n" << m2; NEWLINE;
        cout << "Result of m1 * m2: \n";
        cout << result;
        NEWLINE;
    }

    // determinant test for 2x2 matrix
    {
        Matrix2 m1(2,3,5,6);
        cout << "m1: \n" << m1; NEWLINE;
        cout << "Determinant: " << Determinant(m1); NEWLINE;
    }

    // cut test
    {
        Matrix3 m1(2.2f, 3.4f, 1.2f,
                   4.2f, 1.1f, 0.2f,
                   2.2f, 3.0f, 4.2f);
        cout << "m1: \n" << m1; NEWLINE;
        cout << "Cut(m1,1,2): \n" << Cut(m1,1,2); NEWLINE;
        cout << "Cut(m1,0,0): \n" << Cut(m1,0,0); NEWLINE;
    }

    // Minor test
    {
        Matrix3 m1(1,8,7,3,9,5,1,0,4);
        cout << "m1: \n" << m1; NEWLINE;
        cout << "Minor of m1: \n" << Minor(m1); NEWLINE;
    }
}

// Main application entry
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    TestVectors();
    TestMatrices();

    return a.exec();
}
