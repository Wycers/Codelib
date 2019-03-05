# Lab2 Report

## Author

吴烨昌 11711918

## Complie & Run
``` makefile
main : main.cpp
	clang++ -std=c++11 -stdlib=libc++ -lglfw -framework CoreVideo -framework OpenGL -framework IOKit -framework GLUT -framework Cocoa -framework Carbon main.cpp -o main
clean :
	rm main
```
``` bash
make && ./main
```

## Detail

### Create Shader

Shader is written with GLSL. In this lab, I hard code them.

``` c++
const char *vertex_shader =
    "#version 400\n"
    "layout (location = 0) in vec3 aPos;"     // set 0 as location of position var
    "layout (location = 1) in vec3 aColor;"   // set 1 as location of color var
    "out vec3 myColor;"                       // output a color
    "void main(){"
    "gl_Position = vec4(aPos, 1.0f);"
    "myColor = aColor;"
    "}";
```

Compile shader

``` c++
GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
glShaderSource(vertexShader, 1, &vertex_shader, NULL);
glCompileShader(vertexShader);
```

After creating a shader, we can use following code to check the shader is successfully compiled.
``` c++
GLint success;
GLchar infoLog[512];
glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
if(!success)
{
    glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
}
```

### Create trangle
``` c++

float vertices[] = {
    //postion           //color 		  // index
     0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, // 1
    -0.5f, -0.5f, 0.0f, 1.0f, 0.53f, 0.65f, // 0
     0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f, // 4
    -0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f, // 5
     0.0f, 0.75f, 0.0f, 0.0f, 0.0f, 1.0f, // 6
    0.75f,  0.0f, 0.0f, 0.0f, 0.0f, 1.0f, // 2
     0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, // 1
    0.75f, 0.75f, 0.0f, 0.5f, 0.0f, 0.0f, // 3
     0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f, // 4
     0.0f, 0.75f, 0.0f, 0.0f, 0.0f, 1.0f  // 6
};
```
``` c++
GLuint VAO, VBO;
glGenVertexArrays(1, &VAO);
glGenBuffers(1, &VBO);

glBindVertexArray(VAO);
glBindBuffer(GL_ARRAY_BUFFER, VBO);
glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
// 0 is location of position
glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
// 1 is location of color
glEnableVertexAttribArray(0);
glEnableVertexAttribArray(1);
return VAO;
```

### Render

``` c++
glUseProgram(programme); // activate programme
glBindVertexArray(VAO);  // bind VAO
glDrawArrays(GL_TRIANGLES, 0, 3); // Render trangle with vertice 1 0 4,
glDrawArrays(GL_TRIANGLES, 1, 3); // Render trangle with vertice 0 4 5,
glDrawArrays(GL_TRIANGLES, 2, 3); // Render trangle with vertice 4 5 6,
glDrawArrays(GL_TRIANGLES, 5, 3); // Render trangle with vertice 2 1 3,
glDrawArrays(GL_TRIANGLES, 6, 3); // Render trangle with vertice 1 3 4,
glDrawArrays(GL_TRIANGLES, 7, 3); // Render trangle with vertice 3 4 6
glBindVertexArray(0);
```


## ScreenShot

![t1](/Users/wycer/Documents/Codelib/CS312 Computer Graphic/Lab2/t1.png)

![t2](/Users/wycer/Documents/Codelib/CS312 Computer Graphic/Lab2/t2.png)

![t3](/Users/wycer/Documents/Codelib/CS312 Computer Graphic/Lab2/t3.png)

![t4](/Users/wycer/Documents/Codelib/CS312 Computer Graphic/Lab2/t4.png)

## Reference
https://learnopengl-cn.readthedocs.io/zh/latest/01%20Getting%20started/05%20Shaders