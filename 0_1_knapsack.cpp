# revision-recursion
#include<bits/stdc++.h>
using namespace std;

int knapsack(int* price, int* wt, int n, int c, int i)
{
	if (n == 0 or c == 0)
	{
		return 0;
	}
	if (wt[i] > c)
		return 0;

	int ans = 0;
	int inc, exc;
	inc = exc = 0;
	//if (wt[i] <= c)
	inc = price[i] + knapsack(price, wt, n - 1, c - wt[i], i + 1);

	exc = knapsack(price, wt, n - 1, c, i + 1);
	ans = max(inc, exc);
	return ans;
}

int main()
{

#ifndef ONLINE_jUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	int wt[n];
	int price[n];
	for (int i = 0; i < n; i++)
	{
		cin >> wt[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> price[i];
	}

	int c = 7;
	cout << knapsack(price, wt, n, c, 0);
}
