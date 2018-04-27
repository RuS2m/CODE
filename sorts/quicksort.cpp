#include <iostream>
#include <vector>

using namespace std;

std::vector <int>::iterator partition (std::vector<int>::iterator v_begin, std:vector<int>::iterator v_end, int g) {
    std::vector<int>::iterator last = v_begin;
    for (std::vector<int>::iterator i = v_begin; i != v_end; ++i) {
        if (*i < g) {
            std::swap(*i, *last);
            last++;
        }
    }
    return last;
}

void quick_sort(std::vector<int>::iterator v_begin, std::vector<int>::iterator v_end) {
    if ((v_end - v_begin) < 2) {
        return;
    }
    int Max = -1000000000;
    int Min = 1000000000;
    for (std::vector<int>::iterator i = v_begin; i != v_end; ++i) {
        if (*i < Min) {
            Min = *i;
        }
        if (*i > Max) {
            Max = *i;
        }
    }
    if (Min == Max) {
        return;
    }
    int g = (Max + Min) / 2;
    if (g == Max) {
        g--;
    } else if (g == Min) {
        g++;
    }
    std::vector<int>::iterator middle = partition(v_begin, v_end, g);
    quicksort(v_begin, middle);
    quicksort(middle, v_end);
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> v;
    for (size_t i = 0; i != n; ++i) {
        int a;
        std::cin >> a;
        v.push_back(a);
    }
    quicksort(v.begin(), v.end());
    for (size_t i = 0; i != n; ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << "\n";
    return 0;
}
