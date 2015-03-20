//
//  main.cpp
//  pat1052
//
//  Created by Myh on 2/13/15.
//  Copyright (c) 2015 Myh. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
class C{
public:
    char add[6];
    int key;
    char next[6];
};
int compare(C x,C y){
    return x.key<y.key;
}
//int is_equal(char x[], char y[]){
//    for(int i=0;i<6;++i){
//        if(x+i!=y+1)
//            return 0;
//    }
//    return 1;
//}
int main(int argc, const char * argv[]) {
    // insert code here...
    int N;
    cin>>N;
    string start;
    cin>>start;
    vector<C> ls;
    map<string,C> m;
    for(int i=0;i<N;++i){
        C c;
        scanf("%s %d %s",c.add,&c.key,c.next);
//        cin>>c.add>>c.key>>c.next;
        m[c.add]=c;
    }
    string address=start;
    while(address!="-1"){
        ls.push_back(m[address]);
        address=m[address].next;
    }
    if(ls.size()==0){
        cout<<0<<" -1"<<endl;
        return 0;
    }
    sort(ls.begin(),ls.end(),compare);
    address=ls[0].add;
    cout<<ls.size()<<" "<<address<<endl;
    for(int i=0;i<ls.size()-1;i++){
        printf("%s %d %s\n",ls[i].add,ls[i].key,ls[i+1].add);
//        cout<<ls[i].add<<" "<<ls[i].key<<" "<<ls[i+1].add<<endl;
    }
    cout<<ls[ls.size()-1].add<<" "<<ls[ls.size()-1].key<<" "<<"-1"<<endl;
    
    
    return 0;
}
