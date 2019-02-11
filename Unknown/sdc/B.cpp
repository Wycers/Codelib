#include <iostream>
#include <cstdlib>
#include <queue>
#define DEBUG false
using namespace std;
const int N = 25;
const int mp[N][N] = {
    { -1, -1, -1, -1, -1, -1, -1, -2,-30,248,247,246,245,152,151,150,149, -2, -1, -1, -1, -1, -1, -1, -1},
    { -1, -2, -2, -2, -2, -2, -1, -2,-31,250,249,244,243,154,153,148,147, -2, -1, -2, -2, -2, -2, -2, -1},
    { -1, -2, -1, -1, -1, -2, -1, -2,-32,252,251,242,241,156,155,146,145, -2, -1, -2, -1, -1, -1, -2, -1},
    { -1, -2, -1, -1, -1, -2, -1, -2,-33,254,253,240,239,158,157,144,143, -2, -1, -2, -1, -1, -1, -2, -1},
    { -1, -2, -1, -1, -1, -2, -1, -2,-34,256,255,238,237,160,159,142,141, -2, -1, -2, -1, -1, -1, -2, -1},
    { -1, -2, -2, -2, -2, -2, -1, -2,-35,258,257,236,235,162,161,140,139, -2, -1, -2, -2, -2, -2, -2, -1},
    { -1, -1, -1, -1, -1, -1, -1, -2, -1, -2, -1, -2, -1, -2, -1, -2, -1, -2, -1, -1, -1, -1, -1, -1, -1},
    { -2, -2, -2, -2, -2, -2, -2, -2,-36,260,259,234,233,164,163,138,137, -2, -2, -2, -2, -2, -2, -2, -2},
    {-44,-43,-42,-41,-40,-39, -1,-38,-37,262,261,232,231,166,165,136,135,-17,-16,-15,-14,-13,-12,-11,-10},
    {344,343,342,341,312,311, -2,310,309,264,263,230,229,168,167,134,133, 87, 86, 85, 84, 33, 32, 31, 30},
    {346,345,340,339,314,313, -1,308,307,266,265,228,227,170,169,132,131, 89, 88, 83, 82, 35, 34, 29, 28},
    {348,347,338,337,316,315, -2,306,305,268,267,226,225,172,171,130,129, 91, 90, 81, 80, 37, 36, 27, 26},
    {350,349,336,335,318,317, -1,304,303,270,269,224,223,174,173,128,127, 93, 92, 79, 78, 39, 38, 25, 24},
    {352,351,334,333,320,319, -2,302,301,272,271,222,221,176,175,126,125, 95, 94, 77, 76, 41, 40, 23, 22},
    {354,353,332,331,322,321, -1,300,299,274,273,220,219,178,177,124,123, 97, 96, 75, 74, 43, 42, 21, 20},
    {356,355,330,329,324,323, -2,298,297,276,275,218,217,180,179,122,121, 99, 98, 73, 72, 45, 44, 19, 18},
    {358,357,328,327,326,325, -1,296,295,278,277,216,215,182,181,120, -1, -1, -1, -1, -1, 47, 46, 17, 16},
    { -2, -2, -2, -2, -2, -2, -2, -2, -1,280,279,214,213,184,183,119, -1, -2, -2, -2, -1, 49, 48, 15, 14},
    { -1, -1, -1, -1, -1, -1, -1, -2,-18,282,281,212,211,186,185,118, -1, -2, -1, -2, -1, 51, 50, 13, 12},
    { -1, -2, -2, -2, -2, -2, -1, -2,-19,284,283,210,209,188,187,117, -1, -2, -2, -2, -1, 53, 52, 11, 10},
    { -1, -2, -1, -1, -1, -2, -1, -2,-20,286,285,208,207,190,189,116, -1, -1, -1, -1, -1, 55, 54,  9,  8},
    { -1, -2, -1, -1, -1, -2, -1, -2,-21,288,287,206,205,192,191,115,114,101,100, 71, 70, 57, 56,  7,  6},
    { -1, -2, -1, -1, -1, -2, -1, -2,-22,290,289,204,203,194,193,113,112,103,102, 69, 68, 59, 58,  5,  4},
    { -1, -2, -2, -2, -2, -2, -1, -2,-23,292,291,202,201,196,195,111,110,105,104, 67, 66, 61, 60,  3,  2},
    { -1, -1, -1, -1, -1, -1, -1, -2,-24,294,293,200,199,198,197,109,108,107,106, 65, 64, 63, 62,  1,  0}
};
int a[N][N];

