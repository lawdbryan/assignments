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