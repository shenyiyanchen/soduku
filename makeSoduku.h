#pragma once
#include<iostream>
#include<time.h>
using namespace std;

extern int sodu[9][9];
bool set_a_sodu(int x, int y, int value)
{
	if (sodu[y][x] != 0)
		return false;
	int x0, y0;
	for (x0 = 0; x0 < 9; x0++)
	{
		if (sodu[y][x0] == value)
			return false;
	}
	for (y0 = 0; y0 < 9; y0++)
	{
		if (sodu[y0][x] == value)
			return false;
	}
	for (y0 = y / 3 * 3; y0 < y / 3 * 3 + 3; y0++)
	{
		for (x0 = x / 3 * 3; x0 < x / 3 * 3 + 3; x0++)
		{
			if (sodu[y0][x0] == value)
				return false;
		}
	}
	sodu[y][x] = value;
	return true;
}


void reset_that_sodu(int x, int y)
{
	sodu[y][x] = 0;
}


void initialize_Element(int* element)
{
	int i, k, temp;
	for (i = 0; i < 9; i++)
	{
		element[i] = i;
	}
	for (i = 0; i < 9; i++)
	{
		k = rand() % 9;
		temp = element[k];
		element[k] = element[i];
		element[i] = temp;
	}
}


bool fill_the_form(int y, int value)
{
	int element[9];
	initialize_Element(element);
	for (int i = 0; i < 9; i++)
	{
		int x = element[i];
		if (set_a_sodu(x, y, value))
		{
			if (y == 8)
			{
				if (value == 9 || fill_the_form(0, value + 1))
					return true;
			}
			else
			{
				if (fill_the_form(y + 1, value))
					return true;
			}
			reset_that_sodu(x, y);
		}
	}
	return false;
}


void print_the_sodu()
{
	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			cout << sodu[y][x] << " ";
		}
		cout << endl;
	}
}

void makesoduku(int num)
{
	while (!fill_the_form(0, 1));
	for (int m = 1; m <= num; m++)
	{
	S1:int k;
		k = rand() % 81;
		int i = k / 9;
		int j = k % 9;

		if (sodu[j][i] == 0)
			goto S1;
		else
			sodu[j][i] = 0;
	}
	//print_the_sodu();
}
