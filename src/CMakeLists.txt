target_sources(gmpf
        PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/main.cc
        ${CMAKE_CURRENT_LIST_DIR}/gmpf.cc
        )

include(${CMAKE_CURRENT_LIST_DIR}/callbacks/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/data_structures/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/config/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/misc/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/commands/CMakeLists.txt)
