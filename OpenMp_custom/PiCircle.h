#pragma once
// author: Ключерев Артем

#include <omp.h>
#include <random>

// функция для вычисления значения pi, используя библиотеку OpenMP
double count_pi_parallel(const int num_points);

// функция для вычисления значения pi в одном потоке
double count_pi(const int num_points);

