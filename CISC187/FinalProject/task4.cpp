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