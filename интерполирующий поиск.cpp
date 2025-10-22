#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int interpolationSearch(const vector<int>& arr, int target) {
    /**
     * Интерполирующий поиск - улучшенная версия бинарного поиска
     * Использует равномерное распределение данных для предсказания позиции
     */
    
    // Проверяем, что массив не пустой
    if (arr.empty()) {
        return -1;
    }
    
    // Левая граница поиска (начало массива)
    int low = 0;
    // Правая граница поиска (конец массива)
    int high = arr.size() - 1;
    
    // Пока целевой элемент находится в пределах границ и границы валидны
    while (low <= high && target >= arr[low] && target <= arr[high]) {
        // Если границы совпали, проверяем этот элемент
        if (low == high) {
            if (arr[low] == target) {
                return low;
            }
            return -1;
        }
        
        // Ключевая формула интерполирующего поиска:
        // Вычисляем позицию на основе линейной интерполяции
        // pos = low + ((target - arr[low]) * (high - low)) / (arr[high] - arr[low])
        int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (target - arr[low]));
        
        // Проверяем, что позиция находится в допустимых границах
        if (pos < low || pos > high) {
            break;
        }
        
        // Если нашли целевой элемент
        if (arr[pos] == target) {
            return pos;
        }
        // Если целевой элемент меньше элемента в найденной позиции
        else if (arr[pos] > target) {
            // Сужаем поиск к левой части
            high = pos - 1;
        }
        // Если целевой элемент больше элемента в найденной позиции
        else {
            // Сужаем поиск к правой части
            low = pos + 1;
        }
    }
    
    // Элемент не найден
    return -1;
}