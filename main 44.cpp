//
//  main.cpp
//  PAT1036
//
//  Created by Myh on 2/12/15.
//  Copyright (c) 2015 Myh. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
class S{
public:
    string name,ID;
    char gender;
    int grade;
};
int compare1(S x, S y){
    return x.grade<y.grade;
}
int compare2(S x, S y){
    return x.grade>y.grade;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int N;
    cin>>N;
    deque<S> f, m;
    for(int i=0;i<N;++i){
        S s;
        cin>>s.name>>s.gender>>s.ID>>s.grade;
        if(s.gender=='M')
            m.push_back(s);
        else
            f.push_back(s);
    }
    sort(f.begin(),f.end(),compare2);
    sort(m.begin(),m.end(),compare1);
    
    if(f.size()>0)
        cout<<f[0].name<<" "<<f[0].ID<<endl;
    else
        cout<<"Absent"<<endl;
    
    if(m.size()>0)
        cout<<m[0].name<<" "<<m[0].ID<<endl;
    else
        cout<<"Absent"<<endl;
    
    if(f.size()==0||m.size()==0)
        cout<<"NA";
    else
        cout<<f[0].grade-m[0].grade;
    
    return 0;
}
