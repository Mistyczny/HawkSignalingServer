
add_subdirectory(Net)
add_subdirectory(Controllers)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SOURCES)
add_executable(HawkSignalingServer
    ${SOURCES}
)
target_link_libraries(HawkSignalingServer
        PRIVATE
    Drogon::Drogon
    Hawk::Net
    Hawk::UserController
    Hawk::UsersController
    Hawk::SignalingController
)
target_include_directories(HawkSignalingServer
        PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)
