#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

void DFS(std::vector<std::unordered_set<int>>& Tree, std::vector<int>& colour, int v) {
    if (colour[v] == 0) {
        colour[v] = 1;
        for (int elem : Tree[v]) {
            DFS(Tree, colour, elem);
        }
        colour[v] = 2;
    }
}
int main() {
    int vamount;
    int ramount;
    int vnumber1;
    int vnumber2;
    std::cin >> vamount >> ramount;
    std::vector<int> colour(vamount);
    for (size_t j = 0; j != vamount; ++j) {
        colour[j] = 0;
    }
    std::vector<std::unordered_set<int>> Tree(vamount);
    for (size_t i = 0; i != ramount; ++i) {
        std::cin >> vnumber1 >> vnumber2;
        Tree[vnumber1 - 1].insert(vnumber2 - 1);
        Tree[vnumber2 - 1].insert(vnumber1 - 1);
    }
    DFS(Tree, colour, 0);
    int answer = 0;
    for (int elem : colour) {
        if (elem == 2) {
            ++answer;
        }
    }
    std::cout << answer << "\n";
    for (size_t i = 0; i != vamount; ++i) {
        if (colour[i] == 2) {
            std::cout << i + 1 << " ";
        }
    }
}