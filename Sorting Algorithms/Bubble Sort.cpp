#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main (){
 ifstream fin;
 ofstream fout;
 fin.open("sort.txt");
 vector<int> vi;
 int value;
while(fin >> value){
  vi.push_back(value);
}
 fin.close();
 fout.open("sort.txt");
 int i, j, first, temp;
      int numLength = vi.size();
      for (i= numLength - 1; i > 0; i--)
     {
           first = 0;          
           for (j=1; j<=i; j++) 
          {
                 if (vi[j] > vi[first])
                 first = j;
          }
         temp = vi[first];   
         vi[first] = vi[i];
         vi[i] = temp;
     }
fout.close();

fout.open("sort.txt");
for(int i = 0 ; i<numLength;i++)
{
	fout<<vi[i]<<"\n";
}
fout.close();

return 0;
}
