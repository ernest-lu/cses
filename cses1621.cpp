#include<bits/stdc++.h>
using namespace std;

//var 
int n,a[200001],un;

int main(){
	cin >> n;
	for(int i = 1; i<=n; i++)cin >> a[i];
	sort(a+1,a+n+1); un = 1;
	for(int i = 2; i<=n; i++)if(a[i]!=a[i-1])un++;
	cout << un << endl;
}