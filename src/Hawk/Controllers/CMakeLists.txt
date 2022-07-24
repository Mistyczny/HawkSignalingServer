
add_subdirectory(UsersControllerHandlers)

add_library(UsersController STATIC ${CMAKE_CURRENT_SOURCE_DIR}/UsersController.cpp)
target_link_libraries(UsersController
        PUBLIC
    nlohmann_json::nlohmann_json
    UsersControllerHandlers
    Hawk::Net
)
target_include_directories(UsersController
        PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)
