#include<iostream>
using namespace std;
int main(){
	int N, sum = 0;
	cout<<"Enter a number:";
	cin>>N;
	for(int i = 1; i<=N;i++){
		sum +=1;
	}
	cout <<"sum ="<<sum;
	return 0;
}