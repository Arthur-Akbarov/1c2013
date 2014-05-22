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

void DFS(int current, bool** adjacency, bool* flag);

int main() {
	cout << "Put number of vertexes" << endl;
	cin >> n;					// input the number of vertexes

	bool** adjacency = new bool*[n];		// declare matrix of adjacency as two-dimensional dynamic array
	for (int i = 0; i < n; i++)
		adjacency[i] = new bool[n];

	cout << "Put the matrix of adjacency" << endl;
	for (int i = 0; i < n; i++)			// input the matrix of adjacency
		for (int j = 0; j < n; j++)
			cin >> adjacency[i][j];

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
