#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
int n=100000,l=20;
int main()
{
	cout<<n<<' '<<l<<endl;
	for(int i=1;i<=n;i++) cout<<char(rand()%26+'a');
	cout<<endl;
	return 0;
}
