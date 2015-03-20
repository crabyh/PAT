//
//  main.cpp
//  PAT1057
//
//  Created by Myh on 2/17/15.
//  Copyright (c) 2015 Myh. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> s;
    multiset<int,greater<int>> lower;
    multiset<int> upper;
    int mid=0;
    int N;
    cin>>N;
    for(int i=0;i<N;++i){
        char str[11];
        scanf("%s",str);
        if(str[1]=='o'){
            if(s.empty()){
                printf("Invalid\n");
            }
            else{
                int x=s.back();
                printf("%d\n",s.back());
                s.pop_back();
                if(x<=mid){
                    lower.erase(lower.find(x));
                }
                else{
                    upper.erase(upper.find(x));
                }
                if(s.empty())
                    mid=0;
                else{
                    if(lower.size()>upper.size()+1){
                        upper.insert(*lower.begin());
                        lower.erase(lower.begin());
                    }
                    else if(lower.size()<upper.size()){
                        lower.insert(*upper.begin());
                        upper.erase(upper.begin());
                    }
                    mid=*lower.begin();
                }
            }
            
        }
        else if(str[1]=='e'){
            if(s.empty()){
                printf("Invalid\n");
            }
            else{
                printf("%d\n",mid);
            }
        }
        else if(str[1]=='u'){
            int n;
            scanf("%d", &n);
            s.push_back(n);
            if (n>mid)
            {
                upper.insert(n);
            }
            else
            {
                lower.insert(n);
            }
            if (upper.size() > lower.size())
            {
                lower.insert(*upper.begin());
                upper.erase(upper.begin());
            }
            else if (lower.size() > upper.size() + 1)
            {
                upper.insert(*lower.begin());
                lower.erase(lower.begin());
            }
            mid = *lower.begin();
        }
    }
    
    
    
    
    
    return 0;
}
