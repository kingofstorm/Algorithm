#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<cstdlib>
#include<cstdio>
#include<vector>
int lay = 1;
using namespace std;
/*Vertices are numbered form 0*/
#define NotAvertex (-1)
#define NumVertex (100)
#define Infinity  (2<<30)
#define MaxVertexNum 100
int Visited[1000];
int Nv=0;
vector<int> list;
int state = -1;
typedef unsigned int Vertex;
typedef unsigned int WeightType;
/////
struct AdjVNode{
	Vertex AdjV;
	WeightType Weight;
	struct AdjVNode* Next;

};
typedef struct AdjVNode *PtrToAdjVNode;

typedef struct Vnode{
	PtrToAdjVNode FirstEdge;
	//DataType Data;
} AdjList[MaxVertexNum];

struct GNode
{
	int Nv;//顶点数
	int Ne;//边数
	AdjList G;//邻接表
};
typedef struct GNode *PtrToGNode;
typedef PtrToGNode LGraph;

////////节点//////////////

struct ENode   
{
	Vertex V1, V2;
	WeightType Weight;
};
typedef struct ENode  *PtrToENode;
typedef PtrToENode Edge;
/////初始化有顶点但没有边的图
LGraph CreateGraph(int VertexNum)
{
	Vertex V;
	LGraph Graph;
	Graph = (LGraph)malloc(sizeof(struct GNode));
	Graph->Nv= VertexNum;
	Graph->Ne = 0;
	for (V = 0; V < Graph->Nv; V++)
		Graph->G[V].FirstEdge = NULL;

	return Graph;
}

void InsertEdge(LGraph Graph, Edge E)
{
	PtrToAdjVNode NewNode;
	/*************插入边<V1,V2>**/
	/*为V2建立新节点*/
	NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->AdjV = E->V2;
	//NewNode->Weight = E->Weight;
	////////将V1插到V2的表头///////
	NewNode->Next = Graph->G[E->V1].FirstEdge;
	Graph->G[E->V1].FirstEdge = NewNode;
}
/*建立图*/
LGraph BuildGraph(vector<vector<int>>& in_put)
{
	LGraph Graph;
	Edge E;
	//Vertex V;
	int i;
	for (int i = 0; i <Nv; i++)
		Visited[i] =-1;
	/*for (int i = 0; i < Nv; i++)
		cout << Visited[i] << " ";
	cout << endl;*/

	Graph = CreateGraph(Nv);
	Graph->Ne = Nv;
	//scanf("%d", &(Graph->Ne));
	cout << "边：" <<Graph->Ne<<endl;
	if (Graph->Ne != 0)
	{
		E = (Edge)malloc(sizeof(struct GNode));
		for (i = 0; i < Graph->Ne; i++)
		{
			E->V1 =in_put[i][1];
			E->V2 =in_put[i][2] ;
			E->Weight =in_put[i][3] ;
			InsertEdge(Graph, E);
		}
	}


	return Graph;
}
void Visit(Vertex V)
{
	printf("正在访问顶点%d\n", V);
}

/* Visited[]为全局变量，已经初始化为false */
void DFS(LGraph Graph, Vertex V_begin/*, void(*Visit)(Vertex),*/,Vertex& destination_V)
{   /* 以V为出发点对邻接表存储的图Graph进行DFS搜索 */
	cout << lay++ << endl;
	if (state == 1)
		return;
	PtrToAdjVNode W;
	//Visit(V_begin);/* 访问第V个顶点 */
	list.push_back(V_begin);
	Visited[V_begin] =V_begin; /* 标记V已访问 */
	if (V_begin == destination_V)
	{
		for (auto r : list)
			cout << r << "|";
		/*for (int i = 0; i <Nv; i++)
		if (Visited[i] != -1)
			cout << Visited[i]<<"|";*/
		cout << endl;
		state = 1;
	}
	for (W = Graph->G[V_begin].FirstEdge; W; W = W->Next) /* 对V的每个邻接点W->AdjV */
		if (Visited[W->AdjV]==-1)    /* 若W->AdjV未被访问 */
			DFS(Graph, W->AdjV,destination_V);    /* 则递归访问之 */
}
int main()
{
	cout << "Hello world!" << endl;
	ifstream pp("C:\\topo1.csv");
	string s;
	vector<vector<int>> in_put;
	stringstream os;
	while (getline(pp, s))
	{
		//cout << s << endl;
		vector<int> tmp(4,0);
		string stmp;
		int j = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] != ',')
			{
				stmp += s[i];
			}
			else{
				
				os << stmp;
				os >> tmp[j++];
				os.clear();
				stmp.clear();
			}
		}
		os << stmp;
		os >> tmp[j++];
		os.clear();
		stmp.clear();
		in_put.push_back(tmp);
		//cout << s << endl;
		Nv++;
		//po << s << endl;
	}
	/*for (auto r : in_put)
	{
		for (auto b : r)
			cout << b<<" ";
		cout << endl;
	}*/
	cout << "顶点：" << Nv << endl;
	Vertex destination_V;
	Vertex begin;
	cout << "起点：";
	cin >> begin;
	cout << "输入目的点：";
	cin >> destination_V;



	LGraph test=BuildGraph(in_put);
	DFS(test,begin,destination_V);

	//ofstream po("C:\\out.csv");
	

	return 0;
}















