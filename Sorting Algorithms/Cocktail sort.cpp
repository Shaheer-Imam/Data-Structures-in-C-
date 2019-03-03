#include<iostream>
#include<conio.h>
#include<fstream>
#include<vector>
using namespace std;
int main(){
 ifstream fin;
 ofstream fout;
 int value,start=0,n,temp;
 bool swapped = true;
 vector<int> v;
 fin.open("cocktail.txt");
 while(fin>>value){
 	v.push_back(value);
 }
 fin.close();
 n=v.size();
 int end = n-1;
 fout.open("cocktail.txt");
 while(swapped){
 	swapped = false;
 	for(int i=start;i<end;++i){
 	 	if(v[i]>v[i+1]){
 		 temp=v[i+1];
 		 v[i+1]=v[i];
 		 v[i]=temp;
 		 swapped = true;
		}
	}
	 if(!swapped){
	 	break;
	 }
	 swapped=false;
	 --end;
	 for(int i=end-1;i>=start;--i){
	 	if(v[i]>v[i+1]){
	 	 temp=v[i+1];
 		 v[i+1]=v[i];
 		 v[i]=temp;
 		 swapped = true;
		 }
		 ++start;
	 }
 }
 fout.close();
 fout.open("cocktail.txt");
 for(int i=0;i<v.size();i++){
 	fout<<v[i]<<" ";
 }
 fout.close();
 return 0;
}

