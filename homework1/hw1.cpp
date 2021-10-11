#include <iostream>
#include <fstream>

int main() {
    std::ifstream input_file("in.txt");
    int a;

    std::ofstream out_file("result.txt");
    out_file << "Result";
    out_file << a*a << '\n';

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
