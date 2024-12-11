#pragma once
// author:  лючерев јртем

#include <omp.h>
#include <random>
// author:  лючерев јртем

#include "PiCircle.h"

// функци€ дл€ вычислени€ значени€ pi, использу€ библиотеку OpenMP
double count_pi_parallel(const int num_points) {

    int num_inside = 0;

    // parallel - опредл€ет код, который будет параллельно выполн€тьс€ несколькими потоками
    // for - распараллеливание цикла
    // reduction(+:num_inside) - здесь + это операци€, num_inside - обща€ переменна€, 
    // локальный экземпл€р которой создаЄтс€ дл€ каждого потока
    // reduction решает проблему, св€занную с неопределЄнностью параллелизма
#pragma omp parallel for reduction(+:num_inside)
    for (int i = 0; i < num_points; ++i) {
        double x = (double)rand() / RAND_MAX;
        double y = (double)rand() / RAND_MAX;

        //cout << x << " " << y << endl;
        //провер€ем попала ли точка в окружность,если да,то увеличиваем счетчик на 1
        if (x * x + y * y <= 1) {
            num_inside++;
        }
    }

    double pi = 4.0 * ((double)num_inside / num_points);
    return pi;
}

// функци€ дл€ вычислени€ значени€ pi в одном потоке
double count_pi(const int num_points) {

    int num_inside = 0;
    double x, y;

    for (int i = 0; i < num_points; ++i) {
        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;

        //cout << x << " " << y << endl;

        if (x * x + y * y <= 1) {
            num_inside++;
        }
    }

    double pi = 4.0 * ((double)num_inside / num_points);
    return pi;
}
// функци€ дл€ вычислени€ значени€ pi, использу€ библиотеку OpenMP
double count_pi_parallel(const int num_points);

// функци€ дл€ вычислени€ значени€ pi в одном потоке
double count_pi(const int num_points);

