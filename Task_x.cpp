//////////////////////////////////////////////////////////////////////////
//									//
//	Задача 2							//
//									//
//	Подсчитать количество компонент связанности в данном		//
//	неориентированном графе.					//
//									//
//////////////////////////////////////////////////////////////////////////
//									//
//	Решение								//
//									//
//	Запустить DFS по всем нехоженным и маркировать все хоженные	//
//	Ответ: кол-во вызовов DFS					//
//									//
//////////////////////////////////////////////////////////////////////////


#include <iostream>
using namespace std;


int n;							// n - number of vertexes in graph
int count = 0;						// count - number of connective components
bool** adjacency;

void DFS(int current, bool** adjacency, bool* flag);


void ReadVertexNumber(int* n)
{
	cout << endl << "Put the number of vertexes" << endl;
	cin >> *n;
}


template< typename T>
void CreateAdjacency(int* n, T** adjacency)
{
	adjacency = new T*[*n];
	for (int i = 0; i < *n; i++)
		adjacency[i] = new T[*n];		
}


template< typename T>
void ReadAdjacency(int* n, T** adjacency)
{
	cout << endl << "Put the marix of adjacency" << endl;
	for (int i = 0; i < *n; i++)
		for (int j = 0; j < *n; j++)
			cin >> adjacency[i][j];
}

int main()
{

	ReadVertexNumber(&n);

	CreateAdjacency<bool>(&n, adjacency);
	ReadAdjacency<bool>(&n, adjacency);	

	bool* flag = new bool[n];			// declare array of flags
	for (int i = 0; i < n; i++)			// initialize array of flag as false
		flag[i] = 0;

	for (int i = 0; i < n; i++)			// run about the graph
		if (!flag[i]) {
			count++;			// count every new connective component
			DFS(i, adjacency, flag);
		}

	cout << "Number of connective components = " << count << endl;

	for (int i = 0; i < n; i++)
		delete[] adjacency[i];
	delete[] adjacency;
	delete[] flag;


	return 0;
}


void DFS(int current, bool** adjacency, bool* flag) {
	flag[current] = 1;
	for (int i = 0; i < n; i++)
		if (adjacency[current][i] & !flag[i])
			DFS(i, adjacency, flag);
}


