
``` c++
#include <cstdio>
#include <cmath>
const double pi = acos(-1.0);

struct Vector
{
    double x, y;
};

Vector operator+(const Vector &a, const Vector &b)
{
    return (Vector){a.x + b.x, a.y + b.y};
}
Vector operator-(const Vector &a, const Vector &b)
{
    return (Vector){a.x - b.x, a.y - b.y};
}
Vector operator*(const Vector &a, const double &k)
{
    return (Vector){a.x * k, a.y * k};
}
Vector operator/(const Vector &a, const double &k)
{
    return (Vector){a.x / k, a.y / k};
}
double operator*(const Vector &a, const Vector &b)
{
    return a.x * b.x + a.y * b.y;
}
double operator^(const Vector &a, const Vector &b)
{
    return a.x * b.y - a.y * b.x;
}

int main()
{

}
```

定义了`pi`以及向量之间的加减 点乘 叉乘 倍增。

在本模板中，使用`a ^ b`表示叉乘。