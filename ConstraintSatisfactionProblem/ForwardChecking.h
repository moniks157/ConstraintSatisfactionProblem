#pragma once

using namespace std;

class ForwardChecking
{
private:
	vector<vector<int>> _domain;
	int board[20];
	int _N;
	int nodes;
public:
	int x;
	ForwardChecking(int N);
	~ForwardChecking();

	void run();
	void queen(int row, vector<vector<int>> &domain);
	bool place(int row, int column, vector<vector<int>> &new_domain);
	void setDomain();


	void print(int n);
};