// -1 must be black
// -2 must be white
// -24..-10: format info
// -44..-30: format info

void debug()
{
    if (DEBUG)
    {
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
                printf("%c", a[i][j] ? '#' : ' ');
            puts("");
        }
    }
}
void readin()
{
    int k;
    cin >> k;
    if (k != 25)
    {
        puts("yu lao ni ge da pian zi");
        exit(-1);
    }
    char tmp[N][N]; getchar();
    for (int i = 0; i < N; ++i)
    {   
        cin.getline(tmp[i], N + 1);
        for (int j = 0; j < N; ++j)
            a[i][j] = (tmp[i][j] == '#');
    }
    debug();
}
void generate()
{
    // check image
    if (DEBUG)
    {
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
                printf("%c", mp[i][j] == -1 ? '#' : ' ');
            puts("");
        }

        // generate path
        for (int i = -24; i < -10; ++i)
        {
            for (int x = 0; x < N; ++x)
                for (int y = 0; y < N; ++y)
                    if (mp[x][y] == i)
                    {
                        printf("q.push(a[%d][%d]);\n", x, y);
                        break;
                    }
        }
        puts("");
        for (int i = 0; i < 359; ++i)
        {
            for (int x = 0; x < N; ++x)
                for (int y = 0; y < N; ++y)
                    if (mp[x][y] == i)
                    {
                        printf("q.push(a[%d][%d]);\n", x, y);
                        break;
                    }
        }
    }
}

void rotateEdge(int tr, int tc, int dr, int dc)  
{
	int times = dc - tc;
	int temp = 0;
	for (int i = 0; i < times; i++)
	{
		temp = a[tr][tc + i]; 
		a[tr][tc + i] = a[dr - i][tc];
		a[dr - i][tc] = a[dr][dc - i];
		a[dr][dc - i] = a[tr + i][dc];
		a[tr + i][dc] = temp;
	}
}
void rotate()
{
    int tr = 0, tc = 0, dr = N - 1, dc = N - 1;
	while (tr < dr) 
		rotateEdge(tr++, tc++, dr--, dc--);
}
bool check()
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            if (mp[i][j] == -1 && a[i][j] != 1)
                return false;
            if (mp[i][j] == -2 && a[i][j] != 0)
                return false;
        }
    return true;
}
void correct()
{
    for (int i = 0; i < 4; ++i)
    {
        if (check())
            return;
        rotate();
    }
    puts("yu lao ni shu ju you cuo ba");
    exit(-1);
}

queue<int> q;
int read(int n)
{
    int res = 0;
    for (int i = 0; i < n; ++i)
    {
        res = res << 1 | q.front();
        q.pop();
    }
    return res;
}

void mask()
{
    while (!q.empty())
        q.pop();
    q.push(a[24][8]);
    q.push(a[23][8]);
    q.push(a[22][8]);
    q.push(a[21][8]);
    q.push(a[20][8]);
    q.push(a[19][8]);
    q.push(a[18][8]);
    q.push(a[8][17]);
    q.push(a[8][18]);
    q.push(a[8][19]);
    q.push(a[8][20]);
    q.push(a[8][21]);
    q.push(a[8][22]);
    q.push(a[8][23]);
    int error = read(2) ^ 2;
    int type = read(3) ^ 5;
    if (type > 7)
    {
        puts("yu lao ni shu ju you cuo ba");
        exit(-1);
    }
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            if (mp[i][j] < 0)
                continue;
            bool flag = false;
            if (type == 0 && (i + j) % 2 == 0) 
                flag = true;
            else if (type == 1 && i % 2 == 0)
                flag = true;
            else if (type == 2 && j % 3 == 0)
                flag = true;
            else if (type == 3 && (i + j) % 3 == 0)
                flag = true;
            else if (type == 4 && ((i / 2) + (j / 3)) % 2 == 0)
                flag = true;
            else if (type == 5 && (i * j % 2 + i * j % 3) == 0)
                flag = true;
            else if (type == 6 && (i * j % 2 + i * j % 3) % 2 == 0)
                flag = true;
            else if (type == 7 && (i * j % 3 + (i + j) % 2) % 2 == 0)
                flag = true;
            if (flag)
                a[i][j] ^= 1;
        }
    debug();
}

