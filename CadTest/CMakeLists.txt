cmake_minimum_required( VERSION 3.4.0 )
project(CurvesProject CXX )

set (CMAKE_CXX_STANDARD 14)
set (LIBRARY CurvesLib)

set(CurvesLibSrc src/Circle.cpp src/Curve.cpp src/Ellipse.cpp src/Helix.cpp)
set(CurvesLibHeaders src/Circle.h src/Curve.h src/Ellipse.h src/Helix.h)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_library(${LIBRARY} SHARED ${CurvesLibSrc} ${CurvesLibHeaders})

add_executable(${PROJECT_NAME} CadTest.cpp ${CurvesLibHeaders})
find_package(OpenMP)
if (OpenMP_CXX_FOUND)
    target_link_libraries(${PROJECT_NAME} PUBLIC OpenMP::OpenMP_CXX ${LIBRARY})
else()
	target_link_libraries(${PROJECT_NAME} ${LIBRARY})
endif()
