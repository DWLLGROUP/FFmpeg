# Cmake构建的最小版本
cmake_minimum_required(VERSION 3.4.1)


#添加库名
#SHARED 表示动态so库，STATIC表示静态a库
#要编译的cpp源文件文件路径
add_library(
        native-lib
        SHARED
        native-lib.cpp
)

#导入第三方库，第三方库名称、指明类型为动态so库、指明为导入到库
add_library(NovaPushStream SHARED IMPORTED)
#表示以导入的方式添加一个库。
#设置导入第三方库 #第三方so库名称、指明配置导入第三方so库路径、第三方库的具体路径
set_target_properties(
        NovaPushStream #指名目标库名
        PROPERTIES IMPORTED_LOCATION #指明要设置的参数库路径
        ${CMAKE_SOURCE_DIR}/ffmpeg/${ANDROID_ABI}/libNovaPushStream.so  #导入库的路径
)

#将native-lib关联到第三方库头文件
target_include_directories(
        native-lib
        PRIVATE
        ${CMAKE_SOURCE_DIR}/ffmpeg/include)

target_link_libraries(
        native-lib
        log)

find_library(
        log-lib
        #这一块保持不变，不过如果需要其他NDK原生库的话，可自行在此处添加
        log)


#将native-lib库关联到NDK原生log库中，从而可以在native-lib中调用log中的内容
target_link_libraries(
        native-lib
        NovaPushStream
        ${log-lib})