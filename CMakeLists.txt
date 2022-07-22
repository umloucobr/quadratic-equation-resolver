# CMakeList.txt: projeto de CMake para QuadraticEquationSolver, incluir origem e definir
# lógica específica a um projeto aqui.
#
cmake_minimum_required (VERSION 3.8)

project ("QuadraticEquationSolver")

# Adicione a origem ao executável deste projeto.
add_executable (QuadraticEquationSolver "quadraticequationsolver.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET QuadraticEquationSolver PROPERTY CXX_STANDARD 20)
endif()

# TODO: Adicione testes e instale destinos, se necessário.
