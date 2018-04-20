#pragma once
class Backtracking
{
private:
	int board[20];
	int _N;
	int nodes;
public:
	int x;
	Backtracking(int N);
	~Backtracking();

	void run();
	void queen(int row);
	bool place(int row, int column);
};

