#include <bits/stdc++.h>

using namespace std;

int fibo(int n){
	if(n<3) return 1;
	else return fibo(n-1)+fibo(n-2);
}

int main(){
	int n;
	cin>>n;
	cout<<"So fibonacci thu "<<n<<" la: "<<fibo(n)<<".";
}