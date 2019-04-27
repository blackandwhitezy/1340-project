//trace the customer chosen in the cashier
#include "trace_line.h"

using namespace std;

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
