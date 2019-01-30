#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headerA.h"
//switchは続いて読んじゃうからブレイクする必要あるけどif文はどうなんだ？きちんと背反で条件をわけないとダメ？
void GaussianFilter(ImageData *imgIn, ImageData *imgOut){
  int xi, yi;
  int _w = imgIn->width;
  int _h = imgIn->height;
  int _channels = imgIn->channels;
  int is_color = (imgIn->channels == 3); //color:1 gray:0
  unsigned char img[(imgIn->width)*(imgIn->height)][3];
  unsigned char img2[(imgIn->width)*(imgIn->height)];
  int upper=-_w, lower=+_w, right=+1, left=-1;



  if(is_color){
    memcpy(img, imgIn->data, _channels*_h*_w);
    for(yi=0; yi< _h; yi++ ){
      for(xi=0; xi< _w; xi++){
        int i = xi + yi*_w;


	if(xi == 0) left = 0;
	if(xi == _w-1) right = 0;
	if(yi == 0) upper = 0;
	if(yi == _h-1) lower =0;

	*(imgOut->data + i*3) = (unsigned char)((2*((int)img[i+left][0]+(int)img[i+right][0]+(int)img[i+upper][0]+(int)img[i+lower][0])+4*((int)img[i][0])+((int)img[i+upper+left][0]+(int)img[i+upper+right][0]+(int)img[i+lower+left][0]+(int)img[i+lower+right][0]))/16);
	*(imgOut->data + i*3+1) = (unsigned char)((2*((int)img[i+left][1]+(int)img[i+right][1]+(int)img[i+upper][1]+(int)img[i+lower][1])+4*((int)img[i][1])+((int)img[i+upper+left][1]+(int)img[i+upper+right][1]+(int)img[i+lower+left][1]+(int)img[i+lower+right][1]))/16);
	*(imgOut->data + i*3+2) = (unsigned char)((2*((int)img[i+left][2]+(int)img[i+right][2]+(int)img[i+upper][2]+(int)img[i+lower][2])+4*((int)img[i][2])+((int)img[i+upper+left][2]+(int)img[i+upper+right][2]+(int)img[i+lower+left][2]+(int)img[i+lower+right][2]))/16);

  upper=-_w;
  lower=+_w;
  right=+1;
  left=-1;
//printf("%d  ", i);
      }
    }
  }
  else{
    memcpy(img2, imgIn->data, _channels*_h*_w);
    for(yi=0; yi< _h; yi++ ){
      for(xi=0; xi< _w; xi++){
        int i = xi + yi*_w;

	if(xi == 0) left = 0;
	if(xi == _w-1) right = 0;
	if(yi == 0) upper = 0;
	if(yi == _h-1) lower =0;

	*(imgOut->data + i) = (unsigned char)((2*((int)img2[i+left]+(int)img2[i+right]+(int)img2[i+upper]+(int)img2[i+lower])+4*((int)img2[i])+((int)img2[i+upper+left]+(int)img2[i+upper+right]+(int)img2[i+lower+left]+(int)img2[i+lower+right]))/16);
//printf("%d  ", i);
  upper=-_w;
  lower=+_w;
  right=+1;
  left=-1;
      }
    }
  }
}
/*	*(imgOut->data + i*3) = (unsigned char)((2*((int)img[i-1][0]+(int)img[i+1][0]+(int)img[i-_w][0]+(int)img[i+_w][0])+4*((int)img[i][0])+((int)img[i-_w-1][0]+(int)img[i-_w+1][0]+(int)img[i+_w-1][0]+(int)img[i+_w+1][0]))/16);
	*(imgOut->data + i*3+1) = (unsigned char)((2*((int)img[i-1][1]+(int)img[i+1][1]+(int)img[i-_w][1]+(int)img[i+_w][1])+4*((int)img[i][1])+((int)img[i-_w-1][1]+(int)img[i-_w+1][1]+(int)img[i+_w-1][1]+(int)img[i+_w+1][1]))/16);
	*(imgOut->data + i*3+2) = (unsigned char)((2*((int)img[i-1][2]+(int)img[i+1][2]+(int)img[i-_w][2]+(int)img[i+_w][2])+4*((int)img[i][2])+((int)img[i-_w-1][2]+(int)img[i-_w+1][2]+(int)img[i+_w-1][2]+(int)img[i+_w+1][2]))/16);
*/
