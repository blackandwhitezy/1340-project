#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int GOOD_MAX=100;
struct customer{
  double profit;
  int item_no;
};
int readlist(int * good[]){
  
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

void generate_random(){}

void arrange_line(){}

void print_line(){}

int main()
{
  int good[GOOD_MAX];
  int n;
  cout << "How many customers in the line?" <<endl;
  cin >> n;
  customer *line = new customer[n];
  for (int i=0;i<n;i++)
  {
    void 
  }

}
