def quick_sort(arr):
    """
    Базовая реализация быстрой сортировки
    """
    if len(arr) <= 1:
        return arr
    
    # Выбираем опорный элемент (pivot)
    pivot = arr[len(arr) // 2]
    
    # Разделяем массив на три части
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    
    # Рекурсивно сортируем левую и правую части
    return quick_sort(left) + middle + quick_sort(right)


def quick_sort_in_place(arr, low=0, high=None):
    """
    Быстрая сортировка на месте (in-place)
    """
    if high is None:
        high = len(arr) - 1
    
    if low < high:
        # Получаем индекс разделения
        pi = partition(arr, low, high)
        
        # Рекурсивно сортируем элементы до и после разделения
        quick_sort_in_place(arr, low, pi - 1)
        quick_sort_in_place(arr, pi + 1, high)
    
    return arr


def partition(arr, low, high):
    """
    Функция разделения массива
    """
    # Выбираем опорный элемент (последний элемент)
    pivot = arr[high]
    
    # Индекс меньшего элемента (указывает на правильную позицию pivot)
    i = low - 1
    
    for j in range(low, high):
        # Если текущий элемент меньше или равен опорному
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]  # Меняем местами
    
    # Помещаем опорный элемент на правильную позицию
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1


def quick_sort_visual(arr, low=0, high=None, depth=0):
    """
    Версия с визуализацией процесса
    """
    if high is None:
        high = len(arr) - 1
    
    indent = "  " * depth
    print(f"{indent}quick_sort(arr[{low}:{high+1}]) - {arr[low:high+1]}")
    
    if low < high:
        # Выбор опорного элемента (медиана трех)
        mid = (low + high) // 2
        pivot_index = median_of_three(arr, low, mid, high)
        arr[pivot_index], arr[high] = arr[high], arr[pivot_index]
        pivot = arr[high]
        
        print(f"{indent}Опорный элемент: {pivot}")
        
        pi = partition_visual(arr, low, high, pivot, indent)
        
        print(f"{indent}После разделения: {arr[low:high+1]}")
        print(f"{indent}Индекс разделения: {pi}")
        
        # Рекурсивные вызовы
        quick_sort_visual(arr, low, pi - 1, depth + 1)
        quick_sort_visual(arr, pi + 1, high, depth + 1)
    
    return arr


def partition_visual(arr, low, high, pivot, indent):
    """
    Визуализированное разделение
    """
    i = low - 1
    
    print(f"{indent}  Разделение: pivot = {pivot}")
    
    for j in range(low, high):
        if arr[j] <= pivot:
            i += 1
            if i != j:
                print(f"{indent}    Меняем {arr[i]} и {arr[j]}")
                arr[i], arr[j] = arr[j], arr[i]
            else:
                print(f"{indent}    {arr[j]} на месте")
    
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    print(f"{indent}  Помещаем pivot на позицию {i + 1}")
    
    return i + 1


def median_of_three(arr, low, mid, high):
    """
    Выбор медианы из трех элементов для улучшения производительности
    """
    a, b, c = arr[low], arr[mid], arr[high]
    if a <= b <= c or c <= b <= a:
        return mid
    elif b <= a <= c or c <= a <= b:
        return low
    else:
        return high


def quick_sort_random_pivot(arr, low=0, high=None):
    """
    Версия со случайным выбором опорного элемента
    """
    import random
    
    if high is None:
        high = len(arr) - 1
    
    if low < high:
        # Случайный выбор опорного элемента
        random_index = random.randint(low, high)
        arr[random_index], arr[high] = arr[high], arr[random_index]
        
        pi = partition(arr, low, high)
        
        quick_sort_random_pivot(arr, low, pi - 1)
        quick_sort_random_pivot(arr, pi + 1, high)
    
    return arr


# Тестирование
def test_quick_sort():
    """
    Тестирование различных реализаций быстрой сортировки
    """
    print("ТЕСТИРОВАНИЕ БЫСТРОЙ СОРТИРОВКИ")
    print("=" * 50)
    
    test_arrays = [
        [64, 34, 25, 12, 22, 11, 90],
        [5, 2, 8, 1, 9, 3],
        [1, 2, 3, 4, 5],  # Уже отсортирован
        [5, 4, 3, 2, 1],  # Обратно отсортирован
        [3, 3, 3, 1, 1, 2],  # С повторениями
        [42]  # Один элемент
    ]
    
    for i, arr in enumerate(test_arrays, 1):
        print(f"Тест {i}:")
        print(f"Исходный: {arr}")
        
        # Простая версия
        result1 = quick_sort(arr.copy())
        print(f"Простая:  {result1}")
        
        # In-place версия
        result2 = quick_sort_in_place(arr.copy())
        print(f"In-place: {result2}")
        
        # Со случайным pivot
        result3 = quick_sort_random_pivot(arr.copy())
        print(f"Случайный: {result3}")
        print()
    
    # Визуализация
    print("ВИЗУАЛИЗАЦИЯ ПРОЦЕССА:")
    print("=" * 30)
    arr_visual = [6, 2, 8, 1, 9, 3]
    print(f"Исходный массив: {arr_visual}")
    quick_sort_visual(arr_visual.copy())
    print(f"Результат: {arr_visual}")


if __name__ == "__main__":
    test_quick_sort()