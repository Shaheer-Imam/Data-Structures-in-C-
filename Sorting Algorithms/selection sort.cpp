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
 int i,j,temp;
 for(i=1;i<v.size();i++){
	for(j=i+1;j<v.size();j++){
		if(v[i]>v[j]){
			temp=v[i];
			v[i]=v[j];
			v[j]=temp;
		}
	}
 }
 fout.close();
 fout.open("sort.txt");
 for(i=0;i<=v.size();i++){
 	fout<<v[i]<<"\n";
 }
 return 0;
}
