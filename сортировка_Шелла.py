def shell_sort(arr):
    """
    Сортировка Шелла - улучшенная версия сортировки вставками
    """
    # Получаем длину массива
    n = len(arr)
    
    # Вычисляем начальный интервал (шаг) используя последовательность Кнута
    # Можно использовать другие последовательности, но последовательность Кнута
    # является одной из наиболее эффективных: (3^k - 1) / 2
    gap = 1
    # Находим максимальный начальный интервал, который меньше n/3
    while gap < n // 3:
        gap = gap * 3 + 1  # Формула Кнута: 1, 4, 13, 40, 121, ...
    
    # Начинаем с наибольшего интервала и уменьшаем его до 1
    while gap > 0:
        # Применяем сортировку вставками для элементов на расстоянии gap
        # Проходим по всем элементам, начиная с позиции gap
        for i in range(gap, n):
            # Сохраняем текущий элемент для вставки
            temp = arr[i]
            
            # Сохраняем начальную позицию для сравнения
            j = i
            
            # Сдвигаем элементы, которые больше temp, на позиции с шагом gap
            # Сравниваем элементы на расстоянии gap
            while j >= gap and arr[j - gap] > temp:
                # Сдвигаем элемент вправо на gap позиций
                arr[j] = arr[j - gap]
                # Переходим к предыдущему элементу с шагом gap
                j -= gap
            
            # Вставляем сохраненный элемент на найденную позицию
            arr[j] = temp
        
        # Уменьшаем интервал для следующей итерации
        # По формуле Кнута: (gap - 1) // 3
        gap = (gap - 1) // 3
    
    return arr


def shell_sort_visual(arr):
    """
    Версия с визуализацией процесса сортировки
    """
    n = len(arr)
    print(f"Начальный массив: {arr}")
    print(f"Длина массива: {n}")
    print("=" * 50)
    
    # Вычисляем начальный интервал по последовательности Кнута
    gap = 1
    while gap < n // 3:
        gap = gap * 3 + 1
    
    iteration = 1
    while gap > 0:
        print(f"\n🎯 ИТЕРАЦИЯ {iteration}: интервал gap = {gap}")
        print(f"Текущий массив: {arr}")
        
        for i in range(gap, n):
            temp = arr[i]
            j = i
            
            print(f"  Обрабатываем элемент arr[{i}] = {temp}")
            
            comparisons = 0
            shifts = 0
            
            while j >= gap and arr[j - gap] > temp:
                comparisons += 1
                shifts += 1
                print(f"    Сравниваем arr[{j - gap}] = {arr[j - gap]} > {temp}")
                print(f"    Сдвигаем arr[{j - gap}] -> arr[{j}]")
                
                arr[j] = arr[j - gap]
                j -= gap
            
            if comparisons > 0:
                print(f"    Вставляем {temp} на позицию {j}")
            else:
                print(f"    Элемент {temp} уже на правильной позиции")
            
            arr[j] = temp
            print(f"    Текущее состояние: {arr}")
        
        # Уменьшаем интервал
        gap = (gap - 1) // 3
        iteration += 1
    
    print("=" * 50)
    print(f"Финальный результат: {arr}")
    return arr


def shell_sort_simple(arr):
    """
    Упрощенная версия с последовательностью Шелла (n/2, n/4, ..., 1)
    """
    n = len(arr)
    
    # Начинаем с большого интервала и уменьшаем его
    gap = n // 2
    
    while gap > 0:
        # Применяем сортировку вставками с текущим интервалом
        for i in range(gap, n):
            temp = arr[i]
            j = i
            
            # Сдвигаем элементы, которые больше temp
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
            
            # Вставляем элемент на правильную позицию
            arr[j] = temp
        
        # Уменьшаем интервал вдвое
        gap //= 2
    
    return arr


# Функция для тестирования
def test_shell_sort():
    """
    Тестирование алгоритма сортировки Шелла
    """
    print("ТЕСТИРОВАНИЕ СОРТИРОВКИ ШЕЛЛА")
    print("=" * 50)
    
    # Тест 1: Простой случай
    arr1 = [64, 34, 25, 12, 22, 11, 90]
    print("Тест 1:")
    print(f"Исходный массив: {arr1}")
    result1 = shell_sort(arr1.copy())
    print(f"Отсортированный: {result1}")
    print()
    
    # Тест 2: Уже отсортированный массив
    arr2 = [1, 2, 3, 4, 5, 6, 7]
    print("Тест 2 (уже отсортированный):")
    print(f"Исходный массив: {arr2}")
    result2 = shell_sort(arr2.copy())
    print(f"После сортировки: {result2}")
    print()
    
    # Тест 3: Обратно отсортированный массив
    arr3 = [7, 6, 5, 4, 3, 2, 1]
    print("Тест 3 (обратно отсортированный):")
    print(f"Исходный массив: {arr3}")
    result3 = shell_sort(arr3.copy())
    print(f"Отсортированный: {result3}")
    print()
    
    # Тест 4: Массив с повторяющимися элементами
    arr4 = [3, 7, 3, 1, 7, 2, 1, 3]
    print("Тест 4 (с повторениями):")
    print(f"Исходный массив: {arr4}")
    result4 = shell_sort(arr4.copy())
    print(f"Отсортированный: {result4}")
    print()
    
    # Тест 5: Визуализация процесса
    arr5 = [8, 3, 6, 1, 9, 2, 5, 4]
    print("ТЕСТ С ВИЗУАЛИЗАЦИЕЙ:")
    print("=" * 50)
    shell_sort_visual(arr5.copy())


# Дополнительная функция для сравнения с обычной сортировкой вставками
def insertion_sort_comparison(arr):
    """
    Обычная сортировка вставками для сравнения
    """
    n = len(arr)
    for i in range(1, n):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
    return arr


if __name__ == "__main__":
    # Запускаем тестирование
    test_shell_sort()
    
    # Демонстрация разницы между последовательностями
    print("\n" + "=" * 60)
    print("СРАВНЕНИЕ ПОСЛЕДОВАТЕЛЬНОСТЕЙ ИНТЕРВАЛОВ")
    print("=" * 60)
    
    test_arr = [5, 2, 8, 1, 9, 3, 7, 4, 6]
    
    print("Исходный массив:", test_arr)
    print()
    
    result_shell = shell_sort_simple(test_arr.copy())
    print("С последовательностью Шелла (n/2, n/4, ...):", result_shell)
    
    result_knuth = shell_sort(test_arr.copy())
    print("С последовательностью Кнута (1, 4, 13, ...):", result_knuth)
    
    result_insertion = insertion_sort_comparison(test_arr.copy())
    print("Обычная сортировка вставками:", result_insertion)