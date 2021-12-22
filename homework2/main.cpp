#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>


int main(int argc, char** argv) {

    std::ifstream infile(argv[1]);

    std::vector<double> x_i;
    std::vector<double> y_i;

    double h;  infile >> h;


    double x = 0;
    double v_x, v_y;
    infile >> v_x >> v_y;

    double g = -9.81;

    int n = 0;

    int size = 0;
    double x_n, y_n;
    while (infile >> x_n >> y_n) { //Считаем координаты из файла
        x_i.push_back(x_n);
        y_i.push_back(y_n);
        size++;
    }

    while (true) {
        int next;
        if (v_x > 0) {
            next = n;
        } else {
            next = n - 1;
        }
        if (next < 0) {
            std::cout << "0" << std::endl; //Вылет за левый край
            return 0;
        }
        if (next > size - 1) {
            std::cout << size << std::endl; //Вылет за правый край
            return 0;
        }

        double t = std::abs((x - x_i[next]) / v_x);

        x = x_i[next];
        h = h + v_y * t + 0.5 * g * t * t;
        v_y = v_y + g * t;

        if (h <= 0) {
            std::cout << n << std::endl; //Упали на n промежутке
            return 0;
        }
        if (h > y_i[next]) {
            if (v_x > 0) {
                n++;
            } else {
                n--;
            }
        } else {
            v_x = v_x * (-1);
        }
    }

}
