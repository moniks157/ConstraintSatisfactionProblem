#include "stdafx.h"
#include "ForwardChecking.h"
#include <string.h>
#include <chrono>
#include <algorithm>
#include <numeric>


ForwardChecking::ForwardChecking(int N)
{
	_N = N;
	x = 0;
	setDomain();
	nodes = 0;
}


ForwardChecking::~ForwardChecking()
{
}


void ForwardChecking::run()
{
	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 10; ++i)
	{
		queen(1, _domain);
	}
	auto finish = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count()/10 << "\n";
	//printf_s("%d\n", x);
}

void ForwardChecking::queen(int row, vector<vector<int>> &domain)
{
	int column;
	if (domain.size() != 0 && row - 1 != _N) {
		for (column = 1; column <= domain[0].size();)
		{
			//nodes++;
			board[row] = domain[0][0]; //no conflicts so place queen
			if (row == _N)
				;//++x;//dead end
			else//try queen with next position
			{
				vector<vector<int>> new_domain;
				new_domain.assign(domain.begin() + 1, domain.end());
				place(row, domain[0][0], new_domain);
				queen(row + 1, new_domain);
			}
			domain[0].erase(domain[0].begin());
		}
	}
}

bool ForwardChecking::place(int row, int column, vector<vector<int>> &new_domain)
{
	int i;
	//new_domain = domain;
	for (i = 0; i<_N - row ;++i)
	{
		new_domain[i].erase(std::remove(new_domain[i].begin(), new_domain[i].end(), column), new_domain[i].end());
		new_domain[i].erase(std::remove(new_domain[i].begin(), new_domain[i].end(), i + 1 + column), new_domain[i].end());
		new_domain[i].erase(std::remove(new_domain[i].begin(), new_domain[i].end(), column - (i + 1) ), new_domain[i].end());
	}
	return true;
}

void ForwardChecking::setDomain()
{
	vector<int> temp(_N);
	for (int i = 1; i <= _N ; i++) {
		iota(temp.begin(), temp.end(),1);
		_domain.emplace_back(temp);
	}
}



