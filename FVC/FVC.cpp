#include <algorithm>
#include <iostream>
#include <time.h>
#include <vector>
#include <set>
#include <cmath>
#include <utility>
#include <unordered_set>

int main() {
    int number_of;
    int edge_number = 0;
    std::cin >> number_of;
    std::vector<std::unordered_set<int>> adjacency(number_of);
    int adj_size;
    int number;
    for (size_t i = 0; i != number_of; ++i) {
        std::cin >> adj_size;
        edge_number += adj_size;
        for (size_t j = 0; j != adj_size; ++j) {
            std::cin >> number;
            adjacency[i].insert(number);
        }
    }
    edge_number = edge_number / 2;
    int parent;
    int vertex_cover = 0;
    while (edge_number != 0) {
        for (size_t i = 0; i != adjacency.size(); ++i) {
            if ((adjacency[i].size() == 1) && (*adjacency[i].begin() != number_of + 1)) {
                parent = *adjacency[i].begin();
                for (int elem : adjacency[parent]) {
                    edge_number--;
                    adjacency[elem].erase(parent);
                    if (adjacency[elem].size() == 0) {
                        adjacency[elem].insert(number_of + 1);
                    }
                }
                for (int elem : adjacency[parent]) {
                    adjacency[parent].erase(elem);
                }
                adjacency[parent].insert(number_of + 1);
                vertex_cover++;
            }
        }
    }
    std::cout << vertex_cover;
}