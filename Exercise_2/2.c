#define _CRT_SECURE_NO_WARNINGS

// Необходимые библиотеки
#include <stdio.h>
#include <locale.h>
#include <math.h>

// Основная функция
int main()
{
    // Русская локаль
    setlocale(LC_CTYPE, "RUS");

    FILE* out;
    char choice;
    double start, end, step, x, y;
    char mode[3];

    printf("Табулирование функции y = sin(x) + cos(x)\n");

    // Выбор режима работы с файлом
    printf("Выберите действие:\n");
    printf("1 - Запись в новый файл\n");
    printf("2 - Дозапись в существующий файл\n");
    printf("Ваш выбор: ");
    scanf("%c", &choice);
    getchar();

    if (choice == '1')
        strcpy(mode, "wt");
    else if (choice == '2')
        strcpy(mode, "at");
    else
    {
        printf("Неверный выбор\n");
        return 0;
    }

    // Ввод параметров табулирования
    printf("Введите начало интервала: ");
    scanf("%lf", &start);
    getchar();

    printf("Введите конец интервала: ");
    scanf("%lf", &end);
    getchar();

    printf("Введите шаг табуляции: ");
    scanf("%lf", &step);
    getchar();

    // Открытие файла
    if ((out = fopen("temp.txt", mode)) == NULL)
    {
        printf("Ошибка открытия файла\n");
        return 0;
    }

    // Заголовок в файл
    if (choice == '1')
    {
        fprintf(out, "Табулирование функции y = sin(x) + cos(x)\n");
        fprintf(out, "Интервал: [%.2lf, %.2lf]\n", start, end);
        fprintf(out, "Шаг: %.2lf\n\n", step);
        fprintf(out, "   x        y\n");
        fprintf(out, "-----------------\n");
    }

    // Табулирование и запись в файл
    printf("\nВычисление...\n");
    for (x = start; x <= end; x += step)
    {
        y = sin(x) + cos(x);
        fprintf(out, "%6.2lf   %8.4lf\n", x, y);
        printf("x = %6.2lf, y = %8.4lf\n", x, y);
    }

    fclose(out);
    printf("\nРезультаты записаны в файл temp.txt\n");

    getchar();
    return 0;
}