class Solution {
public:
  string longestPalindrome(string s) {
	if(s.size()<=1)
		return s;
	string Tmp="^";
	for(int i=0;i<s.size();i++)
	{
		Tmp+="#"+s.substr(i,1);
	}
	Tmp+="#*";
	int Len=Tmp.size();
	int C=0;
	int R=0;
	int maxlen=0;
	int pos=0;
	vector<int> foo(Len,0);
	for(int i=1;i<Tmp.size()-1;i++)
	{
		int radius=2*C-i;
		foo[i]=i<R? min(foo[radius],R-i):0;
		while(Tmp[foo[i]+i+1]==Tmp[i-foo[i]-1])
		{
			foo[i]++;
		}
		if(i+foo[i]>R)
		{
			C=i;
			R=foo[i]+i;
		}
		if(foo[i]>maxlen)
		{
			maxlen=foo[i];
			pos=i;
		}
	}
	
	string res="";
	for(int j=pos-maxlen;j<=pos+maxlen;j++)
	{
		if((Tmp[j]<='z'&&Tmp[j]>='a')||(Tmp[j]<='Z'&&Tmp[j]>='A')||(Tmp[j]<='9'&&Tmp[j]>='0'))
			res+=Tmp[j];
	}
	return res;
	
}
};
