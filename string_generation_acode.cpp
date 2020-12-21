# revision-recursion
#include<bits/stdc++.h>
using namespace std;
//char pattern[][10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void subsequences(char* in, char* out, int i, int j)
{
	if (in[i] == '\0')
	{
		out[j] = '\0';
		cout << out << endl;
		return;
	}

	int digit1 = in[i] - '0';
	char ch = digit1 + 'A' - 1;
	out[j] = ch;
	subsequences(in, out, i + 1, j + 1);

	if (in[i + 1] != '\0')
	{
		int digit2 = (in[i + 1] - '0') + (digit1 * 10);
		if (digit2 <= 26)
		{
			char ch2 = digit2 + 'A' - 1;
			out[j] = ch2;
			subsequences(in, out, i + 2, j + 1);
		}
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
	char out[100];
	subsequences(in, out, 0, 0);
}
