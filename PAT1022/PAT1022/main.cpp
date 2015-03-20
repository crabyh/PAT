//
//  main.cpp
//  PAT1022
//
//  Created by Myh on 2/7/15.
//  Copyright (c) 2015 Myh. All rights reserved.
//

#include <iostream>
#include <map>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;

int compare(string a, string b){
    return a<b;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    map<string, deque<string>> title, author, key_word, publisher;
    map<string, deque<string>> year;
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        string ID,y;
        string t,a,k,p;
        cin>>ID;
        getline(cin,t); //???
        getline(cin,t);
        getline(cin,a);
        getline(cin,k);
        getline(cin,p);
        cin>>y;
        title[t].push_back(ID);
        author[a].push_back(ID);
        while(k.find(' ')!=-1){
//            cout<<k.find(' ');
            key_word[k.substr(0,k.find(' '))].push_back(ID);
            k=k.substr(k.find(' ')+1);
        }
        key_word[k].push_back(ID);
        publisher[p].push_back(ID);
        year[y].push_back(ID);
    }
    cin>>N;
    for(int i=0;i<N;i++){
        int op;
        cin>>op;
        getchar();
        getchar();
        cout<<op<<": ";
        switch (op) {
            case 1:{
                string t;
                getline(cin,t);
                cout<<t<<endl;
                if(title[t].size()>0){
                    sort(title[t].begin(),title[t].end(),compare);
                    for(int j=0;j<title[t].size();j++){
                        cout<<title[t][j]<<endl;
                    }
                }
                else cout<<"Not Found"<<endl;
                break;
            }
            case 2:{
                string a;
                getline(cin,a);
                cout<<a<<endl;
                if(author[a].size()>0){
                    sort(author[a].begin(),author[a].end(),compare);
                    for(int j=0;j<author[a].size();j++){
                        cout<<author[a][j]<<endl;
                    }
                }
                else cout<<"Not Found"<<endl;
                break;
            }
            case 3:{
                string k;
                getline(cin,k);
                cout<<k<<endl;
                while(k.find(' ')!=-1){
                    if(key_word[k.substr(0,k.find(' '))].size()>0){
                        sort(key_word[k].begin(),key_word[k].end(),compare);
                        for(int j=0;j<key_word[k.substr(0,k.find(' '))].size();j++){
                            cout<<key_word[k.substr(0,k.find(' '))][j]<<endl;
                        }
                    }
                    k=k.substr(k.find(' ')+1);
                }
                if(key_word[k].size()>0){
                    sort(key_word[k].begin(),key_word[k].end(),compare);
                    for(int j=0;j<key_word[k].size();j++){
                        cout<<key_word[k][j]<<endl;
                    }
                }
                else cout<<"Not Found"<<endl;
                break;
            }
            case 4:{
                string p;
                getline(cin,p);
                cout<<p<<endl;
                if(publisher[p].size()>0){
                    sort(publisher[p].begin(),publisher[p].end(),compare);
                    for(int j=0;j<publisher[p].size();j++){
                        cout<<publisher[p][j]<<endl;
                    }
                }
                else cout<<"Not Found"<<endl;
                break;
            }
            case 5:{
                string y;
                cin>>y;
                cout<<y<<endl;
                if(year[y].size()>0){
                    sort(year[y].begin(),year[y].end(),compare);
                    for(int j=0;j<year[y].size();j++){
                        cout<<year[y][j]<<endl;
                    }
                }
                else cout<<"Not Found"<<endl;
                break;
            }
        }
    }
    return 0;
}
