////////////第一题
#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<queue>
using namespace std;
int calc(string s,int len,int* res)
{
	int count = 0;
	for (int i = 0; i < len - 1; i++)
	{
		if (s[i] == '.')
			(*res)++;
	}
	if ((*res) == 0)
	{
		//cout << *res << endl;
		return 0;
	}
		
	for (int i = 0; i < len-1; i++)
	{
		if (s[i] == '.'&&s[i + 1] == '.')
			count++;
	}
	return count;

}
int main()
{
    int n1;
	int n2;
	while (cin >> n1 >> n2){
		if (n1<1 || n1>300000)
			break;
		if (n2<1 || n2>300000)
			break;
		string s;
		cin>>s;
		if (s.size()>n1)
		{
			string stmp="";
			for (int i = 0; i < n1; i++)
				stmp+= s[i];
			s = stmp;
		}
		for (int i = 0; i < n2; i++)
		{
			int num;
			char ch;
			cin >> num;
			if (num>n1)
				break;
			cin >> ch;
			s[num - 1] = ch;
			int res = 0;
			int numer = calc(s, n1,&res);
				if (res == 0)
					{
						cout <<0<< endl;
						continue;
					}
			if (numer == 0)
				cout <<1<< endl;
			else
				cout << numer << endl;
			//cout << s << endl;
		}
	}
	return 0;
}

/*第二题*/


#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    int n;
	int b;
	while (cin>>n>>b)
	{
	
		if (n <= 0 || n > 3000000)//记不清最大多少了
			break;
		if (n == 1)
		{
			cout << 1 << endl;
			continue;
		}
		if (n % 2 == 0)
			{	
				int Premiddle = n / 2 + 1;
				int Postmiddle = n / 2;
				if (b >= Premiddle)
				{
					int a = b-1;
					cout << a << endl;
					continue;
				}
				if (b<=Postmiddle)
				{
					int a = b+1;
					cout << a << endl;
					continue;
				}
			}
		if (n % 2 == 1)
			{
				int middle =(n + 1) / 2;
				if (b == middle)
				{
					int a = n / 2;
					cout << a << endl;
					continue;
				}
				if (b > middle)
				{
					int a = b-1;
					cout << a << endl;
					continue;
				}

				if (b<middle)
				{
					int a = b+1;
					cout << a << endl;
					continue;
				}
			}

	}
	
	return 0;
}

