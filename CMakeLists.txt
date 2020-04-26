cmake_minimum_required(VERSION 3.16)
project(Asm C)

set(CMAKE_C_STANDARD 11)
#set(CMAKE_BUILD_TYPE Debug)
include_directories(.)
set(DCMAKE_SH="CMAKE_SH-NOTFOUND")
add_executable(Asm
        code/card_file.c
        header/card_file.h
        code/card_service.c
        header/card_service.h
        code/list.c
        header/list.h
        code/login_log.c
        header/login_log.h
        code/login_log_file.c
        header/login_log_file.h
        code/main.c
        header/main.h
        code/menu.c
        header/menu.h
        code/other_log.c
        header/other_log.h
        code/other_log_file.c
        header/other_log_file.h
        code/search_file.c
        header/search_file.h
        code/tool.c
        header/tool.h)
