#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    string name;
    int weight;
    int value;
};

int unboundedKnapsack(int W, vector<Item>& items) {
    vector<int> dp(W + 1, 0);
    setlocale(LC_ALL, "rus");

    for (int i = 0; i <= W; ++i) {
        for (const Item& item : items) {
            if (item.weight <= i) {
                dp[i] = max(dp[i], dp[i - item.weight] + item.value);
            }
        }
    }

    return dp[W];
}

int main() {
    vector<Item> items = {
        {"Тетрадь", 2, 6},
        {"Камера", 3, 10},
        {"Книга", 4, 12},
        {"Кошелек", 5, 14}

    };

    int maxWeight = 8;

    setlocale(LC_ALL, "rus");
    cout << "Предметы (вес, ценность):" << endl;
    for (const auto& item : items) {
        cout << "(" << item.weight << ", " << item.value << ")" << endl;
    }


    cout << "Максимальная ценность, которую можно унести: " << unboundedKnapsack(maxWeight, items) << endl;

    return 0;
}
