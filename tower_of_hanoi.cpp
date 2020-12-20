# revision-recursion
#include<bits/stdc++.h>
using namespace std;

void tower(int n, char source, char helper, char dest)
{
	if (n == 0)
	{
		return;
	}

	tower(n - 1, source, dest, helper);
	cout << "move disk " << n << " from " << source << " to " << dest << endl;
	tower(n - 1, helper, source, dest);
}



int main()
{

#ifndef ONLINE_jUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	tower(n, 'A', 'B', 'C');
}
