#include "../src/proxy.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int shouldDisplayImage();
char imageDisplayed[12];

Image* getMockRealImage(char* filePath);


void fakeDisplayRealImage(Image* image){
     strcpy(imageDisplayed,((RealImage*)image)->fileName);
}

int main(){
    int isAllPassed=1;
    if(shouldDisplayImage()==-1){
        printf("Test failed : In Proxy Pattern : --> shouldDisplayImage \n");
        isAllPassed=0;
    }

    if(isAllPassed!=1){
        exit(-1);
    }
    else{
         printf("All tests are passed : In Proxy Pattern \n");
    }
}

int shouldDisplayImage(){
      Image* image=getProxyImage("myImage.png");
      image->display(image);

      ((ProxyImage*)image)->realImage->display=fakeDisplayRealImage;

      image->display(image);  
      if(strcmp(imageDisplayed,"myImage.png")!=0) return -1;
      return 0;
}
