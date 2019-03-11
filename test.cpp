#include <bits/stdc++.h>
using namespace std;

int n,k;
int a[10001];

int binarySearch(int x,int begin,int end){
	int left=begin,right=end;
	int mid;
	while(left<=right){
		mid=(left+right)/2;
		if(a[mid]==x) return mid;
		else if(x>a[mid]) left=mid+1;
		else if(x<a[mid]) right=mid-1;
	}
	if(x>a[mid]) return mid;
	else return mid-1;
}

//a[begin:end]循环右移k位
void shiftRight(int begin,int end,int k){
	for(int i=0;i<k;i++){
		int temp=a[end];
		for(int i=end;i>begin;i--) a[i]=a[i-1];
		a[begin]=temp;
	}
}

 void merge(){
	 int i=0;
	 int j=k;
	 while (i<j&&j<n){
		 int p=binarySearch(a[i],j,n-1); //在a[j:n-1]中找a[i]的位置
		 shiftRight(i,p,p-j+1);
		 i+=p-j+2;
		 j=p+1;
	 }
 }

int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>a[i];
	merge();

	for(int i=0;i<n;i++){
		cout<<a[i]<<' ';
	}
	cout<<endl;
	return 0;
}
