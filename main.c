#include <stdio.h>

#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/gl.h>

#include "math_3d.h"

void RenderSceneCB()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    Vector3f Vertices[1];
    Vertices[0] = Vector3fNew(0.0f, 0.0f, 0.0f);

    GLuint VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glDrawArrays(GL_POINTS, 0, 1);
    glDisableVertexAttribArray(0);

    glutSwapBuffers();
}

int main (int argc, char* argv[])
{
    if (argc > 0) {
        char* name = &(argv[0][2]);
        fprintf(stderr, "%s", name);
    }
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

    int width = 512;
    int height = 512;

    glutInitWindowSize(width, height);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Hello Open GL: 01");

    GLenum res = glewInit();
    if (res != GLEW_OK) {
        fprintf(stderr, "Error: %s\n", glewGetErrorString(res));
        return EXIT_FAILURE;
    }


    glutDisplayFunc(RenderSceneCB);

    glutMainLoop();

    return EXIT_SUCCESS;
}
