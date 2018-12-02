#ifndef CORE_H
#define CORE_H
#include <iostream>
#include <cmath>
#include <exception>
#include <string.h>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <limits>
#include <stdio.h>
#include <stdlib.h>

void calc_results(long double start, long double end, long double step, long double prec);
void fetch_file_data(std::ifstream &fin, long double &start, long double &end,
                     long double &step, long double prec);
bool read_from_file(long double &start, long double &end, long double &step, long double &prec);
void create_table_hat();
void add_table_row(long double x, long double embedded_func,
                   long double my_func, long double diviation, long long steps);
long double rec(long double x, long double prec, long double a1,long double sum, long long &n);
template <typename Str, typename T>
void input (Str * msg, T &inp_var);
bool start_work();
void calc_results(std::ofstream &fout, long double start, long double end, long double step, long double prec);
void add_table_row(std::ofstream &fout, const long double x, const long double embedded_func,
                   const long double my_func, const long double diviation, const long long steps);
void create_table_hat(std::ofstream &fout);
bool write_in_file_func(long double start, long double end, long double step, long double prec);


#endif // CORE_H
