#pragma once
#include <iostream>
#include <algorithm>
using namespace std;
extern int sodu[9][9];
extern int temp[9][9];
bool Element(int count)
{
	int row = count / 9;
	int col = count % 9;
	int j;

	for (j = 0; j < 9; ++j)
	{
		if (sodu[row][j] == sodu[row][col] && j != col)
		{
			return false;
		}
	}

	for (j = 0; j < 9; ++j)
	{
		if (sodu[j][col] == sodu[row][col] && j != row)
		{
			return false;
		}
	}

	int tempRow = row / 3 * 3;
	int tempCol = col / 3 * 3;

	for (j = tempRow; j < tempRow + 3; ++j)
	{
		for (int k = tempCol; k < tempCol + 3; ++k)
		{
			if (sodu[j][k] == sodu[row][col] && j != row && k != col)
			{
				return false;
			}
		}
	}

	return true;
}

void backtrace(int count)
{
	if (count == 81)
	{
		for (int i = 0; i < 9; ++i)
		{
			for (int j = 0; j < 9; ++j)
			{
				temp[i][j] = sodu[i][j];
			}
		}
		return;
	}

	int row = count / 9;
	int col = count % 9;

	if (sodu[row][col] == 0)
	{
		for (int i = 1; i <= 9; ++i)
		{
			sodu[row][col] = i;
			if (Element(count))
			{
				backtrace(count + 1);
			}
		}
		sodu[row][col] = 0;
	}
	else
	{
		backtrace(count + 1);
	}
}
