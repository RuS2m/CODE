#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <set>

int main() {
    int N;
    std::cin >> N;
    std::vector<std::vector<int>> Bean(N, std::vector<int> (N, 0));
    std::vector<std::vector<int>> length(N, std::vector<int> (N, 1000000));
    for (size_t i = 0; i != N; ++i) {
        for (size_t j = 0; j != N; ++j) {
            std::cin >> Bean[i][j];
            length[i][j] = Bean[i][j];
        }
    }
    for (size_t i = 0; i != N; ++i) {
        length[i][i] = 0;
    }
    for (size_t k = 0; k != N; ++k) {
        for (size_t i = 0; i != N; ++i) {
            for (size_t j = 0; j != N; ++j) {
                if (length[i][j] > length[i][k] + length[k][j]) {
                    length[i][j] = length[i][k] + length[k][j];
                }
            }
        }
    }
    for (size_t i = 0; i != N; ++i) {
        for (size_t j = 0; j != N; ++j) {
            std::cout << length[i][j] << " ";
        }
        std::cout << "\n";
    }
}

