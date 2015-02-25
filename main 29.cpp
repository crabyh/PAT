//
//  main.cpp
//  PAT1028
//
//  Created by Myh on 2/9/15.
//  Copyright (c) 2015 Myh. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <deque>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
class R{
public:
    char ID[10]={};
    char name[10]={};
    int score;
};
int strcmp1(char* x, char* y){
    int i=0;
    while(x[i]==y[i]&&i<10) ++i;
    if(i==10)
        return -1;
    if(x[i]<y[i])
        return 1;
    else
        return 0;
}
int cp1(R* x, R* y){
    //    cout<<x->ID<<" "<<y->ID<<endl;
    
    return strcmp1(x->ID, y->ID);
}
int cp2(R* x, R* y){
    if(strcmp1(x->name, y->name)==-1)
        return strcmp1(x->ID, y->ID);
    return strcmp1(x->name, y->name);
}
int cp3(R* x, R* y){
    if(x->score==y->score)
        return strcmp1(x->ID, y->ID);
    return x->score<y->score;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int N,C;
    cin>>N>>C;
    deque<R*> q;
    for(int i=0;i<N;i++){
        R* r=new R;
        scanf("%s%s%d",r->ID,r->name,&r->score);
        //        cin>>r->ID>>r->name>>r->score;
        q.push_back(r);
    }
    switch (C) {
        case 1:{
            sort(q.begin(),q.end(),cp1);
            break;
        }
        case 2:{
            sort(q.begin(),q.end(),cp2);
            break;
        }
        case 3:{
            sort(q.begin(),q.end(),cp3);
            break;
        }
    }
    for(int i=0;i<q.size();i++){
        printf("%s %s %d\n",q[i]->ID,q[i]->name,q[i]->score);
        //        cout<<q[i]->ID<<" "<<q[i]->name<<" "<<q[i]->score<<endl;
    }
    return 0;
}
