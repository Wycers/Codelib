#include <cstdio>
#include <algorithm>
using namespace std;
const int ans[5][5] = {{1,1,1,1,1},
                {0,1,1,1,1},
                {0,0,2,1,1},
                {0,0,0,0,1},
                {0,0,0,0,0}};
const int d[8][2] = {{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1}};
int mp[5][5],lim,sx,sy;
bool flag;
char Read()
{
    char ch = getchar();
    while (ch != '1' && ch != '0' && ch != '*')
        ch = getchar();
    return ch;
}
void Readin()
{
    char ch;
    for (int i=0;i<5;i++)
        for (int j=0;j<5;j++)
        {
            ch = Read();
            if (ch != '*')
                mp[i][j] = ch - 48;
            else
            {
                mp[i][j] = 2;
                sx = i;
                sy = j;
            }
        }
}

int Func(bool k)//t - judge /f - eva
{
    int temp = 0;
    for (int i=0;i<5;i++)
        for (int j=0;j<5;j++)
            if (mp[i][j] != ans[i][j])
                temp ++;
    if (k)
        return temp == 0;
    else
        return temp;
}

void Try(int x,int y,int s)
{
    if (s == lim)
    {
        if (Func(true))
            flag = true;
        return;
    }
    if (flag)
        return;
    for (int i=0;i<8;i++)
    {
        int dx = x + d[i][0];
        int dy = y + d[i][1];
        if (dx < 0 || dx > 4 || dy < 0 || dy > 4)
            continue;
        swap(mp[x][y],mp[dx][dy]);
        if (Func(false) + s <= lim)
            Try(dx,dy,s + 1);
        swap(mp[x][y],mp[dx][dy]);
    }

}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        Readin();
        flag = false;
        for (lim=1;lim<=15;lim++)
        {
            Try(sx,sy,0);
            if (flag)
                break;
        }
        if (flag)
            printf("%d\n",lim);
        else
            puts("-1");
    }
    return 0;
}
