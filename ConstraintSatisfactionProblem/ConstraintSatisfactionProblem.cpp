#include "stdafx.h"
#include "Backtracking.h"
#include<stdio.h>
#include<math.h>
#include <iostream>
#include <string>
#include "ForwardChecking.h"
#include "BT_LatinSquare.h"
#include "FC_LatinSquare.h"
using namespace std;

int board[20], county;



int main()
{
	for (int i = 1; i <= 14; i++)
	{
		//printf_s("%d\t", i);
		//Backtracking bc = Backtracking(i);
		//bc.run();
	}
	//printf_s("\n");
	for (int i = 1; i <= 14; i++)
	{	
		//printf_s("%d\t", i);
		ForwardChecking fc = ForwardChecking(i);
		auto start = std::chrono::high_resolution_clock::now();
		
		fc.run();
		auto finish = std::chrono::high_resolution_clock::now();
		std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << "\n";
	}
	for (int i = 1; i <= 5; i++)
	{
		//printf_s("%d\t", i);
		//BT_LatinSquare lbt = BT_LatinSquare(i);
		//lbt.run();
	}
	for (int i = 1; i <= 5; i++)
	{
		//printf_s("%d\t", i);
		//FC_LatinSquare lbt = FC_LatinSquare(i);
		//lbt.run();
	}
	system("pause");
	return 0;
}