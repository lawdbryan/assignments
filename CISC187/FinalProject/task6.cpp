#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int findLongestStreak(const vector<int>& data) {
    unordered_set<int> vault(data.begin(), data.end());
    int longestStreak = 0;

    for (int number : data) {
        if (vault.find(number - 1) == vault.end()) {
            int current = number;
            int streak = 1;

            while (vault.find(current + 1) != vault.end()) {
                current++;
                streak++;
            }

            if (streak > longestStreak) {
                longestStreak = streak;
            }
        }
    }

    return longestStreak;
}

int main() {
    vector<int> inputNumbers = {10, 5, 12, 3, 55, 30, 4, 11, 2};

    cout << "Input: ";
    for (int n : inputNumbers) cout << n << " ";
    cout << endl;

    int result = findLongestStreak(inputNumbers);

    cout << "Longest consecutive streak length: " << result << endl;
    return 0;
}
