/* Ask for an OpenGL Core Context */
#define GL_SILENCE_DEPRECATION
#define GLFW_INCLUDE_GLCOREARB
#include <GLFW/glfw3.h>
#include <cstdio>

GLuint VAO[2], VBO[2];
void createTrangle(int index, float *vertex)
{
    glBindVertexArray(VAO[index]);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[index]);
    glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), vertex, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GL_FLOAT), NULL);
    glEnableVertexAttribArray(0);
}

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
    const char *vertex_shader =
        "#version 400\n"
        "in vec3 vp;"
        "void main() {"
        "  gl_Position = vec4(vp, 1.0);"
        "}";
    const char *fragment_shader =
        "#version 400\n"
        "out vec4 frag_colour;"
        "void main() {"
        "  frag_colour = vec4(0, 0.5372, 0.6549, 1.0);"
        "}";
    GLuint vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs, 1, &vertex_shader, NULL);
    glCompileShader(vs);
    GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs, 1, &fragment_shader, NULL);
    glCompileShader(fs);

    GLuint shader_programme = glCreateProgram();
    glAttachShader(shader_programme, fs);
    glAttachShader(shader_programme, vs);
    glLinkProgram(shader_programme);

    glGenVertexArrays(2, VAO);
    glGenBuffers(2, VBO);
    float points0[] = {
        0.0f, 0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f};
    float points1[] = {
        0.0f, 0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.5f, 1.0f, 0.0f};
    createTrangle(0, points0);
    createTrangle(1, points1);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear the buffers

        for (int i = 0; i < 2; ++i)
        {
            glUseProgram(shader_programme);
            glBindVertexArray(VAO[i]);
            glDrawArrays(GL_TRIANGLES, 0, 3);
            glBindVertexArray(0);
        }
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}