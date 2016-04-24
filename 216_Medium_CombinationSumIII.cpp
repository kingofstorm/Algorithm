/*Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Ensure that numbers within the set are sorted in ascending order.


Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]

Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]
Credits:
*/


#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<string>
#include<algorithm>
#include<bitset>
using namespace std;
void sum_backtrack(int& k, int& n,int count,vector<int>&sum_tmp, vector<vector<int>>&sum_V)
{
	
	if (k < 0 || n < 0)
		return;
	if (k>0 && n == 0)
		return;
	if (k == 0 && n>0)
		return;
	if (k == 0 && n == 0)
	{
		sum_V.push_back(sum_tmp);
		return;
	}
	for (int i =1+count; i <= 9; i++)
	{
		sum_tmp.push_back(i);
		--k;
		n = n - i;
		count=i;
		sum_backtrack(k, n,count, sum_tmp, sum_V);
		sum_tmp.pop_back();
		k++;
		n = n + i;
	}
}
vector<vector<int>> combinationSum3(int k, int n) {
	vector <vector< int >> sum_V;
	vector<int> sum_tmp;
	int count = 0;
	sum_backtrack(k, n,count, sum_tmp, sum_V);
	return sum_V;

}
int main()
{
	vector<vector<int>> a;
	int k = 3;
	int n = 9;
	a=combinationSum3(k, n);
	for (auto r : a)
	{
		for (auto t : r)
			cout << t;
		cout << endl;
	}
	return 0;
	
}

