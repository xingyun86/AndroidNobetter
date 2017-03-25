# Sets the minimum version of CMake required to build the native
# library. You should either keep the default value or only pass a
# value of 3.4.0 or lower.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds it for you.
# Gradle automatically packages shared libraries with your APK.

include_directories(src/main/cpp/libjson-1.8.0)
link_directories(src/main/cpp/libjson-1.8.0)
add_library( # Sets the name of the library.
            json

            # Sets the library as a shared library.
            # SHARED
            STATIC

            # Provides a relative path to your source file(s).
            # Associated headers in the same location as their source
            # file are automatically included.
             src/main/cpp/libjson-1.8.0/json_reader.cpp
             src/main/cpp/libjson-1.8.0/json_value.cpp
             src/main/cpp/libjson-1.8.0/json_writer.cpp)

include_directories(src/main/cpp/zlib-1.2.8)
link_directories(src/main/cpp/zlib-1.2.8)
add_library( # Sets the name of the library.
            zlib

            # Sets the library as a shared library.
            # SHARED
            STATIC

            # Provides a relative path to your source file(s).
            # Associated headers in the same location as their source
            # file are automatically included.
             src/main/cpp/zlib-1.2.8/adler32.c
             src/main/cpp/zlib-1.2.8/compress.c
             src/main/cpp/zlib-1.2.8/crc32.c
             src/main/cpp/zlib-1.2.8/deflate.c
             src/main/cpp/zlib-1.2.8/gzclose.c
             src/main/cpp/zlib-1.2.8/gzlib.c
             src/main/cpp/zlib-1.2.8/gzread.c
             src/main/cpp/zlib-1.2.8/gzwrite.c
             src/main/cpp/zlib-1.2.8/infback.c
             src/main/cpp/zlib-1.2.8/inflate.c
             src/main/cpp/zlib-1.2.8/inftrees.c
             src/main/cpp/zlib-1.2.8/inffast.c
             src/main/cpp/zlib-1.2.8/trees.c
             src/main/cpp/zlib-1.2.8/uncompr.c
             src/main/cpp/zlib-1.2.8/zutil.c)

