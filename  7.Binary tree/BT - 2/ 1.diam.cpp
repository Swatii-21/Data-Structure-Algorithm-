#include <bits/stdc++.h>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* buildtree(vector<int>& nodes, int& index) {
    if (index >= nodes.size() || nodes[index] == -1) {
        index++;
        return NULL;
    }

    Node* root = new Node(nodes[index++]);
    root->left = buildtree(nodes, index);
    root->right = buildtree(nodes, index);

    return root;
}


int height (Node* root){
    if(root == NULL){
        return 0 ; 
    }
    
    int leftht = height(root ->left);
    int rightht = height(root ->right);
    
    int currht = max(leftht , rightht ) + 1;
    return currht ; 
}
 //approach 1 O(n2)
int diam1(Node* root){
    if(root == NULL){
        return 0 ; 
    }
    
    int currdiam = height(root ->left) +height(root ->right) +1 ; 
    int leftdiam = diam1(root ->left);
    int rightdiam = diam1(root ->right);
    
    return max(currdiam , max(leftdiam , rightdiam));
}

//approach 2 ()
pair<int,int> diam2(Node* root){
    if(root == NULL){
        return make_pair(0,0);
    }
    
    //(diamete , height)
    pair<int,int> leftinfo = diam2(root ->left) ;  //(LD , LH)
    pair<int,int> rightinfo = diam2(root ->right) ; //(RD , RH)
    
    int currdiam = leftinfo.second + rightinfo.second +1;
    int finaldiam = max(currdiam , max(leftinfo.first , rightinfo.first)) ; 
    
    int finalht = max(leftinfo.second , rightinfo.second) +1;
    
    return make_pair(finaldiam , finalht);
    
}



int main() {
	  vector<int> nodes = {1 , 2 , 3 , -1 , -1 , 5 , -1 , -1 , 3 , -1 , 6 , -1 , -1};
	  int index = 0 ; 
	  Node* root = buildtree(nodes , index);
	  
	   pair<int, int> ans = diam2(root);
       cout << "diameter = " << ans.first << endl;
	  
	  
	  return 0;

}
