#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headerA.h"

//コマンドライン入力の第一引数を入力画像のファイル名、第２引数をフィルター適用回数とする。

int main(int argc, char *argv[]){
  //FILE *fp;
  ImageData imgIn, imgOut, imgNow;

  //printf("B!");

  if(argc != 3){
    printf("wrong command,\n ./b7-1 {filename} {the number of filters}\n");
    return -1;
  }
  /*
  if((fp = fopen(argv[1], "rb")) == NULL){
    printf("there aint such a fxxking file!\n");
    return -2;
    }*/

  if(atoi(argv[2]) == 0){
    printf("don't you wannna filter your image?\n");
    return -3;
  }

  LoadImage(argv[1], &imgIn);
  CopyImage(&imgIn, &imgOut); //for copying imgIn's channels, width, height.and to secure the memory of imgOut.data

  //printf("%d", atoi(argv[2]));
  //("A!");

  for(int i=0; i<atoi(argv[2]); i++){
    GaussianFilter(&imgIn, &imgOut);
    CopyImage(&imgOut, &imgIn);
    //printf("%d", i);
  }

  if(imgIn.channels == 1){
    SaveImage("FilteredImageGray.pgm", &imgOut);
  }
  else{
    SaveImage("FilteredImageColor.ppm", &imgOut);
  }

  ReleaseImage(&imgIn);
  ReleaseImage(&imgOut);

  return 0;
}
