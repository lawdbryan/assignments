Question 3:
```cpp
#include <iostream>
using namespace std;

struct BstNode{
    int data;
    BstNode* left;
    BstNode* right;

};

int FindMax(BstNode* root){
    if(root == NULL){
        cout<<"The Tree is Empty"<<endl;
        return -1;
    }

    while(root->right != NULL){
        root = root->right;
    }
    return root->data;
}
```

Question 4:
```cpp
#include <iostream>
using namespace std;

struct BstNode{
    int data;
    BstNode* left;
    BstNode* right;
};

BstNode* GetNewNode(int data){
    BstNode* newNode = new BstNode();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BstNode* Insert(BstNode* root, int data){
    if(root == NULL){
        root = GetNewNode(data);
        return root;
    }
    else if(data <= root->data){
        root->left = Insert(root->left,data);
    }
    else{
        root->right = Insert(root->right,data);
    }
    return root;
}

int main(){
    BstNode* root = NULL;
    root = Insert(root, 1);
    root = Insert(root, 5);
    root = Insert(root, 9);
    root = Insert(root, 2);
    root = Insert(root, 4);
    root = Insert(root, 10);
    root = Insert(root, 6);
    root = Insert(root, 3);
    root = Insert(root, 8);
}

```

video: https://youtu.be/_mCYMgJ9cQ4

