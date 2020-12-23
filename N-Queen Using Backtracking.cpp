# revision-recursion#include<bits/stdc++.h>
using namespace std;
//char pattern[][10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

bool issafe(int board[][10], int i, int j, int n)
{
	for (int row = i; row >= 0; row--)
	{
		if (board[row][j] == 1)
		{
			return false;
		}
	}

	int x = i;
	int y = j;

	while (x >= 0 and y < n)
	{
		if (board[x - 1][y + 1] == 1)
		{
			return false;
		}
		x--;
		y++;
	}

	x = i;
	y = j;

	while (x >= 0 and y >= 0)
	{
		if (board[x - 1][y - 1] == 1)
		{
			return false;
		}
		x--;
		y--;
	}

	return true;
}

bool solvenqueen(int n, int board[][10], int i)
{
	if (i == n)
	{
		for (int ro = 0; ro < n; ro++)
		{
			for (int co = 0; co < n; co++)
			{
				if (board[ro][co] == 1)
				{
					cout << "Q ";
				}
				else
				{
					cout << "_ ";
				}
			}
			cout << endl;
		}
		cout << endl;
		//return true;
	}

	for (int j = 0; j < n; j++)
	{
		if (issafe(board, i, j, n))
		{
			board[i][j] = 1;
			bool nextqueenrakhpaye = solvenqueen(n, board, i + 1);
			if (nextqueenrakhpaye)
			{
				return true;
			}
			board[i][j] = 0;
		}
	}
	return false;
}

int main()
{

#ifndef ONLINE_jUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	int board[10][10] = {0};
	solvenqueen(n, board, 0);

}
