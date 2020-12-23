# revision-recursion
#include<bits/stdc++.h>
using namespace std;
//char pattern[][10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void permutation(char* in, int i, set<string> &s)
{
	if (in[i] == '\0')
	{
		cout << in << ",";
		string t(in);
		s.insert(t);
		return;
	}

	for (int j = i; in[j] != '\0'; j++)
	{
		swap(in[i], in[j]);
		permutation(in, i + 1, s);
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
	set<string> s;
	permutation(in, 0, s);
	cout << endl;
	for (auto x : s)
	{
		cout << x << ",";
	}

}
