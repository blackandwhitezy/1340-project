#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <iomanip>

using namespace std;

const int GOOD_MAX=100;
const int TIME=90;
const int COST_PER_LINE=50;
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
    //cout << line[cus_pos].profit <<" " << line[cus_pos].item_no << endl;
  }
}

void print_customer(customer line[],int cus_no){
  for (int i=0;i<cus_no;i++){
    cout<<"Customer "<<setw(3)<<i+1<<" bought "<<setw(3)<<line[i].item_no<<" items Profit: "<<line[i].profit<<endl;
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
int arrange_line(int cus_no,customer *&p,int **&pack){
  int test=0;
  pack=new int*[cus_no+1];
  for (int i=0;i<cus_no+1;i++){
    pack[i] = new int [TIME+1];
  }
  for (int i=0;i<cus_no+1;i++)
    for (int j=0;j<TIME+1;j++)
      pack[i][j]=0;
  for (int i=1;i<cus_no+1;i++){
    for (int j=1;j<TIME+1;j++){
      test=(p[i-1].item_no>j?pack[i][j-1]:pack[i-1][j-p[i-1].item_no]+p[i-1].profit);
      test=isBigger(test,pack[i][j-1],pack[i-1][j]);
      pack[i][j]=test;
    }
  }
  return pack[cus_no][TIME];
}


int trace_line(int counter,int trace[],int i, int j,customer *&p,int **&pack){
  if (i == 0){
    return counter;
  }
  if (pack[i][j] == pack[i-1][j]){
    trace_line (counter,trace,i-1,j,p,pack);
  }
  else if (pack[i][j] == pack[i-1][j-p[i-1].item_no]+p[i-1].profit && pack[i][j]!=0){
    trace[i-1] = i;
    counter+=1;
    p[i-1].item_no=0;
    p[i-1].profit=0;
    trace_line(counter,trace,i-1,j-p[i-1].item_no,p,pack);
  }

}


void print_line(int customer_number[],int number, int profit){
  for(int i=0; i<number;i++){
    if (customer_number[i]=0)
      cout << "Customer "<<setw(3)<<customer_number[i] << " being chosen "<< endl;
  }
  cout << "profit for this cashier: $" << profit<<endl;
}

int main()
{
  int good[GOOD_MAX];
  int good_no = readlist(good);
  int cus_no=0,profit=0,line_no=0,cashier_counter=0,counter=0;
  int **pack;
  cout << "How many customers in the line?" <<endl;
  cin >> cus_no;
  customer *line = new customer[cus_no];
  for (int i=0;i<cus_no;i++){
    line[i].profit=0;
    line[i].item_no=0;
  }
  srand(time(0));
  for (int i=0;i<cus_no;i++){
    generate_random(line,i,good,good_no);
  }
  print_customer(line,cus_no);
  profit=arrange_line(cus_no,line,pack);
  cout<<"Profit for openning a new cashier: $"<<profit<<endl;
  int trace[100]={0};
  while (profit>COST_PER_LINE){
    cashier_counter+=1;
    line_no=trace_line(counter,trace,cus_no,TIME,line,pack);
    cout << "Cashier #" << cashier_counter<<endl;
    print_line(trace,line_no,profit);
    trace[100]={0};
    profit=arrange_line(cus_no,line,pack);
    cout<<"Profit for openning a new cashier: $"<<profit<<endl;
  }
}
