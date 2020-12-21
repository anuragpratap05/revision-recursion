# revision-recursion
#include<bits/stdc++.h>
using namespace std;

void parenthesis(int n, char* out, int i, int open , int close)
{
	if (i == 2 * n)
	{
		out[i] = '\0';
		cout << out << endl;
		return;
	}

	if (open < n)
	{
		out[i] = '(';
		parenthesis(n, out, i + 1, open + 1, close);
	}

	if (close < open)
	{
		out[i] = ')';
		parenthesis(n, out, i + 1, open, close + 1);
	}
	return;
}

int main()
{

#ifndef ONLINE_jUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	char out[100];
	parenthesis(n, out, 0, 0, 0);
}
