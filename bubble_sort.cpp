# revision-recursion
#include<bits/stdc++.h>
using namespace std;

void bubble_sort(int* a, int j, int n)
{
	if (n == 1)
	{
		return;
	}

	if (j == n - 1)
	{
		bubble_sort(a, 0, n - 1);
		return;

	}

	if (a[j] > a[j + 1])
	{
		swap(a[j], a[j + 1]);
		bubble_sort(a, j + 1, n);
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

	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	bubble_sort(a, 0, n);
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}
