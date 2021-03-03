/*!!!Создать ветку dynamic_templated, и в этой ветке шаблонизировать все функции для работы с двумерными динамическимим массивами!!!*/
#include <iostream>
using namespace std;

template <typename T> T** Allocate(const int m,const int n);	//Выделяет память под динамический массив
void FillRand(int** arr, const int m, const int n);//Заполнение массива случайными числами
void Print(int** arr, const int m, const int n);//Печать двумерного массива
template <typename T> void Clear(T** arr, const int m);		//Удаляет динамический массив
template <typename T> T** Push_row_back(T** arr, int& m, const int n);	//Добавляет строку в конец ДДМ
int** Push_row_front(int** arr, int& m, const int n);//Добавляет строку в начало ДДМ
int** insert_row(int** arr, int& m, const int n, int index);//Вставляет строку в двумерный динамический массив по индексу
int** pop_row_back(int** arr, int& m, const int n);	//Удаляет строку с конца ДДМ
int** pop_row_front(int** arr, int& m, const int n);	//Удаляет строку с начала ДДМ
int** erase_row(int** arr, int& m, const int n, int index);	//Удаляет строку по указанному индексу
int** push_col_back(int** arr, const int m, int& n);	//Добавляет столбец в конец ДДМ
int** push_col_front(int** arr, const int m, int& n);//Добавляет столбец в начало ДДМ
int** insert_col(int** arr, const int m, int& n, int index);	//Вставляет столбец по указанному индексу
int** pop_col_back(int** arr, const int m, int& n);	//Удаляет столбец в конце ДДМ
int** pop_col_front(int** arr, const int m, int& n); //Удаляет столбец в начале ДДМ
int** erase_col(int** arr, const int m, int& n, int index);	//Удаляет столбец по указанному индексу

int main()
{
	setlocale(LC_ALL,"");
	int n,m,index;
	/*Двумерный массив и операции с ним*/
	cout << "Введите количество строк: "; cin >> m;
	cout << "Введите количество элементов строки: "; cin >> n;
	cout << endl;
	int** arr_2 = Allocate(m, n);
	FillRand(arr_2, m, n);
	Print(arr_2,m,n);
	cout << endl;
	cout << "Добавление строки в конец ДДМ: " << endl;
	cout << endl;
	arr_2 = Push_row_back(arr_2, m, n);
	Print(arr_2, m, n);
	cout << endl;
	cout << "Добавление строки в начало ДДМ: " << endl;
	cout << endl;
	arr_2 = Push_row_front(arr_2, m, n);
	Print(arr_2, m, n);
	cout << endl;
	cout << "Введите индекс добавляемой строки: "; cin >> index;
	cout << "Добавление строки по индексу в ДДМ: " << endl;
	cout << endl;
	arr_2 = insert_row(arr_2,m,n,index);
	Print(arr_2, m, n);
	cout << endl;
	cout << "Удаление строки в конце ДДМ: " << endl;
	cout << endl;
	arr_2 = pop_row_back(arr_2, m, n);
	Print(arr_2, m, n);
	cout << endl;
	cout << "Удаление строки в начале ДДМ: " << endl;
	cout << endl;
	arr_2 = pop_row_front(arr_2, m, n);
	Print(arr_2, m, n);
	cout << endl;
	cout << "Введите индекс удаляемой строки: "; cin >> index;
	cout << "Удаление строки по индексу в ДДМ: " << endl;
	cout << endl;
	arr_2 = erase_row(arr_2, m, n, index);
	Print(arr_2, m, n);
	cout << endl;
	cout << "Добавление столбца в конец ДДМ: " << endl;
	cout << endl;
	arr_2 = push_col_back(arr_2, m, n);
	Print(arr_2, m, n);
	cout << endl;
	cout << "Добавление столбца в начало ДДМ: " << endl;
	cout << endl;
	arr_2 = push_col_front(arr_2, m, n);
	Print(arr_2, m, n);
	cout << endl;
	cout << "Введите индекс добавляемого столбца: "; cin >> index;
	cout << "Добавление столбца по индексу в ДДМ: " << endl;
	cout << endl;
	arr_2 = insert_col(arr_2, m, n, index);
	Print(arr_2, m, n);
	cout << endl;
	cout << "Удаление столбца в конце ДДМ: " << endl;
	cout << endl;
	arr_2 = pop_col_back(arr_2, m, n);
	Print(arr_2, m, n);
	cout << endl;
	cout << "Удаление столбца в начале ДДМ: " << endl;
	cout << endl;
	arr_2 = pop_col_front(arr_2, m, n);
	Print(arr_2, m, n);
	cout << endl;
	cout << "Введите индекс удаляемого столбца: "; cin >> index;
	cout << "Удаление столбца по индексу в ДДМ: " << endl;
	cout << endl;
	arr_2 = erase_col(arr_2, m, n, index);
	Print(arr_2, m, n);
	cout << endl;
	Clear(arr_2,m);
}



