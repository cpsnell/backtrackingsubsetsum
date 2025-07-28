#include <iostream>
#include <vector>
#include <algorithm>

void findCombinations(const std::vector<int>& weights, int target, int index,
                      std::vector<int>& current, std::vector<std::vector<int>>& results, int maxItems = -1) {
    if (target == 0 && (maxItems == -1 || current.size() <= maxItems)) {
        results.push_back(current);
        return;
    }
    if (target < 0 || index >= weights.size() || (maxItems != -1 && current.size() >= maxItems)) {
        return;
    }

    // Include this weight
    current.push_back(weights[index]);
    findCombinations(weights, target - weights[index], index + 1, current, results, maxItems);
    current.pop_back();

    // Skip this weight
    findCombinations(weights, target, index + 1, current, results, maxItems);
}

int main() {
    std::vector<int> weights = {1, 3, 4, 5}; // truck weights
    int target = 9;                          // desired total load
    int maxItems = 3;                        // optional limit on number of trucks used

    std::vector<std::vector<int>> results;
    std::vector<int> current;

    findCombinations(weights, target, 0, current, results, maxItems);

    std::cout << "Valid truck combinations:\n";
    for (const auto& combo : results) {
        for (int w : combo) std::cout << w << " ";
        std::cout << "\n";
    }

    return 0;
}
