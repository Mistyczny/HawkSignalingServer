
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} HAWK_NET_SOURCES)
add_library(Net SHARED ${HAWK_NET_SOURCES})

target_link_libraries(Net
        PUBLIC
    Drogon::Drogon
)
target_include_directories(Net
        PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)
add_library(Hawk::Net ALIAS Net)