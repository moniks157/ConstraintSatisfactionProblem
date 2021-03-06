#include "stdafx.h"
#include "Backtracking.h"
#include<stdio.h>
#include<math.h>
#include <iostream>
#include <string>
#include "ForwardChecking.h"

using namespace std;

int board[20], county;



int main()
{
	for (int i = 4; i <= 13; i++)
	{
		//printf_s("%d\t", i);
		Backtracking bc = Backtracking(i);
		bc.run();
	}
	printf_s("\n");
	for (int i = 4; i <= 13; i++)
	{	
		//printf_s("%d\t", i);
		ForwardChecking fc = ForwardChecking(i);
		fc.run();
	}
	system("pause");
	return 0;
}