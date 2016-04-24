/*继承*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

class Rectangle{
protected://不能是private
	int width;
	int height;
public:
	void Display()
	{
		cout<<width<<' '<<height<<endl;     
	}
};
class RectangleArea:public Rectangle{
public:
	void Input(){
		cin>>width>>height;
	}
	void Display(){//非虚函数情况下，这是函数的覆盖
		cout<<width*height<<endl;
	}
};
int main() {
	RectangleArea r_area;
	r_area.Input();
	Rectangle *r;
	r=&r_area;
	r->Display();
	r_area.Display();
	system("pause");
	return 0;
}



/*单继承*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Triangle{
public:
	void triangle(){
		cout<<"I am a triangle\n";
	}
};

class Isosceles : public Triangle{
public:
	void isosceles(){
		cout<<"I am an isosceles triangle\n";
	}
	void triangle(){
		cout<<"I am a triangle\n";
	}
};
class  Equilateral:public Isosceles{
public:
	void  equilateral()
	{
		cout<<"I am an equilateral triangle"<<endl;
	}
};

//Write your code here.
int main(){

	Equilateral eqr;
	eqr.equilateral();
	eqr.isosceles();
	eqr.triangle();
	system("pause");
	return 0;
}


/*多重继承*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include<map>
using namespace std;
using namespace std;
#include<iostream>

using namespace std;

int callA=0;
int callB=0;
int callC=0;
class A
{
protected:
	void func(int  & a)
	{
		a=a*2;
		callA++;
	}
};
class B
{
protected:
	void func(int & a)
	{
		a=a*3;
		callB++;
	}
};
class C
{
protected:
	void func(int & a)
	{
		a=a*5;
		callC++;
	}
};
class D :public A,public B,public  C
{

	int val;
public:
	//Initially val is 1
	D()
	{
		val=1;
	}


	//Implement this function
	void update_val(int new_val)
	{
		int a=new_val;
		while(a%2==0)
		{
			a=a/2;
			A::func(val);
		}
		while(a%3==0)
		{
			a=a/3;
			B::func(val);

		}
		while(a%5==0)
		{
			a=a/5;
			C::func(val);
		}
	}
	//For Checking Purpose
	void check(int); //Do not delete this line.
};
void D::check(int new_val)
{
	update_val(new_val);
	cout<<"Value = "<<val<<endl<<"A's func called "<<callA<<" times "<<endl<<"B's func called "<<callB<<" times "<<endl<<"C's func called "<<callC<<" times"<<endl;
}


int main()
{

	D d;
	int new_val;
	cin>>new_val;
	d.check(new_val);

	system("pause");
}

/*重载矩形加法运算符*/
class matrix{
public:
	matrix& operator+(matrix& x){
		int m = x.a.size();
		int n = x.a[0].size();
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				(*this).a[i][j] = (*this).a[i][j] + x.a[i][j];
			}
		}
		return *this;
	}
	vector<vector<int>> a;

};
