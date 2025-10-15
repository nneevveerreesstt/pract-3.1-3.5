def bubble_sort_detailed(arr):
    """
    Версия с подробным выводом каждого шага для обучения
    """
    n = len(arr)
    print(f"Начальный массив: {arr}")
    print(f"Длина массива: {n}")
    print("-" * 60)
    
    for i in range(n):
        print(f"\n🎯 ИТЕРАЦИЯ {i + 1}:")
        print(f"   Будем просматривать элементы с 0 до {n - i - 1}")
        
        swapped = False
        comparisons = 0  # Счетчик сравнений
        swaps = 0        # Счетчик обменов
        
        for j in range(0, n - i - 1):
            comparisons += 1
            print(f"   Сравниваем arr[{j}]={arr[j]} и arr[{j + 1}]={arr[j + 1]}", end="")
            
            if arr[j] > arr[j + 1]:
                # Меняем элементы местами
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True
                swaps += 1
                print(f" → ОБМЕН! Теперь: {arr}")
            else:
                print(f" → порядок верный")
        
        print(f"   Итог итерации {i + 1}: {arr}")
        print(f"   Сравнений: {comparisons}, Обменов: {swaps}")
        
        if not swapped:
            print(f"   ⭐ Не было обменов! Массив отсортирован после {i + 1} итераций")
            break
        else:
            print(f"   Последние {i + 1} элемент(ов) на своих местах")
    
    print("-" * 60)
    print(f"Финальный результат: {arr}")
    return arr

# Тестируем подробную версию
print("\n" + "=" * 70)
print("ПОДРОБНАЯ ВЕРСИЯ С ОБЪЯСНЕНИЕМ КАЖДОГО ШАГА")
print("=" * 70)

test_detailed = [64, 34, 25, 12, 22]
bubble_sort_detailed(test_detailed)