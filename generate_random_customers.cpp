// generate a random list of the item each customer bought
#include "generate_random_customer.h"

using namespace std;

void generate_random_customer(customer line[],int cus_pos, int good[], int good_no, string goodname[]){
  int n = 0;
  ofstream fout("Raw_Customer.txt",ios::app);
  fout << "Customer "<<left<< setw(3)<<cus_pos+1 <<"bought ";
  for (int i=0;i<good_no;i++){
    n = rand()%6;
    fout <<setw(2) <<n << goodname[i]<< ", ";
    line[cus_pos].profit += good[i] * n;
    line[cus_pos].item_no += n;
  }
  fout << " Total items: "<<left <<setw(3)<< line[cus_pos].item_no <<" Total profit: "<<left<<setw(3)<< line[cus_pos].profit<<endl;
  fout.close();
}