//
//using namespace std;
//typedef unsigned int DistType;
//typedef int Vertex;
//void ReadGraph(Graph G, Table T);
//
//typedef struct TableEntry
//{
//	List Header;
//	int Known;
//	DistType Dist;
//	Vertex Path;
//
//};
//typedef struct TableEntry Table[NumVertex];
//void InitTable(Vertex Start,Graph G,Table T)
//{
//	int i;
//	ReadGraph(G, T);
//	for (int i = 0; i < NumVertex; i++)
//	{
//		T[i].Known = false;
//		T[i].Dist =Infinity;
//		T[i].Path = NotAvertex;
//
//	}
//	T[Start].Dist = 0;
//}
///***/
//void PrintPath(Vertex V,Table T){
//	if (T[V].Path != NotAvertex)
//	{
//		PrintPath(T[V].Path, T);
//			printf(" to");
//
//	}
//	printf("%d", V);
//
//}
//
//
//void Dijkstra(Table T)
//{
//	Vertex V, W;
//	for (;;)
//	{
//		V = smallest unkonw distance;
//		if (V == NotAvertex)
//			break;
//		T[V].Known = true;
//		for each W adjacent to V
//			if (!T[W].Known)
//				if ()
//
//	}
//
//
//}
//
//
//int main()
//{
//	/*string s1 = "14";
//	s1 += '5';
//	char a = 'f';
//	char b = 'a';
//	int c = 'z'%b;
//	string s;
//	os << c;
//	os >> s;
//	cout << s << endl;*/
//
//	stringstream os;
//	char N = 'g';
//	string s1 = "1a";
//	string s2 = "3f";
//	string res = "";
//	int i = 0;
//	int carry=0;
//	int sum=0;
//	//string ssum;
//	int n = N - 'a'+10;
//	while (i<s1.size()&& i<s2.size())
//	{
//		 char ssum;
//		 sum = (s1[i] + s2[i])%n+carry;
//		 carry = (s1[i] + s2[i])/n;
//		 if (sum>=0&&sum<10)
//			 ssum= sum + '0';
//		 else
//		 {
//			 ssum = sum - 10 + 'a';
//		 }
//		 res += ssum;
//		 i++;
//
//	}
//	cout << res << endl;
//
//
//	return 0;
//}
/*3.31*/




/*codecraft*/
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<cstdlib>
#include<cstdio>
#include<vector>
int lay = 1;
using namespace std;
/*Vertices are numbered form 0*/
#define NotAvertex (-1)
#define NumVertex (100)
#define Infinity  (2<<30)
#define MaxVertexNum 100
int Visited[50];
int Nv=0;
int ne = 0;
vector<int> list;
int state = -1;
typedef unsigned int Vertex;
typedef unsigned int WeightType;
/////
struct AdjVNode{
	Vertex AdjV;
	WeightType Weight;
	struct AdjVNode* Next;

};
typedef struct AdjVNode *PtrToAdjVNode;

typedef struct Vnode{
	PtrToAdjVNode FirstEdge;
	//DataType Data;
} AdjList[MaxVertexNum];

struct GNode
{
	int Nv;//顶点数
	int Ne;//边数
	AdjList G;//邻接表
};
typedef struct GNode *PtrToGNode;
typedef PtrToGNode LGraph;

////////节点//////////////

struct ENode   
{
	Vertex V1, V2;
	WeightType Weight;
};
typedef struct ENode  *PtrToENode;
typedef PtrToENode Edge;
/////初始化有顶点但没有边的图
LGraph CreateGraph(int VertexNum)
{
	Vertex V;
	LGraph Graph;
	Graph = (LGraph)malloc(sizeof(struct GNode));
	Graph->Nv= VertexNum;
	Graph->Ne = 0;
	for (V = 0; V < Graph->Nv; V++)
		Graph->G[V].FirstEdge = NULL;

	return Graph;
}

void InsertEdge(LGraph Graph, Edge E)
{
	PtrToAdjVNode NewNode;
	/*************插入边<V1,V2>**/
	/*为V2建立新节点*/
	NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->AdjV = E->V2;
	//NewNode->Weight = E->Weight;
	////////将V1插到V2的表头///////
	NewNode->Next = Graph->G[E->V1].FirstEdge;
	Graph->G[E->V1].FirstEdge = NewNode;
}
/*建立图*/
LGraph BuildGraph(vector<vector<int>>& in_put)
{
	LGraph Graph;
	Edge E;
	//Vertex V;
	int i;
	for (int i = 0; i <Nv; i++)
		Visited[i] =-1;
	/*for (int i = 0; i < Nv; i++)
		cout << Visited[i] << " ";
	cout << endl;*/

	Graph = CreateGraph(Nv);
	Graph->Ne =ne;
	//scanf("%d", &(Graph->Ne));
	//cout << "边：" <<Graph->Ne<<endl;
	if (Graph->Ne != 0)
	{
		E = (Edge)malloc(sizeof(struct GNode));
		for (i = 0; i < Graph->Ne; i++)
		{
			E->V1 =in_put[i][1];
			E->V2 =in_put[i][2] ;
			E->Weight =in_put[i][3] ;
			InsertEdge(Graph, E);
		}
	}


	return Graph;
}
void Visit(Vertex V)
{
	printf("正在访问顶点%d\n", V);
}

