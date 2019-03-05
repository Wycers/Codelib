/* Ask for an OpenGL Core Context */
#define GL_SILENCE_DEPRECATION
#define GLFW_INCLUDE_GLCOREARB
#include <GLFW/glfw3.h>
// #ifdef __APPLE_CC__
// #include <GLUT/glut.h>
// #else
// #include <GL/glut.h>
// #endif
// #include <cstring>
// using namespace std;

// #define BUFFER_OFFSET(i) ((char *)NULL + (i))

// void init2D(float r, float g, float b)
// {
//     glClearColor(r, g, b, 0.0);
//     glMatrixMode(GL_PROJECTION);
//     gluOrtho2D(0.0, 600.0, 0.0, 600.0);
// }

// void rectangle()
// {
//     glBegin(GL_POLYGON);
//     glColor3f(0.4,0,0.8);
//     glVertex3f(150.0f, 200.0f, 0.0f);
//     glColor3f(0.4,0,0.8);
//     glVertex3f(450.0f, 200.0f, 0.0f);
//     glColor3f(0.6,0,0.6);
//     glVertex3f(450.0f, 400.0f, 0.0f);
//     glColor3f(0.6,0,0.6);
//     glVertex3f(150.0f, 400.0f, 0.0f);
//     glEnd();
// }

// void text()
// {
//     char menu[80];
//     strcpy(menu,"Hello");
//     int len;
//     len = strlen(menu);

//     glColor3f(1,1,1);

//     glMatrixMode( GL_PROJECTION );
//     glPushMatrix();
//     glLoadIdentity();

//     gluOrtho2D( 0, 600, 0, 600 );

//     glMatrixMode( GL_MODELVIEW );
//     glPushMatrix();

//     glLoadIdentity();

//     glRasterPos2i(190, 300);

//     for ( int i = 0; i < len; ++i )
//     {
//         glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, menu[i]);
//     }

//     glPopMatrix();

//     glMatrixMode( GL_PROJECTION );
//     glPopMatrix();
//     glMatrixMode( GL_MODELVIEW );
// }

// void display()
// {

//     glClear(GL_COLOR_BUFFER_BIT);

// //    rectangle();
//     text();

//     glFlush();
// }

// int main(int argc, char** argv)
// {
//     glutInit(&argc, argv);
//     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

//     glutInitWindowPosition(0, 0);
//     glutInitWindowSize(600, 600);
//     glutCreateWindow("我哭了 这不是glfw");
//     init2D(0.0f, 0.0f, 0.0f);
//     glutDisplayFunc(display);

//     glutMainLoop();
// }

int main(int argc, char **argv)
{
    GLFWwindow *window;

    /* Initialize the library */
    if (!glfwInit())
    {
        return -1;
    }

#ifdef __APPLE__
    /* We need to explicitly ask for a 3.2 context on OS X */
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#endif

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1280, 720, "11711918 吴烨昌", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    glClearColor(0.5686f, 0.7058f, 0.5764f, 1.0f);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear the buffers

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}