# Sets the minimum version of CMake required to build the native
# library. You should either keep the default value or only pass a
# value of 3.4.0 or lower.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds it for you.
# Gradle automatically packages shared libraries with your APK.

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

add_library( # Sets the name of the library.
             native-lib

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             # Associated headers in the same location as their source
             # file are automatically included.
             src/main/cpp/native-lib.cpp )

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
                       native-lib

                       jpeg

                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )