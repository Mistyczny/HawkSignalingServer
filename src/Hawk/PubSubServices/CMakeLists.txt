add_library(UsersPubSubService
# TODO: Check how to make it shared
        STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/UsersPubSubService.cpp
)

target_link_libraries(UsersPubSubService
        PUBLIC
    Hawk::Net
    Drogon::Drogon
)
target_include_directories(UsersPubSubService
        PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)
add_library(Hawk::UsersPubSubService ALIAS UsersPubSubService)