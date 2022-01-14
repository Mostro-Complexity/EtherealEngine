file(GLOB_RECURSE libsrc *.h *.cpp *.hpp *.c *.cc)

add_library (physics ${libsrc})
target_link_libraries(physics PUBLIC Bullet3Common BulletDynamics BulletCollision LinearMath)
target_include_directories(physics PUBLIC ${BULLET_PHYSICS_SOURCE_DIR}/src)
set_target_properties(physics PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

include(target_warning_support)
set_warning_level(physics high)
