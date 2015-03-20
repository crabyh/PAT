//
//  main.cpp
//  PAT1070
//
//  Created by Myh on 2/24/15.
//  Copyright (c) 2015 Myh. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Mooncake{
public:
    double weight;
    double price;
};
int compare(Mooncake x,Mooncake y){
    return x.price/x.weight>y.price/y.weight;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int N;
    double D;
    cin>>N>>D;
    vector<Mooncake> v;
    for(int i=0;i<N;++i){
        Mooncake m;
        cin>>m.weight;
        v.push_back(m);
    }
    for(int i=0;i<N;++i){
        cin>>v[i].price;
    }
    sort(v.begin(),v.end(),compare);
    double cur=0;
    double profit=0;
    int i=-1;
    while(cur<D&&i<(int)v.size()){
        i++;
        cur+=v[i].weight;
        profit+=v[i].price;
    }
    if(cur>D)
        profit-=(cur-D)/v[i].weight*v[i].price;
    printf("%.2lf",profit);
    return 0;
}
