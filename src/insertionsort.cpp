//Quick Sort

#include<iostream>
#include"benchmarking.h"
typedef unsigned long long int ulli;
using namespace std;
int j,key;
void insertionsort(int *a, int n){
	for(int i = 1; i < n; i++){
		key = a[i];
		for(j = i-1; j >= 0; j--){
			if(key >= a[j]){
				break;
			}
			a[j+1] = a[j];
		}
		a[j+1] = key;
	}
}

/*void outarray(int *a, int n){
	for(int i = 0; i < n; i++){
		cout<<a[i]<<" ";
	}
	cout<<"\n";
}*/
int main(){
	ulli start = getUlliMsTime();
	int n;
	//cout<<"Enter number of elements: ";
	cin>>n;
	int *a = new int[n];
	//cout<<"Enter elements:\n";
	for(int i = 0; i < n; i++){
		//cout<<"a["<<i<<"] = ";
		cin>>a[i];
	}
	//cout<<"You entered: ";
	//outarray(a,n);
	insertionsort(a,n);
	//cout<<"Array after sort is: ";
	//outarray(a,n);
	cout<<getUlliMsTime()-start;
}
