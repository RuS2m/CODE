#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    int vertex_num;
    std::cin >> vertex_num;
    int number;
    std::vector<std::vector<int>> count(vertex_num);
    for (size_t i = 0; i != vertex_num; ++i) {
        for (size_t j = 0; j != vertex_num; ++j) {
            std::cin >> number;
            count[i].push_back(number);
        }
    }
    std::vector<int> start(vertex_num);
    for (size_t i = 0; i != vertex_num; ++i) {
        start[i] = i;
    }
    int min_len = 10000000000000;
    int len = 0;
    while (next_permutation(start.begin(), start.end())) {
        for (size_t i = 0; i != vertex_num - 1; ++i) {
            if (count[start[i]][start[i + 1]] != 0) {
                len += count[start[i]][start[i + 1]];
            } else {
                len = -1;
                break;
            }
        }
        if ((len != -1) && (count[start[vertex_num - 1]][start[0]] != 0)) {
            len += count[start[vertex_num - 1]][start[0]];
            if (min_len >= len) {
                min_len = len;
            }
        }
        len = 0;
    }
    if (vertex_num == 1) {
        std::cout << number;
    } else if (min_len == 10000000000000 || min_len == 1316134912) {
        std::cout << -1;
    } else {
        std::cout << min_len;
    }
}