/* Visited[]为全局变量，已经初始化为false */
void DFS(LGraph Graph, Vertex V_begin/*, void(*Visit)(Vertex),*/,Vertex& destination_V)
{   /* 以V为出发点对邻接表存储的图Graph进行DFS搜索 */
	cout << lay++ << endl;
	if (state == 1)
		return;
	PtrToAdjVNode W;
	//Visit(V_begin);/* 访问第V个顶点 */
	list.push_back(V_begin);
	Visited[V_begin] =V_begin; /* 标记V已访问 */
	if (V_begin == destination_V)
	{
		for (auto r : list)
			cout << r << "|";
		/*for (int i = 0; i <Nv; i++)
		if (Visited[i] != -1)
			cout << Visited[i]<<"|";*/
		cout << endl;
		state = 1;
	}
	for (W = Graph->G[V_begin].FirstEdge; W; W = W->Next) /* 对V的每个邻接点W->AdjV */
	{
		if (Visited[W->AdjV] == -1 && state == -1)    /* 若W->AdjV未被访问 */
			DFS(Graph, W->AdjV, destination_V);    /* 则递归访问之 */
	
	}
	Visited[V_begin] = -1;
}
int main()
{
	cout << "Hello world!" << endl;
	ifstream pp("C:\\topo2.csv");
	string s;
	vector<vector<int>> in_put;
	stringstream os;
	while (getline(pp, s))
	{
		//cout << s << endl;
		vector<int> tmp(4,0);
		string stmp;
		int j = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] != ',')
			{
				stmp += s[i];
			}
			else{
				
				os << stmp;
				os >> tmp[j++];
				if (j - 1>0)
					Nv = tmp[j - 1] > Nv ? tmp[j - 1] : Nv;
				os.clear();
				stmp.clear();
			}
		}
		os << stmp;
		os >> tmp[j++];
		os.clear();
		in_put.push_back(tmp);
		ne++;
	}
	cout << "最大顶点：" << Nv << endl;
	cout << "输入边数：" << ne << endl;
	Vertex destination_V;
	Vertex begin;
	cout << "起点：";
	cin >> begin;
	cout << "输入目的点：";
	cin >> destination_V;



	LGraph test=BuildGraph(in_put);
	DFS(test,begin,destination_V);
	return 0;
}
















using namespace std;
typedef unsigned int DistType;
typedef int Vertex;
void ReadGraph(LGraph G, Table T);

typedef struct TableEntry
{
	List Header;
	int Known;
	DistType Dist;
	Vertex Path;

};
typedef struct TableEntry Table[NumVertex];
void InitTable(Vertex Start,LGraph G,Table T)
{
	int i;
	ReadGraph(G, T);
	for (int i = 0; i < NumVertex; i++)
	{
		T[i].Known = false;
		T[i].Dist =Infinity;
		T[i].Path = NotAvertex;

	}
	T[Start].Dist = 0;
}
/***/
void PrintPath(Vertex V,Table T){
	if (T[V].Path != NotAvertex)
	{
		PrintPath(T[V].Path, T);
			printf(" to");

	}
	printf("%d", V);

}


void Dijkstra(Table T)
{
	Vertex V, W;
	for (;;)
	{
		for (W = Graph->G[V_begin].FirstEdge; W; W = W->Next)
		V = smallest unkonw distance;
		if (V == NotAvertex)
			break;
		T[V].Known = true;
		for each W adjacent to V
			if (!T[W].Known)
				if ()

	}


}
//
//
//int main()
//{
//	/*string s1 = "14";
//	s1 += '5';
//	char a = 'f';
//	char b = 'a';
//	int c = 'z'%b;
//	string s;
//	os << c;
//	os >> s;
//	cout << s << endl;*/
//
//	stringstream os;
//	char N = 'g';
//	string s1 = "1a";
//	string s2 = "3f";
//	string res = "";
//	int i = 0;
//	int carry=0;
//	int sum=0;
//	//string ssum;
//	int n = N - 'a'+10;
//	while (i<s1.size()&& i<s2.size())
//	{
//		 char ssum;
//		 sum = (s1[i] + s2[i])%n+carry;
//		 carry = (s1[i] + s2[i])/n;
//		 if (sum>=0&&sum<10)
//			 ssum= sum + '0';
//		 else
//		 {
//			 ssum = sum - 10 + 'a';
//		 }
//		 res += ssum;
//		 i++;
//
//	}
//	cout << res << endl;
//
//
//	return 0;
//}
