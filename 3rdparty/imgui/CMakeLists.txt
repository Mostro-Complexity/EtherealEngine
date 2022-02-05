cmake_minimum_required(VERSION 3.19)

# --------------------------------------
# Project bgfx+imgui
# --------------------------------------
project(imgui)

# --------------------------------------
# Patch Vanilla imgui with bgfx changes
# --------------------------------------

set(VANILLA_IMGUI_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/imgui/imgui.h
    ${CMAKE_CURRENT_LIST_DIR}/imgui/imgui.cpp
    ${CMAKE_CURRENT_LIST_DIR}/imgui/imgui_demo.cpp
    ${CMAKE_CURRENT_LIST_DIR}/imgui/imgui_draw.cpp
    ${CMAKE_CURRENT_LIST_DIR}/imgui/imgui_internal.h
    ${CMAKE_CURRENT_LIST_DIR}/imgui/imgui_tables.cpp
    ${CMAKE_CURRENT_LIST_DIR}/imgui/imgui_widgets.cpp
    ${CMAKE_CURRENT_LIST_DIR}/imgui/imstb_rectpack.h
    ${CMAKE_CURRENT_LIST_DIR}/imgui/imstb_textedit.h
    ${CMAKE_CURRENT_LIST_DIR}/imgui/imstb_truetype.h)

set(IMGUI_USER_PATCH
    ${CMAKE_CURRENT_LIST_DIR}/imgui_user/imgui_bgfx_extra.cpp
    ${CMAKE_CURRENT_LIST_DIR}/imgui_user/imgui_external.h
    ${CMAKE_CURRENT_LIST_DIR}/imgui_user/imgui_date_picker.h
    ${CMAKE_CURRENT_LIST_DIR}/imgui_user/imgui_date_picker.cpp
    ${CMAKE_CURRENT_LIST_DIR}/imgui_user/imgui_user.h
    ${CMAKE_CURRENT_LIST_DIR}/imgui_user/imgui_user.cpp)

set(IMGUIZMO_SOURCES ${CMAKE_CURRENT_LIST_DIR}/imguizmo/imguizmo.h
                     ${CMAKE_CURRENT_LIST_DIR}/imguizmo/imguizmo.cpp)

set(BGFX_IMGUI_PATCH
    ${CMAKE_CURRENT_LIST_DIR}/../bgfx/bgfx/3rdparty/dear-imgui/imconfig.h
    ${CMAKE_CURRENT_LIST_DIR}/../bgfx/bgfx/3rdparty/dear-imgui/imgui_user.h
    ${CMAKE_CURRENT_LIST_DIR}/../bgfx/bgfx/3rdparty/dear-imgui/imgui_user.inl
    ${CMAKE_CURRENT_LIST_DIR}/../bgfx/bgfx/3rdparty/dear-imgui/widgets)

# set(IMGUI_GENERATED_DIR ${CMAKE_CURRENT_BINARY_DIR}/generated)
# file(COPY ${VANILLA_IMGUI_SOURCES} DESTINATION ${IMGUI_GENERATED_DIR}/imgui)
# file(COPY ${BGFX_IMGUI_PATCH}
#      DESTINATION ${IMGUI_GENERATED_DIR}/bgfx_imgui_patch)
# file(COPY ${IMGUI_USER_PATCH} DESTINATION ${IMGUI_GENERATED_DIR}/imgui_user)
# file(COPY ${IMGUIZMO_SOURCES} DESTINATION ${IMGUI_GENERATED_DIR}/imguizmo)

# --------------------------------------
# Add bgfx examples/common copy because these files are required. It is better
# to maintain a local copy here because there is no guarantee that anything in
# examples actually work so this files may require modifications for your own
# environment.
# --------------------------------------

file(GLOB_RECURSE INTEGRATION_SOURCES ${CMAKE_CURRENT_LIST_DIR}/common/*)

# --------------------------------------
# Combine patched imgui with commons
# --------------------------------------

set(SOURCES ${VANILLA_IMGUI_SOURCES} ${IMGUI_USER_PATCH} ${IMGUIZMO_SOURCES} ${BGFX_IMGUI_PATCH} ${INTEGRATION_SOURCES})

# --------------------------------------
# Define the library
# --------------------------------------
add_library(${PROJECT_NAME} STATIC ${SOURCES})

# --------------------------------------
# Includes
# --------------------------------------
target_include_directories(
  ${PROJECT_NAME}
  PUBLIC ${CMAKE_CURRENT_LIST_DIR})

# --------------------------------------
# Link libraries
# --------------------------------------
target_link_libraries(${PROJECT_NAME} PUBLIC bgfx bx bimg meshoptimizer)
