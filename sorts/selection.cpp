#include <iostream>
#include <vector>


void swap_max_end_end(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    std::vector<int>::iterator max = end - 1;
    for (std::vector<int>::iterator i = end - 1; i >= begin; i--) {
        if (*i >= *max) {
            max = i;
        }
    }
    int temp = *max;
    *max = *(end - 1);
    *(end - 1) = temp;
}

int main() {
    int N;
    std::cin >> N;
    std::vector<int> vec(N);
    for (size_t i = 0; i < N; i ++) {
        std::cin >> vec[i];
    }
    if (N != 0) {
        std::vector<int>::iterator temp_end = vec.end();
        while (temp_end - 1 != vec.begin()) {
            swap_max_end_end(vec.begin(), temp_end);
            temp_end--;
        }
    }
    for (size_t i = 0; i < N; i ++) {
        std::cout << vec[i] << " ";
    }
}

