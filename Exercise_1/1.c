#define _CRT_SECURE_NO_WARNINGS

// Необходимые библиотеки
#include <stdio.h>
#include <locale.h>

// Основная функция
int main()
{
    // Русская локаль
    setlocale(LC_CTYPE, "RUS");

    char fname[20] = "number.txt";
    FILE* out;

    puts("Создание файла number.txt");

    // А) Создание файла с записью числа 5
    if ((out = fopen(fname, "wt")) == NULL)
    {
        printf("Ошибка открытия файла для записи\n");
        return 0;
    }

    fprintf(out, "%d", 5);
    fclose(out);
    printf("Файл создан с числом 5\n\n");

    // Б) Добавление числа 12.56 в файл
    puts("Добавление числа 12.56 в файл");
    if ((out = fopen(fname, "at")) == NULL)
    {
        printf("Ошибка открытия файла для добавления\n");
        return 0;
    }

    fprintf(out, " 12.56");
    fclose(out);
    printf("Число 12.56 добавлено\n\n");

    // В) Запись каждого числа с новой строки
    puts("Запись чисел с новой строки");
    if ((out = fopen(fname, "wt")) == NULL)
    {
        printf("Ошибка открытия файла для записи\n");
        return 0;
    }

    fprintf(out, "5\n");
    fprintf(out, "12.56\n");
    fprintf(out, "100\n");
    fprintf(out, "3.14\n");

    fclose(out);
    printf("Числа записаны с новой строки\n");

    getchar();
    return 1;
}