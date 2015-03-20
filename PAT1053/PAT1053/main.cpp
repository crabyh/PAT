//
//  main.cpp
//  PAT1053
//
//  Created by Myh on 2/15/15.
//  Copyright (c) 2015 Myh. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
class Node{
public:
    int ID;
    int weight;
    int total_weight;
    vector<Node *> child;
    vector<Node *> brother;
    Node * parent=NULL;
    bool is_leaf=1;
};

vector<Node *> nodes;
deque<deque<int>> res;

void trace(deque<int>& x){
    while(x.front()!=0){
        x.push_front(nodes[x.front()]->parent->ID);
    }
}

int compare(deque<int> x,deque<int> y){
    int i=0;
//    cout<<nodes[x[i]]->ID<<" "<<nodes[y[i]]->ID<<endl;
    while(nodes[x[i]]->weight==nodes[y[i]]->weight&&nodes[x[i]]->child.size()!=0&&nodes[y[i]]->child.size()!=0){
        i++;
    }
    return nodes[x[i]]->weight>nodes[y[i]]->weight;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int N,M,K;
    cin>>N>>M>>K;
    for(int i=0;i<N;++i){
        Node* node=new Node;
        node->ID=i;
        cin>>node->weight;
        nodes.push_back(node);
    }
    for(int i=0;i<M;++i){
        int ID,n;
        cin>>ID>>n;
        Node* node=nodes[ID];
        node->is_leaf=0;
        for(int j=0;j<n;++j){
            int id;
            cin>>id;
            node->child.push_back(nodes[id]);
            nodes[id]->parent=node;
        }
    }
    deque<Node *> tree;
    tree.push_back(nodes[0]);
    nodes[0]->total_weight=nodes[0]->weight;
    while(!tree.empty()){
        Node* node=tree.front();
        tree.pop_front();
        for(int i=0;i<node->child.size();++i){
            node->child[i]->total_weight=node->total_weight+node->child[i]->weight;
            tree.push_back(node->child[i]);
        }
    }
    for(int i=0;i<N;++i){
        if(nodes[i]->total_weight==K&&nodes[i]->is_leaf==1){
            deque<int> res1;
            res1.push_front(i);
            trace(res1);
            res.push_back(res1);
        }
    }
    
    sort(res.begin(), res.end(), compare);
    for(int i=0;i<res.size();++i){
        cout<<nodes[res[i][0]]->weight;
        for(int j=1;j<res[i].size();++j){
            cout<<" "<<nodes[res[i][j]]->weight;
        }
        cout<<endl;
    }
    
    
    
    
    
    
    
    return 0;
}
