add_library(account STATIC account.cpp)
target_include_directories(account PUBLIC ${CMAKE_SOURCE_DIR}/includes)

add_library(user user.cpp)
target_include_directories(user PUBLIC ${CMAKE_SOURCE_DIR}/includes)

add_library(fileop fileop.cpp)
target_include_directories(fileop PUBLIC ${CMAKE_SOURCE_DIR}/includes)