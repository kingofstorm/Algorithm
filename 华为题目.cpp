
/*2-35进制加法，大数相加*/
#include<iostream>
#include<string>
using namespace std;
int N_To_Int(string src, int N);
string Int_to_N(int src, int N);
string revert(string s)
{

	for (int i = 0, j = s.size() - 1; i < j; i++, j--)
	{
		char tmp;
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
	}
	return s;
}
int main()
{
	int N;
	cin >> N;
	if (N > 35)
	{
		cout << -1;
		return 0;
	}	
	string s1 = "";
	string s2 = "";
	cin >> s1 >> s2;

	s1=revert(s1);
	s2=revert(s2);


	string result = "";
	int lenght1 = s1.size();
	int lenght2 = s2.size();

	int max = lenght1 > lenght2 ? lenght1 : lenght2;
	if (lenght1<lenght2)
		for (int i = 0; i<lenght2 - lenght1; i++)
			s1 += '0';
	if (lenght1>lenght2)
		for (int i = 0; i<lenght1 - lenght2; i++)
			s2+= '0';
	int carry = 0;
	for (int i = 0; i <max;i++)
	{
		int x;
		if (s1[i]>'9')
			x = s1[i] - 'a' + 10;
		else
			x = s1[i] - '0';
		int y = ((s2[i]>'9')? s2[i] - 'a'+10 : s2[i] - '0');
		int a=x+y+carry;
		carry = a/N;
		a = a%N;
		char b = a > 9 ? a + 'a' - 10 : a + '0';
		result+= b;
	}	
	string s_carry = "";
	if (carry > 0)
		s_carry = carry + '0';
	result += s_carry;
	result = revert(result);
	cout << result << endl;
	return 0;
}

/*此解法不适合N进制加法，
调用了pow函数，开销过大!!!!!!!!!!!
*/
#include<iostream>
#include<string>
using namespace std;
int N_To_Int(string src, int N);
string Int_to_N(int src, int N);
int main()
{
	int N;
	cin >> N;
	if (N > 35)
	{
		cout << -1;
		return 0;

	}

	string s="";
	string s1="";
	cin >> s;
	cin>> s1;
	int result = N_To_Int(s,N) + N_To_Int(s1,N);
	string res = Int_to_N(result,N);
	cout << res << endl;
	return 0;
}

int N_To_Int(string src,int N)//任意N进制数转换成10进制整数
{
	int le = src.size();
	int  tmp=0;
	for (int i = 0; i < le; i++)
		tmp += (src[i]<='9'? src[i]-'0':src[i]-'a'+10)* pow(N, le - i - 1);
		
	return tmp;

}
/*10进制数转换成任意N进制*/
string Int_to_N(int src,int N)
{
	int i = N;
	string tmp="";
	int Ns;//余数
	int Nt;//商
	while (src/i)
	{
		Ns = src%i;
		Nt = src /i;
		char N_char = (Ns >= 10 ? Ns + 'a' - 10 : Ns+'0');
		tmp +=N_char;
		src= src/i;
	}
	char r = ((src%N) >= 10 ? src%N + 'a' - 10 : src%N+'0');
	tmp+= r;
	for (int i = 0, j = tmp.size() - 1; i < j; i++, j--)
	{
		char res;
		res = tmp[i];
		tmp[i] = tmp[j];
		tmp[j] = res;
	}
	return tmp;
}

/*华为笔试题
小明是个马大哈，某天他到超市买了若干双筷子(n 小于 20)
筷子的长度不尽相同，他把全部筷子都放在购物袋里面拿回家，路上不小心漏了一根
请你用程序帮他找出漏掉的筷子是多长的。
输入：  
参数一：剩下的筷子的长度值的数组，例如：1, 2, 3, 2, 1, 3, 2，(筷子的长度必然大于0, 不需要校验)
参数二：数组的元素的数量；
返回值：漏掉的筷子的长度，如上述输入返回：2
当输入的筷子数据异常时返回-1，如：找不到漏掉的筷子
如果漏掉了多根筷子，返回任意一根漏掉的筷子即可。
这个题目有点容易误解的地方就是：n小于20，n到底是n双，还是n根。
*/
#include <stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<unordered_map>
#include<algorithm>
using namespace std;

