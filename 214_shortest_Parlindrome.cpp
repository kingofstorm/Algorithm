class Solution {
public:
     string shortestPalindrome(string s) {
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
	}
	int maxlen=0;
	for(int i=0;i<Tmp.size();i++)
		if(i-foo[i]==1)
			maxlen=max(foo[i],maxlen);

	string append=s.substr(maxlen,s.size()-maxlen);
	reverse(append.begin(),append.end());
	return append+s;
}
};
