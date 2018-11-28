#include <cstdlib>
#include <cstdio>
int main()
{
    while (true)
    {
        system("./G_data > test.in");
        puts("data finish");
        system("./G < test.in > ans.out");
        puts("ans finish");
        system("./G_ < test.in > test.out");
        puts("test finish");
        if (system("diff ans.out test.out"))
            break;
    }
    return 0;
} 