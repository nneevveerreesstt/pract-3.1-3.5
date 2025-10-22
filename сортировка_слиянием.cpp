#include <iostream>
#include <vector>

using namespace std;

// Функция сортировки вставками
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    
    // Проходим по всем элементам массива, начиная со второго (индекс 1)
    // Первый элемент (индекс 0) считается условно отсортированным
    for (int i = 1; i < n; i++) {
        // Запоминаем текущий элемент, который будем вставлять в отсортированную часть
        int current = arr[i];
        
        // Индекс для перемещения по отсортированной части (справа налево)
        // Начинаем с элемента перед текущим (i-1)
        int j = i - 1;
        
        // Перемещаемся по отсортированной части справа налево
        // Ищем правильную позицию для current
        while (j >= 0 && arr[j] > current) {
            // Сдвигаем элемент вправо, чтобы освободить место для вставки
            arr[j + 1] = arr[j];
            // Переходим к следующему элементу слева
            j--;
        }
        
        // Нашли правильную позицию для current
        // Вставляем его на освободившееся место
        arr[j + 1] = current;
    }
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

// Функция с подробной визуализацией процесса
void insertionSortVisual(vector<int>& arr) {
    cout << "НАЧАЛО СОРТИРОВКИ ВСТАВКАМИ" << endl;
    cout << "Исходный массив: ";
    printArray(arr);
    cout << "----------------------------------------" << endl;
    
    int n = arr.size();
    
    for (int i = 1; i < n; i++) {
        int current = arr[i];
        int j = i - 1;
        
        cout << endl << "ИТЕРАЦИЯ " << i << ":" << endl;
        cout << "   Текущий элемент: arr[" << i << "] = " << current << endl;
        
        // Выводим отсортированную и неотсортированную части
        cout << "   Отсортированная часть: [";
        for (int k = 0; k <= i - 1; k++) {
            cout << arr[k];
            if (k < i - 1) cout << ", ";
        }
        cout << "]" << endl;
        
        cout << "   Неотсортированная часть: [";
        for (int k = i; k < n; k++) {
            cout << arr[k];
            if (k < n - 1) cout << ", ";
        }
        cout << "]" << endl;
        
        cout << "   Ищем место для " << current << " в отсортированной части..." << endl;
        
        int shifts = 0;
        // Поиск позиции и сдвиг элементов
        while (j >= 0 && arr[j] > current) {
            cout << "     arr[" << j << "] = " << arr[j] << " > " << current 
                 << " -> сдвигаем " << arr[j] << " вправо" << endl;
            arr[j + 1] = arr[j];
            j--;
            shifts++;
        }
        
        // Вставка элемента на найденную позицию
        arr[j + 1] = current;
        
        cout << "   Вставляем " << current << " на позицию " << j + 1 << endl;
        cout << "   Текущее состояние массива: ";
        printArray(arr);
        cout << "   Сдвигов на этой итерации: " << shifts << endl;
    }
    
    cout << "----------------------------------------" << endl;
    cout << "СОРТИРОВКА ЗАВЕРШЕНА" << endl;
    cout << "Финальный результат: ";
    printArray(arr);
}

int main() {
    cout << "СОРТИРОВКА ВСТАВКАМИ НА C++" << endl;
    cout << "================================" << endl;
    
    // Тест 1: Простая версия
    vector<int> arr1 = {12, 11, 13, 5, 6};
    cout << "Тест 1 - Простая версия:" << endl;
    printArray(arr1, "Исходный массив:");
    insertionSort(arr1);
    printArray(arr1, "Отсортированный массив:");
    cout << endl;
    
    // Тест 2: Другой массив
    vector<int> arr2 = {64, 34, 25, 12, 22, 11, 90};
    cout << "Тест 2:" << endl;
    printArray(arr2, "Исходный массив:");
    insertionSort(arr2);
    printArray(arr2, "Отсортированный массив:");
    cout << endl;
    
    // Тест 3: Уже отсортированный массив
    vector<int> arr3 = {1, 2, 3, 4, 5};
    cout << "Тест 3 (уже отсортированный):" << endl;
    printArray(arr3, "Исходный массив:");
    insertionSort(arr3);
    printArray(arr3, "После сортировки:");
    cout << endl;
    
    // Тест 4: Визуализация процесса
    vector<int> arr4 = {5, 2, 4, 6, 1, 3};
    cout << "ТЕСТ С ВИЗУАЛИЗАЦИЕЙ ПРОЦЕССА:" << endl;
    cout << "================================" << endl;
    insertionSortVisual(arr4);
    
    return 0;
}
