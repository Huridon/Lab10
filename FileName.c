#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <math.h>
#include <locale.h>

double F1(double x);
double F2(double x);
double ExpN(double x, int N);
double ExpEps(double x, double eps);
double AreaSquare(double a);
int GetSide(int r);
int CompareSquare(int r1, int r2);
char Task3(int r, int c, int side, char sym);
int ClearInput();

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");

    // Task1
    printf("Задание 1\n\n");

    double x, f1v, f2v;
    int choice, ok;

    printf("Введите значение x: ");
    ok = scanf("%lf", &x);
    ClearInput();

    if (ok != 1)
    {
        printf("Ошибка ввода x!\n");
    }
    else
    {
        printf("\nМЕНЮ\n");
        printf("1) Вычислить f1(x)\n");
        printf("2) Вычислить f2(x)\n");
        printf("3) Вычислить произведение f1(x) * f2(x)\n");
        printf("4) Вычислить разность квадратов f1(x)^2 - f2(x)^2\n");
        printf("5) Вычислить удвоенную сумму 2 * (f1(x) + f2(x))\n");
        printf("6) Выполнить все расчеты вместе\n");
        printf("\nВыберите пункт меню (1-6): ");
        ok = scanf("%d", &choice);
        ClearInput();
        printf("\n");

        if (ok != 1)
        {
            printf("Ошибка ввода пункта меню!\n");
        }
        else
        {
            f1v = F1(x);
            f2v = F2(x);

            switch (choice)
            {
            case 1:
                printf("f1(x) = %lf\n", f1v);
                break;
            case 2:
                printf("f2(x) = %lf\n", f2v);
                break;
            case 3:
                printf("f1(x) * f2(x) = %lf\n", f1v * f2v);
                break;
            case 4:
                printf("f1(x)^2 - f2(x)^2 = %lf\n", f1v * f1v - f2v * f2v);
                break;
            case 5:
                printf("2 * (f1(x) + f2(x)) = %lf\n", 2 * (f1v + f2v));
                break;
            case 6:
                printf("f1(x) = %lf\n", f1v);
                printf("f2(x) = %lf\n", f2v);
                printf("f1(x) * f2(x) = %lf\n", f1v * f2v);
                printf("f1(x)^2 - f2(x)^2 = %lf\n", f1v * f1v - f2v * f2v);
                printf("2 * (f1(x) + f2(x)) = %lf\n", 2 * (f1v + f2v));
                break;
            default:
                printf("Неверный пункт меню!\n");
            }
        }
    }

    // Task2
    printf("\nЗадание 2\n\n");

    double x2, eps, stdExp, curExp, epsExp;
    int n, ok1, ok2;

    printf("Введите значение x (например, 0,79): ");
    ok1 = scanf("%lf", &x2);
    ClearInput();

    printf("Введите точность eps (например, 1e-6): ");
    ok2 = scanf("%lf", &eps);
    ClearInput();

    if (ok1 != 1)
    {
        printf("Ошибка ввода x!\n");
    }
    else if (ok2 != 1 || eps <= 0)
    {
        printf("Ошибка: eps должно быть числом больше нуля\n");
    }
    else
    {
        printf("\nСПОСОБ 1\n");
        stdExp = exp(-x2);
        printf("Эталонное значение exp(-%.4lf) = %lf\n", x2, stdExp);

        printf("\nСПОСОБ 2\n");
        printf("%3s | %10s | %s\n", "N", "ExpN", "отклонение");
        printf("-----------------------------------\n");

        for (n = 1; n <= 20; n++)
        {
            curExp = ExpN(x2, n);
            printf("%3d | %10.6lf | %+e\n", n, curExp, curExp - stdExp);
        }

        printf("\nСПОСОБ 3\n");
        epsExp = ExpEps(x2, eps);
        printf("Значение с точностью %e = %lf\n", eps, epsExp);
        printf("Отклонение от эталона: %+e\n", epsExp - stdExp);
    }

    // Task3
    printf("\nЗадание 3\n\n");

    int r, r2, side, row, col, menu;
    char sym, cell;

    printf("Введите r (количество символов): ");
    ok = scanf("%d", &r);
    ClearInput();

    if (ok != 1 || r <= 0)
    {
        printf("Ошибка ввода: r должно быть целым числом больше нуля\n");
    }
    else
    {
        side = GetSide(r);

        printf("\nМеню операций:\n");
        printf("1) Рассчитать площадь фигуры\n");
        printf("2) Вывести определение фигуры\n");
        printf("3) Нарисовать фигуру\n");
        printf("4) Сравнить по площади с другим квадратом\n");
        printf("\nВыберите пункт меню (1-4): ");
        ok = scanf("%d", &menu);
        ClearInput();
        printf("\n");

        if (ok != 1)
        {
            printf("Ошибка ввода пункта меню!\n");
        }
        else
        {
            switch (menu)
            {
            case 1:
                printf("Сторона квадрата: %d\n", side);
                printf("Площадь: %.2lf кв. ед.\n", AreaSquare(side));
                break;

            case 2:
                printf("Определение фигуры:\n");
                printf("Правильный четырёхугольник (квадрат) — это четырёхугольник,\n");
                printf("у которого все стороны равны и все углы прямые.\n");
                printf("Площадь квадрата равна квадрату длины его стороны.\n");
                break;

            case 3:
                printf("Введите символ для рисования контура: ");
                ok = scanf(" %c", &sym);
                ClearInput();

                if (ok != 1)
                {
                    printf("Ошибка ввода символа!\n");
                }
                else
                {
                    printf("\nВаша фигура:\n\n");

                    for (row = 0; row < side; row++)
                    {
                        for (col = 0; col < side; col++)
                        {
                            cell = Task3(row, col, side, sym);
                            printf("%c", cell);
                        }
                        printf("\n");
                    }
                }
                break;

            case 4:
                printf("Введите r второго квадрата: ");
                ok = scanf("%d", &r2);
                ClearInput();

                if (ok != 1 || r2 <= 0)
                {
                    printf("Ошибка ввода: r должно быть целым числом больше нуля\n");
                }
                else
                {
                    printf("Разность площадей (первый - второй): %d кв. ед.\n",
                        CompareSquare(r, r2));
                }
                break;

            default:
                printf("Неверный пункт меню!\n");
            }
        }
    }

    return 0;
}

