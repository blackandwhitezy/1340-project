//return maxprofit
#include "arrange_line.h"

using namespace std;

int isBigger(int a,int b,int c){
  int temp;
  if (a > b)
    temp = a;
  else
    temp = b;
  if(temp<c)
    temp = c;
  return temp;
}


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
