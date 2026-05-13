# lab07_solver

Небольшой CMake-пакет для лабораторной работы 7.

Пакет содержит статическую библиотеку с функцией решения квадратного уравнения
и устанавливает конфигурационные файлы CMake, чтобы другой проект мог
подключить его через `find_package`.

```cmake
find_package(lab07_solver CONFIG REQUIRED)
target_link_libraries(app PRIVATE lab07_solver::lab07_solver)
```
