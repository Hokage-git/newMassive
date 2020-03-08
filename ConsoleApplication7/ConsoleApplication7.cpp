#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;

void show_arr(int arr[],int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}

int linear_search(int arr[], int arr_size, int to_search) {
	for (int i = 0; i < arr_size; i++) {
		if (i+1 == to_search)
			return arr[i];
	}
	return -1;
}

void trade(int arr[], int size) {
	int first;
	int second;
	int var;

	cout << "Введите пожалуйста 2 номера значения массива: \n";

	cin >> first;
	cin >> second;

	if (first < 0 || second > size)
		return;

	var = arr[first];
	arr[first] = arr[second];
	arr[second] = var;
}

int sortirovshik(int arr[], int size) {
	int var=0;

	for (int i = 0; i < size-1; ++i) {
		int small = i;

		for (int j = i+1; j < size; ++j) {
			if (arr[j] < arr[small])
				small = j;
		}
		var = arr[small];
		arr[small] = arr[i];
		arr[i] = var;
	}
	return 0;
}

void Bubble(int arr[], int size) {

	int var = 0;

	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {

			if (arr[j] > arr[j + 1]) {
				var = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = var;
			}
		}
	}
}
int  Max_Number(int arr[], int size) {
	int var = 0;

	for (int i = 0; i < size; i++) {
	
		if (arr[i] > arr[i + 1]) {
			var = arr[i];
			return var;
		}
	}
}
void Min_Number(int arr[], int size) {
	int min = arr[0];

	for (int i = 0; i < size; i++) {
		if (arr[i]<min) {
			min = arr[i];
		}
	}
	cout << "Минимальное значение: " << min;
	cout << "\n";
}

int main()
{
	setlocale(LC_ALL, "rus");
	int size = 32;
	cout << "Введите желаемый размер массива: ";
	cin >> size;
	int* arr = new int[size];
	int choose = 0;
	int searcher = 0;
	srand(time(NULL));

	if (size==0)
		return 0;

	for (int i = 0; i < size; i++) {
		arr[i] = rand() * 100 / RAND_MAX;
		cout << arr[i] << " ";
	}

	
	cout << "\nЧто вы желаете сделать с этим массивом:" << endl
		<< "1.Линейный поиск элемента в массиве" << endl
		<< "2.Обмен двух элементов массива" << endl
		<< "3.Cортировка массива методом выбора" << endl
		<< "4.Cортировка массива пузырьком" << endl
		<< "5.Бинарный поиск элемента массива" << endl
		<< "6.Поиск максимального элемента массива" << endl
		<< "7.Поиск минимального элемента массива" << endl;

	cin >> choose;
	system("cls");
	cout << endl;

	show_arr(arr, size);

	cout << endl << endl;

	switch (choose) {

	case 1:
		cout << "Введите число от 1 до " << size<<": ";
		cin >> searcher;
		cout << linear_search(arr, size, searcher);
		break;

	case 2:
		trade(arr, size);
		show_arr(arr, size);
		break;

	case 3:
		sortirovshik(arr, size);
		show_arr(arr, size);
		break;

	case 4:
		Bubble(arr, size);
		show_arr(arr, size);
		break;

	case 5:
		break;

	case 6:
		cout<<Max_Number(arr, size);
		break;

	case 7:
		Min_Number(arr, size);
		break;
	}

	delete[] arr;
}
/*Напишите серию функций, реализующих стандартные действия с массивами ::
	- линейный поиск элемента в массиве int linear_search ( int arr [], int arr_size, int to_search ) 
								( массив, размер массива, значение элемента для поиска ), 
		возвращает номер элемента, или -1, если в массиве этого элемента нет
	- обмен двух элементов массива в функцию кроме массива и размера его нужно передать номера элементов. 
	- удаление элемента массива по номеру (сжатие массива)  пример до {0,1,2,3,4,5,6,7,8} ,удалить элемент №3, после {0,1,2,4,5,6,7,0}
	- сортировка массива методом выбора
	- сортировка массива пузырьком
	- бинарный поиск элемента массива
	- поиск максимального элемента массива
	- поиск минимального элемента массива*/