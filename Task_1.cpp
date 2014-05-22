//////////////////////////////////////////////////////////////////////////
//									//
//	Задача 1							//
//									//
//	Определить, существует ли в данном связном неориентированном    //
//	графе гамильтонов цикл, т.е. цикл, проходящий через каждую      //
//	вершину графа один раз.                                         //
//									//
//////////////////////////////////////////////////////////////////////////
//									//
//	Решение								//
//									//
//	Тупо обойдём все пути, сверяя является ли какой-нибудь		//
//	гамильтоновым циклом						//
//									//
//////////////////////////////////////////////////////////////////////////
				

#include <iostream>					// библиотека для cin/cout
using namespace std;

int n;							// кол-во вершин в графе
int length = 0;						// длина текущего пути
int begin;						// начало текущего пути
bool hamilton = false;					// существование гамильтонова цикла

void WayOut();
void Path(int current, bool** adjacency, bool* flag);

int main() {
	cout << "Put number of vertexes" << endl;
	cin >> n;					// считываем кол-во вершин графа

	bool** adjacency = new bool*[n];		// матрица смежности нашего графа		
	for (int i = 0; i < n; i++)			// как двумерный массив на указателях
        	adjacency[i] = new bool[n];

	cout << "Put the matrix of adjacency" << endl;
	for (int i = 0; i < n; i++)			// считываем матрицу смежности
		for (int j = 0; j < n; j++)
			cin >> adjacency[i][j];

	bool* flag = new bool[n];			// массив флагов, вершин задействованных в текущем пути
	for (int i = 0; i < n; i++)			// инициализация пустого массива флагов
		flag[i] = 0;


	switch (n) {
	case 1:  hamilton = true;  break;		// для 1 вершины считаем всегда верно
	case 2:  hamilton = false;  break;		// для 2 вершин считаем всегда неверно
	default:  for (int i = 0; i < n; i++) {		// начинаем идти по всем путям из всех вершин
		  	begin = i;			// предварительно запомнив корень в begin
		  	Path(begin, adjacency, flag);
		  }
		  break;
	};


	WayOut();					// выводим ответ


	for (int i = 0; i < n; i++)			// очищаем память указателей на ячейки матрицы смежности (массивы столбцов)
		delete[] adjacency[i];
	delete[] adjacency;				// очищаем память указателя на матрицу смежности (массив строк)
	delete[] flag;					// очищаем память указателя на массив флагов
			

	return 0;			
}				


void Path(int current, bool** adjacency, bool* flag) {
	flag[current] = 1;				// добавляем текущую вершину в путь
	length++;					// увеличиваем длину пути на 1

	if (length == n)				// является ли путь гамильтоновым циклом
		if (adjacency[begin][current])
			hamilton = true;

	for (int i = 0; i < n; i++)			// идём дальше по графу
		if (adjacency[current][i] & !flag[i])	// в смежную и нехоженную вершину
			Path(i, adjacency, flag);

	flag[current] = 0;				// убираем текущую вершину из пути
	length--;					// уменьшаем длину пути на 1
}


void WayOut() {
	if (hamilton)
		cout << "This graph contains hamiltonian circuit" << endl;
	else
		cout << "This graph doesn`t contain hamiltonian circuit" << endl;
}
