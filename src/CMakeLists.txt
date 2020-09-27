target_sources(gmpf
        PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/main.cc
        ${CMAKE_CURRENT_LIST_DIR}/gtk.cc
        )

include(${CMAKE_CURRENT_LIST_DIR}/callbacks/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/data_structure/CMakeLists.txt)