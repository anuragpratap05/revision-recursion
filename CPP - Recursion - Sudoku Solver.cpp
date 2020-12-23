# revision-recursion
#include<bits/stdc++.h>
using namespace std;
//char pattern[][10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
bool canweplace(int mat[][9], int i, int j, int num)
{
	for (int x = 0; x < 9; x++)
	{
		if (mat[i][x] == num or mat[x][j] == num)
		{
			return false;
		}
	}

	int sx = (i / 3) * 3;
	int sy = (j / 3) * 3;

	for (int x = sx; x < sx + 3; x++)
	{
		for (int y = sy; y < sy + 3; y++)
		{
			if (mat[x][y] == num)
			{
				return false;
			}
		}
	}

	return true;



}


bool solvesudoku(int mat[][9], int i, int j, int n )
{
	if (i == n)
	{

		for (int ro = 0; ro < n; ro++)
		{
			for (int co = 0; co < n; co++)
			{
				cout << mat[ro][co] << " ";
			}
			cout << endl;
		}
		return true;
	}

	if (j == n)
	{
		return solvesudoku(mat, i + 1, 0, n);
	}

	if (mat[i][j] != 0)
	{
		return solvesudoku(mat, i, j + 1, n);
	}

	for (int num = 1; num <= 9; num++)
	{
		if (canweplace(mat, i, j, num))
		{
			mat[i][j] = num;
			bool goahed = solvesudoku(mat, i, j + 1, n);
			if (goahed)
			{
				return true;
			}
		}
	}
	mat[i][j] = 0;
	return false;
}

int main()
{

#ifndef ONLINE_jUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int mat[9][9] = {{5, 3, 0, 0, 7, 0, 0, 0, 0},
		{6, 0, 0, 1, 9, 5, 0, 0, 0},
		{0, 9, 8, 0, 0, 0, 0, 6, 0},
		{8, 0, 0, 0, 6, 0, 0, 0, 3},
		{4, 0, 0, 8, 0, 3, 0, 0, 1},
		{7, 0, 0, 0, 2, 0, 0, 0, 6},
		{0, 6, 0, 0, 0, 0, 2, 8, 0},
		{0, 0, 0, 4, 1, 9, 0, 0, 5},
		{0, 0, 0, 0, 8, 0, 0, 7, 9}
	};
	solvesudoku(mat, 0, 0, 9);

}
