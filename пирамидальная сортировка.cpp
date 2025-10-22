#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Вспомогательная функция для превращения поддерева в кучу
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;        // Инициализируем наибольший элемент как корень
    int left = 2 * i + 1;   // Левый дочерний элемент
    int right = 2 * i + 2;  // Правый дочерний элемент

    // Если левый дочерний элемент больше корня
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // Если правый дочерний элемент больше текущего наибольшего
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // Если наибольший элемент не корень
    if (largest != i) {
        swap(arr[i], arr[largest]);  // Меняем местами
        heapify(arr, n, largest);    // Рекурсивно преобразуем затронутое поддерево
    }
}

// Основная функция пирамидальной сортировки
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Построение кучи (перегруппируем массив)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Один за другим извлекаем элементы из кучи
    for (int i = n - 1; i > 0; i--) {
        // Перемещаем текущий корень в конец
        swap(arr[0], arr[i]);
        
        // Вызываем heapify на уменьшенной куче
        heapify(arr, i, 0);
    }
}

// Функция для вывода массива
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

// Визуализированная версия heapify
void heapifyVisual(vector<int>& arr, int n, int i, int depth = 0) {
    string indent(depth * 4, ' ');
    cout << indent << "heapify(arr, " << n << ", " << i << ") - значение: " << arr[i] << endl;
    
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        cout << indent << "  Левый потомок " << arr[left] << " > текущего наибольшего " << arr[largest] << endl;
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        cout << indent << "  Правый потомок " << arr[right] << " > текущего наибольшего " << arr[largest] << endl;
        largest = right;
    }

    if (largest != i) {
        cout << indent << "  Меняем местами " << arr[i] << " и " << arr[largest] << endl;
        swap(arr[i], arr[largest]);
        cout << indent << "  Текущее состояние: ";
        printArray(arr);
        heapifyVisual(arr, n, largest, depth + 1);
    } else {
        cout << indent << "  Свойство кучи сохранено" << endl;
    }
}

// Визуализированная версия пирамидальной сортировки
void heapSortVisual(vector<int>& arr) {
    cout << "НАЧАЛО ПИРАМИДАЛЬНОЙ СОРТИРОВКИ" << endl;
    cout << "Исходный массив: ";
    printArray(arr);
    cout << "========================================" << endl;
    
    int n = arr.size();

    // Построение кучи
    cout << "ФАЗА 1: ПОСТРОЕНИЕ КУЧИ (max-heap)" << endl;
    for (int i = n / 2 - 1; i >= 0; i--) {
        cout << "\nОбрабатываем узел " << i << " (значение: " << arr[i] << ")" << endl;
        heapifyVisual(arr, n, i);
    }
    cout << "\nКуча построена: ";
    printArray(arr);

    // Извлечение элементов из кучи
    cout << "\nФАЗА 2: ИЗВЛЕЧЕНИЕ ЭЛЕМЕНТОВ ИЗ КУЧИ" << endl;
    for (int i = n - 1; i > 0; i--) {
        cout << "\nШаг " << n - i << ": перемещаем корень " << arr[0] << " в конец (позиция " << i << ")" << endl;
        swap(arr[0], arr[i]);
        cout << "После перемещения: ";
        printArray(arr);
        
        cout << "Восстанавливаем свойства кучи для корня" << endl;
        heapifyVisual(arr, i, 0);
    }

    cout << "========================================" << endl;
    cout << "Сортировка завершена: ";
    printArray(arr);
}

// Рекурсивная версия heapify (альтернативная реализация)
void heapifyRecursive(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapifyRecursive(arr, n, largest);
    }
}

// Пирамидальная сортировка с использованием make_heap и sort_heap из STL
void heapSortSTL(vector<int>& arr) {
    make_heap(arr.begin(), arr.end());  // Преобразуем в кучу
    sort_heap(arr.begin(), arr.end());  // Сортируем кучу
}

// Функция для проверки корректности сортировки
bool isSorted(const vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

// Демонстрация работы с двоичной кучей
void demonstrateHeap() {
    cout << "\nДЕМОНСТРАЦИЯ СТРУКТУРЫ ДВОИЧНОЙ КУЧИ" << endl;
    cout << "========================================" << endl;
    
    vector<int> arr = {4, 10, 3, 5, 1};
    cout << "Исходный массив: ";
    printArray(arr);
    
    // Показываем индексы для двоичной кучи
    cout << "\nИндексы в двоичной куче:" << endl;
    cout << "Для элемента с индексом i:" << endl;
    cout << "- Левый потомок: 2*i + 1" << endl;
    cout << "- Правый потомок: 2*i + 2" << endl;
    cout << "- Родитель: (i-1)/2" << endl;
    
    // Визуализируем построение кучи
    heapSortVisual(arr);
}

int main() {
    cout << "ПИРАМИДАЛЬНАЯ СОРТИРОВКА (HEAP SORT) НА C++" << endl;
    cout << "========================================" << endl;

    // Тест 1: Базовая версия
    vector<int> arr1 = {12, 11, 13, 5, 6, 7};
    cout << "Тест 1 - Базовая версия:" << endl;
    printArray(arr1, "Исходный массив:");
    heapSort(arr1);
    printArray(arr1, "Отсортированный массив:");
    cout << "Проверка: " << (isSorted(arr1) ? "УСПЕХ" : "ОШИБКА") << endl << endl;

    // Тест 2: STL версия
    vector<int> arr2 = {64, 34, 25, 12, 22, 11, 90};
    cout << "Тест 2 - STL версия:" << endl;
    printArray(arr2, "Исходный массив:");
    heapSortSTL(arr2);
    printArray(arr2, "Отсортированный массив:");
    cout << "Проверка: " << (isSorted(arr2) ? "УСПЕХ" : "ОШИБКА") << endl << endl;

    // Тест 3: Уже отсортированный массив
    vector<int> arr3 = {1, 2, 3, 4, 5, 6, 7};
    cout << "Тест 3 (уже отсортированный):" << endl;
    printArray(arr3, "Исходный массив:");
    heapSort(arr3);
    printArray(arr3, "После сортировки:");
    cout << "Проверка: " << (isSorted(arr3) ? "УСПЕХ" : "ОШИБКА") << endl << endl;

    // Тест 4: Визуализация процесса
    vector<int> arr4 = {4, 10, 3, 5, 1};
    cout << "ТЕСТ С ВИЗУАЛИЗАЦИЕЙ ПРОЦЕССА:" << endl;
    cout << "========================================" << endl;
    heapSortVisual(arr4);

    // Демонстрация структуры кучи
    demonstrateHeap();

    return 0;
}