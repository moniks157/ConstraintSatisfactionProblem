#pragma once
#include <vector>
#include "Field.h"

using namespace std;
class NQueen
{
private:
	int _N;
	int _solutions = 0;
	//vector<Field> _chessboard;

public:
	NQueen(int N);
	~NQueen();

	int getN() { return _N; }

	int backtracking();
	bool check(int i, int j);
	int forwardchecking();
};

