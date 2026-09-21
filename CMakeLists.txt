cmake_minimum_required(VERSION 3.20)
project(financiamento_lab LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Google Test via FetchContent
include(FetchContent)
FetchContent_Declare(googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Biblioteca de calculo do financiamento
add_library(financiamento src/financiamento.cpp)
target_include_directories(financiamento PUBLIC include)
if(MSVC)
  target_compile_options(financiamento PRIVATE /W4 /utf-8)
else()
  target_compile_options(financiamento PRIVATE -Wall -Wextra)
endif()

# Executavel dos testes automatizados
enable_testing()
add_executable(testes_financiamento
  tests/teste_nominal.cpp
  tests/teste_limites.cpp
  tests/teste_prevencao.cpp
  tests/teste_perfis.cpp
)
target_include_directories(testes_financiamento PRIVATE include)
target_link_libraries(testes_financiamento PRIVATE
  financiamento
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(testes_financiamento)

# Executavel interativo CLI
add_executable(cli_financiamento src/main.cpp)
target_include_directories(cli_financiamento PRIVATE include)
target_link_libraries(cli_financiamento PRIVATE financiamento)
