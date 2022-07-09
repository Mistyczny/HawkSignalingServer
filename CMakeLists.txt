cmake_minimum_required(VERSION 3.22)
project(HawkSignalingServer VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Drogon REQUIRED)
find_package(jsoncpp REQUIRED)

aux_source_directory(${CMAKE_SOURCE_DIR}/src SOURCES)
aux_source_directory(${CMAKE_SOURCE_DIR}/src/Controllers CONTROLLERS_SOURCES)
aux_source_directory(${CMAKE_SOURCE_DIR}/src/Controllers/UsersControllerHandlers USERS_CONTROLLERS_HANDLERS_SOURCES)

add_executable(HawkSignalingServer
    ${SOURCES}
    ${CONTROLLERS_SOURCES}
    ${USERS_CONTROLLERS_HANDLERS_SOURCES}
)
target_link_libraries(HawkSignalingServer
        PRIVATE
    Drogon::Drogon
)

target_include_directories(HawkSignalingServer
        PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)
