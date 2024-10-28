cmake_minimum_required(VERSION 3.16)

project(CR61_Xplatforms_App VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(appCR61_Xplatforms_App
    main.cpp
)

qt_add_qml_module(appCR61_Xplatforms_App
    URI CR61_Xplatforms_App
    VERSION 1.0
    QML_FILES
        Main.qml
        SOURCES daimlerstandardsecurityalgo.h daimlerstandardsecurityalgo.cpp
        SOURCES parameterprovider_cr61_sec_18_25_01_20182620112649.h parameterprovider_cr61_sec_18_25_01_20182620112649.cpp
        SOURCES cr61_sec_18_25_01_20182620112649.h cr61_sec_18_25_01_20182620112649.cpp
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appCR61_Xplatforms_App PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appCR61_Xplatforms_App
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appCR61_Xplatforms_App
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appCR61_Xplatforms_App
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
