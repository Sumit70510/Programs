#include <bits/stdc++.h>
using namespace std;

int main()
{
	// your code goes here
	vector<int> v;
	
	string s;
	getline(cin , s);
	istringstream input_stream(s);
	
	int value;
	while(input_stream >> value){
	    v.push_back(value);
	}
	
	int k,num;
	cin >> k >> num;
	
	sort(v.begin(),v.end());
	
	if(v[k-1]>=num){
	    cout << "True\n";
	}else{
	    cout << "False\n";
	}
	
	return 0;
}
