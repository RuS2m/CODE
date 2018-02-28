#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

void next(std::vector<int> &vector) {
    if (vector[vector.size() - 1] == 0) {
        vector[vector.size() - 1] = 1;
    } else {
        int i = vector.size() - 1;
        while (vector[i] == 1) {
            vector[i] = 0;
            i--;
        }
        vector[i] = 1;
    }
}

int max_cut(std::vector<std::vector<int>> &count, std::vector<int> &vector) {
    int max_cut = 0;
    for (size_t i = 0; i != vector.size(); ++i) {
        if (vector[i] == 1) {
            for (size_t j = 0; j != vector.size(); ++j) {
                if (vector[j] == 0) {
                    max_cut += count[i][j];
                }
            }
        }
    }
    return max_cut;
}

int main() {
    int vertex_num;
    std::cin >> vertex_num;
    int all = std::pow(2, vertex_num);
    int number;
    std::vector<std::vector<int>> count(vertex_num);
    for (size_t i = 0; i != vertex_num; ++i) {
        for (size_t j = 0; j != vertex_num; ++j) {
            std::cin >> number;
            count[i].push_back(number);
        }
    }
    std::vector<int> start(vertex_num, 0);
    start[vertex_num - 1] = 1;
    std::vector<int> end(vertex_num, 0);
    int max = 0;
    for (size_t i = 0; i != all - 2; ++i) {
        if (max <= max_cut(count, start)) {
            max = max_cut(count, start);
            end = start;
        }
        next(start);
    }
    std::cout << max << "\n";
    for (int elem : end) {
        std::cout << elem + 1 << " ";
    }
}