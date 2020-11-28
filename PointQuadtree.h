#include "CImg.h"
#include "nodo.h"
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#define N 150

using namespace cimg_library;



class PointQuadtree{
private:
    CImg<float> imagen;
    Nodo * m_pRoot;
    ofstream file;
    std::unordered_map<string,bool> v;
public:
    PointQuadtree(std::string name,CImg<float> & img){
	     imagen= img;
       file.open(name);
       int w=img.width();
       int h=img.height();
       file.write((char*)(&w),sizeof(int));
       file.write((char*)(&h),sizeof(int));
	     Insert(0,0 ,img.width(), img.height());
       file.close();
    }
  private:
    bool verificar(int x1,int y1,int x2,int y2){
        int m_r = imagen(x1,y1,0);
        int m_g = imagen(x1,y1,1);
        int m_b = imagen(x1,y1,2);
	      for(int i=x1; i<x2;i++)
	         for(int j=y1; j<y2;j++){
             int r = imagen(i,j,0);
             int g = imagen(i,j,1);
             int b = imagen(i,j,2);
             if(m_r+N<r)
              return false;
             if(m_g+N<g)
              return false;
             if(m_b+N<b)
              return false;
            m_r=std::min(m_r,r);
            m_g=std::min(m_g,g);
            m_b=std::min(m_b,b);
	         }
	       return true;
    }

    bool Insert(int x1,int y1,int x2,int y2){
      string l=to_string(x1)+"-"+to_string(y1)+"-"+to_string(x2)+"-"+to_string(y2);
      if(v[l]==1)
      {
        return 1;
      }
      else
      v[l]=1;
      if(x2-x1<=1 && y2-y1<=1)
      {
          int r = imagen(x1,y1,0);
          int g = imagen(x1,y1,1);
          int b = imagen(x1,y1,2);
          Nodo a(x1,y1,x2,y2,r,g,b);
          file.write((char*)&a,sizeof(Nodo));
        return 1;
      }

      if(!verificar(x1,y1,x2,y2))
      {
    	    int midX= (x1+ x2) /2;
    	    int midY=(y1+y2)/2;
    	    Insert(x1,y1,midX,midY);
    	    Insert(midX,y1,x2,midY);
    	    Insert(x1,midY,midX,y2);
    	    Insert(midX,midY,x2,y2);
      }
      else
      {
        int r = imagen(x1,y1,0);
        int g = imagen(x1,y1,1);
        int b = imagen(x1,y1,2);
        int total=1;
        for(int i=x1;i<x2;i++)
        {
          for(int j=y1;j<y2;j++)
          {
            r+=imagen(i,j,0);
            g+=imagen(i,j,1);
            b+=imagen(i,j,2);
            total++;
          }
        }
        r/=total;
        g/=total;
        b/=total;
        Nodo a(x1,y1,x2,y2,r,g,b);
        file.write((char*)&a,sizeof(Nodo));
      }
    };

};
