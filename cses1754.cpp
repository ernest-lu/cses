#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
int t,a,b;

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> t;
	while(t--){
		cin >> a >> b;
		cout << (((a+b)/3 <= min(a,b) && (a+b) % 3 == 0 && a && b) || (a==0 && b == 0) ? "YES" : "NO") << endl;
	}	

	cout.flush();
	return 0;
}