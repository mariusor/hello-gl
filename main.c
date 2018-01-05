#include <stdio.h>

#include <GL/glew.h>
#include <GL/glut.h>

#define array_length(a) (sizeof(a) / sizeof(a[0]))
#include "math_3d.h"

GLuint VBO;

static void RenderSceneCB()
{
#if 1
    float Vertices[3][3] = {
        {-1.0f, -1.0f, 0.0f},
        { 1.0f, -1.0f, 0.0f},
        { 0.0f,  1.0f, 0.0f},
    };
#else
    Vector3f Vertices[3];
    Vertices[0] = Vector3fNew (-1.0f, -1.0f, 0.0f);
    Vertices[1] = Vector3fNew (1.0f, -1.0f, 0.0f);
    Vertices[2] = Vector3fNew (0.0f, 1.0f, 0.0f);
#endif

#if 0
    fprintf(stdout, "sizeof vertices %lu\n", sizeof(Vertices));
    for (size_t i = 0; i < array_length(Vertices); i++) {
        fprintf(stdout, "v3(%+.2g %+.2g %+.2g)\n", Vertices[i][0], Vertices[i][1], Vertices[i][2]);
    }
#endif


    glGenBuffers(1, &VBO);

    glBindBuffer (GL_ARRAY_BUFFER, VBO);
    glBufferData (GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);

    glEnableVertexAttribArray (0);

    glBindBuffer (GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer (0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    // draw the elements
    glDrawArrays (GL_POINTS, 0, 3);

    glDisableVertexAttribArray (0);

    glutSwapBuffers ();
}

int main (int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

    int width = 512;
    int height = 512;

    glutInitWindowSize(width, height);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Hello Open GL: 01");

    GLenum res = glewInit();
    if (res != GLEW_OK) {
        fprintf(stderr, "Error: %s\n", glewGetErrorString(res));
        return EXIT_FAILURE;
    }
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glutDisplayFunc(RenderSceneCB);

    glutMainLoop();

    return EXIT_SUCCESS;
}
