# Build example
add_executable(example
  window.cpp
  window.hpp
  glew.c
  example.cpp
  vec2.hpp
  vec2.cpp
  mat2.hpp
  mat2.cpp
  rectangle.hpp
  rectangle.cpp
  circle.hpp
  circle.cpp
  )
target_link_libraries(example
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )
add_dependencies(example glfw nanovg ${COPY_BINARY})

# Build tests
add_executable(tests
  glew.c
  tests.cpp
  window.cpp
  window.hpp
  vec2.hpp
  vec2.cpp
  mat2.hpp
  mat2.cpp
  rectangle.hpp
  rectangle.cpp
  circle.hpp
  circle.cpp
  )
target_link_libraries(tests
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )
#add_dependencies(tests examples ${COPY_BINARY})










