//////////////////////////////////////////////////////////////////////////
//									//
//	Задача 0							//
//									//
//	Определить, существует ли в данном связном неориентированном	//
//	графе эйлеров цикл, т.е. цикл, проходящий через каждое		//
//	ребро графа ровно один раз.					//
//									//
//////////////////////////////////////////////////////////////////////////
//									//
//	Решение (математическое)					//
//									//
//	Сверяем чётность степени каждой вершины				//
//	Эйлеров цикл существует <=> степень каждой вершины четна	//
//									//
//////////////////////////////////////////////////////////////////////////


// for the sake of testing
include <iostream>					// библиотека для cin/cout
using namespace std;

int n;							// кол-во вершин в графе
bool parity;						// счётчик чётности
bool euler = true;					// существование эйлерова цикла

void WayOut();

int main()
{
	cout << "Put number of vertexes" << endl;
	cin >> n;					// считываем кол-во вершин графа

	bool** adjacency = new bool*[n];		// матрица смежности нашего графа		
	for (int i = 0; i < n; i++)			// как двумерный массив на указателях
        	adjacency[i] = new bool[n];


	cout << "Put the matrix of adjacency" << endl;
	for (int i = 0; i < n; i++)			// считываем матрицу смежности
		for (int j = 0; j < n; j++)
			cin >> adjacency[i][j];



	for (int i = 0; i < n; i++) {			// считаем чётность i-ой вершины в parity
		parity = 0;				// изначально ставим 0, т.е. чётное
		for (int j = 0; j < n; j++) {
			if (adjacency[i][j])
				parity = 1 - parity;
		}
		if (parity == 1) {			// если parity = 1, т.е. вершина нечётная, 
			euler = false;			// то эйлерова цикла нет
			break;
		}
	}


	WayOut();					// выводим ответ


	for (int i = 0; i < n; i++)			// очищаем память указателей на ячейки матрицы смежности (массивы столбцов)
		delete[] adjacency[i];
	delete[] adjacency;				// очищаем память указателя на матрицу смежности (массив строк)
	
	return 0;
}


void WayOut() {
	cout << "Hello!";
	if (euler)
		cout << "This graph contains euler circuit" << endl;
	else
		cout << "This graph doesn`t contain euler circuit" << endl;
}