int main()
{
	int size;
	int tmp;
	cin >> size;
	if (size >=20 || size < 0)
	{
		cout << "-1";
		return 0;
	}
	vector<int>  foo;
	
	for (int i = 0; i < size; i++)
	{
		cin >> tmp;
		foo.push_back(tmp);
	}
	unordered_map<int, int> hash;
	int result_num=-1;
	for (auto r : foo)
		hash[r]++;
	for (auto r : hash)
	{
		if (r.second == 1)
		{
			result_num = r.first;
			break;
		}
	}

	cout << result_num ;
	return 0;

}

/*输入一个十进制的正整数，从低位开始查找，找到第一个置位（1）比特的位置
按照如下规则对正整数进行置位比特的查找：
1. 当查找失败时，比如输入正整数0，返回-1
2. 当查找成功时，返回该比特的位置
例子：
比如 如入12，二进制表示是0000000000001100，则第一个置位比特为2
*/


/*注意使用long long 类型*/

#include <stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<unordered_map>
#include<algorithm>
using namespace std;


int find_low_bit(long long number)
{
	 long long min = 1;
	 long long max = ( min<< 62);
	 if (number > max)
		return -1;
	 long long input_number=number;
	if (input_number <= 0)
	{
		return -1;
	}
	int count = 0;
	long long  foo = 1;
	/*注意不要用(input_number&foo)!=1    错的*/
	while (!(input_number&foo))
	{
		count++;
		foo <<= 1;
	}
	return count;
}
int main()
{
	 /*long long rr= 1;
		rr= rr<< 63;*/
	//unsigned long long  rr= 18446744073709551615;
	//cout << rr << endl;
	long long in;
	cin >> in;
	cout<< find_low_bit(in);
	
	return 0;
}

/*
华为简易排号机


*/

