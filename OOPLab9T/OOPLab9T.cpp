#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct Client {
    int id;
    int hours;
    int year;
    int month;
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
    using namespace std;

    struct Client {
        int id;
        int hours;
        int year;
        int month;
    };

    int main() {
        int n;
        cin >> n;

        map<int, vector<Client>> clients;

        for (int i = 0; i < n; i++) {
            int id, hours, year, month;
            cin >> id >> hours >> year >> month;

            clients[id].push_back({ id, hours, year, month });
        }

        vector<pair<int, int>> result;

        for (auto& [id, sessions] : clients) {
            sort(sessions.begin(), sessions.end(), [](const Client& a, const Client& b) {
                return a.year < b.year || (a.year == b.year && a.month < b.month);
                });

            int total_months = 1;
            int last_month = sessions[0].month;

            for (int i = 1; i < sessions.size(); i++) {
                if (sessions[i].month != last_month) {
                    total_months++;
                    last_month = sessions[i].month;
                }
            }

            result.push_back({ total_months, id });
        }

        sort(result.begin(), result.end());

        for (auto& [total_months, id] : result) {
            cout << total_months << " " << id << endl;
        }

        return 0;
    }
    //завдання 2
    #include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> L = { 3, -1, 4, 5, -6, -7, 8, 9, 2 };

    // Find first negative element
    auto first_neg = std::adjacent_find(L.begin(), L.end(), [](int a, int b) {
        return b < a;
        });

    // Insert zero after first negative element
    if (first_neg != L.end()) {
        L.insert(first_neg + 1, 0);
    }

    // Find last positive or negative element with same parity
    auto last_same_parity = std::adjacent_find(L.rbegin(), L.rend(), [parity = L.back() % 2](int a, int b) {
        return a % 2 == parity && b % 2 == parity;
        });

    // Insert zero before last same-parity element
    if (last_same_parity != L.rend()) {
        L.insert(last_same_parity.base(), 0);
    }

    // Print result
    for (auto x : L) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}
    // завдання 3
    #include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <set>

int main() {
    std::string name = "output.txt";
    std::vector<int> V = { 1, 2, 3, 4, 5, 6 };
    std::vector<int> first_half(V.begin(), V.begin() + V.size() / 2);
    std::vector<int> second_half(V.begin() + V.size() / 2, V.end());
    std::set<int, std::greater<int>> first_set(first_half.begin(), first_half.end());
    std::set<int, std::greater<int>> second_set(second_half.begin(), second_half.end());
    std::set<int, std::greater<int>> result_set;
    std::set_difference(second_set.begin(), second_set.end(), first_set.begin(), first_set.end(),
        std::inserter(result_set, result_set.begin()));
    std::ofstream outfile(name);
    std::ostream_iterator<int> output_iterator(outfile, "\n");
    std::copy(result_set.begin(), result_set.end(), output_iterator);
    return 0;
}


