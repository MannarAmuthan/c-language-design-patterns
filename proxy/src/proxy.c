#include "proxy.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void displayRealImage(Image*);
void displayImage(Image* image);

Image* getRealImage(char* filePath){
     RealImage *image=(RealImage*) malloc(sizeof(RealImage));
     int len=strlen(filePath);
     image->display=displayRealImage;
     image->fileName=(char*)malloc(len);
     strcpy(image->fileName,filePath);
     printf("Loading Image from disk (It will be loading only once, no matter how many times you display) %s \n",filePath);
     return (Image*)image;      
}

 Image* getProxyImage(char* filePath){
     ProxyImage *image=(ProxyImage*) malloc(sizeof(ProxyImage));
     int len=strlen(filePath);
     image->display=displayImage;
     image->fileName=(char*)malloc(len);
     strcpy(image->fileName,filePath);
     image->realImage=NULL;
     return (Image*)image;
 }

void displayImage(Image* image){
     ProxyImage* proxyImage=(ProxyImage*) image;
     if(proxyImage->realImage==NULL){
         proxyImage->realImage=(RealImage*)getRealImage(proxyImage->fileName);
     }
     proxyImage->realImage->display((Image*)proxyImage->realImage);
}

void displayRealImage(Image* image){
     RealImage* realImage=(RealImage*) image;
     printf("Displaying image %s \n",realImage->fileName);
}