#include <cstdlib>
int main()
{
    while (true)
    {
        system("G.exe < test.in > ans.out && G_ < test.in > test.out");
        if (system("fc ans.out test.out"))
            break;
    }
    return 0;
}