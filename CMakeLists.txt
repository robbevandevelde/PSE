cmake_minimum_required(VERSION 3.6)
project(pse)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "-Wall -Werror -O2")
set(CMAKE_EXE_LINKER_FLAGS -pthread)

# Set include dir
include_directories(gtest/include)

# Set Library dir
link_directories(gtest/lib)

set(SOURCE_FILES
        Parsers/AirplaneParser.cpp
        Parsers/AirplaneParser.h
        Parsers/AirportParser.cpp
        Parsers/AirportParser.h
        Parsers/LuchthavenParser.cpp
        Parsers/LuchthavenParser.h
        Parsers/RunwayParser.cpp
        Parsers/RunwayParser.h
        TinyXML/tinystr.cpp
        TinyXML/tinystr.h
        TinyXML/tinyxml.cpp
        TinyXML/tinyxml.h
        TinyXML/tinyxmlerror.cpp
        TinyXML/tinyxmlparser.cpp
        Airplane.cpp
        Airplane.h
        Airport.cpp
        Airport.h
        Gates.cpp
        Gates.h
        main.cpp
        Runway.cpp
        Runway.h)

set(DEBUG_SOURCE_FILES
        Parsers/AirplaneParser.cpp
        Parsers/AirplaneParser.h
        Parsers/AirportParser.cpp
        Parsers/AirportParser.h
        Parsers/LuchthavenParser.cpp
        Parsers/LuchthavenParser.h
        Parsers/RunwayParser.cpp
        Parsers/RunwayParser.h
        TinyXML/tinystr.cpp
        TinyXML/tinystr.h
        TinyXML/tinyxml.cpp
        TinyXML/tinyxml.h
        TinyXML/tinyxmlerror.cpp
        TinyXML/tinyxmlparser.cpp
        Airplane.cpp
        Airplane.h
        Airport.cpp
        Airport.h
        Gates.cpp
        Gates.h
        TestMain.cpp
        Runway.cpp
        Runway.h RunwayTest.cpp AirplaneTest.cpp AirportTest.cpp GatesTest.cpp DesignByContract.h LuchthavenParserTest.cpp AirportUtils.cpp AirportUtils.h)

add_executable(pse ${SOURCE_FILES})

# Create DEBUG target
add_executable(pse_debug ${DEBUG_SOURCE_FILES})

# Link library
target_link_libraries(pse_debug gtest)