#include <iostream>
#include <fstream>
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
int arrange_line(int cus_no,int [],customer *p){
  int pack[n][TIME];
  for (int i=0;i<n;i++)
    for (int j=0;j<TIME;j++)
      if (p.item_no<=j)pack[n][j]=p.profit;
  int test=(p.item>j?p[i][j-1]:p[i-1][j-p.item]+p.profit);
  test=(test>p[i][j-1]?test:p[i][j-1]);
  test=(test>p[i-1][j]?test:p[i-1][j]);
  return pack[n-1][TIME-1];  
}

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
    void generate_random(line,good);
  }

}
