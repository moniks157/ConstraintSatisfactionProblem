#include "stdafx.h"
#include "FC_LatinSquare.h"


FC_LatinSquare::FC_LatinSquare(int n)
{
	N = n;
	setDomain();
}


FC_LatinSquare::~FC_LatinSquare()
{
}

void FC_LatinSquare::run()
{
	auto start = std::chrono::high_resolution_clock::now();
	//for (int i = 0; i < 10; ++i)
	{
		latin(0,0, domain);
	}
	auto finish = std::chrono::high_resolution_clock::now();
	//printf_s("%d\n", nodes);
	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << "\n";
}

void FC_LatinSquare::latin(int row, int column, vector<vector<vector<int>>> &domain)
{
	int i;
	if (column == N)
	{
		row = row + 1;
		column = 0;
	}
	for (i = 1; i <= N && domain[row][column].size()!=0; ++i)
	{
		//nodes++;
		board[row][column] = domain[row][column][0];
		if (row == N - 1 && column == N - 1);
			//++solutions;
		else
		{
			vector<vector<vector<int>>> new_domain(domain);
			//new_domain.assign(domain.begin(), domain.end());
			if(place(row, column, domain[row][column][0], new_domain))
				latin(row, column + 1, new_domain);
		}
		domain[row][column].erase(domain[row][column].begin());
		
	}
}

bool FC_LatinSquare::place(int row, int column, int n, vector<vector<vector<int>>> &new_domain)
{
	int i;
	//new_domain = domain;
	for (i = row + 1; i<N; ++i)
	{
		new_domain[i][column].erase(std::remove(new_domain[i][column].begin(), new_domain[i][column].end(), n), new_domain[i][column].end());
		if (new_domain[i][column].size() == 0) return false;
		//new_domain[row][i].erase(std::remove(new_domain[row][i].begin(), new_domain[row][i].end(), n), new_domain[row][i].end());
	}
	for (i = column + 1; i<N; ++i)
	{
		new_domain[row][i].erase(std::remove(new_domain[row][i].begin(), new_domain[row][i].end(), n), new_domain[row][i].end());
		if (new_domain[row][i].size() == 0) return false;
	}
	return true;
}

void FC_LatinSquare::setDomain()
{
	vector<int> temp(N);
	for (int j = 0; j < N; ++j) {
		vector<vector<int>> temp2(0);
		for (int i = 1; i <= N; i++) {
			iota(temp.begin(), temp.end(), 1);
			temp2.emplace_back(temp);
		}
		domain.emplace_back(temp2);
	}
}
