// ConsoleApplication_openmp_pi.cpp

// author: Ключерев Артем
// формула вычисления числа pi: https://habr.com/ru/articles/128454/

#include <iostream>
#include <omp.h>
#include <random>
#include <chrono>
#include "PiCircle.h"

using namespace std;

// функция для получение числа потоков
int get_Num_threads() {
    int num_threads = 0;

    // директивf OpenMP, которая указывает компилятору, что следующий блок кода должен выполняться параллельно
#pragma omp parallel reduction(+:num_threads) 
    num_threads += 1;

    return num_threads;
}

int main() {

    setlocale(LC_ALL, "Russian");
    const int num_points = 10'000'000; // Общее количество точек используемых для вычисления числа π

    srand(time(nullptr));


    // начало измерения времени
    auto startTime = chrono::high_resolution_clock::now();

    double pi = count_pi(num_points);


    // конец измерения времени
    auto endTime = chrono::high_resolution_clock::now();

    // рассчитываем время выполнения перемножения
    auto duration = chrono::duration_cast<chrono::nanoseconds>(endTime - startTime).count();

    std::cout << "Результат вычисления значения pi без распараллеливания: " << pi << std::endl;
    std::cout << "Время выполнения: " << duration <<" наносекнуд" << endl << endl;


    // начало измерения времени
    auto startTime1 = chrono::high_resolution_clock::now();

    pi = count_pi_parallel(num_points);



    // конец измерения времени
    auto endTime1 = chrono::high_resolution_clock::now();

    // рассчитываем время выполнения перемножения
    auto duration1 = chrono::duration_cast<chrono::nanoseconds>(endTime1 - startTime1).count();
    std::cout << "Результат вычисления значения pi c использованием библиотеки OpenMP: " << pi << std::endl;
    std::cout << "Время выполнения: " << duration1 << " наносекнуд" << endl << endl;
    //std::cout << "Вычисленное значение Pi: " << pi << std::endl;

    cout << "Число потоков: " << get_Num_threads() << endl;

    return 0;
}
