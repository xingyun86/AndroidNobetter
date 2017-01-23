#include <jni.h>
#include <string>

#include <jpeglib.h>
#include <jmorecfg.h>
#include <jconfig.h>

extern "C"{
/*===================================================================================
function:       jpeg压缩
input:          1:生成的文件名,2:bmp的指针,3:位图宽度,4:位图高度,5:颜色深度
return:         int
description:    bmp的像素格式为(RGB)
===================================================================================*/
int savejpeg(char *filename, unsigned char *bits, int width, int height, int depth)
{
#define JPEG_QUALITY 80     //它的大小决定jpg的质量好坏
    struct jpeg_compress_struct cinfo;
    struct jpeg_error_mgr jerr;
    FILE * outfile;                 /* target file */
    JSAMPROW row_pointer[1];        /* pointer to JSAMPLE row[s] */
    int     row_stride;             /* physical row width in image buffer */

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_compress(&cinfo);

    if ((outfile = fopen(filename, "wb")) == NULL) {
        fprintf(stderr, "can't open %s/n", filename);
        return -1;
    }
    jpeg_stdio_dest(&cinfo, outfile);

    cinfo.image_width = width;      /* image width and height, in pixels */
    cinfo.image_height = height;
    cinfo.input_components = 3;         /* # of color components per pixel */
    cinfo.in_color_space = JCS_RGB;         /* colorspace of input image */

    jpeg_set_defaults(&cinfo);
    jpeg_set_quality(&cinfo, JPEG_QUALITY, TRUE /* limit to baseline-JPEG values */);

    jpeg_start_compress(&cinfo, TRUE);

    row_stride = width * depth; /* JSAMPLEs per row in image_buffer */

    while (cinfo.next_scanline < cinfo.image_height) {
        //这里我做过修改，由于jpg文件的图像是倒的，所以改了一下读的顺序
        //这是原代码：row_pointer[0] = & bits[cinfo.next_scanline * row_stride];
        row_pointer[0] = (JSAMPROW)&bits[(cinfo.image_height - cinfo.next_scanline - 1) * row_stride];
        (void) jpeg_write_scanlines(&cinfo, row_pointer, 1);
    }

    jpeg_finish_compress(&cinfo);
    fclose(outfile);

    jpeg_destroy_compress(&cinfo);
    return 0;
}

jstring
Java_com_nobetter_ppshuai_androidnobetter_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";

    return env->NewStringUTF(hello.c_str());
}

}
