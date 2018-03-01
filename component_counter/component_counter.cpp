#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <list>
#include <set>
void DFS(std::vector<std::unordered_set<int>>& Tree, std::vector<int>& colour
        , int v, std::vector<std::set<int>>& answer, int component_number) {
    if (colour[v] == 0) {
        colour[v] = 1;
        answer[component_number].insert(v);
        for (int elem : Tree[v]) {
            DFS(Tree, colour, elem, answer, component_number);
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
    int counter = 0;
    std::vector<std::set<int>> ans;
    std::set<int> temp;
    for (size_t i = 0; i != vamount; ++i) {
        if (!colour[i]) {
            ans.push_back(temp);
            DFS(Tree, colour, i, ans, counter);
            counter++;
        }
    }
    std::cout << counter << "\n";
    for (size_t i = 0; i != counter; ++i) {
        std::cout << ans[i].size() << "\n";
        for (int elem : ans[i]) {
            std::cout << elem + 1 << " ";
        }
        std::cout << "\n";
    }
}