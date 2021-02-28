

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

int main()
{
	setlocale(LC_ALL,"");
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n] {};
	FillRand(arr,n);
	Print(arr,n);
	int value, index;
	cout << "введите добавляемое значение: "; cin >> value;
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
	Print(arr, n);
	delete[] arr;

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
