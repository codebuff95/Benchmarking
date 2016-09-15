//Test case generator for quick_sort
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> v;
int n;

int main(){
	srand(time(NULL));
	cin>>n;
	v.resize(n);
	cout<<n<<"\n";
	for(int i = 0; i < n; i++){
		v[i] = rand()%100000;
	}
	sort(v.begin(),v.end(),greater<int>());
	for(int i = 0; i < n; i++){
		cout<<v[i]<<"\n";
	}
}
