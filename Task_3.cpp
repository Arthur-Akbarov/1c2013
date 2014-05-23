//////////////////////////////////////////////////////////////////////////
//									//
//	Задача 3							//
//									//
//	В данном связном неориентированном взвешенном графе найдите	//
//	кратчайший путь от заданной вершины ко всем остальным вершинам.	//
//									//
//////////////////////////////////////////////////////////////////////////
//									//
//	Решение								//
//									//
//	Алгоритм Дейкстры						//
//									//
//////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <stdio.h>
using namespace std;

const int maxdistance = 10000;

int main() {
	int n, root;
	cout << "Put the number of vertices and root" << endl;
	cin >> n >> root;
	root--;


	int** adjacency = new int*[n];
	for (int i = 0; i < n; i++)
		adjacency[i] = new int[n];
	cout << "Put the matrix of adjacency" << endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> adjacency[i][j];


	int* distance = new int[n];
	for (int i = 0; i < n; i++)
		distance[i] = maxdistance;


	bool* flag = new bool[n];
	for (int i = 0; i < n; i++)
		flag[i] = false;


	string* path = new string[n];
	for (int i = 0; i < n; i++)
		path[i] = "";
	
	char* str = new char[10];
	sprintf(str, "%d", root + 1);
	path[root] += str;


	distance[root] = 0;

	for (int i = 0; i < n; i++) {
		static int v, current;
		current = maxdistance + 1;

		for (int u = 0; u < n; u++) {
			if ((flag[u] == false) & (distance[u] < current)) {
				v = u;
				current = distance[v];
			}
		}

		flag[v] = true;

		for (int u = 0; u < n; u++) {
			if ((adjacency[v][u] >= 0) & (distance[u] > distance[v] + adjacency[v][u])) {
				distance[u] = distance[v] + adjacency[v][u];
				sprintf(str, " -> %d", u + 1);
				path[u] = path[v] + str;
			}
		}
	}

	cout << endl;
	for (int i = 0; i < n; i++)
		cout << i + 1 << ":  " << path[i] << endl;


	for (int i = 0; i < n; i++)
		delete[] adjacency[i];
	delete[] adjacency;
	delete[] distance;
	delete[] flag;
	delete[] path;
	delete[] str;


	return 0;
}
