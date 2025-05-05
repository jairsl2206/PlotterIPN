cmake_minimum_required(VERSION 3.16)

project(Charifas VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Solo una llamada para Qt6 con todos los módulos
find_package(Qt6 REQUIRED COMPONENTS Core Widgets SerialPort Charts)

set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
)

if(QT_VERSION VERSION_GREATER_EQUAL "6.0.0")
    qt_add_executable(Charifas
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(Charifas SHARED ${PROJECT_SOURCES})
    else()
        add_executable(Charifas ${PROJECT_SOURCES})
    endif()
endif()

# Solo un bloque para linkear
target_link_libraries(Charifas
    PRIVATE
    Qt6::Core
    Qt6::Widgets
    Qt6::SerialPort
    Qt6::Charts
)

# Propiedades para bundle (macOS/iOS opcional)
if(QT_VERSION VERSION_GREATER_EQUAL "6.0.0")
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Charifas)
endif()
set_target_properties(Charifas PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Charifas
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Charifas)
endif()
