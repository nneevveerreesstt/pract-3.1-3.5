import java.util.Arrays;

public class FibonacciSearch {
    
    /**
     * Алгоритм поиска Фибоначчи
     * Улучшенная версия бинарного поиска, использующая числа Фибоначчи
     */
    public static int fibonacciSearch(int[] arr, int target) {
        // Если массив пустой, возвращаем -1
        if (arr.length == 0) {
            return -1;
        }
        
        // Инициализируем числа Фибоначчи
        int fibMMinus2 = 0;       // F(k-2)
        int fibMMinus1 = 1;       // F(k-1)
        int fibM = fibMMinus1 + fibMMinus2; // F(k)
        
        // Находим наименьшее число Фибоначчи, которое >= длины массива
        while (fibM < arr.length) {
            fibMMinus2 = fibMMinus1;
            fibMMinus1 = fibM;
            fibM = fibMMinus1 + fibMMinus2;
        }
        
        // Инициализируем индекс для устранения смещения
        int offset = -1;
        
        // Выполняем поиск, пока есть элементы для проверки
        while (fibM > 1) {
            // Проверяем, что индекс в пределах массива
            int i = Math.min(offset + fibMMinus2, arr.length - 1);
            
            // Если target больше значения в i, ищем в правой части
            if (arr[i] < target) {
                // Сдвигаем числа Фибоначчи вправо
                fibM = fibMMinus1;
                fibMMinus1 = fibMMinus2;
                fibMMinus2 = fibM - fibMMinus1;
                offset = i; // Обновляем смещение
            }
            // Если target меньше значения в i, ищем в левой части
            else if (arr[i] > target) {
                // Сдвигаем числа Фибоначчи влево
                fibM = fibMMinus2;
                fibMMinus1 = fibMMinus1 - fibMMinus2;
                fibMMinus2 = fibM - fibMMinus1;
            }
            // Если нашли элемент
            else {
                return i;
            }
        }
        
        // Проверяем последний элемент
        if (fibMMinus1 == 1 && offset + 1 < arr.length && arr[offset + 1] == target) {
            return offset + 1;
        }
        
        // Элемент не найден
        return -1;
    }
    
    /**
     * Вспомогательная функция для генерации последовательности Фибоначчи
     */
    public static int[] generateFibonacciSequence(int n) {
        if (n <= 0) return new int[0];
        if (n == 1) return new int[]{0};
        
        int[] fib = new int[n];
        fib[0] = 0;
        fib[1] = 1;
        
        for (int i = 2; i < n; i++) {
            fib[i] = fib[i - 1] + fib[i - 2];
        }
        
        return fib;
    }
    
    /**
     * Визуализированная версия поиска Фибоначчи
     */
    public static int fibonacciSearchVisual(int[] arr, int target) {
        System.out.println("ПОИСК ФИБОНАЧЧИ - ВИЗУАЛИЗАЦИЯ");
        System.out.println("Массив: " + Arrays.toString(arr));
        System.out.println("Ищем: " + target);
        System.out.println("=" + "=".repeat(50));
        
        if (arr.length == 0) {
            System.out.println("Массив пуст!");
            return -1;
        }
        
        // Инициализация чисел Фибоначчи
        int fibMMinus2 = 0;
        int fibMMinus1 = 1;
        int fibM = fibMMinus1 + fibMMinus2;
        
        System.out.println("Инициализация чисел Фибоначчи:");
        System.out.println("  F(k-2) = " + fibMMinus2 + ", F(k-1) = " + fibMMinus1 + ", F(k) = " + fibM);
        
        // Находим подходящее число Фибоначчи
        while (fibM < arr.length) {
            fibMMinus2 = fibMMinus1;
            fibMMinus1 = fibM;
            fibM = fibMMinus1 + fibMMinus2;
            System.out.println("  F(k-2) = " + fibMMinus2 + ", F(k-1) = " + fibMMinus1 + ", F(k) = " + fibM);
        }
        
        int offset = -1;
        int step = 1;
        
        System.out.println("\nНачало поиска:");
        System.out.println("  Найденное F(k) = " + fibM + " (>= " + arr.length + ")");
        System.out.println("  Начальное смещение = " + offset);
        
        while (fibM > 1) {
            System.out.println("\nШаг " + step + ":");
            System.out.println("  F(k) = " + fibM + ", F(k-1) = " + fibMMinus1 + ", F(k-2) = " + fibMMinus2);
            
            int i = Math.min(offset + fibMMinus2, arr.length - 1);
            System.out.println("  Проверяемый индекс: i = min(" + offset + " + " + fibMMinus2 + ", " + (arr.length - 1) + ") = " + i);
            System.out.println("  arr[" + i + "] = " + arr[i] + ", target = " + target);
            
            if (arr[i] < target) {
                System.out.println("  " + arr[i] + " < " + target + " → ищем в ПРАВОЙ части");
                fibM = fibMMinus1;
                fibMMinus1 = fibMMinus2;
                fibMMinus2 = fibM - fibMMinus1;
                offset = i;
                System.out.println("  Новые значения: F(k)=" + fibM + ", F(k-1)=" + fibMMinus1 + ", F(k-2)=" + fibMMinus2);
                System.out.println("  Новое смещение: " + offset);
            }
            else if (arr[i] > target) {
                System.out.println("  " + arr[i] + " > " + target + " → ищем в ЛЕВОЙ части");
                fibM = fibMMinus2;
                fibMMinus1 = fibMMinus1 - fibMMinus2;
                fibMMinus2 = fibM - fibMMinus1;
                System.out.println("  Новые значения: F(k)=" + fibM + ", F(k-1)=" + fibMMinus1 + ", F(k-2)=" + fibMMinus2);
            }
            else {
                System.out.println("  ✅ Найден элемент на позиции " + i);
                return i;
            }
            step++;
        }
        
        // Проверка последнего элемента
        if (fibMMinus1 == 1 && offset + 1 < arr.length && arr[offset + 1] == target) {
            System.out.println("\nПроверка последнего элемента:");
            System.out.println("  arr[" + (offset + 1) + "] = " + arr[offset + 1] + " == " + target);
            System.out.println("  ✅ Найден элемент на позиции " + (offset + 1));
            return offset + 1;
        }
        
        System.out.println("\n🔍 Элемент " + target + " не найден");
        return -1;
    }
    
    /**
     * Сравнение с бинарным поиском
     */
    public static int binarySearch(int[] arr, int target) {
        int left = 0;
        int right = arr.length - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (arr[mid] == target) {
                return mid;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return -1;
    }
    
    