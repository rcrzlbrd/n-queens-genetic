cmake_minimum_required(VERSION 4.2)
project(n_queens_genetic)

set(CMAKE_CXX_STANDARD 17)

# Ejecutable principal
add_executable(n_queens_genetic
        main.cpp
        src/fitness.cpp
        src/genetic_v1.cpp
        src/genetic_v2.cpp
        src/visualizer.cpp
)

# Ejecutable de experimentos
add_executable(run_experiments
        experiments/run_experiments.cpp
        src/fitness.cpp
        src/genetic_v1.cpp
        src/genetic_v2.cpp
)

target_include_directories(n_queens_genetic PRIVATE src)
target_include_directories(run_experiments PRIVATE src)
