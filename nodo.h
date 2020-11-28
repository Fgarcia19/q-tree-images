#include <fstream>

#include "CImg.h"

using namespace std;
using namespace cimg_library;

struct Nodo
{
  int x1;
  int y1;
  int x2;
  int y2;
  int g;
  int r;
  int b;
  Nodo()=default;
  Nodo(int x1, int y1, int x2,int y2,int r,int g,int b)
  {
    this->x1=x1;
    this->y1=y1;
    this->x2=x2;
    this->y2=y2;
    this->g=g;
    this->r=r;
    this->b=b;
  }
};


void read(string pic)
{
  CImg<float>   B("img/IMG2.jpg");
  /* imagen cualquiera para tener escala de colores, cuando no ponia una imagen ahi, el resultado final lo botaba en escala de grises*/

  ifstream f(pic);
  int w;
  int h;
  f.read((char*)(&w),sizeof(int));
  f.read((char*)(&h),sizeof(int));
  B.resize(w,h);


  f.seekg(-sizeof(Nodo),ios::end);
  int fin=f.tellg();
  f.seekg(2*sizeof(int));

  int aux=0;
  while(!f.eof())
  {

    if(f.tellg()==fin) break;
    Nodo a;
    f.read((char*)&a,sizeof(Nodo));
   for(int i=a.x1;i<a.x2;i++)
    {
      for(int j=a.y1;j<a.y2;j++)
      {
        string l=to_string(i)+'-'+to_string(j);
        B(i,j,0)=a.r;
        B(i,j,1)=a.g;
        B(i,j,2)=a.b;
      }
    }
    }
    B.display();
}
