#include<iostream>
#include<fstream>
#include<conio.h>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
 ifstream fin;
 ofstream fout;
 int value;
 vector<int> v;
 fin.open("bucket.txt");
 while(fin>>value){
 	v.push_back(value);
 }
 fin.close();
 fout.open("bucket.txt");
 int i,j,gap,n,temp;
 n=v.size();
 for(gap=n/2;gap>0;gap/=2){
 	for(i=gap;i<n;i++){
 		temp=v[i];
	 	for(j=i;j>=gap&&v[j-gap]>temp;j-=gap){
	 		v[j]=v[j-gap];
		 }
	 	v[j]=temp;
	 }
 }
 fout.close();
 fout.open("bucket.txt");
 for(i=0;i<v.size();i++){
 	fout<<v[i]<<"\n";
 }
 fout.close();
 return 0;
}

