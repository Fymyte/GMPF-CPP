target_sources(gmpf PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/global_data.cc
        ${CMAKE_CURRENT_LIST_DIR}/position.cc
        )

target_sources(unitTest
        PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/position.cc
        )