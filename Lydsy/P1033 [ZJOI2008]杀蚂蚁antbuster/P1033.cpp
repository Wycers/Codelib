#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#define Clri(x) memset(x,0x3f,sizeof(x))
#define Clre(x) memset(x,0x00,sizeof(x))
typedef long long ll;
using namespace std;
const int Inf = 0x3f3f3f3f;
const int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int read()
{
    int x = 0,f = 1;char ch = getchar();
    while (ch < '0' || '9' < ch) {if (ch == '-') f = -1; ch = getchar();}
    while ('0' <= ch && ch <= '9') x = x * 10 + ch - 48,ch = getchar();
    return x * f;
}
int n, m, T;
//Struct
struct point
{
    int x, y;
    point operator - (point b)
    {
        return (point){x - b.x, y - b.y};   
    }
    int operator * (point b)
    {
        return x * b.y - y * b.x;   
    }
};
 
int cnt = 0; double h = 4.0;
int mp[10][10]; bool used[10][10], cake = true;
bool equal(point a, point b)
{
    return (a.x == b.x) && (a.y == b.y);
}
struct Ant
{
    point pos, last; int age, hp, Hp, level;
    bool Tar;
    void Init()
    {
        used[pos.x = last.x = 0][pos.y = last.y = 0] = true; Tar = false;
		if (cnt % 6 == 0)
			h = h * 1.1;
		hp = Hp = (int)h; age = 0; level = (int)((cnt++) / 6) + 1;
    }
    bool Judge(int x, int y)
    {
        if (x < 0 || x > n || y < 0 || y > m || used[x][y])
            return false;
        if (equal((point){x, y}, last))
            return false;
        return true;
    } 
    void Flag()
    {
        int x = pos.x, y = pos.y;
        mp[x][y] += Tar ? 5 : 2;
    }
    void Getcake()
    {
        if (!cake || pos.x != n || pos.y != m)
            return;
        cake = false;
        Tar = true;
        hp = min(Hp, hp + (int)Hp / 2);
    }
    void Godie()
	{
		if (hp >= 0)
			return;
		used[pos.x][pos.y] = false;
		age = -Inf;
		if (Tar)
			cake = true, Tar = false;
	} 
    void Move()
    {
        int x = pos.x, y = pos.y, dx, dy, tx, ty, Dir = -1, mx = -Inf;
        for (int k = 0; k < 4; ++k)
        {
            dx = x + d[k][0]; dy = y + d[k][1];
            if (Judge(dx, dy) && mx < mp[dx][dy])
                if (mx < mp[dx][dy])
                    mx = mp[dx][dy];
        }
        for (int k = 0; k < 4; ++k)
        {
            dx = x + d[k][0]; dy = y + d[k][1];
            if (Judge(dx, dy) && mx == mp[dx][dy])
            {
                Dir = k;
                break;  
            }   
        }
        if (Dir == -1)
        {
            last = pos;
            return;
        }
        if ((age + 1) % 5 == 0)
        {
            for(int k = (Dir - 1 + 4) % 4;;k = (k - 1 + 4) % 4)
            {
                dx = x + d[k][0]; dy = y + d[k][1]; 
                if (Judge(dx, dy))
                {
                    Dir = k;
                    break;  
                }
            }
        }
        tx = x + d[Dir][0]; ty = y + d[Dir][1];
        last = pos;
        used[pos.x][pos.y] = false;
        used[pos.x = tx][pos.y = ty] = true;
    }
} ant[10]; int na = 0;
 
int val, r;
struct Tower
{
    point pos;
    #define sqr(x) ((x) * (x))
    int Dis(point a, point b)
    {
        return sqr(a.x - b.x) + sqr(a.y - b.y);
    }
    pair<point, point> line;
    double Dis2(point a, point b, point c)
    {
        return fabs((b - a) * (c - a));
    }
    bool cross(point pos)
    {
        if (equal(pos, line.first) || equal(pos, line.second))
            return true;
        int x1 = min(line.first.x, line.second.x), x2 = max(line.first.x, line.second.x);
        int y1 = min(line.first.y, line.second.y), y2 = max(line.first.y, line.second.y);
        if (pos.x < x1 || pos.x > x2 || pos.y < y1 || pos.y > y2)
            return false;
        double dis = sqrt(Dis(line.first, line.second));
        if (Dis2(line.first, line.second, pos) <= 0.5 * dis)
            return true;
        return false;
    } 
    void Attack()
    {
        int target = -1, dis = Inf, d;
        for(int i = 1; i <= na; ++i)
        {
            d = Dis(pos, ant[i].pos);
            if(d <= r * r)
            { 
                if (ant[i].Tar)
                    target = i;
                else if(!ant[target].Tar && d < dis)
                {
                    dis = d;
                    target = i;
                }
            }
        }
        if (target == -1)
            return;
        line.first = pos; line.second = ant[target].pos;
        for (int i = 1; i <= na; ++i)
            if (cross(ant[i].pos))
                ant[i].hp -= val;
    }
} tow[30]; int ns;

//Code
void Readin()
{
    n = read(); m = read(); ns = read(); val = read(); r = read();
    point temp;
    Clre(used); Clre(mp);
    for (int i = 1; i <= ns; ++i)
    {
        temp.x = read(); temp.y = read();
        used[temp.x][temp.y] = true;
        tow[i] = (Tower){temp};
    }
    T = read();
}
bool cmp(Ant a,Ant b)
{
    return a.age > b.age;
}
void Print()
{
    printf("%d\n", na);
    sort(ant + 1, ant + na + 1, cmp);
    for (int i = 1; i <= na; ++i)
        printf("%d %d %d %d %d\n", ant[i].age, ant[i].level, ant[i].hp, ant[i].pos.x, ant[i].pos.y);
}
void Update()
{
    sort(ant + 1, ant + na + 1, cmp);
    while (ant[na].hp < 0) 
    {
        used[ant[na].pos.x][ant[na].pos.y] = false;
        ant[na].age = -Inf;
        if (ant[na].Tar)
            cake = true;
        --na;   
    }
}
void Work()
{
    for (int t = 1; t <= T; ++t)
    {
        if (!used[0][0] && na < 6) ant[++na].Init();
        for (int i = 1; i <= na; ++i)
            ant[i].Flag();
        for (int i = 1; i <= na; ++i)
            ant[i].Move();
        for (int i = 1; i <= na; ++i)
            ant[i].Getcake();
        for (int i = 1; i <= ns; ++i)
            tow[i].Attack();
        for (int i = 1; i <= na; ++i)
        	ant[i].Godie(); 
        Update();
        for (int i = 1; i <= na; ++i)
            if (ant[i].Tar && ant[i].pos.x == 0 && ant[i].pos.y == 0)
            {
                printf("Game over after %d seconds\n", t);
                return; 
            }
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= m; ++j)
                if (mp[i][j] > 0)
                    --mp[i][j];
        for (int i = 1; i <= na; ++i)
            ++ant[i].age;
    }
    puts("The game is going on");
}
 
int main()
{
    Readin();
    Work();
	Print();
    return 0;
}

