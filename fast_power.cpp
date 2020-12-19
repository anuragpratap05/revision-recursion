#include<bits/stdc++.h>
using namespace std;

int fastpower(int a, int n)
{
	if (n == 0)
	{
		return 1;
	}

	int sa = fastpower(a, n / 2);
	sa *= sa;
	if (n & 1)
	{
		return a * sa;
	}
	return sa;
}

int main()
{

#ifndef ONLINE_jUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int a, n;
	cin >> a >> n;


	cout << fastpower(a, n);
}
