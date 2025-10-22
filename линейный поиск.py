def linear_search(arr, target):
    """
    Последовательный (линейный) поиск
    Возвращает индекс элемента target в массиве arr
    Если элемент не найден, возвращает -1
    """
    # Проходим по всем элементам массива
    for i in range(len(arr)):
        # Сравниваем текущий элемент с искомым
        if arr[i] == target:
            return i  # Элемент найден, возвращаем индекс
    
    return -1  # Элемент не найден


def linear_search_visual(arr, target):
    """
    Версия с визуализацией процесса поиска
    """
    print(f"Массив: {arr}")
    print(f"Ищем элемент: {target}")
    print("=" * 40)
    
    for i in range(len(arr)):
        print(f"Шаг {i + 1}: проверяем arr[{i}] = {arr[i]}")
        
        if arr[i] == target:
            print(f"✅ Элемент найден на позиции {i}!")
            print(f"Потребовалось {i + 1} сравнений")
            return i
        
        print(f"❌ arr[{i}] ≠ {target}, продолжаем поиск...")
    
    print(f"🔍 Элемент {target} не найден в массиве")
    return -1


def linear_search_all_occurrences(arr, target):
    """
    Поиск всех вхождений элемента
    Возвращает список индексов всех найденных элементов
    """
    indices = []
    
    for i in range(len(arr)):
        if arr[i] == target:
            indices.append(i)
    
    return indices


def linear_search_with_sentinel(arr, target):
    """
    Линейный поиск со стражем (sentinel)
    Улучшенная версия, избегает проверки границ
    """
    # Сохраняем последний элемент
    last = arr[-1]
    
    # Заменяем последний элемент искомым значением
    arr[-1] = target
    
    i = 0
    # Ищем до тех пор, пока не найдем target
    while arr[i] != target:
        i += 1
    
    # Восстанавливаем последний элемент
    arr[-1] = last
    
    # Проверяем, нашли ли мы target
    if i < len(arr) - 1 or arr[-1] == target:
        return i
    else:
        return -1


def linear_search_condition(arr, condition_func):
    """
    Поиск по произвольному условию
    condition_func - функция, возвращающая True/False для каждого элемента
    """
    for i in range(len(arr)):
        if condition_func(arr[i]):
            return i, arr[i]
    
    return -1, None

