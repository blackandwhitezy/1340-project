#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
using namespace std;

const int GOOD_MAX=100;
const int TIME=90; 
const int COST_PER_LINE=100;
const int CUSTOMER_MAX=100;

struct customer{
  double profit;
  int item_no;
};

//creat the good array based on good list. Return the total number of goods available.
int readlist(int good[]){
  string line,name,profit;int i=0;
  ifstream fin("goods.txt");
  while (getline(fin,line)){
    istringstream line_in(line);
    line_in>>name;
    line_in>>profit;
    good[i]=atoi(profit.c_str());
    i++;
  }
  return i;
}

void generate_random(customer line[],int cus_pos, int good[], int good_no){
  int n = 0;
  for (int i=0;i<good_no;i++){
    n = rand()%4;
    line[cus_pos].profit += good[i] * n;
    line[cus_pos].item_no += n;
  }
}

int isBigger(int a,int b,int c){
  int temp;
  if (a > b){
    temp = a;
  }
  else{
    temp = b;
  }
  if(temp<c){
    temp = c;
  }
  return temp;
}

//return maxprofit
int arrange_line(int cus_no,customer *p){
  int test,**pack=new int*[cus_no+1];
  for (int i=0;i<cus_no+1;i++){
    pack[i] = new int [TIME+1];
  }
    for (int i=0;i<cus_no+1;i++)
      for (int j=0;j<TIME+1;j++)
        pack[i][j]=0;
  for (int i=1;i<cus_no+1;i++){
    for (int j=1;j<TIME+1;j++){
      test=(p[i].item_no>j?pack[i][j-1]:pack[i-1][j-p[i].item_no]+p[i].profit);
      test=isBigger(test,pack[i][j-1],pack[i-1][j]);
      pack[i][j]=test;
    }
  }
  delete [] pack;
  return pack[cus_no-1][TIME-1];  
}

void trace_line(int i, int j,customer *p){
  int trace[CUSTOMER_MAX]={0};
  if (c>=0){
    if (pack[i][j] == pack[i-1][j]){
      trace_line (i-1,j);
    }
    else if (pack[i][j] == pack[i-1][j-p[i].item_no]+p[i].profit){
      trace[i] = 1;
      p[i].item_no=0;
      p[i].profit=0;
      trace_line(i-1,j-p[i].item_no)
    }
  }
}
void print_customer(customer line[],int cus_no){
  for (int i=0;i<cus_no,i++){
    cout<<"Customer "<<i<<" bought "<<line[i].item_no<<endl; 
}
  
void print_line(int customer_number[],int number, int profit){
  for(int i=0; i<number;i++)
    cout << customer_number[i] << " " << endl;
  cout << "profit for this cashier: " << profit;
}
  
int main()
{
  int good[GOOD_MAX];
  int good_no = readlist(good);
  int n,cashier_counter=0;
  cout << "How many customers in the line?" <<endl;
  cin >> n;
  customer *line = new customer[n];
  srand(time(0));
  for (int i=0;i<n;i++){
    generate_random(line,i,good,good_no);
  }
  while (arrange_line(n,line)>COST_PER_LINE){
    cashier_counter+=1
    trace_line(cus_no,TIME,line)
    cout<<"Cashier #"<<cashier_counter<<endl;
    print_line();
}
