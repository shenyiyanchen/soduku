#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include "function.h"
#include "makeSoduku.cpp"
#include "solveSoduku.cpp"
using namespace std;
int sodu[9][9];
int temp[9][9];

int main(int argc, char *args[]) 
{
	srand((unsigned)time(NULL));
	// �������ɸ��������̣�-c���ʾ���ɼ�����-o��ʾ���浽�ļ��� 
	if(strcmp(args[1], "-c") == 0)
	{
		int n = arg2number(args[2]);
		while(n--)
		{
			makesoduku(0);
			print();
			if(argc >= 4 && strcmp(args[3], "-o") == 0)
			{
				//string path = arg2path(args[4]);
				ofstream out(args[4], ios::app);
				for(int i = 0; i < 9; i++)
				{
					for(int j = 0; j < 9; j++)
					{
						out << sodu[i][j] << " ";
					}
					out << endl; 
				}
				out << endl;
				out.close();
			}
			reset();
		}
	}
	// ���������-s���ļ���ȡ��-o��������ĳ�ļ��� 
	else if(strcmp(args[1], "-s") == 0)
	{
		//string path = arg2path(args[2]);
		ifstream in(args[2], ios::in);
		while(!in.eof())
		{
			int fail = 0;
			for(int i = 0; i < 9; i++)
			{
				for(int j = 0; j < 9; j++)
				{
					in >> sodu[i][j];
					if(sodu[i][j] == 0)
						fail++;
					temp[i][j] = sodu[i][j];
				}
			}
			if(fail == 81)
				break;
			backtrace(0);
			for(int i = 0; i < 9; i++)
			{
				for(int j = 0; j < 9; j++)
				{
					sodu[i][j] = temp[i][j];
				}
			}
			if(argc >= 4 && strcmp(args[3], "-o") == 0)
			{
				//string outpath = arg2path(args[4]);
				ofstream out(args[4], ios::app);
				for(int i = 0; i < 9; i++)
				{
					for(int j = 0; j < 9; j++)
					{
						out << sodu[i][j] << " "; 
					}
					out << endl;
				}
				out << endl;
				out.close();
			}
			print();
			reset();
		}
		in.close();
	}
	// ����������Ϸ��-n��������-m���Ѷȣ�-o�������ļ���
	// ����������Ϸ��-n��������-r��������-o�������ļ���
	else if(strcmp(args[1], "-n") == 0)
	{
		int mode = 0;
		if(strcmp(args[3], "-m") == 0)
			mode = 1;
		else if(strcmp(args[3], "-r") == 0)
			mode = 2;
		else
		{
			cout << "error" << endl;
			return 0;
		}
		int n = arg2number(args[2]);
		int m, n1, n2;
		if(mode == 1)
			m = arg2number(args[4]);
		else
		{
			char num1[8], num2[8];
			int i;
			for(i = 0; args[4][i] != '-'; i++)
				num1[i] = args[4][i];
			num1[i] = '\0';
			n1 = atoi(num1);
			i++;
			int tmp = i;
			for(i; args[4][i] != '\0'; i++)
				num2[i - tmp] = args[4][i];
			num2[i - tmp] = '\0';
			n2 = atoi(num2);
		}
		while(n--)
		{
			int num = 0;
			if(mode == 1)
				switch(m)
				{
					case 1: num = rand() % 15 + 1; break;
					case 2: num = rand() % 30 + 1; break;
					case 3: num = rand() % 45 + 1; break;
					default: break;
				}
			else if(mode == 2)
			{
				num = rand() % (n2 - n1 + 1) + n1;
			}
			makesoduku(num);
			print();
			if(argc >= 6 && strcmp(args[5], "-o") == 0)
			{
				//string outpath = arg2path(args[6]);
				ofstream out(args[6], ios::app);
				for(int i = 0; i < 9; i++)
				{
					for(int j = 0; j < 9; j++)
					{
						out << sodu[i][j] << " "; 
					}
					out << endl;
				}
				out << endl;
				out.close();
			}
			reset();
		}
	}
	return 0;
}
