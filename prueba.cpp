#include <bits/stdc++.h>
#define N 5
using namespace std;


void partir(int x1,int y1,int x2,int y2)
{
  // if ( x1==x2 && y1==y2)
  // {
  //   return ;
  // }
  // if ( x1+1==x2 || y1+1==y2) return ;

  if(x2-x1<=1 && y2-y1<=1)
  {
    cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
    return;
  }


  int midX= (x1+ x2) /2;
  int midY=(y1+y2)/2;
  partir(x1,y1,midX,midY);
  partir(midX,y1,x2,midY);
  partir(x1,midY,midX,y2);
  partir(midX,midY,x2,y2);
}

int main()
{
  partir(0,0,N,N);
}
