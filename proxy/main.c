#include "src/proxy.h"

int main(){
   Image* image=getProxyImage("myImage.png");

   image->display(image);
   image->display(image);
   image->display(image);
}