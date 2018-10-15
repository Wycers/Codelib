#include <cstdlib>
int main()
{
    while (true)
    {
        system("data > test.in && F < test.in > ans.out && java F_ < test.in > test.out");
        if (system("fc ans.out test.out"))
            break;
    }
    return 0;
}