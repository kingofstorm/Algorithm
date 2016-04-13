#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
	bool position(int i,int j,int n,vector<string> queen)
	{
		for (int x = 0; x<i; x++)
		{
			for (int y = 0; y < n; y++)
			{
				if (((x - y == i - j) || (x + y == i + j) || (x == i) || (y == j))&&(queen[x][y] == 'Q'))
						return false;
			}
		}
		return true;
	}
	void N_queen_build(vector<vector<string>> &N_queen_res,vector<string>& queen, int level, int n)
	{
		if (level == n)
		{
			N_queen_res.push_back(queen);
			return;
		}
		
		for (int i =0; i<n; i++)
		{
			if (position(level,i,n,queen))
			{
				queen[level][i] = 'Q';
				N_queen_build(N_queen_res,queen, level + 1,n);
				queen[level][i] = '.';
				
			}
		}
	}
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> N_queen_res;
		vector<string> N_queen(n, string(n, '.'));

		N_queen_build(N_queen_res, N_queen, 0, n);
		
		return N_queen_res;

	}
int main()
{
	vector<vector<string>> res = solveNQueens(8);
	for (auto r : res)
	{
		for (auto t : r)
		{
			for (auto s : t)
				cout << s;
			cout << endl;
		}
		cout << endl;
	}
	cout <<res.size() << endl;
	return 0;
}

