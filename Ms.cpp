Little Hi runs a web server. Sometimes he has to deny access from a certain set of malicious IP addresses while his friends are still allow to access his server. To do this he writes N rules in the configuration file which look like:

allow 1.2.3.4/30
deny 1.1.1.1
allow 127.0.0.1
allow 123.234.12.23/3
deny 0.0.0.0/0
Each rule is in the form: allow | deny address or allow | deny address/mask.

When there comes a request, the rules are checked in sequence until the first match is found. If no rule is matched the request will be allowed. Rule and request are matched if the request address is the same as the rule address or they share the same first mask digits when both written as 32bit binary number.

For example IP "1.2.3.4" matches rule "allow 1.2.3.4" because the addresses are the same. And IP "128.127.8.125" matches rule "deny 128.127.4.100/20" because 10000000011111110000010001100100 (128.127.4.100 as binary number) shares the first 20 (mask) digits with 10000000011111110000100001111101 (128.127.8.125 as binary number).

Now comes M access requests. Given their IP addresses, your task is to find out which ones are allowed and which ones are denied.

输入
Line 1: two integers N and M.

Line 2-N+1: one rule on each line.

Line N+2-N+M+1: one IP address on each line.

All addresses are IPv4 addresses(0.0.0.0 - 255.255.255.255). 0 <= mask <= 32.



For 40% of the data: 1 <= N, M <= 1000.

For 100% of the data: 1 <= N, M <= 100000.

输出
For each request output "YES" or "NO" according to whether it is allowed.



#include <iostream>
#include <map>
#include <algorithm>
#include <functional>
#include <string>
#include <unordered_map>
#include<cstdlib>
#include<cstdio>
#include<sstream>
using namespace std;
string revert(string tmp)
{
	string binary = "";
	string bb = "";
	stringstream os;
	int num;
	os << tmp;
	os >> num;
	int N1 = num;
	while (N1)
	{
		os.clear();
		int N2 = N1 % 2;
		os << N2;
		os >> bb;
		binary += bb;
		N1 = N1 / 2;
	}
	if (binary.size() < 8)
	{
		int n = binary.size();
		for (int i = 0; i < 8 - n; i++)
			binary += "0";
	}
	string binary_s = "";
	for (int i = 0; i < 8; i++)
	{
		binary_s += binary[7 - i];
	}
	return binary_s;
}
string maskN(string s, int N)
{
	
	int N_len = N;
	string tmp = "";
	string res = "";
	string binary_s = "";
	int num;
	
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != '.')
			tmp += s[i];
		else
		{
			binary_s = revert(tmp);
			res += binary_s;
			tmp.clear();
		}
	}
	binary_s = revert(tmp);
	res += binary_s;
	
	tmp.clear();
	string res11="";
	for (int i =0; i<N_len; i++)
		res11 += res[i];
	return res11;

}
int main()
{
	int flag = 0;
	int flag1= 0;
	int M;
	int N;
	cin >> M>>N;
	unordered_map<string, string> hashmap1;
	unordered_map<string, string> hashmap2;
	unordered_map<string,int> mask;
	cin.get();
	for (int i = 0; i <M; i++){
		int ccc = 0;
		string s;
		
		getline(cin, s);
		string tmp = "";
		string tmp1 = "";
		string tmp2 = "";
		string tmp3 = "";
		for (int i = 0; i < s.size(); i++)
		{	
			if (s[i] == ' ')
			{
				tmp1 = tmp;
				tmp.clear();
				i++;
			}
			if (s[i] == '/')
			{
				ccc = 1;
				tmp2= tmp;
				tmp.clear();
				i++;
			}
			tmp += s[i];
		}
		if (ccc ==1)
		{
			tmp3= tmp;
			hashmap2[tmp2] = tmp1;
			stringstream os;
			int n;
			os<<tmp3;
			os >> n;
			mask[tmp2]=n;
		}
		else
		{
			tmp2 = tmp;
			hashmap1[tmp2] = tmp1;
		}		
	}

	for (int i = 0; i < N; i++)
	{
		string s;
		string allow = "allow";
		string deny = "deny";
		getline(cin, s);
		for (auto r : hashmap1)
		{
			if ((r.first == s))
			{
				flag = 1;
				flag1 = 1;
				if (r.second ==allow)
				{
					cout << "Yes" << endl;
					break;
				}
				else
				{
					cout << "No" << endl;
					break;
				}
			}
			
		}
		for (auto r : hashmap2)
		{
			if (flag1 == 1)
				break;
			if (maskN(r.first, mask[r.first]) == maskN(s, mask[r.first]))
			{
				flag = 1;
				if (r.second == "allow")
				{
					cout << "Yes" << endl;
					break;
				}
				if (r.second == "deny")
				{
					cout << "No" << endl;
					break;
				}
			}
		}
		if (flag==0)
			cout << "Yes" << endl;
		flag =0;
		flag1 = 0;
	}
}
