<h1 align="center">Домашнее задание к работе 19</h1>
<div align="center">

## Условие задачи

<img width="1060" height="841" alt="изображение" src="https://github.com/user-attachments/assets/4441eea3-3a27-40e3-ba3f-81ca401ff528" />


## 1. Алгоритм и блок-схема

### Алгоритм
1. **Начало**
2. Подключение необходимых библиотек:<br>
   - `stdio.h` - для ввода/вывода и работы с файлами<br>
   - `locale.h` - для поддержки русского языка<br>
   - `string.h` - для работы со строками
3. Определение макроса `_CRT_SECURE_NO_WARNINGS` для отключения предупреждений безопасности
4. Объявление структуры `train` с полями:<br>
   - `number` - номер поезда<br>
   - `arrival_time[6]` - время прибытия<br>
   - `departure_time[6]` - время отбытия<br>
   - `direction[50]` - направление движения<br>
   - `distance` - расстояние
5. Создание псевдонима `Train` для типа `struct train` с помощью `typedef`
6. Объявление прототипов функций:<br>
   - `input_train()` - для ввода данных о поезде<br>
   - `print_train()` - для вывода данных на экран<br>
   - `save_to_file()` - для записи данных в файл<br>
   - `print_all_from_file()` - для чтения и вывода всех записей из файла
7. Установка русской локали для корректного отображения текста
8. Объявление переменных:<br>
   - `FILE* out` - указатель на файл<br>
   - `Train train` - структура поезда<br>
   - `char choice` - символ выбора (не используется)<br>
   - `int count` - количество поездов
9. Открытие файла "trains.txt" для записи текста (`"wt"`)
10. Проверка успешного открытия файла
11. Запись заголовка в файл
12. Ввод с клавиатуры количества поездов для записи
13. Цикл `for` для ввода данных каждого поезда:<br>
    - Вывод номера текущего поезда<br>
    - Ввод данных с помощью функции `input_train(&train)`<br>
    - Вывод данных на экран с помощью функции `print_train(train)`<br>
    - Запись данных в файл с помощью функции `save_to_file(train, out)`
14. Закрытие файла после записи
15. Вывод сообщения о успешной записи
16. Вывод содержимого файла на экран с помощью функции `print_all_from_file()`
17. Ожидание нажатия клавиши для задержки закрытия консоли
18. Завершение программы
19. **Конец**

### Функция `input_train()` (ввод данных):
1. **Начало функции**
2. Ввод номера поезда
3. Ввод времени прибытия в формате "ЧЧ:ММ"
4. Ввод времени отбытия в формате "ЧЧ:ММ"
5. Ввод направления движения
6. Удаление символа новой строки из строки направления
7. Ввод расстояния
8. **Конец функции**

### Функция `print_train()` (вывод на экран):
1. **Начало функции**
2. Вывод разделительной линии
3. Вывод номера поезда
4. Вывод времени прибытия
5. Вывод времени отбытия
6. Вывод направления движения
7. Вывод расстояния
8. Вывод разделительной линии
9. **Конец функции**

### Функция `save_to_file()` (запись в файл):
1. **Начало функции**
2. Запись номера поезда в файл
3. Запись времени прибытия в файл
4. Запись времени отбытия в файл
5. Запись направления движения в файл
6. Запись расстояния в файл
7. Запись разделительной линии в файл
8. **Конец функции**

### Функция `print_all_from_file()` (чтение из файла):
1. **Начало функции**
2. Открытие файла "trains.txt" для чтения текста (`"rt"`)
3. Проверка успешного открытия файла
4. Цикл `while` для чтения файла построчно
5. Вывод каждой строки на экран
6. Закрытие файла после чтения
7. **Конец функции**
</div>

### Блок-схема



</div>

## 2. Реализация программы

\```c
#define _CRT_SECURE_NO_WARNINGS

// Необходимые библиотеки
#include <stdio.h>
#include <locale.h>
#include <string.h>

// Объявление структуры поезда
struct train {
    int number;
    char arrival_time[6];
    char departure_time[6];
    char direction[50];
    float distance;
};

// Создание псевдонима
typedef struct train Train;

// Прототипы функций
void input_train(Train* t);
void print_train(Train t);
void save_to_file(Train t, FILE* out);
void print_all_from_file();

// Основная функция
int main()
{
    // Русская локаль
    setlocale(LC_CTYPE, "RUS");

    FILE* out;
    Train train;
    char choice;
    int count;

    printf("Работа со структурой 'Поезд'\n");

    // Открытие файла для записи
    if ((out = fopen("trains.txt", "wt")) == NULL)
    {
        printf("Ошибка создания файла\n");
        return 0;
    }

    // Заголовок в файл
    fprintf(out, "Список поездов\n");
    fprintf(out, "===============================================\n");

    // Ввод количества поездов
    printf("Сколько поездов записать в файл? ");
    scanf("%d", &count);
    getchar();

    // Ввод данных поездов и запись в файл
    for (int i = 0; i < count; i++)
    {
        printf("\nПоезд %d:\n", i + 1);
        input_train(&train);
        print_train(train);
        save_to_file(train, out);
    }

    fclose(out);
    printf("\nВсе поезда записаны в файл trains.txt\n");

    // Чтение и вывод из файла
    printf("\nСодержимое файла trains.txt:\n");
    printf("===============================================\n");
    print_all_from_file();

    getchar();
    return 0;
}

// Функция ввода данных поезда
void input_train(Train* t)
{
    printf("Номер поезда: ");
    scanf("%d", &t->number);
    getchar();

    printf("Время прибытия (ЧЧ:ММ): ");
    fgets(t->arrival_time, 6, stdin);
    getchar();

    printf("Время отбытия (ЧЧ:ММ): ");
    fgets(t->departure_time, 6, stdin);
    getchar();

    printf("Направление: ");
    fgets(t->direction, 50, stdin);
    t->direction[strcspn(t->direction, "\n")] = 0;

    printf("Расстояние (км): ");
    scanf("%f", &t->distance);
    getchar();
}

// Функция вывода данных поезда на экран
void print_train(Train t)
{
    printf("-------------------------------\n");
    printf("Поезд №%d\n", t.number);
    printf("Прибытие: %s\n", t.arrival_time);
    printf("Отбытие: %s\n", t.departure_time);
    printf("Направление: %s\n", t.direction);
    printf("Расстояние: %.1f км\n", t.distance);
    printf("-------------------------------\n");
}

// Функция записи поезда в файл
void save_to_file(Train t, FILE* out)
{
    fprintf(out, "Поезд №%d\n", t.number);
    fprintf(out, "Время_прибытия: %s\n", t.arrival_time);
    fprintf(out, "Время_отбытия: %s\n", t.departure_time);
    fprintf(out, "Направление: %s\n", t.direction);
    fprintf(out, "Расстояние: %.1f\n", t.distance);
    fprintf(out, "-------------------------------\n");
}

// Функция чтения и вывода всех записей из файла
void print_all_from_file()
{
    FILE* in;
    char line[100];

    if ((in = fopen("trains.txt", "rt")) == NULL)
    {
        printf("Ошибка открытия файла для чтения\n");
        return;
    }

    while (fgets(line, sizeof(line), in) != NULL)
    {
        printf("%s", line);
    }

    fclose(in);
}
\```

<div align="center">

## 3. Результаты работы программы


<img width="519" height="456" alt="изображение" src="https://github.com/user-attachments/assets/71ae252c-3b44-4345-8e0c-55cc37919002" />




## 4. Информация о разработчике

Выполнил Гребенников Артем, бИПТ-252
