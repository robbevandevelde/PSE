cmake_minimum_required(VERSION 3.6)
project(pse)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "-Wall -Werror -O2")
set(CMAKE_EXE_LINKER_FLAGS -pthread) #add -pthread on windows/ unix

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
        Gate.cpp
        Gate.h
        main.cpp
        Runway.cpp
        Runway.h
        Flightplan.h
        Flightplan.cpp
        Parsers/FlightplanParser.cpp
        Parsers/FlightplanParser.h
        )

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
        TestMain.cpp
        Runway.cpp
        Runway.h Tests/RunwayTest.cpp
        Tests/AirplaneTest.cpp Tests/AirportTest.cpp
        Tests/GatesTest.cpp DesignByContract.h
        Tests/LuchthavenParserTest.cpp AirportUtils.cpp
        AirportUtils.h Taxiroute.cpp Taxiroute.h Flightplan.cpp
        Flightplan.h Gate.cpp Gate.h AirTrafficController.cpp AirTrafficController.h Simulator.cpp Simulator.h)

add_executable(pse ${SOURCE_FILES})

# Create DEBUG target
add_executable(pse_debug ${DEBUG_SOURCE_FILES})

# Link library
target_link_libraries(pse_debug gtest)