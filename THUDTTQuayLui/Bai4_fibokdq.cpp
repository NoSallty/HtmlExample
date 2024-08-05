#include <bits/stdc++.h>

using namespace std;

int fibo(int n){
	if(n==0) return 0;
	else if (n==1) return 1;
	else{
		int p1 = 0, p2 = 1, fib = 0;
		for (int i =2;i<=n;i++){
			fib = p1+p2;
			p1 = p2;
			p2 = fib;
		}
		return fib;
	}
}

int main(){
	int n;
	cin>>n;
	cout<<"So fibonacci thu "<<n<<" la: "<<fibo(n)<<".";
}