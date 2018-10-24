#include <cstdlib>
int main()
{
    while (true)
    {
        system("./data > test.in && ./D_ < test.in > ans.out && ./D < test.in > test.out");
        if (system("fc ans.out test.out"))
            break;
    }
    return 0;
}