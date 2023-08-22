// app.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace std;
using namespace glm;

void exercise2() {
    cout << "==========" << endl;
    cout << "Exercise 2" << endl;
    const vec3 u(9, 8, 5), v(6, 6, 3);
    vec3 a = u - v;
    vec3 b = u + v * 5.0f;
    cout << "a:" << a.x << " " << a.y << " " << a.z << endl;
    cout << "b:" << b.x << " " << b.y << " " << b.z << endl;
    cout << "==========" << endl;
}

void exercise5() {
    cout << "==========" << endl;
    cout << "Exercise 5" << endl;
    const vec3 u(7, 3, 8);
    cout << "res:" << sqrt(dot(u, u)) << endl;
    cout << "==========" << endl;
}

void exercise11c() {
    cout << "==========" << endl;
    cout << "Exercise 11 c" << endl;
    // TODO
    cout << "==========" << endl;
}

void exercise12a() {
    cout << "==========" << endl;
    cout << "Exercise 12 a" << endl;
    vec2 e1 = vec2(1 / sqrt(2), 1 / sqrt(2));
    vec2 e2 = vec2(-1 / sqrt(2), 1 / sqrt(2));
    vec2 u = vec2(9, 4);
    // a + n = u; a * n = 0; |a| = u * a
    double ans = dot(u, e1) / length(e1);
    cout << "ans: " << ans << endl;
    cout << "==========" << endl;
}

int main()
{
    exercise2();
    exercise5();
    exercise12a();
    std::cout << "11711918 吴烨昌\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
