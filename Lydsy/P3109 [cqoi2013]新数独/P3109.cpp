#include <cstdio>
#include <cstring>
using namespace std;
const short D[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
short cp[10][10][4]; //0U 1D 2L 3R. 1-Bigger -1-Smaller
char Get()
{
    char ch = getchar();
    while (ch != '<' && ch != '>' && ch != '^' && ch != 'v')
        ch = getchar();
    return ch;
}
void Insert(int x,int y,int d,char v)
{
    int temp = -1;
    if (v == '>' || v == 'v')
        temp = 1;
    cp[x][y][d] = temp;
    cp[x + D[d][0]][y + D[d][1]][d ^ 1] = -temp;
}
void Readin()
{
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<6;j++)
            Insert(i * 3 + 1,j / 2 * 3 + j % 2 + 1,3,Get());
        for (int j=1;j<=9;j++)
            Insert(i * 3 + 1,j,1,Get());
        for (int j=0;j<6;j++)
            Insert(i * 3 + 2,j / 2 * 3 + j % 2 + 1,3,Get());
        for (int j=1;j<=9;j++)
            Insert(i * 3 + 2,j,1,Get());
        for (int j=0;j<6;j++)
            Insert(i * 3 + 3,j / 2 * 3 + j % 2 + 1,3,Get());
    }
}

short mp[10][10];
bool usel[10][10],usec[10][10],useb[3][3][10];
bool flag = false;
void Dfs(int x,int y)
{
    if (y > 9)
        y = 1,x ++;
    if (x == 10)
    {
        flag = true;
        return;
    }
    for (int i=1;i<=9;i++)
        if (!usel[x][i] && !usec[y][i] && !useb[(x - 1) / 3][(y - 1) / 3][i])
        {
            if (cp[x][y][0] == 1 && i < mp[x - 1][y])
                continue;
            if (cp[x][y][0] == -1 && i > mp[x - 1][y])
                continue;
            if (cp[x][y][2] == 1 && i < mp[x][y - 1])
                continue;
            if (cp[x][y][2] == -1 && i > mp[x][y - 1])
                continue;
            mp[x][y] = i; usel[x][i] = true; usec[y][i] = true;
            useb[(x - 1) / 3][(y - 1) / 3][i] = true;
            Dfs(x,y + 1);
            if (flag)
                return;
            usel[x][i] = false; usec[y][i] = false;
            useb[(x - 1) / 3][(y - 1) / 3][i] = false;
        }
}
void Print()
{
    for (int i=1;i<=9;i++)
        for (int j=1;j<=9;j++)
            printf("%d%c",mp[i][j],j != 9 ? ' ' : '\n');
}

int main()
{
    Readin();
    memset(usel,false,sizeof(usel));
    memset(usec,false,sizeof(usec));
    memset(useb,false,sizeof(useb));
    Dfs(1,1);
    Print();
    return 0;
}
