#include "stdafx.h"
#include "BT_LatinSquare.h"


BT_LatinSquare::BT_LatinSquare(int n)
{
	N = n;
}


BT_LatinSquare::~BT_LatinSquare()
{
}

void BT_LatinSquare::run()
{
	auto start = std::chrono::high_resolution_clock::now();
	latin(0, 0);
	auto finish = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << "\n";
	//printf_s("%d\n", nodes);
}

void BT_LatinSquare::latin(int row, int column)
{
	int i;
	if (column == N)
	{
		row = row + 1;
		column = 0;
	}
	for (i = 1; i <= N; ++i)
	{
		nodes++;
		if (place(row, column, i))
		{
			board[row][column] = i;
			if (row == N - 1 && column == N - 1)
				++solutions;
			else
				latin(row, column + 1);
		}
	}
}

bool BT_LatinSquare::place(int row, int column, int n)
{
	for (int i = 0; i < row; i++)
	{
		if (board[i][column] == n)
			return false;
	}
	for (int i = 0; i < column; i++)
	{
		if (board[row][i] == n)
			return false;
	}
	return true;
}
