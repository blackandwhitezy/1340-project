void generate_random(customer line[],int cus_pos, int good[], int good_no, string goodname[]){
  int n = 0;
  ofstream fout("Raw_Customer.txt",ios::app);
  fout << "Customer "<<left<< setw(3)<<cus_pos+1 <<"bought ";
  for (int i=0;i<good_no;i++){
    n = rand()%6;
    fout <<setw(2) <<n << goodname[i]<< ", ";
    line[cus_pos].profit += good[i] * n;
    line[cus_pos].item_no += n;
    //cout << line[cus_pos].profit <<" " << line[cus_pos].item_no << endl;
  }
  fout << " Total items: "<<left <<setw(3)<< line[cus_pos].item_no <<" Total profit: "<<left<<setw(3)<< line[cus_pos].profit<<endl;
  fout.close();
}
