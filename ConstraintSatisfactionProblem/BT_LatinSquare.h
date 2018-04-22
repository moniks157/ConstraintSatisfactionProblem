#pragma once
using namespace std;
class BT_LatinSquare
{
private:
	int board[10][10];
	int N;
	int solutions = 0;
	int nodes = 0;

public:
	BT_LatinSquare(int n);
	~BT_LatinSquare();

	void run();
	void latin(int row, int column);
	bool place(int row, int column, int n);

};

