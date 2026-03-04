#include "run_app.h"
#include "problem_04.h"
#include "problem_05.h"
#include <iostream>
#include <string>
#include <vector>

void run_4a() {
    std::cout << "\nproblem 4a\n";
    int val, global_max = -1;
    std::vector<int> current_seq;

    std::cout << "numbers (0 = end per sequence, -1 = end):\n";
    while (std::cin >> val && val != -1) {
        if (val == 0) {
            int m = get_max_from_vector(current_seq);
            if (m != -1) {
                std::cout << "sequence max: " << m << "\n";
                global_max = max2(global_max, m);
            }
            current_seq.clear();
        }
        else current_seq.push_back(val);
    }
    if (global_max != -1)
        std::cout << "global max: " << global_max << "\n";
}

void run_4b() {
    std::cout << "\nproblem 4b\n";
    int n, low, high;
    std::cout << "number of elements: ";
    std::cin >> n;

    std::vector<int> v(n);
    std::cout << "elements: ";
    for (int i = 0; i < n; ++i) std::cin >> v[i];

    std::cout << "interval [min, max]: ";
    std::cin >> low >> high;

    std::vector<int> res = get_longest_in_interval(v, low, high);
    if (!res.empty()) {
        std::cout << "longest sequence: ";
        for (int x : res) std::cout << x << " ";
        std::cout << "\nlength: " << res.size() << "\n";
    }
    else std::cout << "no elements found in the given interval.\n";
}

void run_5a() {
    std::cout << "\nproblem 5a\n";
    double x;
    int n;
    std::cout << "enter real number x: "; std::cin >> x;
    std::cout << "enter natural number n: "; std::cin >> n;

    double result = power(x, n);
    std::cout << "result of x^n: " << result << "\n";
}

void run_5b() {
    std::cout << "\nproblem 5b\n";
    int nr;
    std::cout << "number of elements: "; std::cin >> nr;

    std::vector<int> v(nr);
    std::cout << "elements: ";
    for (int i = 0; i < nr; ++i) std::cin >> v[i];

    std::vector<int> res = get_longest_opposite_signs(v);
    if (!res.empty()) {
        std::cout << "longest sequence: ";
        for (int x : res) std::cout << x << " ";
        std::cout << "\nlength: " << res.size() << "\n";
    }
    else std::cout << "no sequence found.\n";
}

void run_app() {
    std::string choice;
    while (true) {
        std::cout << "\navailable problems: 4a, 4b, 5a, 5b\n";
        std::cout << "enter problem: ";
        std::cin >> choice;

        if (choice == "4a") run_4a();
        else if (choice == "4b") run_4b();
        else if (choice == "5a") run_5a();
        else if (choice == "5b") run_5b();
        else { std::cout << "exiting program.\n"; return; }
    }
}