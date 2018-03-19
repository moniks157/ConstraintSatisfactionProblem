#pragma once
class NQueen
{
private:
	int _N;
	int _solutions = 0;

public:
	NQueen(int N);
	~NQueen();

	int getN() { return _N; }
};