template <typename T> T** Allocate(const int m, const int n)
{
	T** arr = new T* [m];
	for (int i = 0; i < m; i++)
	{
		arr[i] = new T[n] {};
	}
	return arr;
}

void FillRand(int** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}

void Print(int** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << '\t';
		}
		cout << endl;
	}

}

template <typename T> void Clear(T** arr, const int m)
{
	for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

template <typename T> T** Push_row_back(T** arr, int& m, const int n)
{
	T** buffer = Allocate(m + 1, n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			buffer[i][j] = arr[i][j];
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		buffer[m][i] = rand() % 100;
	}
	Clear(arr, m);
	m++;
	return buffer;
}

int** Push_row_front(int** arr, int& m, const int n)
{
	int** buffer = Allocate(m + 1, n);
	for (int i = 1; i < m+1; i++)
	{
		for (int j = 0; j < n; j++)
		{
			buffer[i][j] = arr[i-1][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		buffer[0][i] = rand() % 100;
	}
		
	Clear(arr, m);
	m++;
	return buffer;
}

int** insert_row(int** arr, int& m, const int n, int index)
{
	int** buffer = Allocate(++m, n);
	for (int i = 0; i < index; i++)
	{
		for (int j = 0; j < n; j++)
		{
			buffer[i][j] = arr[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		buffer[index][i] = rand() % 100;
	}
	for (int i = index+1; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			buffer[i][j] = arr[i-1][j];
		}
	}
	Clear(arr, m-1);
	return buffer;
}

int** pop_row_back(int** arr, int& m, const int n)
{
	int** buffer = Allocate(--m, n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			buffer[i][j] = arr[i][j];
		}
	}
	Clear(arr, m + 1);
	return buffer;
}

int** pop_row_front(int** arr, int& m, const int n)
{
	int** buffer = Allocate(--m, n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			buffer[i][j] = arr[i+1][j];
		}
	}
	Clear(arr, m + 1);
	return buffer;
}

int** erase_row(int** arr, int& m, const int n, int index)
{
	int** buffer = Allocate(--m, n);
	for (int i = 0; i < index; i++)
	{
		for (int j = 0; j < n; j++)
		{
			buffer[i][j] = arr[i][j];
		}
	}
	
	for (int i = index; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			buffer[i][j] = arr[i + 1][j];
		}
	}
	Clear(arr, m + 1);
	return buffer;
}

int** push_col_back(int** arr, const int m, int& n)
{
	int** buffer = Allocate(m, n+1);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			buffer[i][j] = arr[i][j];
		}
	}

	for (int i = 0; i < m; i++)
	{
		buffer[i][n] = rand() % 100;
	}
	Clear(arr, m);
	n++;
	return buffer;
}

int** push_col_front(int** arr, const int m, int& n)
{
	int** buffer = Allocate(m, n+1);
	for (int i = 0; i < m; i++)
	{
		for (int j = 1; j < n+1; j++)
		{
			buffer[i][j] = arr[i][j-1];
		}
	}
	for (int i = 0; i < m; i++)
	{
		buffer[i][0] = rand() % 100;
	}

	Clear(arr, m);
	n++;
	return buffer;
}

int** insert_col(int** arr, const int m, int& n, int index)
{
	int** buffer = Allocate(m, ++n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < index; j++)
		{
			buffer[i][j] = arr[i][j];
		}
	}
	for (int i = 0; i < m; i++)
	{
		buffer[i][index] = rand() % 100;
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = index + 1; j < n; j++)
		{
			buffer[i][j] = arr[i][j-1];
		}
	}
	Clear(arr, m);
	return buffer;
}

int** pop_col_back(int** arr, const int m, int& n)
{
	int** buffer = Allocate(m, --n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			buffer[i][j] = arr[i][j];
		}
	}
	Clear(arr, m);
	return buffer;
}

int** pop_col_front(int** arr, const int m, int& n)
{
	int** buffer = Allocate(m, --n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			buffer[i][j] = arr[i][j+1];
		}
	}
	Clear(arr, m);
	return buffer;
}

int** erase_col(int** arr, const int m, int& n, int index)
{
	int** buffer = Allocate(m, --n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < index; j++)
		{
			buffer[i][j] = arr[i][j];
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = index; j < n; j++)
		{
			buffer[i][j] = arr[i][j+1];
		}
	}
	Clear(arr, m);
	return buffer;
}
