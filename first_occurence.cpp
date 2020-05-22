#include<bits/stdc++.h>
using namespace std;

int first_occurence(int a[], int n , int key){
	if(n == 0)
		return -1;
	if(a[0] == key)
		return 0;
	int x = first_occurence(a+1,n-1,key);
	if(x == -1)
		return -1;
	return x + 1;
}
int last_occurence(int *a,int n, int key){
	if(n == 0)
		return -1;
	int x = last_occurence(a+1,n-1,key);
	if(x == -1){
		if(a[0] == key)
			return 0;
		else
			return -1;
	}
	return x+1;
}
void all_occ(int *a, int i,int n, int key){
	if(i == n)
		return ;
	if(a[i] == key){
		cout << i << ',' ;
	}
	all_occ(a,i+1,n,key);
}
int store_occurence(int *a, int i,int n,int key,int *store,int j){
	if(i == n){
		return j;
	}
	if(a[i] == key){
		store[j] = i;
		return store_occurence(a,i+1,n,key,store,j+1);
	}
	return store_occurence(a,i+1,n,key,store,j); 
}
int main(){
	int a[10] = {1,2,3,7,5,6,7,8,9,1};
	cout << first_occurence(a,10,7) << endl;
	cout << last_occurence(a,10,7) << endl;  // last occurnce
	all_occ(a,0,10,7);
	int store[10];
	int count = store_occurence(a,0,10,7,store,0);
	cout << "\n";
	for(int i = 0; i < count; i++){
		cout << store[i] << ',';
	}


}