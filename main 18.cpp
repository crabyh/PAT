//
//  main.cpp
//  PAT1062
//
//  Created by Myh on 2/23/15.
//  Copyright (c) 2015 Myh. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class C{
public:
    int no;
    int virtue;
    int talent;
    int total;
};
C c[100000];
int compare(C x,C y){
    if(x.total==y.total){
        if(x.virtue==y.virtue){
            return x.no<y.no;
        }
        return x.virtue>y.virtue;
    }
    return x.total>y.total;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<C> v1, v2, v3, v4;
    int N, L, H;
    cin>>N>>L>>H;
    for(int i=0;i<N;++i){
        C c;
        scanf("%d %d %d",&c.no,&c.virtue,&c.talent);
        if(c.virtue>=L&&c.talent>=L){
            c.total=c.talent+c.virtue;
            if(c.virtue>=H&&c.talent>=H){
                v1.push_back(c);
            }
            else if(c.virtue>=H){
                v2.push_back(c);
            }
            else if(c.virtue>=c.talent){
                v3.push_back(c);
            }
            else{
                v4.push_back(c);
            }
        }
    }
    sort(v1.begin(),v1.end(),compare);
    sort(v2.begin(),v2.end(),compare);
    sort(v3.begin(),v3.end(),compare);
    sort(v4.begin(),v4.end(),compare);
    cout<<v1.size()+v2.size()+v3.size()+v4.size()<<endl;
    for(int i=0;i<v1.size();++i){
        printf("%d %d %d\n",v1[i].no,v1[i].virtue,v1[i].talent);
    }
    for(int i=0;i<v2.size();++i){
        printf("%d %d %d\n",v2[i].no,v2[i].virtue,v2[i].talent);
    }
    for(int i=0;i<v3.size();++i){
        printf("%d %d %d\n",v3[i].no,v3[i].virtue,v3[i].talent);
    }
    for(int i=0;i<v4.size();++i){
        printf("%d %d %d\n",v4[i].no,v4[i].virtue,v4[i].talent);
    }
    return 0;
}
