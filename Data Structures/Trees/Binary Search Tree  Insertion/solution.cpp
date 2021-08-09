#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  	
  	void preOrder(Node *root) {
		
      	if( root == NULL )
          	return;
      
      	std::cout << root->data << " ";
      	
      	preOrder(root->left);
      	preOrder(root->right);
    }

/*
Node is defined as 

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    Node * insert(Node * root, int data) {
        Node* ret = new Node(0);
        if(root == NULL)
        {
            root = new Node(data);
            return root;
        }
        if(data > root -> data){
            ret = insert(root->right, data);
            root -> right = ret;
        }
        else {
            ret = insert(root->left, data);
            root -> left = ret;
        }
        return root;
    }

};