#pragma once
using namespace std;
class FC_LatinSquare
{
private:
	int board[10][10];
	int N;
	int solutions = 0;
	int nodes = 0;

	vector<vector<vector<int>>> domain;

public:
	FC_LatinSquare(int n);
	~FC_LatinSquare();

	void run();
	void latin(int row, int column, vector<vector<vector<int>>> &domain);
	bool place(int row, int column, int n, vector<vector<vector<int>>> &new_domain);

	void setDomain();
};

