#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
int n, x, MXN = 1000000, tmp, cnt, ans = 1;
bool npr[1000001];
vector<int> pr, cnts;

void seeve(){
	for(int i = 2; i<=MXN; i++){
		if(npr[i])continue;
		pr.pb(i);
		for(int j = i+i; j<=MXN; j+=i)
			npr[j] = 1;
	}
}

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	seeve();
	cout << pr.size() << endl;
	cin >> n;
	while(n--){
		cin >> x; cnts.clear(); tmp = x; ans = 1;
		for(int i = 0; i<pr.size(); i++){
			if(pr[i] * pr[i] > x) break;
			cnt = 0;
			while(tmp%pr[i] == 0){
				cnt++;
				tmp/=pr[i];
			} if(cnt) cnts.pb(cnt);
		} if(tmp != 1) cnts.pb(1);
		for(auto u : cnts)
			ans *= (u+1);

		cout << ans << endl;
	}

	cout.flush();
	return 0;
}