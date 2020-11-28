#include "CImg.h"
#include <dirent.h>
#include "PointQuadtree.h"
#include <vector>
#include <algorithm>
#include <unordered_map>

#define cimg_use_jpeg 1




using namespace cimg_library;
int main()
{

   CImg<float>   A("img/IMG1.jpg");
   PointQuadtree Quad("c.dat",A); /*Descomentar para comprimir la imagen mediante esta estructura y guardala en dicho archivos*/
   // read("c.dat"); /*Descomentar para leer la imagen comprimida en dicho archivos*/



  // g++ -std=c++17 main.cpp -lX11 -lpthread

   return 0;
}
