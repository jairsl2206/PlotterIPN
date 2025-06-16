set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets Test SerialPort Charts)

add_executable(test_clearChart
    test_clearChart.cpp
    ${PROJECT_SOURCE_DIR}/mainwindow.cpp
    ${PROJECT_SOURCE_DIR}/mainwindow.h
    ${PROJECT_SOURCE_DIR}/mainwindow.ui
)

target_include_directories(test_clearChart PRIVATE ${PROJECT_SOURCE_DIR})

target_link_libraries(test_clearChart
    PRIVATE Qt6::Core Qt6::Widgets Qt6::Test Qt6::SerialPort Qt6::Charts
)

add_test(NAME test_clearChart COMMAND test_clearChart)
set_tests_properties(test_clearChart PROPERTIES ENVIRONMENT "QT_QPA_PLATFORM=offscreen")

add_executable(test_fft
    test_fft.cpp
    ${PROJECT_SOURCE_DIR}/mainwindow.cpp
    ${PROJECT_SOURCE_DIR}/mainwindow.h
)
target_include_directories(test_fft PRIVATE ${PROJECT_SOURCE_DIR})
target_link_libraries(test_fft PRIVATE Qt6::Core Qt6::Widgets Qt6::Test Qt6::SerialPort Qt6::Charts)
add_test(NAME test_fft COMMAND test_fft)
set_tests_properties(test_fft PROPERTIES ENVIRONMENT "QT_QPA_PLATFORM=offscreen")
