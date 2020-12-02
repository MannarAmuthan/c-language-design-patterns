#ifndef _PROXY_H
#define _PROXY_H

typedef struct _image{
    void (*display)();
}Image;

typedef struct _real_image{
    void (*display)();
    char *fileName; 
}RealImage;

typedef struct _proxy_image{
    void (*display)();
    char *fileName; 
    RealImage* realImage;
}ProxyImage;

Image* getProxyImage(char* filePath);

#endif


