#include "problem_04.h"

int max2(int a, int b) {
    return (a > b) ? a : b;
}

int get_max_from_vector(const std::vector<int>& v) {
    if (v.empty()) return -1;
    int m = v[0];
    for (int x : v)
        m = max2(m, x);
    return m;
}

std::vector<int> get_longest_in_interval(const std::vector<int>& v, int min_v, int max_v) {
    int b_len = 0;
    int b_start = -1;
    int c_len = 0;
    int c_start = 0;

    for (int i = 0; i < (int)v.size(); ++i) {
        if (v[i] >= min_v && v[i] <= max_v) {
            if (c_len == 0) c_start = i;
            c_len++;
            if (c_len > b_len) {
                b_len = c_len;
                b_start = c_start;
            }
        }
        else c_len = 0;
    }

    if (b_start == -1) return {};

    return std::vector<int>(v.begin() + b_start, v.begin() + b_start + b_len);
}