#include <cstdlib>
using namespace std;
int main()
{
    system("/test && ./zj &&./C && diff pai.out zj.out");
    return 0;
}