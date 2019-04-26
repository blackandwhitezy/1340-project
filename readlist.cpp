//creat the good array based on good list. Return the total number of goods available.
#include <readlist.h>
using namespace std;
int readlist(int good[],string goodname[]){
  string line,name,profit;int i=0;
  ifstream fin("goods.txt");
  while (getline(fin,line)){
    istringstream line_in(line);
    line_in>>goodname[i];
    line_in>>profit;
    good[i]=atoi(profit.c_str());
    i++;
  }
  fin.close();
  return i;
}
