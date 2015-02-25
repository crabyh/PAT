//
//  main.cpp
//  PAT1004
//
//  Created by Myh on 9/26/14.
//  Copyright (c) 2014 myh. All rights reserved.
//

#include <iostream>
#include <deque>
using namespace std;
/*int main(int argc, const char * argv[])
{

    deque<int> q1,q2;
    int nodes, non_leaf_nodes;
    cin >> nodes >> non_leaf_nodes;
    if(non_leaf_nodes==0)
        cout << 1 << endl;
    q1.push_back(1);
    int i=0;
    int parent, child_num, child[100];
    int leaf_nodes=0;
    cin >> parent >> child_num;         //record one node
    for(int j=0;j<child_num;j++){
        cin >> child[j];
    }
    while(i<non_leaf_nodes){
        while(!q1.empty()){
            while(q1.front()!=parent && !q1.empty()){
                q1.pop_front();
                leaf_nodes++;
            }
            if(q1.front()==parent && !q1.empty()){
                i++;
                q1.pop_front();
                for(int j=0;j<child_num;j++){
                    q2.push_back(child[j]);
                }
                if(i<non_leaf_nodes){
                    cin >> parent >> child_num;         //record the next node
                    for(int j=0;j<child_num;j++){
                        cin >> child[j];
                    }
                }
            }
        }
        q1=q2;  //next level
        q2.clear();
        cout << leaf_nodes << " ";
        leaf_nodes=0;
        
    }
    if(i==non_leaf_nodes){
        while(!q1.empty()){
            leaf_nodes++;
            q1.pop_back();
        }
        cout << leaf_nodes;
    }
    return 0;
}*/
int main(int argc, const char * argv[]){
    deque<int> q1, q2;
    deque<int> q[101];
    int nodes, non_leaf_nodes, parent, child_num, child;
    cin >> nodes >> non_leaf_nodes;
    for(int i=0;i<non_leaf_nodes;i++){
        cin >> parent >> child_num;
        for(int j=0;j<child_num;j++){
            cin >> child;
            q[parent].push_back(child);
        }
    }
    q1.push_back(1);
    q2.push_back(-1);
    int leaf_nodes=0;
    while(!q2.empty()){
        if(q2.back()!=-1)
            cout << leaf_nodes << " ";
        q2.clear();
        leaf_nodes=0;
        while(!q1.empty()){
            parent=q1.front();
            q1.pop_front();
            if(q[parent].empty())
                leaf_nodes++;
            while(!q[parent].empty()){
                q2.push_back(q[parent].front());
                q[parent].pop_front();
            }
        }
        q1=q2;
    }
    cout << leaf_nodes;
    return 0;
}

