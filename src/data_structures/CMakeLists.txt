target_sources(gmpf PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/global_data.cc
        ${CMAKE_CURRENT_LIST_DIR}/position.cc
        ${CMAKE_CURRENT_LIST_DIR}/size.cc
        ${CMAKE_CURRENT_LIST_DIR}/angle.cc
        ${CMAKE_CURRENT_LIST_DIR}/project_info.cc
        )

target_sources(unitTest
        PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/position.cc
        ${CMAKE_CURRENT_LIST_DIR}/size.cc
        ${CMAKE_CURRENT_LIST_DIR}/angle.cc
        )

include(${CMAKE_CURRENT_LIST_DIR}/layers/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/tools/CMakeLists.txt)
