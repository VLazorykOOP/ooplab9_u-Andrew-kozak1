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
