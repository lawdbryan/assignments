## This covers question 1

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

## This covers quetion 2

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

Video: https://youtu.be/N_OqZSthOI8 

