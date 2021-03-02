

#include <iostream>
using namespace std;

void FillRand(int arr[], const int n); //Заполняет массив
void Print(int arr[], const int n);    //Выводит массив на экран
int* push_back(int arr[], int& n, int value); //Добавляет элемент в конец массива
int* push_front(int arr[], int& n, int value); //Добавляет элемент в начало массива
int* pop_back(int arr[], int& n); //Удаляет последний элемент массива
int* pop_front(int arr[], int& n); // Удаляет первый элемент массива
int* insert(int arr[], int& n, int value, int index); //Вставляем элемент в массив по индексу
int* erase(int arr[], int& n, int index); //Удаляет элемент из массива по индексу

int** Allocate(const int m,const int n);	//Выделяет память под динамический массив
void FillRand(int** arr, const int m, const int n);//Заполнение массива случайными числами
void Print(int** arr, const int m, const int n);//Печать двумерного массива
void Clear(int** arr, const int m);		//Удаляет динамический массив
int** Push_row_back(int** arr, int& m, const int n);	//Добавляет строку в конец ДДМ
int** Push_row_front(int** arr, int& m, const int n);//Добавляет строку в начало ДДМ
int** insert_row(int** arr, int& m, const int n, int index);//Вставляет строку в двумерный динамический массив по индексу
int** pop_row_back(int** arr, int& m, const int n);	//Удаляет строку с конца ДДМ
int** pop_row_front(int** arr, int& m, const int n);	//Удаляет строку с начала ДДМ
int** erase_row(int** arr, int& m, const int n, int index);	//Удаляет строку по указанному индексу

int main()
{
	setlocale(LC_ALL,"");
	int n,m;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n] {};
	/*FillRand(arr,n);
	Print(arr,n);*/
	int value, index;
	/*cout << "введите добавляемое значение: "; cin >> value;
	arr=push_back(arr, n, value);
	Print(arr, n);
	cout << "введите добавляемое значение: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);
	cout << "Удаляем последний элемент массива"<<endl;
	arr = pop_back(arr, n);
	Print(arr, n);
	cout << "Удаляем первый элемент массива" << endl;
	arr = pop_front(arr, n);
	Print(arr, n);
	cout << "введите добавляемое значение: "; cin >> value;
	cout << "введите индекс добавляемого элемента: "; cin >> index;
	arr = insert(arr,n,value,index);
	Print(arr, n);
	cout << "введите индекс удаляемого элемента: "; cin >> index;
	arr = erase(arr,n,index);
	Print(arr, n);*/
	delete[] arr;
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
	Clear(arr_2,m);
	
	



    

}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << '\t';
	}
	cout << endl;
}

int* push_back(int arr[], int& n, int value)
{
	/*1) Выделить блок памяти необходимого размера
	Создаем буфферный массив нужного размера*/
	int* buffer = new int[n + 1];
	/*Копируем данные массива в буфер*/
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	/*Удаляем исходный массив*/
	delete[] arr;
	/*подменяем адрес старого массива адресом нового*/
	arr = buffer;
	/*Записываем значение в конец массива*/
	arr[n] = value;
	/*Увеличиваем размер массива на 1*/
	n++;
	return arr;
}
int* push_front(int arr[], int& n, int value)
{
	
	int* buffer = new int[n + 1];

	
	for (int i = 0; i < n; i++)
	{
		buffer[i+1] = arr[i];
	}
	
	delete[] arr;
	
	arr = buffer;
	
	arr[0] = value;
	
	n++;
	return arr;
}

int* pop_back(int arr[], int& n)
{
	
	int* buffer = new int[--n]{};
	
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	
	delete[] arr;
	return buffer;
}

int* pop_front(int arr[], int& n)
{
	int* buffer = new int[--n]{};
	for (int i = 0; i < n; i++) buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}

int* insert(int arr[], int& n, int value, int index)
{
	int* buffer = new int[++n]{};
	for (int i = 0; i < index; i++) buffer[i] = arr[i];
	buffer[index] = value;
	for (int i = index + 1; i <= n-1; i++) buffer[i] = arr[i-1];
	delete[] arr;
	return buffer;
}

int* erase(int arr[], int& n, int index)
{
	int* buffer = new int[--n]{};
	for (int i = 0; i < index; i++) buffer[i] = arr[i];
	for (int i = index; i < n; i++) buffer[i] = arr[i +1];
	delete[] arr;
	return buffer;
}

int** Allocate(const int m, const int n)
{
	int** arr = new int* [m];
	for (int i = 0; i < m; i++)
	{
		arr[i] = new int[n] {};
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

void Clear(int** arr, const int m)
{
	for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

int** Push_row_back(int** arr, int& m, const int n)
{
	int** buffer = Allocate(m + 1, n);
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
