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