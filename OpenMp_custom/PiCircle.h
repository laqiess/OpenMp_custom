#pragma once
// author: �������� �����

#include <omp.h>
#include <random>

// ������� ��� ���������� �������� pi, ��������� ���������� OpenMP
double count_pi_parallel(const int num_points);

// ������� ��� ���������� �������� pi � ����� ������
double count_pi(const int num_points);