#include <stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<unordered_map>
#include<algorithm>
#include<queue>
using namespace std;
void wait_Machine_for_bank(void)
{
	
	int N_max = 10000;
	int N = 0;
	int N_normal = 0;
	int N_vip = 0;
	queue<int> q_normal;
	queue<int> q_vip;
	string s;
	while (1)
	{
		int global = -1;
		getline(cin,s);
		if (s == "get")
		{
			global = 1;
			N++;
			N_normal = N;
			q_normal.push(N_normal);
			cout << N << endl;
		}
		if (s == "get vip")
		{
			global = 1;
			N++;
			N_vip = N;
			q_vip.push(N_vip);
			cout << "vip " << N << endl;
		}
		if (s == "call")
		{
			global = 1;
			if (!q_vip.empty())
			{
				cout << "vip "<<q_vip.front() << endl;
				q_vip.pop();
			}
			else
			{
				if (q_normal.empty())
					cout << "error" << endl;
				else
				{
					cout << q_normal.front() << endl;
					q_normal.pop();
				}
			}
		}
		if ((s.size() >= 7 && s[0] == 'd') && (s[5] = 'e')&&s[2]=='l'&&s[3]=='e'&&s[4]=='t')
		{
			global = 1;
			int count_state = -1;
			int count_state1 = -1;
			string ss = "";
			for (int i = 7; i < s.size(); i++)
			{
				if ('0' <= s[i] && s[i] <= '9')
				{
					ss += s[i];
				}
				else
				{
					cout << "error" << endl;
					count_state = 1;
				}
				count_state1 = 1;
			}
			if (count_state == 1)
				continue;
			if (count_state1 == -1)
			{

				cout << "error" << endl;
				continue;

			}
			
			int Num;
			stringstream os;
			os << ss;
			os >> Num;
			os.clear();
		
			int state = -1;
			//int size = q_normal.size();
			queue<int> tmp;
			while (!q_normal.empty())
			{
				if (q_normal.front() != Num)
				{
					tmp.push(q_normal.front());
					q_normal.pop();
				}
				else{
					cout << q_normal.front() << endl;
					q_normal.pop();
					state += 1;
				}
			}
			q_normal = tmp;
			queue<int> tmp1;
			while (!q_vip.empty())
			{
				if (q_vip.front() != Num)
				{
					tmp1.push(q_vip.front());
					q_vip.pop();
				}
				else{
					cout << "vip "<<q_vip.front() << endl;
					q_vip.pop();
					state += 1;
				}
			}
			q_vip= tmp1;
			if (state == -1)
			{
				cout << "error" << endl;
			}

		}
		if (s == "count")
		{
			global = 1;
			int  number = q_normal.size() + q_vip.size();
			cout << number << endl;
		}
		if ((s.size()>=6&&s[5]=='N')&&s[0]=='c'&&s[1]=='o'&&s[2]=='u'&&s[3]=='n'&&s[4]=='t')
		{
			global = 1;
			int count_state = -1;
			int count_state1 = -1;///判断有没有进入for
			string ss="";
			for (int i = 7; i < s.size(); i++)
			{
				if ('0' <= s[i] && s[i] <= '9')
				{
					ss += s[i];
				}
				else
				{
					cout << "error" << endl;
					count_state = 1;
				}
				count_state1 = 1;
			}
			if (count_state == 1)
				continue;
			if (count_state1 == -1)
			{
			
				cout << "error" << endl;
				continue;
				
			}
			int N;
			stringstream os;
			os << ss;
			os >> N;
			os.clear();
			int num1 = 0;
			int num2 = 0;
			queue<int> tmp1;
			queue<int> tmp2;
			while (!q_normal.empty())
			{
				if (q_normal.front() <=N)
				{
					num1++;
					tmp1.push(q_normal.front());
					q_normal.pop();
				}
				else
				{
					tmp1.push(q_normal.front());
					q_normal.pop();	
				}
				
			}
			q_normal = tmp1;

			while (!q_vip.empty())
			{
				if (q_vip.front() <=N)
				{
					num2++;
					tmp2.push(q_vip.front());
					q_vip.pop();
				}
				else
				{
					tmp2.push(q_vip.front());
					q_vip.pop();
				}

			}
			q_vip = tmp2;
			cout << (num1 + num2) << endl;
		}
		if (s == "quit")
			break;
		if (s == "reset")
		{
			 global = 1;
			 N_max = 10000;
			 N = 0;
			 N_normal = 0;
		     N_vip = 0;
			while (!q_normal.empty())
			{
				q_normal.pop();
			}
			while (!q_vip.empty())
			{
				q_vip.pop();
			}

		}
		if (global ==-1)
			cout << "error"<<endl;
	}
}
int main()
{
	wait_Machine_for_bank();
	return 0;

}

/*IP地址转换
测试用例7/1

*/

#include<iostream>
#include<string>
#include<sstream>
using namespace std;

void ip_transformer(int num)
{
	unsigned int number = num;
	string s1;
	string s = "0x";
	while (number)
	{
		int tmp = number % 16;
		switch(tmp)
		{case 10:
			s1 = "A";
			break;
		case 11:
			s1 = "B";
			break;
		case 12:
			s1 = "C";
			break;
		case 13:
			s1 = "D";
			break;
		case 14:
			s1 = "E";
			break;
		case 15:
			s1 = "F";
			break;
		default:
			s1 = to_string(tmp);
			break;
		}
		s+= s1;
		number = number / 16;
	}
	for (int i= s.size()-1,j = 2; i > j; i--, j++)
	{
		char tmp;
		tmp=s[j];
		s[j] = s[i];
		s[i] = tmp;
		
	}
	
	string res = "";
	string result = "";
	int tmp=0;
	int count = 1;
	for (int i = 2; i < s.size();)
	{
		
		if ((s[i] >= '0') && (s[i] <= '9'))
			tmp = tmp+(s[i] - '0') ;
		else
			tmp = tmp + (s[i] - 'A' + 10) * 16;
		if (s[i+1] >= 'A'&&s[i+1] <= 'E')
			tmp = tmp + (s[i+1] - 'A' + 10) * 16;
		else
			tmp = tmp + (s[i+1] - '0');
		i += 2;
		stringstream os;
		os << tmp;
		os >> res;
		tmp = 0;
		result += res;
		if (count < 4)
		{
			result += '.';
			count++;
		}
	}



	cout << result<< endl;
}

