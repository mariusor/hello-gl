#include <stdio.h>

#include <GL/glut.h>

void RenderSceneCB()
{
    glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
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

    glutDisplayFunc(RenderSceneCB);

    glutMainLoop();

    return 0;
}
