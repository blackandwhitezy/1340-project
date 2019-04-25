#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
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
    cout<<"Customer "<<i<<" bought "<<line[i].item_no<<endl;
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
    //cout << pack[cus_no-1][TIME-1];
    //  cout << pack [i][j];
    }
  }
   /*for (int i=1;i<cus_no+1;i++)
      for (int j=1;j<TIME+1;j++)
        cout <<  pack[i][j] << " ";
      cout << endl;*/
  cout << pack[cus_no][TIME];
  return pack[cus_no][TIME];
}


int trace_line(int trace[],int i, int j,customer *&p,int **&pack){
  int counter=0;
/*  for (int k=1;k<i+1;k++){
     for (int l=1;l<TIME+1;l++)
       {cout <<  pack[k][l];}
     cout << endl;} */
     //cout << pack[i][j] << endl;
    //cout << (pack[i][j] == pack[i-1][j]) <<"a"<< (pack[i][j] == pack[i-1][j-p[i-1].item_no]+p[i-1].profit);
  if (i == 0){
    return 0;
  }
  if (pack[i][j] == pack[i-1][j]){
    cout <<"aaaaa";
    trace_line (trace,i-1,j,p,pack);
  }
  else if (pack[i][j] == pack[i-1][j-p[i-1].item_no]+p[i-1].profit){
    cout <<"bbbbbb";
    trace[i-1] = 1;
    for (int k=0;k<i;k++){
      cout << trace[k];
    }
    cout <<endl;
    counter+=1;
    p[i].item_no=0;
    p[i].profit=0;
    trace_line(trace,i-1,j-p[i].item_no,p,pack);
  }
    //return counter;

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
  int cus_no=0,profit,line_no,cashier_counter=0;
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
  for (int i=0;i<cus_no;i++){
    cout << line[i].profit << " " << line[i].item_no << endl;
  }
  profit=arrange_line(cus_no,line,pack);
  //cout << profit;
  int trace[100]={0};
  while (profit>COST_PER_LINE){
    //cout << " aaaa";
    cashier_counter+=1;
    trace_line(trace,cus_no,TIME,line,pack);
    //cout << line_no;
    cout << "Cashier #" << cashier_counter<<endl;
    print_line(trace,line_no,profit);
    profit=arrange_line(cus_no,line,pack);
  }
}
