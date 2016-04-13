#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<string>
#include<algorithm>
#include<bitset>
#include<unordered_set>
#include<stack>
using namespace std;

/*01背包
N背包最大重量量
M可以取的糖果堆 tmp1重量 tmp2价值

*/
int main()
{
	
	int M,N;
	cin >> M>>N;
	vector<vector<int>> sugar(M+1, vector<int>(N+1, 0));
	vector<int> list(1, 0);
	vector<int> list_value(1, 0);
	for (int i = 0; i < M; i++)
	{
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		list.push_back(tmp1);
		list_value.push_back(tmp2);
	}
	vector<int> sugar1(N+1,0);
	for (int i = 1;i<=M ; i++)
	{
		for (int j = N; j>=list[i]; j--)
		{
			if (sugar1[j]<(sugar1[j - list[i]]+list_value[i]))
				sugar1[j]= sugar1[j-list[i]]+list_value[i];

		}
	}
	for (auto r : sugar1)
		cout << r << " ";
		cout<< endl;
	cout << sugar1[N] << endl;
	return 0;
}

/*修改后*/
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<string>
#include<algorithm>
#include<bitset>
#include<unordered_set>
#include<stack>
using namespace std;

/*01背包
N背包最大重量量
M可以取的糖果堆 tmp1重量 tmp2价值

*/
int main()
{
	
	int M,N;
	cin >> M>>N;
//	vector<vector<int>> sugar(M+1, vector<int>(N+1, 0));
     vector<int> list(M,0);
   	int tmp1, tmp2;
	vector<int> list_value(M,0);
/*	for (int i = 0; i < M; i++)
	{
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		list.push_back(tmp1);
		list_value.push_back(tmp2);
	}*/
	vector<int> sugar1(N+1,0);
	for (int i =0;i<M ; i++)//使用一维数组优化后可以从0开始
	{	cin>>list[i];
		cin>>list_value[i];
		for (int j = N; j>=list[i]; j--)
		{
			if (sugar1[j]<(sugar1[j - list[i]]+list_value[i]))
				sugar1[j]= sugar1[j-list[i]]+list_value[i];

		}
	}
	for (auto r : sugar1)
		cout << r << " ";
		cout<< endl;
	cout << sugar1[N] << endl;
	return 0;
}

/*最简化代码*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int M, N;
	cin >> M >> N;
	vector<int> sugar1(N + 1, 0);
	int w, v;
	for (int i = 0; i<M; i++)//使用一维数组优化后可以从0开始
	{
		cin >> w >> v;
		for (int j = N; j >= w; j--)
		{
			sugar1[j] = sugar1[j]>(sugar1[j - w] + v) ? sugar1[j] : (sugar1[j - w] + v);
		}
	}
	cout << sugar1[N] << endl;
	return 0;
}
