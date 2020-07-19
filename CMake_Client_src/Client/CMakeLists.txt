cmake_minimum_required (VERSION 3.8)

project (UDP_Client LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5 REQUIRED COMPONENTS Widgets)

set(project_ui
    mainwindow.ui)

set(project_headers 
    mainwindow.h)

set(project_sources 
    UDP_Client.cpp
    mainwindow.cpp)

qt5_wrap_ui(project_hearders_wrapped ${project_ui})
qt5_wrap_cpp(project_sources_moc ${project_headers})

add_executable(${PROJECT_NAME} ${project_headers} ${project_sources} ${project_sources_moc} ${project_hearders_wrapped})

target_link_libraries(${PROJECT_NAME}   
    PUBLIC
    Qt5::Widgets
)