int main()
{

	unsigned int num ;
	cin >> num;
	ip_transformer(num);
	return 0;
}
/*成都麻将胡牌判定*/
#include<iostream>
#include<string>
#include<sstream>
#include<map>
#include<unordered_map>
using namespace std;
int main()
{
	//string s = "1T2T3T4T6T1W2W3W5D6D7D8D8D";
	//string s = "1T8T6W6W5D4W1T3W6W2W5D6T1T";
	
	string s;
	cin >> s;
	int global_count = 0;
	map<int, int> T;
	map<int, int> D;
	map<int, int> W;
	for (int i = 1; i <= 9; i++)
		W[i] = 0;
	for (int i = 1; i <= 9; i++)
		T[i] = 0;
	for (int i = 1; i <= 9; i++)
		D[i] = 0;
	for (int i = 0; i < s.size();)
	{
		if (s[i + 1] == 'T')
			T[s[i] - '0']++;
		if (s[i + 1] == 'D')
			D[s[i] - '0']++;
		if (s[i + 1] == 'W')
			W[s[i] - '0']++;
		i += 2;

	}
	map<int, int>::iterator t = T.begin();
	map<int, int>::iterator d = D.begin();
	map<int, int>::iterator w = W.begin();


	////////////////////////////////处理T
	int ppre;
	int pre;

	vector<int> tmpT;
	for (auto a : T)
		tmpT.push_back(a.second);

	bool state = true;
	while (state)
	{
		ppre = tmpT[0];
		pre = tmpT[1];
		state = false;
		for (int i = 2; i < 9; i++)
		{
			if (ppre == 1 && pre == 0 && tmpT[i] == 1)
			{
				if (i + 2 < 9)
				{
					i = i + 2;
					ppre = tmpT[i - 1];
					pre = tmpT[i];
					continue;
				
				}
			}

			if (ppre >= 1 && pre >= 1 && tmpT[i] >= 1)
			{
				tmpT[i - 2] -= 1;
				tmpT[i - 1] -= 1;
				tmpT[i] -= 1;
				state = true;
			}
			ppre = tmpT[i - 1];
			pre = tmpT[i];
		}
	}
	

	////////////////////////////D////////////////
	vector<int> tmpD;
	for (auto a : D)
		tmpD.push_back(a.second);
	

	state = true;
	while (state)
	{
		ppre = tmpD[0];
		pre = tmpD[1];
		state = false;
		for (int i = 2; i < 9; i++)
		{

			if (ppre == 1 && pre == 0 && tmpD[i] == 1)
			{
				if (i + 2 < 9)
				{
					i = i + 2;
					ppre = tmpD[i - 1];
					pre = tmpD[i];
					continue;

				}
			}
			if (ppre >= 1 && pre >= 1 && tmpD[i] >= 1)
			{
				tmpD[i - 2] -= 1;
				tmpD[i - 1] -= 1;
				tmpD[i] -= 1;
			}
			ppre = tmpD[i - 1];
			pre = tmpD[i];
		}
	}
	for (int i = 0; i < 9; i++)
	if (tmpD[i] >= 3)
		tmpD[i] -= 3;

	//////////////////////////W////////////////////////
	vector<int> tmpW;
	for (auto a : W)
		tmpW.push_back(a.second);
	state = true;
	while (state)
	{
		ppre = tmpW[0];
		pre = tmpW[1];
		state = false;
		for (int i = 2; i < 9; i++)
		{
			if (ppre == 1 && pre == 0 && tmpW[i] == 1)
			{
				if (i + 2 < 9)
				{
					i = i + 2;
					ppre = tmpW[i - 1];
					pre = tmpW[i];
					continue;

				}
			}
			if (ppre >= 1 && pre >= 1 && tmpW[i] >= 1)
			{
				tmpW[i - 2] -= 1;
				tmpW[i - 1] -= 1;
				tmpW[i] -= 1;
			}
			ppre = tmpW[i - 1];
			pre = tmpW[i];
		}
	}
	
	for (int i = 0; i < 9; i++)
	if (tmpW[i] >= 3)
		tmpW[i] -= 3;

	//////////////////////////


	///////////////////////糊三条
	ppre = tmpT[0];
	pre = tmpT[1];
		for (int i = 2; i < 9; i++)
		{
			if (ppre == 1 && pre == 1 && tmpT[i] == 0)////////////////////
			{
				if (i>2 && i < 8)
				{
					cout << 2 << endl;//两种
					cout << i - 2 << "T" << i + 1 << "T" << endl;
					global_count = 1;
					break;
				}
				else{
				
					cout << i + 1 << "T" << endl;
					global_count = 1;
					break;
				}
				
			}
			if(ppre==1 && pre == 0 && tmpT[i] == 1)////////////只能有一种可能
			{
				cout << 1 << endl;
				cout << i<< "T" << endl;
				global_count = 1;
				break;
			}
			if (ppre ==0&& pre == 1 && tmpT[i] == 1)//////////////
			{
				if (i>=2 && i< 8)
				{
					cout << 2 << endl;//两种
					cout << i - 1 << "T" << i + 2 << "T" << endl;
					global_count = 1;
					break;
				}
				else{
					cout << i - 1 << "T" << endl;
					global_count = 1;
					break;
				}


			
			}
			ppre = tmpT[i - 1];
			pre = tmpT[i];
		}
///////////////////////////////////////////////
		ppre = tmpD[0];
		pre = tmpD[1];
		for (int i = 2; i <9; i++)
		{
			if (ppre == 1 && pre == 1 && tmpD[i] == 0)
			{
				if (i>2 && i < 8)
				{
					cout << 2 << endl;//两种
					cout << i - 2 << "D" << i + 1 << "D" << endl;
					global_count = 1;
					break;
				}
				else{

					cout << i + 1 << "D" << endl;
					global_count = 1;
					break;
				}
			}
			if (ppre == 1 && pre == 0 && tmpD[i] == 1)
			{
				cout << i << "D" << endl;
				global_count = 1;
				break;
			}
			if (ppre == 0 && pre == 1 && tmpD[i] == 1)
			{
				if (i >= 2 && i< 8)
				{
					cout << 2 << endl;//两种
					cout << i - 1 << "D" << i + 2 << "D" << endl;
					global_count = 1;
					break;
				}
				else{
					cout << i - 1 << "D" << endl;
					global_count = 1;
					break;
				}
			}
			ppre = tmpD[i - 1];
			pre = tmpD[i];
		}
///////////////////////////////////////////////////////////////
		ppre = tmpW[0];
		pre = tmpW[1];
		for (int i = 2; i <9; i++)
		{
			if (ppre == 1 && pre == 1 && tmpW[i] == 0)
			{
				if (i>2 && i < 8)
				{
					cout << 2 << endl;//两种
					cout << i - 2 << "W" << i + 1 << "W" << endl;
					global_count = 1;
					break;
				}
				else{

					cout << i + 1 << "W" << endl;
					global_count = 1;
					break;
				}
			}
			if (ppre == 1 && pre == 0 && tmpW[i] == 1)
			{
				cout << i << "W" << endl;
				global_count = 1;
				break;
			}
			if (ppre == 0 && pre == 1 && tmpW[i] == 1)
			{
				if (i >= 2 && i< 8)
				{
					cout << 2 << endl;//两种
					cout << i - 1 << "W" << i + 2 << "W" << endl;
					global_count = 1;
					break;
				}
				else{
					cout << i - 1 << "W" << endl;
					global_count = 1;
					break;
				}
			}
			ppre = tmpW[i - 1];
			pre = tmpW[i];
		}

  ////////////////////////////////
	
	//糊对子
		string res = "";
		vector<int> res1;
		int countN = 0;
		for (int i = 0; i < 9;i++ )
		{
			if (tmpT[i] == 2)
			{

				countN++;
				if (countN == 2)
				{
					cout << 2 << endl;
					cout << res1[0] << res<<i+1<<"T"<< endl;
					global_count = 1;
					break;
				}
				else
				{
					res += "T";
					res1.push_back(i + 1);
				}
			}
			
		}
		for (int i = 0; i < 9;i++)
		{
			if (tmpD[i] == 2 )
			{
				countN++;
				if (countN == 2)
				{
					cout << 2 << endl;
					cout << res1[0] << res << i + 1 << "D" << endl;
					global_count = 1;
					break;
				}
				else{
					res += "T";
					res1.push_back(i + 1);
				}
			}
			
		}

		for (int i = 0; i < 9; i++)
		{
			if (tmpW[i] == 2)
			{
				countN++;
				if (countN == 2)
				{
					cout << 2 << endl;
					cout << res1[0] << res << i + 1 << "W" << endl;
					global_count = 1;
					break;
				}
				else{
					res += "T";
					res1.push_back(i + 1);
				}
			}		
		}

///////////////////////////糊单个//////////////////////////
		if (global_count == 0)
		{
			int i = 0;
			for (auto r : tmpT)
			{
				i++;
				if (r == 1)
				{
					cout << 1 << endl;
					cout << i << "T" << endl;
				}
			}
			int j = 0;
			for (auto r : tmpD)
			{
				j++;
				if (r == 1)
				{
					cout << 1 << endl;
					cout << j << "D" << endl;
				}
			}
			int k = 0;
			for (auto r : tmpW)
			{
				k++;
				if (r == 1)
				{
					cout << 1 << endl;
					cout << k << "W" << endl;
				}
			}
		}
	return 0;
}
















