# Lab2 Report

## Author

吴烨昌 11711918

## Code
``` cpp
glm::mat4 transform = glm::mat4(1.0f); 
transform = glm::translate(transform, glm::vec3(0.75 * sin((float)glfwGetTime()), 0.75 * cos((float)glfwGetTime()), 0.0f));
transform = glm::rotate(transform, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 0.8f));
```
use this transform matrix to make the square rotate and move.

## ScreenShot

![t1](1.png)

![t2](2.png

![t3](3.png)

## Reference
https://learnopengl-cn.github.io/01%20Getting%20started/07%20Transformations/