include_directories(src/main/cpp/libjpeg-turbo-1.5.0)
link_directories(src/main/cpp/libjpeg-turbo-1.5.0)
add_library( # Sets the name of the library.
            jpeg

            # Sets the library as a shared library.
            # SHARED
            STATIC

            # Provides a relative path to your source file(s).
            # Associated headers in the same location as their source
            # file are automatically included.
            src/main/cpp/libjpeg-turbo-1.5.0/bmp.c
            src/main/cpp/libjpeg-turbo-1.5.0/cdjpeg.c
            src/main/cpp/libjpeg-turbo-1.5.0/cjpeg.c
            src/main/cpp/libjpeg-turbo-1.5.0/example.c
            src/main/cpp/libjpeg-turbo-1.5.0/jaricom.c
            src/main/cpp/libjpeg-turbo-1.5.0/jcapimin.c
            src/main/cpp/libjpeg-turbo-1.5.0/jcapistd.c
            src/main/cpp/libjpeg-turbo-1.5.0/jccoefct.c
            src/main/cpp/libjpeg-turbo-1.5.0/jccolor.c
            src/main/cpp/libjpeg-turbo-1.5.0/jcdctmgr.c
            src/main/cpp/libjpeg-turbo-1.5.0/jchuff.c
            src/main/cpp/libjpeg-turbo-1.5.0/jcinit.c
            src/main/cpp/libjpeg-turbo-1.5.0/jcmainct.c
            src/main/cpp/libjpeg-turbo-1.5.0/jcmarker.c
            src/main/cpp/libjpeg-turbo-1.5.0/jcmaster.c
            src/main/cpp/libjpeg-turbo-1.5.0/jcomapi.c
            src/main/cpp/libjpeg-turbo-1.5.0/jcparam.c
            src/main/cpp/libjpeg-turbo-1.5.0/jcphuff.c
            src/main/cpp/libjpeg-turbo-1.5.0/jcprepct.c
            src/main/cpp/libjpeg-turbo-1.5.0/jcsample.c
            src/main/cpp/libjpeg-turbo-1.5.0/jctrans.c
            src/main/cpp/libjpeg-turbo-1.5.0/jdapimin.c
            src/main/cpp/libjpeg-turbo-1.5.0/jdapistd.c
            src/main/cpp/libjpeg-turbo-1.5.0/jdatadst-tj.c
            src/main/cpp/libjpeg-turbo-1.5.0/jdatadst.c
            src/main/cpp/libjpeg-turbo-1.5.0/jdatasrc-tj.c
            src/main/cpp/libjpeg-turbo-1.5.0/jdatasrc.c
            src/main/cpp/libjpeg-turbo-1.5.0/jdcoefct.c
            src/main/cpp/libjpeg-turbo-1.5.0/jdcolor.c
            src/main/cpp/libjpeg-turbo-1.5.0/jddctmgr.c
            src/main/cpp/libjpeg-turbo-1.5.0/jdhuff.c
            src/main/cpp/libjpeg-turbo-1.5.0/jdinput.c
            src/main/cpp/libjpeg-turbo-1.5.0/jdmainct.c
            src/main/cpp/libjpeg-turbo-1.5.0/jdmarker.c
            src/main/cpp/libjpeg-turbo-1.5.0/jdmaster.c
            src/main/cpp/libjpeg-turbo-1.5.0/jdmerge.c
            src/main/cpp/libjpeg-turbo-1.5.0/jdphuff.c
            src/main/cpp/libjpeg-turbo-1.5.0/jdpostct.c
            src/main/cpp/libjpeg-turbo-1.5.0/jdsample.c
            src/main/cpp/libjpeg-turbo-1.5.0/jdtrans.c
            src/main/cpp/libjpeg-turbo-1.5.0/jerror.c
            src/main/cpp/libjpeg-turbo-1.5.0/jfdctflt.c
            src/main/cpp/libjpeg-turbo-1.5.0/jfdctfst.c
            src/main/cpp/libjpeg-turbo-1.5.0/jfdctint.c
            src/main/cpp/libjpeg-turbo-1.5.0/jidctflt.c
            src/main/cpp/libjpeg-turbo-1.5.0/jidctfst.c
            src/main/cpp/libjpeg-turbo-1.5.0/jidctint.c
            src/main/cpp/libjpeg-turbo-1.5.0/jidctred.c
            src/main/cpp/libjpeg-turbo-1.5.0/jmemmgr.c
            src/main/cpp/libjpeg-turbo-1.5.0/jmemnobs.c
            src/main/cpp/libjpeg-turbo-1.5.0/jquant1.c
            src/main/cpp/libjpeg-turbo-1.5.0/jquant2.c
            src/main/cpp/libjpeg-turbo-1.5.0/jsimd_none.c
            src/main/cpp/libjpeg-turbo-1.5.0/jutils.c
            src/main/cpp/libjpeg-turbo-1.5.0/rdbmp.c
            src/main/cpp/libjpeg-turbo-1.5.0/rdcolmap.c
            src/main/cpp/libjpeg-turbo-1.5.0/rdgif.c
            src/main/cpp/libjpeg-turbo-1.5.0/rdppm.c
            src/main/cpp/libjpeg-turbo-1.5.0/rdrle.c
            src/main/cpp/libjpeg-turbo-1.5.0/rdswitch.c
            src/main/cpp/libjpeg-turbo-1.5.0/rdtarga.c
            src/main/cpp/libjpeg-turbo-1.5.0/tjutil.c
            src/main/cpp/libjpeg-turbo-1.5.0/transupp.c
            src/main/cpp/libjpeg-turbo-1.5.0/turbojpeg.c
            src/main/cpp/libjpeg-turbo-1.5.0/wrbmp.c
            src/main/cpp/libjpeg-turbo-1.5.0/wrgif.c
            src/main/cpp/libjpeg-turbo-1.5.0/wrrle.c
            src/main/cpp/libjpeg-turbo-1.5.0/wrtarga.c )

set(LIBCURL_PATH D:/DevelopmentEnvironment/Workspaces/Android/AndroidNobetter/app/src/main/cpp/libcurl-ssl-7.52.1)
include_directories(${LIBCURL_PATH}/include)
add_library( # Sets the name of the library.
            curl

            # Sets the library as a shared library.
            # SHARED
            STATIC

            IMPORTED
            )

set_target_properties(curl PROPERTIES IMPORTED_LOCATION ${LIBCURL_PATH}/${ANDROID_ABI}/libcurl.a)

add_library( # Sets the name of the library.
             nativehelper-lib

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             # Associated headers in the same location as their source
             # file are automatically included.
             src/main/cpp/nativehelper-lib.cpp
             src/main/cpp/utils/mobile.cpp
             src/main/cpp/utils/md5.cpp
             src/main/cpp/utils/curl_helper.cpp
             src/main/cpp/utils/img_conv.cpp
             src/main/cpp/utils/base64.cpp
             src/main/cpp/utils/crypt_helper.cpp
             src/main/cpp/utils/rijndael.cpp
             src/main/cpp/utils/utils.cpp
             )

# Searches for a specified prebuilt library and stores the path as a
# variable. Because system libraries are included in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in the
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
                       nativehelper-lib

                       curl
                       jpeg
                       zlib
                       json

                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )