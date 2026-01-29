#include<iostream>
using namespace std;
int main(){
	char grade;
	int year;
	double basic ,salary, bonus,gross,tax=0,net;
	cout<<"Enter employee grade(A,B,C) :";
	cin>>grade;
	cout<<"enter year of service :";
	cin>>year;
	
	if(grade=='A')
	salary =50000;
	if(grade=='B')
	salary=30000;
	if(grade=='C')
	salary=20000;
	if(year>=10)
	bonus=0.10*salary;
	if(year>=5&&year<=9)
	bonus=0.05*salary;
	if(year<5)
	bonus=0;
	gross=salary+bonus;
	if(gross>40000)
	tax=0.20*gross;
	if(gross>=30000&&gross<=40000)
	tax=0.10*gross;
	if(gross<30000)
	tax=0;

	net=gross-tax;
	cout<<"basic salary:"<<salary<<endl;
	cout<<"bonus:"<<bonus<<endl;
	cout<<"gross salary:"<<gross<<endl;
	cout<<"net salary :"<<net<<endl;
	return 0;
	
	
	
}
