#include <cstdlib>
int main()
{
    while (true)
    {
        // system("E.exe < test.in > ans.out && E_ < test.in > test.out");
        system("data.exe > test.in && D_.exe < test.in > ans.out && D.exe < test.in > test.out");
        if (system("fc ans.out test.out"))
            break;
    }
    return 0;
}