#include "SLLst.h"
#include <iostream>

int main ()
{
	using namespace std;
	SLLst<int> aint;
	int a;
	cout<<"Please input aint:"<<endl;
	cin>>a;
	aint.addToHead(a);
	while (a!=0) {
		cout<<"Please input aint:"<<endl;
		cin>>a;
		aint.addToHead(a);
	}
    
	cout<<"The info in Head is : "<<endl;
	cout<<aint.deletFromTail()<<endl;
	while(1);
	return 0;
}