#include <iostream>
#include <vector>
#include <algorithm>

struct bean {
    int weight = 0;
    int first_number = 0;
    int second_number = 0;
    bool operator < (bean b) {
        return weight < b.weight;
    }
};

int main() {
    int N, M;
    std::cin >> N >> M;
    std::vector<bean> Bean(M);
    bean temp;
    for (int i = 0; i != M; ++i) {
        std::cin >> temp.first_number >> temp.second_number >> temp.weight;
        Bean[i] = temp;
    }
    std::vector<int> id(N + 1);
    for (int i = 1; i != N + 1; ++i) {
        id[i] = i;
    }
    int answer = 0;
    std::sort(Bean.begin(), Bean.end());
    int fn, sn, w;
    for (bean elem : Bean) {
        fn = elem.first_number;
        sn = elem.second_number;
        w = elem.weight;
        if (id[fn] != id[sn]) {
            answer += w;
            int old = id[sn];
            for (int i = 1; i != N + 1; ++i) {
                if (id[i] == old) {
                    id[i] = id[fn];
                }
            }
        }
    }
    std::cout << answer;
}

