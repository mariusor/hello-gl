#ifndef MATH_3D_H
#define MATH_3D_H

typedef union _Vector3f {
    struct {
        float x, y, z;
    };
    struct {
        float r, g, b;
    };
    struct {
        float u, v, t;
    };
    float e[3];
} Vector3f;

Vector3f Vector3fNew(float x, float y, float z)
{
    Vector3f result;
    result.x = x;
    result.y = y;
    result.z = z;

    return result;
}

#endif // MATH_3D_H
