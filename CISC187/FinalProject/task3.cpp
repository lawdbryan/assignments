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

