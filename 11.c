#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int main()
{
	int len = 0;
	string str = "cabefebeagildhfaklhfahbihiwqihqjfqjfjqjfqjfquuuuuuuuuueeeeeeeeeeeeffffffffffffff";
	int N = str.size();
	int** Len = new int*[N];
	for (int i = 0; i < N; i++)
		Len[i] = new int[N];
	for (int i = 0; i < N; i++)
		for (int j =0;j<N; j++)
			Len[i][j] = 0;
	for (int i = N-2; i>=0; i--)
	{
		for (int j =1;j<N; j++)
		{
			if (i <j){
				if (str[i] == str[j])
					Len[i][j] = Len[i + 1][j - 1] + 2;
				else
					Len[i][j] = max(Len[i][j - 1], Len[i + 1][j]);
			}
			else if(str[i] == str[j]&&i==j)
				Len[i][j] = Len[i + 1][j - 1] + 1;

		}
			
	}
	cout << Len[0][N-1]<< endl;

}
