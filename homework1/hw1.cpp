#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <cmath>

bool is_on_left(int x0, int y0, int x, int y) {
	if (y0*x < x0*y) {
		return true;
	} else {
		return false;
	}
}

double scalar_prod_normalized(int x0, int y0, int x, int y) {
	return (x0*x+y0*y)/(sqrt(x*x+y*y)*sqrt(x0*x0+y0*y0));
}

int main() {
	std::ifstream infile("in.txt");

	int x, y;

	int left_x = 0, left_y = 0;
	int right_x = 0, right_y = 0;
	double right_cos = 1;
	double left_cos = 1;

	int x0, y0;
	infile >> x0 >> y0;


	while (infile >> x >> y) {

		double sc_prod = scalar_prod_normalized(x0, y0, x, y);
		sc_prod = std::round(sc_prod * 10000000000.0) / 10000000000.0;
		bool on_left = is_on_left(x0, y0, x, y);

		if (sc_prod <= left_cos && on_left) {
			left_cos = sc_prod;
			left_x = x; left_y = y;

		}
		if (sc_prod <= right_cos && !on_left) {
			right_cos = sc_prod;
			right_x = x; right_y = y;
		}
	}

	std::cout << "Leftmost: " << left_x << " " << left_y << std::endl;
	std::cout << "Rightmost: " << right_x << " " << right_y << std::endl;
}
