cmake_minimum_required(VERSION 3.4.1)
add_library(native-lib
             SHARED
             src/main/cpp/native-lib.cpp )


find_library(log-lib
              log )
#动态方式加载 third是libxxxx.so的xxxx部分
add_library(third SHARED IMPORTED)

SET(third_path ${CMAKE_CURRENT_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libthird.so)

#设置要连接的so的相对路径，${ANDROID_ABI}表示so文件的ABI类型的路径,这一步引入了动态加入编译的so
set_target_properties(third  PROPERTIES IMPORTED_LOCATION ${third_path})

MESSAGE(STATUS “src  third so path= ${third_path}”)

#配置加载native依赖
include_directories( ${ProjectRoot}/app/src/main/cpp/external/include )

target_link_libraries(native-lib third ${log-lib} )