//int count1 = 0;///三条
//int count2 = 0;//对子
//int count3 = 0;
//int sum = 0;
//int tmp = 0;
//while (t != T.end())
//{

//	if ((*t).second > 0)
//	{
//		sum++;
//		if (sum == 3)
//		{
//			count1 += 1;
//			sum = 0;
//		}
//		//(*t).second--;
//	}
//	else
//		sum = 0;
//	if ((*t).second == 2)
//	{
//		count2++;
//	}
//	if ((*t).second == 3)
//	{
//		count3++;
//	}
//	t++;
//}
//cout << count1 << endl;
//while (d != D.end())
//{
//	if ((*d).second == 1)
//	{
//		sum++;
//		if (sum == 3)
//		{
//			count1 += 1;
//			sum = 0;
//		}
//	}
//	if ((*d).second != 1)
//		sum = 0;
//	if ((*d).second == 2)
//	{
//		count2++;
//	}
//	if ((*d).second == 3)
//	{
//		count3++;
//	}
//	d++;
//}
//while (w != W.end())
//{
//	if ((*w).second == 1)
//	{
//		sum++;
//		if (sum == 3)
//		{
//			count1 += 1;
//			sum = 0;
//		}
//	}
//	else
//		sum = 0;
//	//((*w).second != 1)

//	if ((*w).second == 2)
//	{
//		count2++;
//	}
//	if ((*w).second == 3)
//	{
//		count3++;
//	}
//	w++;
//}





//for (auto r : tmpT)
//cout << "T " << r << endl;
//for (auto r : tmpD)
//cout << "D " << r << endl;
//
//for (auto r : tmpW)
//cout << "W " << r << endl;
/*for (auto a : T)
cout << "T"<<a.first << " "<<a.second << endl;
cout << endl;
for (auto a : D)
cout << "D"<<a.first << " " << a.second << endl;
cout << endl;
for (auto a : W)
cout << "W"<<a.first << " " << a.second << endl;
cout << endl;*/
//if (count1 == 3 && count2 == 1)
//{
//	cout << "三个" << endl;
//}
//if (count1 == 4 && count2 == 0)
//{
//	cout << "对子" << endl;
//}