double F1(double x)
{
    if (x <= 3)
        return x * x - 3 * x + 9;
    else
        return 1.0 / (x * x * x + 3);
}

double F2(double x)
{
    return x * exp(sin(x * x));
}

// e^-x = sum (-1)^k x^k / k!, суммируются N членов ряда
double ExpN(double x, int N)
{
    double sum = 0.0;
    double term = 1.0;
    int k;

    for (k = 0; k < N; k++)
    {
        sum += term;
        term = term * (-x) / (k + 1);
    }
    return sum;
}

// суммирование, пока модуль очередного члена больше eps (eps > 0 проверяется в main)
double ExpEps(double x, double eps)
{
    double sum = 0.0;
    double term = 1.0;
    int k = 0;

    while (fabs(term) > eps)
    {
        sum += term;
        term = term * (-x) / (k + 1);
        k++;
    }
    return sum;
}

double AreaSquare(double a)
{
    return a * a;
}

int GetSide(int r)
{
    return 2 * r;
}

int CompareSquare(int r1, int r2)
{
    return (int)(AreaSquare(GetSide(r1)) - AreaSquare(GetSide(r2)));
}

// возвращает символ для клетки (r, c): контур или пробел
char Task3(int r, int c, int side, char sym)
{
    if (r == 0 || r == side - 1 || c == 0 || c == side - 1)
        return sym;
    else
        return ' ';
}

int ClearInput()
{
    int ch = getchar();

    while (ch != '\n' && ch != EOF)
        ch = getchar();

    return ch;
}