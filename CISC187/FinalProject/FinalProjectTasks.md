Task 1: 
```cpp
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

struct Player{
    string first_name;
    string last_name;
    string team;
};

int main(){
vector<Player> basketball_players = {
    {"Jill", "Huang", "Gators"},
      {"Janko", "Barton", "Sharks"},
      {"Wanda","Vakulskas", "Sharks"},
      {"Jill", "Moloney", "Gators"},
      {"Luuk", "Watkins", "Gators"}
};

vector<Player> football_players = {
    {"Hanzla", "Radosti", "32ers"},
    {"Tina", "Watkins", "Barleycorns"},
    {"Alex", "Patel", "32ers"},
    {"Jill", "Huang", "Barleycorns"},
    {"Wanda", "Vakulskas", "Barleycorns"}
};

unordered_set<string> basketball_names;

for (const Player& p : basketball_players){
    string full_name = p.first_name + " " + p.last_name;
    basketball_names.insert(full_name);

}

vector<Player> common_players;
for (const Player& p : football_players){
    string full_name = p.first_name + " " + p.last_name;
    if(basketball_names.find(full_name) != basketball_names.end()){
        common_players.push_back(p);
    }
}

cout<<"The following players play both sports: "<<endl;
for(const Player&p : common_players){
    cout<<p.first_name + " " + p.last_name<<endl;
}

}
```

Task 2:
```cpp
#include <iostream>
#include <vector>

using namespace std;

int findMissingNumber (const vector<int>& nums){
    int n = nums.size();
    int expected_sum = (n*(n-1))/2;

    int actual_sum = 0;

    for(int num : nums){
        actual_sum += num;
    }
    return expected_sum - actual_sum;
}

```

Task 3:
```cpp
#include <iostream>
#include <vector>

using namespace std;

int findBestProfit(const vector<int>& stockPrices){
    if(stockPrices.size() < 2){
        cout << "Not enough data!"<<endl;
        return 0;
    }
    int lowestPrice = stockPrices[0];
    int bestProfit = 0;

    for(int i = 1; i < stockPrices.size(); i++){
        int todayPrice = stockPrices[i];
        int profitToday = todayPrice - lowestPrice;

        if (profitToday > bestProfit){
            bestProfit = profitToday;
        }

        if (todayPrice < lowestPrice){
            lowestPrice = todayPrice;
        }
    }
    return bestProfit;
}

int main(){
    cout<<"Analyzing stock prices..."<<endl;

    vector<int> stockPrices = {10, 7, 5, 8, 11, 2, 6};

    int bestProfit = findBestProfit(stockPrices);

    cout <<"The most profit you can make is: $"<<bestProfit<<endl;
}

```

Task 4:
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int highestProduct(const vector<int>& numbers){
    if(numbers.size()<2){
        cout<<"Not enough data to compute!"<<endl;
        return 0;
    }

    int big1 = max(numbers[0], numbers[1]);
    int big2 = min(numbers[0], numbers[1]);

    int small1 = min(numbers[0], numbers[1]);
    int small2 = max(numbers[0], numbers[1]);

    for(int i = 2; i < numbers.size(); i++){
        int current = numbers[i];

        if(current > big1){
            big2 = big1;
            big1 = current;
        } else if (current>big2){
            big2 = current;
        }

        if(current < small1){
            small2 = small1;
            small1 = current;
        }else if(current < small2){
            small2 = current;
        }

    }

    int productA = big1 * big2;
    int productB = small1 * small2;

    return max(productA, productB);

}

int main(){
    vector<int> prices = {5, -10, -6, 9, 4};

    int result = highestProduct(prices);

    cout<<"The highest product from the list of numbers is: "<<result<<endl;
}
```

Task 5:
```cpp
#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<float>& bucket){
    for(int i = 1; i < bucket.size(); i++){
        float key = bucket[i];
        int j = i-1;
        while(j>=0 && bucket[j] > key){
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}

void bucketSort(float arr[], int n){
    vector<float> b[n];

    for(int i = 0; i < n; i++){
        int bi = n * arr[i];
        b[bi].push_back(arr[i]);
    }

    for(int i = 0; i < n; i++){
        insertionSort(b[i]);
    }

    int index = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < b[i].size(); j++){
            arr[index++] = b[i][j];
        }
    }
}

int main(){
    float arr[] = {98.6, 98.0, 97.1, 99.0, 98.9, 97.8, 98.5, 98.2, 98.0, 97.1};

    int n = sizeof(arr)/sizeof(arr[0]);
    bucketSort(arr, n);

    cout << "The following are the body tempuratures lsited in order: "<<endl; 
    for( int i = 0; i < n ; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
```

Task 6:
```cpp
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
```



