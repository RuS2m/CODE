#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <set>
#include <queue>
int main() {
    int number;
    std::cin >> number;
    std::vector<std::vector<int>> Tree(number + 1);
    std::vector<int> el(number + 1);
    for (size_t i = 1; i != number + 1; ++i) {
        Tree[i] = el;
    }
    for (size_t i = 1; i != number + 1; ++i) {
        for (size_t j = 1; j != number + 1; ++j) {
            std::cin >> Tree[i][j];
        }
    }
    int start, end;
    std::cin >> start >> end;
    std::queue<int> burn;
    burn.push(start);
    std::vector<bool> used(number + 1);
    std::vector<int> d(number + 1);
    std::vector<int> p(number + 1);
    used[start] = true;
    while (!burn.empty()) {
        int v = burn.front();
        burn.pop();
        for (int i = 1; i != number + 1; ++i) {
            if (Tree[v][i] && !used[i]) {
                burn.push(i);
                used[i] = true;
                d[i] = d[v] + 1;
                p[i] = v;
            }
        }
    }
    if (!used[end]) {
        std::cout << "-1";
    } else {
        std::vector<int> s;
        for (int v = end; v > 0; v = p[v]) {
            s.push_back(v);
        }
        std::cout << s.size() - 1 << "\n";
        if (s.size() != 1) {
            std::reverse(s.begin(), s.end());
            for (size_t i = 0; i != s.size(); ++i)
                std::cout << s[i] << " ";
        }
    }
}