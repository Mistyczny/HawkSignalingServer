
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/UsersControllerHandlers USERS_CONTROLLER_SOURCES)
add_library(UsersController
        # TODO: Check how to make it shared
        STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/UsersController.cpp
    ${USERS_CONTROLLER_SOURCES}
)

target_link_libraries(UsersController
        PUBLIC
    Hawk::Net
    Drogon::Drogon
)
target_include_directories(UsersController
        PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)
add_library(Hawk::UsersController ALIAS UsersController)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/UserControllerHandlers USER_CONTROLLER_SOURCES)
add_library(UserController
        # TODO: Check how to make it shared
        STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/UserController.cpp
    ${USER_CONTROLLER_SOURCES}
)

target_link_libraries(UserController
        PUBLIC
    Hawk::Net
    Drogon::Drogon
)
target_include_directories(UserController
        PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)
add_library(Hawk::UserController ALIAS UserController)


add_library(SignalingController
        # TODO: Check how to make it shared
        STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/SignalingController.cpp
)

target_link_libraries(SignalingController
        PUBLIC
    Hawk::Net
    Drogon::Drogon
)
target_include_directories(SignalingController
        PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)
add_library(Hawk::SignalingController ALIAS SignalingController)