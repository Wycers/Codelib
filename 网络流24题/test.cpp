#include <cstdio>
#include <cstring>
using namespace std;
int a[2];
int main() 
{
    memset(a, 0xff, sizeof(a));
    printf("%d %d %d\n", a[0], a[1], 0xffffffff);
    return 0;
}