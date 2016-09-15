//Test case generator for quick_sort
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

int main(){
	int n,ele;
	srand(time(NULL));
	cin>>n;
	cout<<n<<"\n";
	for(int i = 0; i < n; i++){
		ele = rand() % 1000;
		cout<<ele<<"\n";		
	}
}
