#include <bits/stdc++.h>

using namespace std;

int uscln(int a,int b){
	while (b!=0){
		int t =b;
		b = a%b;
		a = t;
	}
	return a;
}

int main(){
	int a = 24;int b = 36;
	cout<<"Uoc so chung lan nhat cua 24 va 36 la: "<<uscln(a,b)<<".";
}