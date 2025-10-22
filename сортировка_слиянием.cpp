#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Функция слияния двух отсортированных массивов
void merge(vector<int>& arr, int left, int mid, int right) {
    // Размеры двух подмассивов для слияния
    int n1 = mid - left + 1;    // Размер левого подмассива
    int n2 = right - mid;       // Размер правого подмассива
    
    // Создаем временные массивы для левой и правой частей
    vector<int> leftArr(n1);
    vector<int> rightArr(n2);
    
    // Копируем данные во временные массивы
    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }
    
    // Индексы для обхода временных массивов и основного массива
    int i = 0;      // Индекс для левого подмассива
    int j = 0;      // Индекс для правого подмассива
    int k = left;   // Индекс для основного массива
    
    // Слияние временных массивов обратно в основной массив
    while (i < n1 && j < n2) {
        // Выбираем меньший элемент из двух подмассивов
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    
    // Копируем оставшиеся элементы левого подмассива (если есть)
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    
    // Копируем оставшиеся элементы правого подмассива (если есть)
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Основная функция сортировки слиянием
void mergeSort(vector<int>& arr, int left, int right) {
    // Базовый случай рекурсии: если в подмассиве 1 элемент или меньше
    if (left >= right) {
        return;
    }
    
    // Находим среднюю точку для разделения массива
    int mid = left + (right - left) / 2;
    
    // Рекурсивно сортируем левую и правую половины
    mergeSort(arr, left, mid);      // Сортировка левой половины
    mergeSort(arr, mid + 1, right); // Сортировка правой половины
    
    // Объединяем отсортированные половины
    merge(arr, left, mid, right);
}

// Перегруженная версия для удобного вызова (только массив)
void mergeSort(vector<int>& arr) {
    if (arr.size() <= 1) return;
    mergeSort(arr, 0, arr.size() - 1);
}

// Вспомогательная функция для вывода массива
void printArray(const vector<int>& arr, const string& message = "") {
    if (!message.empty()) {
        cout << message << endl;
    }
    
    cout << "[";
    for (size_t i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

// Функция с визуализацией процесса сортировки
void mergeSortVisual(vector<int>& arr, int left, int right, int depth = 0) {
    // Отступ для визуализации уровней рекурсии
    string indent(depth * 4, ' ');
    
    cout << indent << "mergeSort(arr, " << left << ", " << right << ")" << endl;
    cout << indent << "Текущий подмассив: [";
    for (int i = left; i <= right; i++) {
        cout << arr[i];
        if (i < right) cout << ", ";
    }
    cout << "]" << endl;
    
    // Базовый случай
    if (left >= right) {
        cout << indent << "Базовый случай - возврат" << endl;
        return;
    }
    
    int mid = left + (right - left) / 2;
    cout << indent << "Средняя точка: " << mid << endl;
    
    // Рекурсивные вызовы
    cout << indent << "Рекурсивный вызов для левой половины:" << endl;
    mergeSortVisual(arr, left, mid, depth + 1);
    
    cout << indent << "Рекурсивный вызов для правой половины:" << endl;
    mergeSortVisual(arr, mid + 1, right, depth + 1);
    
    // Состояние перед слиянием
    cout << indent << "Перед слиянием - левая часть: [";
    for (int i = left; i <= mid; i++) {
        cout << arr[i];
        if (i < mid) cout << ", ";
    }
    cout << "], правая часть: [";
    for (int i = mid + 1; i <= right; i++) {
        cout << arr[i];
        if (i < right) cout << ", ";
    }
    cout << "]" << endl;
    
    // Выполняем слияние
    merge(arr, left, mid, right);
    
    // Состояние после слияния
    cout << indent << "После слияния: [";
    for (int i = left; i <= right; i++) {
        cout << arr[i];
        if (i < right) cout << ", ";
    }
    cout << "]" << endl;
    cout << indent << "---" << endl;
}

// Упрощенная версия с визуализацией
void mergeSortVisual(vector<int>& arr) {
    if (arr.size() <= 1) return;
    cout << "НАЧАЛО СОРТИРОВКИ СЛИЯНИЕМ" << endl;
    cout << "Исходный массив: ";
    printArray(arr);
    cout << "========================================" << endl;
    
    mergeSortVisual(arr, 0, arr.size() - 1);
    
    cout << "========================================" << endl;
    cout << "Финальный результат: ";
    printArray(arr);
}

// Функция для проверки отсортированности массива
bool isSorted(const vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    cout << "СОРТИРОВКА СЛИЯНИЕМ НА C++" << endl;
    cout << "================================" << endl;
    
    // Тест 1: Простая версия
    vector<int> arr1 = {12, 11, 13, 5, 6, 7};
    cout << "Тест 1 - Простая версия:" << endl;
    printArray(arr1, "Исходный массив:");
    mergeSort(arr1);
    printArray(arr1, "Отсортированный массив:");
    cout << "Проверка сортировки: " << (isSorted(arr1) ? "УСПЕХ" : "ОШИБКА") << endl;
    cout << endl;
    
    // Тест 2: Больший массив
    vector<int> arr2 = {38, 27, 43, 3, 9, 82, 10};
    cout << "Тест 2:" << endl;
    printArray(arr2, "Исходный массив:");
    mergeSort(arr2);
    printArray(arr2, "Отсортированный массив:");
    cout << "Проверка сортировки: " << (isSorted(arr2) ? "УСПЕХ" : "ОШИБКА") << endl;
    cout << endl;
    
    // Тест 3: Уже отсортированный массив
    vector<int> arr3 = {1, 2, 3, 4, 5, 6, 7};
    cout << "Тест 3 (уже отсортированный):" << endl;
    printArray(arr3, "Исходный массив:");
    mergeSort(arr3);
    printArray(arr3, "После сортировки:");
    cout << "Проверка сортировки: " << (isSorted(arr3) ? "УСПЕХ" : "ОШИБКА") << endl;
    cout << endl;
    
    // Тест 4: Массив с повторяющимися элементами
    vector<int> arr4 = {5, 2, 5, 1, 2, 3, 1};
    cout << "Тест 4 (с повторяющимися элементами):" << endl;
    printArray(arr4, "Исходный массив:");
    mergeSort(arr4);
    printArray(arr4, "Отсортированный массив:");
    cout << "Проверка сортировки: " << (isSorted(arr4) ? "УСПЕХ" : "ОШИБКА") << endl;
    cout << endl;
    
    // Тест 5: Визуализация процесса
    vector<int> arr5 = {6, 2, 8, 1, 4};
    cout << "ТЕСТ С ВИЗУАЛИЗАЦИЕЙ ПРОЦЕССА:" << endl;
    cout << "================================" << endl;
    mergeSortVisual(arr5);
    
    return 0;
}