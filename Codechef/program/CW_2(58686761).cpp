#include <bits/stdc++.h>
using namespace std;
#define ll long long
/*ll binarysearch(multiset<ll>ms,ll i,ll j,ll n){
	ll mid;
	while(i<=j){
		mid = (i+j)/2;
		auto it = ms.begin();
		advance(it,mid);
		if(*it == (n-mid))
			return *it;
		else if(*it>(n-mid))
			j = mid-1;
		else
			i = mid+1;
	}abcdc

	return n-i;
}*/
ll check(string s){
	ll i = 0,j = s.size()-1,x = 0;
	bool f = false;
	while(i<=j){
		if(s[i] != s[j] && !f){
			j--;
		}else if(s[i] == s[j]){
			if(!f){
				x = j;
				f = true;
			}
			i++;
			j--;
		}else if(s[i] != s[j] && f){
			i = 0;
			f = false;
			x = 0;
		}
	}
	return x;
}

string Palindrome(string s){
	ll x = check(s);
	if(x == s.size()-1)
		return "None";
	int n = x+1;
	string ans = "";
	for(int i = n;i<s.size();i++){
		ans+=s[i];
	}
	reverse(ans.begin(),ans.end());
	return ans;
}

void solve(){
	string s;
	cin >> s;
	cout << Palindrome(s) << "\n";
}


int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	solve();
	/*ll t;
	cin >> t;
	for(ll i = 1;i<=t;i++){
	  solve(i);
	}*/
	return 0;
}