//
//  main.cpp
//  PAT1066
//
//  Created by Myh on 2/24/15.
//  Copyright (c) 2015 Myh. All rights reserved.
//

#include <iostream>
using namespace std;
class Node{
public:
    int value;
    int height;
    Node* left=NULL;
    Node* right=NULL;
};
Node* demo=new Node;
void single_right_rotation(Node* ptr){
    ptr->right=ptr->left->left;
    ptr->right->depth--;
    int tmp=ptr->value;
    ptr->value=ptr->left->value;
    ptr->left->value=tmp;
    
}
void balance(Node *ptr){
    int l_height=-1, r_height=-1;
    if(ptr->left!=NULL){
        l_height=height-ptr->left->depth;
    }
    if(ptr->right!=NULL){
        r_height=height-ptr->left->depth;
    }
    if(l_height<=r_height+1&&r_height<=l_height+1){
        return;
    }
    if(ptr->left!=NULL){
        if(ptr->left->left!=NULL){
            single_right_rotation(ptr);
        }
        else if(ptr->left->right!=NULL){
            left_right_rotation(ptr);
        }
    }
    else if(ptr->right!=NULL){
        if(ptr->right->right!=NULL){
            single_left_rotation(ptr);
        }
        else if(ptr->right->left!=NULL){
            right_left_rotation(ptr);
        }
    }
}
void insert(Node * ptr, Node* node){
    if(node->value>ptr->value){
        if(ptr->right!=NULL){
            insert(ptr->right, node);
        }
        else{
            ptr->right=node;
            if(node->left==NULL){
                height=node->depth;
            }
        }
    }
    else if(node->value<ptr->value){
        if(ptr->left!=NULL){
            insert(ptr->left, node);
        }
        else{
            ptr->left=node;
            node->depth=ptr->depth+1;
            if(node->depth>height){
                height=node->depth;
            }
        }
    }
    balance(ptr);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    demo->depth=-1;
    int N;
    cin>>N;
    for(int ri=0;ri<N;++ri){
        Node* node=new Node;
        cin>>node->value;
        if(demo->left==NULL){
            demo->left=node;
            node->depth=0;
        }
        else{
            insert(demo, node);
        }
    }
    return 0;
}
