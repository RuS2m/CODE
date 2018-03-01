#include <iostream>
#include <vector>
#include <string>

using namespace std;
void Dijkstra(std::vector<std::vector<int>> &table, std::vector<int> &min_len,
              std::vector<bool> &been, std::vector<int> &pred) {
    int m = been.end() - been.begin() + 2;
    auto min_it = been.end();
    int current_number;
    for (auto it = been.begin() + 1; it != been.end(); ++it) {
        current_number = it - been.begin();
        if (*it == false && min_len[current_number] < m) {
            m = min_len[it - been.begin()];
            min_it = it;
        }
    }
    been[min_it - been.begin()] = true;
    for (int i = 1; i != been.size(); ++i) {
        if (table[i][min_it - been.begin()] != 0) {
            min_len[i] = std::min(min_len[i], min_len[min_it - been.begin()] + 1);
            if (std::min(min_len[i], min_len[min_it - been.begin()] + 1)
                == min_len[min_it - been.begin()] + 1) {
                pred[i] = min_it - been.begin();
            }
        }
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> table(n + 1, std::vector<int> (n + 1));
    for (int i = 0; i < m; i++) {
        std::vector<int> stations;
        int s;
        std::cin >> s;
        for (int k = 0; k < s; k++) {
            int st;
            std::cin >> st;
            stations.push_back(st);
        }
        for (int x = 0; x < s; x++) {
            for (int y = 0; y < s; y++) {
                table[stations[x]][stations[y]] = 1;
                table[stations[y]][stations[x]] = 1;
            }
        }
    }
    int beg, fin;
    std::cin >> beg >> fin;
    std::vector<int> min_len(n + 1, n);
    min_len[beg] = 0;
    std::vector<int> pred(n + 1);
    std::vector<bool> been(n + 1, 0);
    int p = beg;
    for (int k = 0; k != n + 1; ++k) {
        Dijkstra(table, min_len, been, pred);
    }
    std::vector<int> result;
    if (min_len[fin] == n)
        std::cout << -1;
    else
        std::cout << min_len[fin] - 1;
}