void scan()
{
    while (!q.empty())
        q.pop();
    q.push(a[24][24]);
    q.push(a[24][23]);
    q.push(a[23][24]);
    q.push(a[23][23]);
    q.push(a[22][24]);
    q.push(a[22][23]);
    q.push(a[21][24]);
    q.push(a[21][23]);
    q.push(a[20][24]);
    q.push(a[20][23]);
    q.push(a[19][24]);
    q.push(a[19][23]);
    q.push(a[18][24]);
    q.push(a[18][23]);
    q.push(a[17][24]);
    q.push(a[17][23]);
    q.push(a[16][24]);
    q.push(a[16][23]);
    q.push(a[15][24]);
    q.push(a[15][23]);
    q.push(a[14][24]);
    q.push(a[14][23]);
    q.push(a[13][24]);
    q.push(a[13][23]);
    q.push(a[12][24]);
    q.push(a[12][23]);
    q.push(a[11][24]);
    q.push(a[11][23]);
    q.push(a[10][24]);
    q.push(a[10][23]);
    q.push(a[9][24]);
    q.push(a[9][23]);
    q.push(a[9][22]);
    q.push(a[9][21]);
    q.push(a[10][22]);
    q.push(a[10][21]);
    q.push(a[11][22]);
    q.push(a[11][21]);
    q.push(a[12][22]);
    q.push(a[12][21]);
    q.push(a[13][22]);
    q.push(a[13][21]);
    q.push(a[14][22]);
    q.push(a[14][21]);
    q.push(a[15][22]);
    q.push(a[15][21]);
    q.push(a[16][22]);
    q.push(a[16][21]);
    q.push(a[17][22]);
    q.push(a[17][21]);
    q.push(a[18][22]);
    q.push(a[18][21]);
    q.push(a[19][22]);
    q.push(a[19][21]);
    q.push(a[20][22]);
    q.push(a[20][21]);
    q.push(a[21][22]);
    q.push(a[21][21]);
    q.push(a[22][22]);
    q.push(a[22][21]);
    q.push(a[23][22]);
    q.push(a[23][21]);
    q.push(a[24][22]);
    q.push(a[24][21]);
    q.push(a[24][20]);
    q.push(a[24][19]);
    q.push(a[23][20]);
    q.push(a[23][19]);
    q.push(a[22][20]);
    q.push(a[22][19]);
    q.push(a[21][20]);
    q.push(a[21][19]);
    q.push(a[15][20]);
    q.push(a[15][19]);
    q.push(a[14][20]);
    q.push(a[14][19]);
    q.push(a[13][20]);
    q.push(a[13][19]);
    q.push(a[12][20]);
    q.push(a[12][19]);
    q.push(a[11][20]);
    q.push(a[11][19]);
    q.push(a[10][20]);
    q.push(a[10][19]);
    q.push(a[9][20]);
    q.push(a[9][19]);
    q.push(a[9][18]);
    q.push(a[9][17]);
    q.push(a[10][18]);
    q.push(a[10][17]);
    q.push(a[11][18]);
    q.push(a[11][17]);
    q.push(a[12][18]);
    q.push(a[12][17]);
    q.push(a[13][18]);
    q.push(a[13][17]);
    q.push(a[14][18]);
    q.push(a[14][17]);
    q.push(a[15][18]);
    q.push(a[15][17]);
    q.push(a[21][18]);
    q.push(a[21][17]);
    q.push(a[22][18]);
    q.push(a[22][17]);
    q.push(a[23][18]);
    q.push(a[23][17]);
    q.push(a[24][18]);
    q.push(a[24][17]);
    q.push(a[24][16]);
    q.push(a[24][15]);
    q.push(a[23][16]);
    q.push(a[23][15]);
    q.push(a[22][16]);
    q.push(a[22][15]);
    q.push(a[21][16]);
    q.push(a[21][15]);
    q.push(a[20][15]);
    q.push(a[19][15]);
    q.push(a[18][15]);
    q.push(a[17][15]);
    q.push(a[16][15]);
    q.push(a[15][16]);
    q.push(a[15][15]);
    q.push(a[14][16]);
    q.push(a[14][15]);
    q.push(a[13][16]);
    q.push(a[13][15]);
    q.push(a[12][16]);
    q.push(a[12][15]);
    q.push(a[11][16]);
    q.push(a[11][15]);
    q.push(a[10][16]);
    q.push(a[10][15]);
    q.push(a[9][16]);
    q.push(a[9][15]);
    q.push(a[8][16]);
    q.push(a[8][15]);
    q.push(a[7][16]);
    q.push(a[7][15]);
    q.push(a[5][16]);
    q.push(a[5][15]);
    q.push(a[4][16]);
    q.push(a[4][15]);
    q.push(a[3][16]);
    q.push(a[3][15]);
    q.push(a[2][16]);
    q.push(a[2][15]);
    q.push(a[1][16]);
    q.push(a[1][15]);
    q.push(a[0][16]);
    q.push(a[0][15]);
    q.push(a[0][14]);
    q.push(a[0][13]);
    q.push(a[1][14]);
    q.push(a[1][13]);
    q.push(a[2][14]);
    q.push(a[2][13]);
    q.push(a[3][14]);
    q.push(a[3][13]);
    q.push(a[4][14]);
    q.push(a[4][13]);
    q.push(a[5][14]);
    q.push(a[5][13]);
    q.push(a[7][14]);
    q.push(a[7][13]);
    q.push(a[8][14]);
    q.push(a[8][13]);
    q.push(a[9][14]);
    q.push(a[9][13]);
    q.push(a[10][14]);
    q.push(a[10][13]);
    q.push(a[11][14]);
    q.push(a[11][13]);
    q.push(a[12][14]);
    q.push(a[12][13]);
    q.push(a[13][14]);
    q.push(a[13][13]);
    q.push(a[14][14]);
    q.push(a[14][13]);
    q.push(a[15][14]);
    q.push(a[15][13]);
    q.push(a[16][14]);
    q.push(a[16][13]);
    q.push(a[17][14]);
    q.push(a[17][13]);
    q.push(a[18][14]);
    q.push(a[18][13]);
    q.push(a[19][14]);
    q.push(a[19][13]);
    q.push(a[20][14]);
    q.push(a[20][13]);
    q.push(a[21][14]);
    q.push(a[21][13]);
    q.push(a[22][14]);
    q.push(a[22][13]);
    q.push(a[23][14]);
    q.push(a[23][13]);
    q.push(a[24][14]);
    q.push(a[24][13]);
    q.push(a[24][12]);
    q.push(a[24][11]);
    q.push(a[23][12]);
    q.push(a[23][11]);
    q.push(a[22][12]);
    q.push(a[22][11]);
    q.push(a[21][12]);
    q.push(a[21][11]);
    q.push(a[20][12]);
    q.push(a[20][11]);
    q.push(a[19][12]);
    q.push(a[19][11]);
    q.push(a[18][12]);
    q.push(a[18][11]);
    q.push(a[17][12]);
    q.push(a[17][11]);
    q.push(a[16][12]);
    q.push(a[16][11]);
    q.push(a[15][12]);
    q.push(a[15][11]);
    q.push(a[14][12]);
    q.push(a[14][11]);
    q.push(a[13][12]);
    q.push(a[13][11]);
    q.push(a[12][12]);
    q.push(a[12][11]);
    q.push(a[11][12]);
    q.push(a[11][11]);
    q.push(a[10][12]);
    q.push(a[10][11]);
    q.push(a[9][12]);
    q.push(a[9][11]);
    q.push(a[8][12]);
    q.push(a[8][11]);
    q.push(a[7][12]);
    q.push(a[7][11]);
    q.push(a[5][12]);
    q.push(a[5][11]);
    q.push(a[4][12]);
    q.push(a[4][11]);
    q.push(a[3][12]);
    q.push(a[3][11]);
    q.push(a[2][12]);
    q.push(a[2][11]);
    q.push(a[1][12]);
    q.push(a[1][11]);
    q.push(a[0][12]);
    q.push(a[0][11]);
    q.push(a[0][10]);
    q.push(a[0][9]);
    q.push(a[1][10]);
    q.push(a[1][9]);
    q.push(a[2][10]);
    q.push(a[2][9]);
    q.push(a[3][10]);
    q.push(a[3][9]);
    q.push(a[4][10]);
    q.push(a[4][9]);
    q.push(a[5][10]);
    q.push(a[5][9]);
    q.push(a[7][10]);
    q.push(a[7][9]);
    q.push(a[8][10]);
    q.push(a[8][9]);
    q.push(a[9][10]);
    q.push(a[9][9]);
    q.push(a[10][10]);
    q.push(a[10][9]);
    q.push(a[11][10]);
    q.push(a[11][9]);
    q.push(a[12][10]);
    q.push(a[12][9]);
    q.push(a[13][10]);
    q.push(a[13][9]);
    q.push(a[14][10]);
    q.push(a[14][9]);
    q.push(a[15][10]);
    q.push(a[15][9]);
    q.push(a[16][10]);
    q.push(a[16][9]);
    q.push(a[17][10]);
    q.push(a[17][9]);
    q.push(a[18][10]);
    q.push(a[18][9]);
    q.push(a[19][10]);
    q.push(a[19][9]);
    q.push(a[20][10]);
    q.push(a[20][9]);
    q.push(a[21][10]);
    q.push(a[21][9]);
    q.push(a[22][10]);
    q.push(a[22][9]);
    q.push(a[23][10]);
    q.push(a[23][9]);
    q.push(a[24][10]);
    q.push(a[24][9]);
    q.push(a[16][8]);
    q.push(a[16][7]);
    q.push(a[15][8]);
    q.push(a[15][7]);
    q.push(a[14][8]);
    q.push(a[14][7]);
    q.push(a[13][8]);
    q.push(a[13][7]);
    q.push(a[12][8]);
    q.push(a[12][7]);
    q.push(a[11][8]);
    q.push(a[11][7]);
    q.push(a[10][8]);
    q.push(a[10][7]);
    q.push(a[9][8]);
    q.push(a[9][7]);
    q.push(a[9][5]);
    q.push(a[9][4]);
    q.push(a[10][5]);
    q.push(a[10][4]);
    q.push(a[11][5]);
    q.push(a[11][4]);
    q.push(a[12][5]);
    q.push(a[12][4]);
    q.push(a[13][5]);
    q.push(a[13][4]);
    q.push(a[14][5]);
    q.push(a[14][4]);
    q.push(a[15][5]);
    q.push(a[15][4]);
    q.push(a[16][5]);
    q.push(a[16][4]);
    q.push(a[16][3]);
    q.push(a[16][2]);
    q.push(a[15][3]);
    q.push(a[15][2]);
    q.push(a[14][3]);
    q.push(a[14][2]);
    q.push(a[13][3]);
    q.push(a[13][2]);
    q.push(a[12][3]);
    q.push(a[12][2]);
    q.push(a[11][3]);
    q.push(a[11][2]);
    q.push(a[10][3]);
    q.push(a[10][2]);
    q.push(a[9][3]);
    q.push(a[9][2]);
    q.push(a[9][1]);
    q.push(a[9][0]);
    q.push(a[10][1]);
    q.push(a[10][0]);
    q.push(a[11][1]);
    q.push(a[11][0]);
    q.push(a[12][1]);
    q.push(a[12][0]);
    q.push(a[13][1]);
    q.push(a[13][0]);
    q.push(a[14][1]);
    q.push(a[14][0]);
    q.push(a[15][1]);
    q.push(a[15][0]);
    q.push(a[16][1]);
    q.push(a[16][0]);
    int type = read(4);
    if (type != 4)
    {
        puts("yu lao ni ge da pian zi");
        exit(-1);
    }
    int len = read(8);
    for (int i = 0; i < len; ++i)
        printf("%c", read(8));
}
int main()
{
    // freopen("test.in", "r", stdin);
    // generate();
    int T; cin >> T;
    while (T--)
    {
        readin();
        correct();
        mask();
        scan();
        if (T)
        {
            puts("");
            puts("");
        }
    }
    return 0;
}