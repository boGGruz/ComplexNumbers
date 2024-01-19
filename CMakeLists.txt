cmake_minimum_required(VERSION 3.25)
project(Complex)

set(CMAKE_CXX_STANDARD 20)

# Ваш исполняемый файл (приложение)
add_executable(Complex test1.cpp ComplexNumbers.h)

# Добавляем папку с исходными файлами Google Test
add_subdirectory(googletest-main)

# Включаем заголовочные файлы Google Test
include_directories(googletest-main/googletest/include)

# Создаем исполняемый файл для тестов
add_executable(ComplexTests test1.cpp) # Замените test1.cpp и test2.cpp на ваши файлы с тестами

# Линкуем с Google Test
target_link_libraries(ComplexTests gtest gtest_main)

