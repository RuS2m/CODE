#include <iostream>
#include <vector>

using namespace std;

class Matrix {
 private:
    vector<vector<int>> data;

 public:
    Matrix(const vector<vector<int>>& d)
            : data(d) {
        bool error = false;
        for(size_t i = 0; i != data.size(); ++i) {
            if (data[i].size() != data[0].size()) {
                error = true;
                break;
            }
        }
        if(error) {
            throw std::length_error("constructor row length error");
        }
    }
    std::pair<size_t, size_t> size() const {
        return std::pair<size_t, size_t> (data.size(), data[0].size());
    }
    const int& operator() (size_t i, size_t j) const {
        return data[i][j];
    }

    int& operator() (size_t i, size_t j) {
        return data[i][j];
    }
    void print() const{
        for (size_t i = 0; i != data.size(); i++) {
            for (size_t j = 0; j != data[0].size(); j++) {
                cout << data[i][j];
                if (j != data[0].size() - 1) {
                    cout << "\t";
                } else {
                    if (i != data.size() - 1) {
                        cout << "\n";
                    }
                }
            }
        }
        cout << "\n";
    }
    int get_elem(int row, int col) const {
        if ((row >= data.size()) || (col >= data[0].size())) {
            throw std::out_of_range("get_elem bad indexes");
        }
        return data[row][col];
    }
    Matrix operator+(const Matrix& other) const {
        vector<vector<int>> m;
        m.resize(((*this).size().first));
        for (size_t i = 0; i != (*this).size().first; i++) {
            m[i].resize(other.size().second);
        }

        for (size_t i = 0; i != other.size().first; i++) {
            for (size_t j = 0; j != other.size().second; j++) {
                m[i][j] = (*this)(i, j) + other(i, j);
            }
        }
        Matrix C(m);
        if (other.size() != (*this).size()) {
            throw std::length_error("operator+ size error");
        }
        return C;
    }
};