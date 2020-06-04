#include<bits/stdc++.h>
using namespace std;

//var 
string s;
int t1,t2,ans = 0;

int main(){
	t1 = 0; t2 = 0;
	cin >> s;
	while(t1<s.size()){
		t2 = t1;
		while(s[t2]==s[t1] && t2<s.size())t2++;
		t2--; ans = max(ans,t2-t1+1);
		t1 = t2+1;
	}cout << ans << endl;
}