//
//  main.cpp
//  PAT1075
//
//  Created by Myh on 2/25/15.
//  Copyright (c) 2015 Myh. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
int p[6];
class C{
public:
    string no;
    int a[10];
    int sum=0;
};
int compare(C* x,C* y){
    if(x->sum==y->sum){
        int ssum1=0, ssum2=0;
        for(int i=5;i<10;++i){
            if(x->a[i]==1)
                ssum1++;
            if(y->a[i]==1)
                ssum2++;
        }
        if(ssum1==ssum2){
            return stoi(x->no)<stoi(y->no);
        }
        return ssum1>ssum2;
    }
    return x->sum>y->sum;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int N,K,M;
    map<string,C> m;
    vector<C*> v;
    cin>>N>>K>>M;
    for(int i=0;i<K;++i){
        cin>>p[i];
    }
    for(int i=0;i<M;++i){
        string s;
        cin>>s;
        int n, x;
        cin>>n>>x;
        if(m.count(s)==0){
            for(int j=0;j<10;j++){
                m[s].a[j]=-2;
            }
            m[s].no=s;
            m[s].a[n-1]=x;
            if(x==p[n-1]){
                m[s].a[n+4]=1;
            }
            v.push_back(&m[s]);
        }
        else{
            if(x>m[s].a[n-1]){
                m[s].a[n-1]=x;
                if(x==p[n-1]){
                    m[s].a[n+4]=1;
                }
            }
        }
    }
    map<string,C>::iterator it;
    for(it=m.begin();it!=m.end();++it){
        for(int i=0;i<5;++i){
            if(it->second.a[i]>=0){
                it->second.sum+=it->second.a[i];
            }
        }
    }
    sort(v.begin(),v.end(),compare);
    int rank=1;
    int k=1;
    cout<<rank<<" ";
    cout<<v[0]->no<<" "<<v[0]->sum;
    for(int i=0;i<K;++i){
        if(v[0]->a[i]>=0){
            cout<<" "<<v[0]->a[i];
        }
        else if(v[0]->a[i]==-1){
            cout<<" 0";
        }
        else{
            cout<<" -";
        }
    }
    cout<<endl;
    for(int ri=1;ri<v.size();++ri){
        int flag=0;
        for(int i=0;i<5;++i){
            if(v[ri]->a[i]>=0){
                flag=1;
                break;
            }
        }
        if(flag==0){
            continue;
        }
        if(v[ri]->sum==v[ri-1]->sum){
            k++;
        }
        else{
            rank+=k;
            k=1;
        }
        cout<<rank<<" ";
        cout<<v[ri]->no<<" "<<v[ri]->sum;
        for(int i=0;i<K;++i){
            if(v[ri]->a[i]>=0){
                cout<<" "<<v[ri]->a[i];
            }
            else if(v[ri]->a[i]==-1){
                cout<<" 0";
            }
            else{
                cout<<" -";
            }
        }
        cout<<endl;
    }
    return 0;
}
