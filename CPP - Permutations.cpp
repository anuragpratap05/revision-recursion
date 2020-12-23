# revision-recursion
#include<bits/stdc++.h>
using namespace std;
//char pattern[][10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void permutation(char* in, int i)
{
	if (in[i] == '\0')
	{
		cout << in << ",";
		return;
	}

	for (int j = i; in[j] != '\0'; j++)
	{
		swap(in[i], in[j]);
		permutation(in, i + 1);
		swap(in[i], in[j]);
	}
	return;
}

int main()
{

#ifndef ONLINE_jUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	char in[100];
	cin >> in;
	permutation(in, 0);

}
