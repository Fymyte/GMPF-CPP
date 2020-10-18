target_sources(gmpf PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/global_data.cc
        ${CMAKE_CURRENT_LIST_DIR}/position.cc
        ${CMAKE_CURRENT_LIST_DIR}/size.cc
        ${CMAKE_CURRENT_LIST_DIR}/angle.cc
        ${CMAKE_CURRENT_LIST_DIR}/layer.cc
        ${CMAKE_CURRENT_LIST_DIR}/layer_manager.cc
        )

target_sources(unitTest
        PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/position.cc
        ${CMAKE_CURRENT_LIST_DIR}/size.cc
        ${CMAKE_CURRENT_LIST_DIR}/angle.cc
        )