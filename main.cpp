#include <main.h>
using namespace std;



int main()
{
  int good[GOOD_MAX];
  string goodname[GOOD_MAX];
  int good_no = readlist(good,goodname);
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
    generate_random(line,i,good,good_no,goodname);
  }
  profit=arrange_line(cus_no,line,pack);
  while (profit>COST_PER_LINE){
    int trace[100]={0};
    cashier_counter+=1;
    trace_line(trace,cus_no,TIME,line,pack);
    print_line(trace,cus_no,profit,cashier_counter);
    profit=arrange_line(cus_no,line,pack);
  }
  delete [] pack;
  delete [] line;
}
