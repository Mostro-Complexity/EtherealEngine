add_subdirectory( mml )

option(IMGUI_KEYBOARD_MAPPING "True to use imgui key mapping instead of windows virtual key." ON)

target_include_directories (mml-window PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/mml/include)

set_target_properties( mml-system PROPERTIES FOLDER "3rdparty/mml" )
set_target_properties( mml-window PROPERTIES FOLDER "3rdparty/mml" )
