cmake_minimum_required(VERSION 3.20)
project(My_C_Learning C)

set(CMAKE_C_STANDARD 99)

# === 魔法开始：自动寻找所有 .c 文件 ===
# 这里的 GLOB_RECURSE 表示连子文件夹里的也要找
file(GLOB_RECURSE MY_SOURCES "*.c")

# 遍历找到的每一个文件
foreach(file_path ${MY_SOURCES})
    # 排除掉 cmake 自动生成的临时文件（以防万一）
    if(NOT ${file_path} MATCHES "cmake-build-debug")
        # 获取文件名（不带后缀），作为运行时的名字
        get_filename_component(target_name ${file_path} NAME_WE)

        # 自动生成 executable
        add_executable(${target_name} ${file_path}
                cpl7/substr.c
                cpl7/BigTitle.c)
    endif()
endforeach()