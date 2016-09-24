#include<iostream>
#include<vector>
#include"benchmarking.h"
typedef unsigned long long int ulli;
using namespace std;

void mergesort(vector<int> &a, int start, int end){
	if(start >= end) return;
	int mid = (start + end) / 2;
	mergesort(a,start,mid);
	mergesort(a,mid+1,end);
	int ptr1 = start, ptr2 = mid+1;
	vector<int> locvec;
	while(ptr1 != mid + 1 && ptr2 != end+1){
		if(a[ptr1] <= a[ptr2]){
			locvec.push_back(a[ptr1]);
			ptr1++;
		}else{
			locvec.push_back(a[ptr2]);
			ptr2++;
		}
	}
	while(ptr1 != mid + 1){
		locvec.push_back(a[ptr1]);
		ptr1++;
	}
	while(ptr2 != end+1){
		locvec.push_back(a[ptr2]);
		ptr2++;
	}
	for(int i = 0; i < locvec.size(); i++){
		a[start+i] = locvec[i];
	}
}
int main(){
	int n;
	vector<int> a;
	cin>>n;
	a.resize(n);
	for(int i = 0; i < n; i++){
		cin>>a[i];
	}
	ulli start = getUlliMsTime();
	mergesort(a,0,n-1);
	cout<<getUlliMsTime()-start;
}
