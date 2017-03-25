#ifndef __IMG_ICONV_H
#define __IMG_ICONV_H

#include <string>
#include <jpeglib.h>
#include <jmorecfg.h>
#include <jconfig.h>

/*===================================================================================
function:       jpeg压缩
input:          1:生成的文件名,2:bmp的指针,3:位图宽度,4:位图高度,5:颜色深度
return:         int
description:    bmp的像素格式为(RGB)
===================================================================================*/
int savejpeg(char *filename, unsigned char *bits, int width, int height, int depth);

#endif //__IMG_ICONV_H