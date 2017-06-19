#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main(int argc, char const *argv[])
{
	cin.tie(NULL);
	cout.tie(NULL);

	ll int T,Arr[100], N, U, D, flag;
	string line;
	char ch;

	freopen("input.txt","r", stdin);
	freopen("output.txt","w",stdout);

	cin >> T;
	while(T-- > 0) {
	    cin >> line;
	    U = 0;
	    D = 0;
	    flag = 0;
	    if(line[0] == 'D'){
	    	D++;	    	
	    }
	    else{
	    	U++;
	    }
	    for (int i = 1; i < line.size(); ++i)
	    {
	    	if(line[i-1] == 'D' && line[i] == 'U' && flag == 0){
	    		U++;
	    		flag = 1;
	    	}
	    	else if(line[i-1] == 'U' && line[i] == 'D' && flag == 0){
	    		D++;
	    		flag = 1;
	    	}
	    	else{
	    		flag = 0;
	    	}
	    }
	    cout << min(U,D) << endl;
	}
	return 0;
}