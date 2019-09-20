#include <cstdlib>
#include <cstdio>
int main()
{
    while (true)
    {
        system("./J_data > test.in");
        puts("data finish");
        system("./J < test.in > ans.out");
        puts("ans finish");
        system("./J_ < test.in > test.out");
        puts("test finish");
        if (system("diff ans.out test.out"))
            break;
    }
    return 0;
} 