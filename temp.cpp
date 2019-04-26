#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <iomanip>

using namespace std;

const int GOOD_MAX=100;
const int TIME=90;
const int COST_PER_LINE=250;
const int CUSTOMER_MAX=500;

struct customer{
  double profit;
  int item_no;
};

//creat the good array based on good list. Return the total number of goods available.
int read_goods_file(int good[],string good_name[]){
  string line,name,profit;int i=0;
  ifstream fin("goods.txt");
  while (getline(fin,line)){
    istringstream line_in(line);
    line_in>>good_name[i];
    line_in>>profit;
    good[i]=atoi(profit.c_str());
    i++;
  }
  fin.close();
  return i;
}

void generate_random_customers(customer line[],int cus_pos, int good[], int good_no, string good_name[]){
  int n = 0;
  ofstream fout("Raw_Customer.txt",ios::app);
  fout << "Customer "<<left<< setw(3)<<cus_pos+1 <<"bought ";
  for (int i=0;i<good_no;i++){
    n = rand()%6;
    fout <<setw(2) <<n << good_name[i]<< ", ";
    line[cus_pos].profit += good[i] * n;
    line[cus_pos].item_no += n;
    //cout << line[cus_pos].profit <<" " << line[cus_pos].item_no << endl;
  }
  fout << " Total items: "<<left <<setw(3)<< line[cus_pos].item_no <<" Total profit: "<<left<<setw(3)<< line[cus_pos].profit<<endl;
  fout.close();
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


int trace_line(int trace[],int i, int j,customer *&p,int **&pack){
  if (i == 0){
    return 0;
  }
  if (pack[i][j] == pack[i-1][j]){
    trace_line (trace,i-1,j,p,pack);
  }
  else if (pack[i][j] == pack[i-1][j-p[i-1].item_no]+p[i-1].profit && pack[i][j]!=0){
    trace[i-1] = i;
    p[i-1].profit=0;
    trace_line(trace,i-1,j-p[i-1].item_no,p,pack);
  }

}


void write_cashier_arrangement(int customer_number[],int number, int profit, int cashier_counter){
  ofstream fout("Cashier_Arrangement.txt",ios::app);
  fout << "Cashier #" << cashier_counter<<endl;
  for(int i=0; i<number;i++){
    if (customer_number[i] !=0)
      fout << "Customer "<< left <<setw(3) << customer_number[i] << "being chosen "<< endl;
  }
  fout << "Total profit for this cashier: $" << profit <<endl;
  fout.close();
}

int main()
{
  int good[GOOD_MAX];
  string good_name[GOOD_MAX];
  int good_no = read_goods_file(good,good_name);
  int cus_no=0,profit=0,cashier_counter=0;
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
    generate_random_customers(line,i,good,good_no,good_name);
  }
  profit=arrange_line(cus_no,line,pack);
  while (profit>COST_PER_LINE){
    int trace[100]={0};
    cashier_counter+=1;
    trace_line(trace,cus_no,TIME,line,pack);
    write_cashier_arrangement(trace,cus_no,profit,cashier_counter);
    profit=arrange_line(cus_no,line,pack);
  }
  delete [] pack;
  delete [] line;
}
