//Quick Sort

#include<iostream>
#include<benchmarking.h>
typedef unsigned long long int ulli;
using namespace std;
void swap( int &b, int &a){
	int c = a;
	a = b;
	b = c;
}
int findpartition(int *a, int start, int end){
	if(start == end) return start;
	int neutval = a[end];
	int smallptr = start,bigptr = end-1;
	while(smallptr != bigptr){
		if(a[smallptr] > neutval){
			swap(a[smallptr],a[bigptr]);
			bigptr--;
		}else{
			smallptr++;
		}
	}
	if(a[smallptr] > neutval){
		swap(a[smallptr],a[end]);
		return smallptr;
	}
	swap(a[smallptr+1],a[end]);
	return smallptr+1;
}
void quicksort(int *a, int start, int end){
	if(start > end) return;
	int partition = findpartition(a,start,end);
	quicksort(a,start,partition-1);
	quicksort(a,partition+1,end);
}
void outarray(int *a, int n){
	for(int i = 0; i < n; i++){
		cout<<a[i]<<" ";
	}
	cout<<"\n";
}
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
	quicksort(a,0,n-1);
	//cout<<"Array after sort is: ";
	//outarray(a,n);
	cout<<getUlliMsTime()-start;
}
