#include "stdafx.h"
#include "Backtracking.h"
#include <string.h>
#include <chrono>


Backtracking::Backtracking(int N)
{
	_N = N;
	x = 0;
	nodes = 0;
}


Backtracking::~Backtracking()
{
}


void Backtracking::run()
{
	auto start = std::chrono::high_resolution_clock::now();
	//for (int i = 0; i < 10; ++i)
	{
		queen(1);
	}
	auto finish = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count()<<"\n";
	//printf_s("%d\n", x);
}

void Backtracking::queen(int row)
{
	int column;
	for (column = 1; column <= _N; column++)
	{
		nodes++;
		if (place(row, column))
		{
			board[row] = column; //no conflicts so place queen
			if (row == _N)
				x++;//dead end
			else //try queen with next position
				queen(row + 1);
		}
	}
}

bool Backtracking::place(int row, int column)
{
	int i;
	for (i = 1; i <= row - 1; i++)
	{
		//checking column and digonal conflicts
		if (board[i] == column)
			return false;
		else if (board[i] - column == i - row)
				return false;
		else if (board[i] - column == -i + row)
			return false;
	}
	return true; //no conflicts
}
