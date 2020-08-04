#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
string s,ans = "",rev;
int fq[26];
pii o;

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> s;
	for(int i = 0; i<s.size(); i++)
		fq[s[i] - 'A']++;

	o = mp(-1,-1);

	for(int i = 0; i<26; i++){
		if(fq[i]%2 == 0){
			for(int j = 1; j<=fq[i]/2; j++)
				ans += ((char)i+'A');
			continue;
		}
		if(o == mp(-1,-1)){
			o = mp(i,fq[i]);
		}
		else{
			cout << "NO SOLUTION" << endl;
			return 0;
		}
	}

	for(int i = 1; i<=o.s; i++)
		ans += ((char)o.f + 'A');

	rev = "";
	for(int i = 0; i<26; i++){
		if(fq[i]%2 == 0)
			for(int j = 1; j<=fq[i]/2;j++)
				rev += ((char)i+'A');
	}
	reverse(rev.begin(),rev.end());
	cout << ans + rev << endl;

	cout.flush();
	return 0;
}