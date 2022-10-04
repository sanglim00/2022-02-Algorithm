#include <iostream>
using namespace std;

struct Node {
    int data; // 노드에 저장되는 정수 데이터 
    Node* left; // 왼쪽 서브트리
    Node* right; // 오른쪽 서브트리
};

void insert(Node** root, int data) { 
    if(*root == NULL) {
        Node* p = new Node();
        p->data = data;
        *root = p;
    }
    else {
        if (data > (*root)->data) {
            insert(&(*root)->left, data);
        }
        else if(data < (*root)->data) {
            insert(&(*root)->right, data);
        }
    }
}

void preOrder(Node* root) {
    if(root == NULL) return;
    cout<< root->data <<' ';
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root) {
    if(root == NULL) return;
    inOrder(root->left);
    cout<< root->data <<' ';
    inOrder(root->right);
}

void postOrder(Node* root) {
    if(root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout<< root->data <<' ';
}

int size(Node* root) {
    int count = 0;
    if (root != NULL) 
        return (size(root->left) + 1 + size(root->right));

    return count;
}

int height(Node* root) {
    int totalH = 0;

    if(root != NULL){
        int leftH = height(root->left);
        int rightH = height(root->right);
        int maxHeight = max(leftH, rightH);
        totalH = maxHeight + 1;
    }
    return totalH;
}

int sumOfWeight(Node* root) {
    if (root != NULL) 
        return (root->data + sumOfWeight(root->left) + sumOfWeight(root->right));

    return 0;
}

int maxPathWeight(Node* root) {
    if (root != NULL) {
        int leftW = root->data + sumOfWeight(root->left);
        int rightW = root->data + sumOfWeight(root->right);

        return max(leftW, rightW);
    }
    return 0;
}

void mirror(Node** root){
    
}

void destruct(Node** root) {
    if(root != nullptr) {
		if( ((*root)->left == nullptr) && ((*root)->right == nullptr)) {
			delete root;
			root = nullptr;
		} else if((*root)->left != nullptr) {
			destruct(&(*root)->left);
		} 
        else if((*root)->right != nullptr) {
			destruct(&(*root)->right);
		} 
        else {
            destruct(&(*root)->left);
            destruct(&(*root)->right);
        }
    }
    return;
}

int main() {

    int times, num;
    
    
    cin>> times;
    for(int i = 0; i< times; i++) {
        Node* root = NULL;
        cin>> num;
        for(int j = 0; j < num; j++) {
            int data;
            cin >> data;
            insert(&root, data);
        }
        cout << size(root) << endl;
        cout << height(root)-1 << endl;
        cout << sumOfWeight(root) << endl;
        cout << maxPathWeight(root) << endl;
        mirror(&root);
        preOrder(root);
        cout<<endl;
        inOrder(root);
        cout<<endl;
        postOrder(root);
        cout<<endl;
        cout<< 0 << endl;
    }

    return 0;
}