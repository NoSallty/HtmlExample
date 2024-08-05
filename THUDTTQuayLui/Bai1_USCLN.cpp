#include <bits/stdc++.h>

using namespace std;

int uscln(int a,int b){
	if ( a == 0) return b;
	else if (b == 0) return a;
	else return uscln (b,a%b);
}

int main(){
	int a = 24;int b = 36;
	cout<<"Uoc so chung lan nhat cua 24 va 36 la: "<<uscln(a,b)<<".";
}