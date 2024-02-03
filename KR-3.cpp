#include <iostream>
#include <cstdlib>
#include <ctime>
void fill(int* arr, int size) { // "заполнить одномерный динамический массив случайными числами от 1 до 50"
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 50 + 1; // случайное от 1 до 50
    }
}
void print(int* arr, int size) { // "Показать его на экран"
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " "; //вывод элементов
    }
    std::cout << std::endl;
}
void Difference(int* arr, int size, int diff) { // "Написать функцию которая находит и выводит на экран все пары элементов матрицы разность которых равна заданному числу" 
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (abs(arr[i] - arr[j]) == diff) { //если разница равна введенной пользователем разнице
                std::cout << "Найдена пара: (" << arr[i] << ", " << arr[j] << ")" << std::endl; // вывести пару
            }
        }
    }
}
int main() {
    setlocale(LC_ALL,"Russian");
    srand(static_cast<unsigned int>(time(0)));
    int size = 0; //переменная размера массива
    std::cout << "Введите размер массива: "; 
    std::cin >> size; // "количество элементов в массиве"
    int* arr = new int[size]; // "указатель на динамический массив"
    fill(arr, size); // "заполнить одномерный динамический массив случайными числами от 1 до 50"
    std::cout << "Сгенерированный массив: ";
    print(arr, size);// "Показать его на экран"
    int diff = 0; // переменная разницы (вводится пользователем)
    std::cout << "Введице разницу: ";
    std::cin >> diff; // "заданное число"
    Difference(arr, size, diff); // "Написать функцию которая находит и выводит на экран все пары элементов матрицы разность которых равна заданному числу"
    delete[] arr; // очистка
    return 0; 
}