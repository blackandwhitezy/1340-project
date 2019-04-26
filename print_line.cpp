// output the result    
#include <iostream>
#include <fstream>
#include <iomanip>
void print_line(int customer_number[],int number, int profit, int cashier_counter){
  ofstream fout("Line_Customer.txt",ios::app);
  fout << "Cashier #" << cashier_counter<<endl;
  for(int i=0; i<number;i++){
    if (customer_number[i] !=0)
      fout << "Customer "<< left <<setw(3) << customer_number[i] << "being chosen "<< endl;
  }
  fout << "Total profit for this cashier: $" << profit <<endl;
  fout.close();
}
