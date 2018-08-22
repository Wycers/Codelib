# 求圆和多边形的交面积

## 核心代码：

``` c++
void init()
{
    int i;
    double temp, sum;
    for (i = 2; i < n; i++)
    {
        temp = Area2(p[1], p[i], p[i + 1]);
        sum += temp;
    }
    if (sum < 0)
        reverse(p + 1, p + n + 1);
    p[n + 1] = p[1];
}

inline bool inCircle(Vector &s)
{
    return dist(o, s) <= R;
}

bool SameSide(Vector a, Vector b)
{
    if (dist(a, o) > dist(b, o))
        swap(a, b);
    return dot(a, b, o) < eps;
}

double ShadomOnCircle(Vector a, Vector b)
{
    double flag = Area2(o, a, b), res = 0;
    if (fabs(flag) < eps)
        return 0;

    bool ina = inCircle(a), inb = inCircle(b);
    if (ina && inb)
    {
        res = fabs(Area2(o, a, b)) / 2;
    }
    else if (!ina && !inb)
    {
        if (SameSide(a, b))
        {
            double theta = acos(dot(o, a, b) / dist(o, a) / dist(o, b));
            res = R * R * theta / 2;
        }
        else
        {
            double height = fabs(Area2(o, a, b)) / dist(a, b);
            double theta = acos(dot(o, a, b) / dist(o, a) / dist(o, b));
            if (height >= R)
            {
                res = R * R * theta / 2;
            }
            else
            {
                double _theta = 2 * acos(height / R);
                res = R * R * (theta - _theta) / 2 + R * R * sin(_theta) / 2;
            }
        }
    }
    else
    {
        if (!ina && inb)
            swap(a, b);
        double height = fabs(Area2(o, a, b)) / dist(a, b);
        double temp = dot(a, o, b);
        double theta = acos(dot(o, a, b) / dist(o, a) / dist(o, b)), theta1, theta2;
        if (fabs(temp) < eps)
        {
            double _theta = acos(height / R);
            res += R * height / 2 * sin(_theta);
            res += R * R / 2 * (theta - _theta);
        }
        else
        {
            theta1 = asin(height / R);
            theta2 = asin(height / dist(a, o));
            if (temp > 0)
            {
                res += dist(o, a) * R / 2 * sin(pi - theta1 - theta2);
                res += R * R / 2 * (theta + theta1 + theta2 - pi);
            }
            else
            {
                res += dist(o, a) * R / 2 * sin(theta2 - theta1);
                res += R * R / 2 * (theta - theta2 + theta1);
            }
        }
    }
    if (flag < 0)
        return -res;
    else
        return res;
}
```

## 原理
将多边形拆成多个三角形。通过累加三角形和圆的交面积获得多边形和圆的交面积。

三角形与圆的相交有 6 种情况。分情况讨论统计答案。

详见网络XD