//
//  main.cpp
//  PAT1055
//
//  Created by Myh on 2/15/15.
//  Copyright (c) 2015 Myh. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
class C{
public:
    int rankinage;
    char name[10];
    int age;
    int worth;
};
int compare1(C x,C y){
    if(x.age==y.age){
        if(x.worth==y.worth){
            int i=0;
            while(x.name[i]==y.name[i]) ++i;
            return x.name[i]<y.name[i];
        }
        else
            return x.worth>y.worth;
    }
    else
        return x.age<y.age;
}
int compare2(C x,C y){
    if(x.worth==y.worth){
        if(x.age==y.age){
            int i=0;
            while(x.name[i]==y.name[i]) ++i;
                return x.name[i]<y.name[i];
        }
        else
            return x.age<y.age;
    }
    else
        return x.worth>y.worth;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int N,K;
    cin>>N>>K;
    vector<C> v,vv;
    for(int i=0;i<N;i++){
        C c;
        scanf("%s %d %d", c.name, &c.age, &c.worth);
        vv.push_back(c);
    }
    sort(vv.begin(),vv.end(),compare1);
    int age=-1;
    int mmin[201]={}, mmax[201]={};
    int j;

    vv[0].rankinage=1;
    v.push_back(vv[0]);
    for(j=1;j<N;++j){
        if(vv[j].age==vv[j-1].age){
            vv[j].rankinage=vv[j-1].rankinage+1;
        }
        else{
            vv[j].rankinage=1;
        }
        if(vv[j].rankinage<=10)//should be 100
        {
            v.push_back(vv[j]);
        }
    }
    sort(v.begin(),v.end(),compare1);
    N=v.size();
    for(j=0;j<N;++j){
        if(v[j].age>age){
            for(int k=age+1;k<=v[j].age;k++){
                mmin[k]=j;
            }
            age=v[j].age;
        }
    }
    for(int k=age+1;k<=200;++k){
        mmin[k]=-1;
    }
    age=201;
    for(int j=N-1;j>=0;--j){
        if(v[j].age<age){
            for(int k=age-1;k>=v[j].age;--k){
                mmax[k]=j;
            }
            age=v[j].age;
        }
    }
    for(int k=age-1;k>=0;--k){
        mmax[k]=-1;
    }
//    map<int,int>::iterator it;
//    for(it=mmin.begin();it!=mmin.end();++it){
//        cout<<it->first<<" "<<it->second<<endl;
//    }
//    for(it=mmax.begin();it!=mmax.end();++it){
//        cout<<it->first<<" "<<it->second<<endl;
//    }
    vector<C> res;
    for(int i=0;i<K;++i){
        int M, Amin, Amax;
        scanf("%d %d %d", &M, &Amin, &Amax);
        int front=mmin[Amin], end=mmax[Amax];
        if(end>=front&&end!=-1&&front!=-1){
            for(int j=front;j<=end;++j){
//                if(v[j].worth>=min_worth)
                    res.push_back(v[j]);
            }
        }

        sort(res.begin(),res.end(),compare2);
        printf("Case #%d:\n",i+1);
        if(res.size()>0&&M>0){
            printf("%s %d %d\n",res[0].name,res[0].age,res[0].worth);
            for(int j=1;j<res.size()&&j<M;j++){
                printf("%s %d %d\n",res[j].name,res[j].age,res[j].worth);
            }
        }
        else printf("None\n");
        res.clear();
    }
    
    
    
    
    return 0;
}
