#include <iostream>
#include <string>
#include <map>
#include <deque>
using namespace std;
int main(){
	string s1, s2;
	cin >> s1 >> s2;
	map<char, int> m;
	deque <char> q;
	int j = 0;
	for (int i = 0; i < s1.length(); ++i){
		if (j == s2.length()){
			if (s1[i] >= 'a'&&s1[i] <= 'z'){
				if (m.count(s1[i] + 'A' - 'a') == 0){
					q.push_back(s1[i] + 'A' - 'a');
				}
				m[s1[i] + 'A' - 'a'] = 1;
			}
			else{
				if (m.count(s1[i]) == 0){
					q.push_back(s1[i]);
				}
				m[s1[i]] = 1;
			}
			continue;
		}
		if (s1[i] == s2[j]){
			j++;
		}
		else{
			if (s1[i]>='a'&&s1[i] <= 'z'){
				if (m.count(s1[i] + 'A' - 'a') == 0){
					q.push_back(s1[i] + 'A' - 'a');
				}
				m[s1[i]+'A'-'a'] = 1;
			}
			else{
				if (m.count(s1[i]) == 0){
					q.push_back(s1[i]);
				}
				m[s1[i]] = 1;
			}

		}
	}
	while (!q.empty()){
		cout << q.front();
		q.pop_front();
	}
	return 0;
}