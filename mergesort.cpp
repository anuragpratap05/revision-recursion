# revision-recursion
#include<bits/stdc++.h>
using namespace std;

void merge(int* a, int s, int e)
{
	int temp[100];

	int mid = (s + e) / 2;

	int i = s;
	int j = mid + 1;
	int k = s;

	while (i <= mid and j <= e)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			i++;
			k++;
		}
		else
		{
			temp[k] = a[j];
			j++;
			k++;
		}
	}

	while (i <= mid)
	{
		temp[k] = a[i];
		i++;
		k++;
	}

	while (j <= e)
	{
		temp[k] = a[j];
		j++;
		k++;
	}
	//k = 0;
	for (int i = s; i <= e; i++)
	{
		a[i] = temp[i];
		//k++;
	}

}

void merge_sort(int* a , int s, int e)
{
	if (s >= e)
	{
		return;
	}
	int mid = (s + e) / 2;

	merge_sort(a, s, mid);
	merge_sort(a, mid + 1, e);

	merge(a, s, e);
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

	merge_sort (a, 0, n - 1 );
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}
