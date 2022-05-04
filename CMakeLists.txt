cmake_minimum_required(VERSION 3.13)  # Проверка версии
project(CodeEditorCpp)                # Название проекта 
set(CMAKE_CXX_STANDARD 14)            # Использовать стандарт С++17

set(SOURCE_FILES main.cpp)           

FILE (GLOB SOURCE Source/*.cpp)

add_executable(TabsEditorCpp ${SOURCE} main.cpp)

SET(TARGET_H
    Headers/csvconverter.h
    Headers/TArrayTable.h
    Headers/TTabRecord.h
    Headers/TDataCom.h
    Headers/TDataValue.h
    Headers/TTable.h
    Headers/TScanTable.h

)

SET(TARGET_SRC

)

