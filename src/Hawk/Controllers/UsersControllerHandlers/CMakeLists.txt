
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} USERS_CONTROLLER_HANDLERS_SOURCES)

add_library(UsersControllerHandlers STATIC ${USERS_CONTROLLER_HANDLERS_SOURCES})
target_link_libraries(UsersControllerHandlers
        PUBLIC
    Hawk::Net
)
target_include_directories(UsersControllerHandlers
        PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)