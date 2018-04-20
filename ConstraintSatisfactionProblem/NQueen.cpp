#include "stdafx.h"
#include "NQueen.h"


NQueen::NQueen(int N)
{
	_N = N;
	for (int i = 0; i < _N; i++)
	{
		for (int j = 0; j < _N; j++)
		{
			//_chessboard.push_back({ i,j });
		}
	}
}


NQueen::~NQueen()
{
}

int NQueen::backtracking()
{
	
	return 0;
}

bool NQueen::check(int i, int j)
{
	return false;
}
