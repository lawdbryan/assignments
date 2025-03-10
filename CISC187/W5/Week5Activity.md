## Question 1

```c++
#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    int array[]={200, 400, 100, 50, 350};
    int size = sizeof(array)/sizeof(array[0]);

    unordered_map<int,bool>hashMap;

    for(int i = 0; i < size; i++){
        hashMap[array[i]] = true;
    }

    int findElement = 200;

    if(hashMap.find(findElement) != hashMap.end()){
        cout<< findElement << " was found in the array"<<endl;
    } else{
        cout<< findElement << " was not found in the array" << endl;
    }



}
```

## Queston 2

```c++
#include <iostream>
#include <string>
#include <functional>

using namespace std;

int main(){
    string myName = "Bryan";

    hash<string> hashFuntion;

    size_t hashValue = hashFuntion(myName);

    cout<<"The hash value of: "<< myName << "is: "<< hashValue <<endl;

    return 0;
}
```

## Question 3

The figure showed there were multiple insert operations where keys are placed in the hash table. For instance, inserting k = 555322 with h(k_ = 22 leads to a collision, and linear probing was used to find the next available slot. If a tombstone is encountered suring the process, the new key can be placed in the tombstone's position, but this can ead to further complications during the search operations. When searching for a key such as k = 555322, the search starts at the hash index and probes linearly. If a tombstone is encountered, the search must continue, possibly leading to more probes than necessary. 

Video: https://youtu.be/N_OqZSthOI8 



