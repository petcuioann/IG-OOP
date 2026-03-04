#include "problem_05.h"

double power(double x, int n) {
    double res = 1.0;
    while (n > 0) {
        if (n % 2 == 1) res *= x;
        x *= x;
        n /= 2;
    }
    return res;
}

bool is_opposite(int a, int b) {
    return (a > 0 && b < 0) || (a < 0 && b > 0); // viteza optima
    // return (a * b < 0); // claritate cod optim
}

std::vector<int> get_longest_opposite_signs(const std::vector<int>& v) {
    if (v.empty()) return {};

    int b_len = 1, b_start = 0;
    int c_len = 1, c_start = 0;

    for (int i = 0; i < (int)v.size() - 1; ++i) {
        if (is_opposite(v[i], v[i+1])) {
            c_len++;
            if (c_len > b_len) {
                b_len = c_len;
                b_start = c_start;
            }
        }
        else {
            c_len = 1;
            c_start = i + 1;
        }
    }

    std::vector<int> res;
    for (int i = b_start; i < b_start + b_len; ++i)
        res.push_back(v[i]);
    return res;
}