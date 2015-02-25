//
//  main.cpp
//  PAT1033
//
//  Created by Myh on 2/11/15.
//  Copyright (c) 2015 Myh. All rights reserved.
//

#include <iostream>
#include <deque>
#include <algorithm>
#include <iomanip>
using namespace std;
class S{
public:
    double price;
    int dis;
};
int compare(S x, S y){
    return x.dis<y.dis;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int C, D, avg, N;
    cin>>C>>D>>avg>>N;
    deque<S> q;
    for(int i=0;i<N;++i){
        S s;
        cin>>s.price>>s.dis;
        q.push_back(s);
    }
    sort(q.begin(),q.end(),compare);
    int max_dis=C*avg;
    if(q[0].dis!=0){
        cout<<"The maximum travel distance = 0.00"<<endl;
        return 0;
    }
    else{
        if(q.size()>1){
            for(int i=0;i<q.size()-1;i++){
                if(q[i+1].dis-q[i].dis>max_dis){
                    cout<<"The maximum travel distance = "<<setiosflags(ios::fixed)<<setprecision(2)<<q[i].dis+max_dis<<".00"<<endl;
                    return 0;
                }
            }
        }
        if(D-q[q.size()-1].dis>max_dis){
            cout<<"The maximum travel distance = "<<setiosflags(ios::fixed)<<setprecision(2)<<q[q.size()-1].dis+max_dis<<".00"<<endl;
            return 0;
        }
    }
    double total=0;
    S s;
    s.price=0;
    s.dis=D;
    q.push_back(s);
    for(int i=(int)q.size()-1;i>0;){
        int cheapest=i-1;
        for(int j=i-1;j>=0;j--){
            if(q[i].dis-q[j].dis>max_dis){
                break;
            }
            else if(q[j].price<q[cheapest].price){
                cheapest=j;
            }
        }
        total+=(q[i].dis-q[cheapest].dis)*q[cheapest].price/avg;
        if(q[i].price>q[cheapest].price&&i!=q.size()-1){
            total=total+(max_dis-((q[i].dis-q[cheapest].dis)))*(q[cheapest].price-q[i].price)/avg;
        }
        i=cheapest;
    }
    cout<<setiosflags(ios::fixed)<<setprecision(2)<<total;
    
    
    
    
    
    
    return 0;
}
