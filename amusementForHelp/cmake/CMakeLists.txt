cmake_minimum_required(VERSION 3.8...3.12 FATAL_ERROR)


project (test)

find_package(VTK REQUIRED
  vtkCommonCore
  vtkFiltersSources
  vtkFiltersSources
  vtkInteractionStyle
  vtkRenderingOpenGL2
)
include(${VTK_USE_FILE})
add_executable(vtkfir MACOSX_BUNDLE vtkfir.cpp)
target_link_libraries(vtkfir pthread)
target_link_libraries(vtkfir ${VTK_LIBRARIES})
