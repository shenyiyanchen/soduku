#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
using namespace std;

extern int sodu[9][9];
int arg2number(char *arg)
{
	char num[8];
	int i;
	for(i = 0; arg[i] != '\0'; i++)
		num[i] = arg[i];
	num[i] = '\0';
	int n = atoi(num);
	return n;
}

string arg2path(char *arg)
{
	string path = "";
	int i;
	for(i = 0; arg[i] != '\0'; i++)
		path += arg[i];
	path += '\0';
	return path;
}
void print()
{
	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 9; j++)
			cout << sodu[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

void reset()
{
	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 9; j++)
			sodu[i][j] = 0;
	}
}
