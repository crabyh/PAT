//
//  main.cpp
//  PAT1058
//
//  Created by Myh on 2/17/15.
//  Copyright (c) 2015 Myh. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    int x,x1,x2,y,y1,y2,z,z1,z2;
    char ch;
    cin>>x1>>ch>>y1>>ch>>z1;
    cin>>x2>>ch>>y2>>ch>>z2;
    x=x1+x2;
    y=y1+y2;
    z=z1+z2;
    if(z>=29){
        z-=29;
        ++y;
    }
    if(y>=17){
        y-=17;
        ++x;
    }
    cout<<x<<"."<<y<<"."<<z<<endl;
    return 0;
}
