#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

const int GOOD_MAX=100;
const int TIME=90; 

struct customer{
  double profit;
  int item_no;
};

//creat the good array based on good list. return the total number of goods available.
int readlist(int good[]){
  
  string line,name,profit;int i=0;
  ifstream fin("goods.txt");
  isringstream line_in(line);
  while (getline(fin,line)){
    line_in>>name;
    line_in>>profit;
    good[i]=atoi(profit.c_str());
    i++
  }
  return i;
}

void generate_random(customer line[],int good[]){
  
}

//return maxprofit
int arrange_line(int cus_no,int cus_chosen_id[],customer *p){
  int test,*pack=new int[cus_no+1][TIME+1];
    for (int i=0;i<cus_no+1;i++)
      for (int j=0;j<TIME+1;j++)
        pack[i][j]=0;
  for (int i=1;i<cus_no+1;i++){
    for (int j=1;j<TIME+1;j++){
      test=(p[i].item>j?pack[i][j-1]:pack[i-1][j-p[i].item]+p[i].profit);
      test=isBigger(test,pack[i][j-1],pack[i-1][j]);
    }
  }
  return pack[n-1][TIME-1];  
}

int isBigger(int a,int b,int c){}

void print_line(){}

int main()
{
  int good[GOOD_MAX],line[TIME];
  readlist(good);
  int n;
  cout << "How many customers in the line?" <<endl;
  cin >> n;
  customer *line = new customer[n];
  for (int i=0;i<n;i++)
  {
    generate_random(line,good);
  }

}
