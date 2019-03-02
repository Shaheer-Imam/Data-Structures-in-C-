#include<iostream>
#include<conio.h>
#include<fstream>
#include<vector>
using namespace std;
int main(){
 ifstream fin;
 ofstream fout;
 fin.open("sort.txt");
 vector<int> v;
 int value;
 while(fin>>value){
 	v.push_back(value);
 }
 fin.close();
 fout.open("sort.txt");
 int i,k,j;
 for(i=1;i<v.size();i++){
 	k = v[i];
 	j = i-1;
 	while(j>=0 && v[j] > k){
 		v[j+1] = v[j];
 		j--;
	 }
	 v[j+1]=k;
 }
 fout.close();
 fout.open("sort.txt");
 for(i=0;i<v.size();i++){
 	fout<<v[i]<<"\n";
 }
 return 0;
}

