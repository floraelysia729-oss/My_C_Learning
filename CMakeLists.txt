cmake_minimum_required(VERSION 3.20)
project(My_C_Learning C)

set(CMAKE_C_STANDARD 99)

# ==========================================
# 1. 定义“配角”列表（工具文件）
# 把那些没有 main 函数、只是用来被调用的 .c 文件列在这里
# 如果你的 cuboid 或 mines 不需要这些工具，这里可以留空
# ==========================================
set(MY_TOOLS
        cpl7/substr.c
        cpl7/BigTitle.c
        cpl7/pife.c
)

# ==========================================
# 2. 自动寻找所有 .c 文件
# ==========================================
file(GLOB_RECURSE ALL_SOURCES "*.c")

# ==========================================
# 3. 遍历文件，生成程序
# ==========================================
foreach(file_path ${ALL_SOURCES})

    # A. 排除 cmake 自动生成的临时文件
    if(NOT ${file_path} MATCHES "cmake-build-debug")

        # B. 排除掉“配角”文件
        # (我们不希望为 substr.c 单独生成一个 exe，因为它没有 main 函数跑不起来)
        # 这里判断：如果当前文件不在 MY_TOOLS 列表中，才处理
        list(FIND MY_TOOLS ${file_path} _index)

        if(_index EQUAL -1)
            # 获取文件名（不带后缀）作为 exe 的名字
            get_filename_component(target_name ${file_path} NAME_WE)

            # C. 生成可执行文件
            # 这里的逻辑是：exe = 主角文件 + 所有配角文件
            add_executable(${target_name}
                    ${file_path}   # 当前的主角 (例如 cuboid.c)
                    ${MY_TOOLS}    # 所有的工具 (例如 BigTitle.c)
            )

            # 只要成功添加，就在 CMake 面板里打印一行提示，方便你看
            message(STATUS "这就为您生成程序: ${target_name}")
        endif()
    endif()
endforeach()