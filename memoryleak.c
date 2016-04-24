/*
  vs平台内存泄露的检测


*/

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <iostream>
using namespace std;

void GetMemory(char *p, int num)
{
	p = (char*)malloc(sizeof(char) * num);
}

int main(int argc,char** argv)
{
	char *str = NULL;
	GetMemory(str, 100);
	

	cout<<"Memory leak test!"<<endl;
		_CrtDumpMemoryLeaks();
	system("pause");
	return 0;
}

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>

using namespace std;

_CrtMemState s1, s2, s3;

void GetMemory(char *p, int num)
{
	p = (char*)malloc(sizeof(char) * num);
}

int main(int argc,char** argv)
{
	_CrtMemCheckpoint( &s1 );
	char *str = NULL;
	GetMemory(str, 100);
	_CrtMemCheckpoint( &s2 );
	if ( _CrtMemDifference( &s3, &s1, &s2) )
		_CrtMemDumpStatistics( &s3 );
	cout<<"Memory leak test!"<<endl;
	_CrtDumpMemoryLeaks();
	system("pause");
	return 0;
}
