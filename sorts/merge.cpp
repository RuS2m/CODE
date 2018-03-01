#include <iostream>
#include <vector>


std::vector<int> two_vectors_merger(std::vector<int>::iterator begin1,
                                    std::vector<int>::iterator end1,
                                    std::vector<int>::iterator begin2,
                                    std::vector<int>::iterator end2) {
    std::vector<int> merger(end1  - begin1 + end2 - begin2);
    std::vector<int>::iterator counter1 = begin1;
    std::vector<int>::iterator counter2 = begin2;
    for (size_t i = 0; i != end1 - begin1 + end2 - begin2; i++) {
        if (counter1 == end1) {
            merger[i] = *counter2;
            counter2++;
        } else if (counter2 == end2) {
            merger[i] = *counter1;
            counter1++;
        } else {
            if (*counter1 <= *counter2) {
                merger[i] = *counter1;
                counter1++;
            } else {
                merger[i] = *counter2;
                counter2++;
            }
        }
    }
    return merger;
}

void merge_sort(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if ((end - begin) > 1) {
        int temp = (end - begin) / 2;
        merge_sort(begin, temp + begin);
        merge_sort(temp + begin, end);
        std::vector<int> vec = two_vectors_merger(begin, temp + begin, temp + begin, end);
        for (size_t i = 0; i != end - begin; i++) {
            *(begin + i) = vec[i];
        }
    }
}

int main() {
    int N;
    std::cin >> N;
    std::vector<int> vec(N);
    for (size_t i = 0; i < N; i ++) {
        std::cin >> vec[i];
    }
    merge_sort(vec.begin(), vec.end());
    for (size_t i = 0; i != N; i ++) {
        std::cout << vec[i] << " ";
    }
}

