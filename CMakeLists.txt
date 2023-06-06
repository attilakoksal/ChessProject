CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
project(ChessProject)

ADD_EXECUTABLE(test
	ChessBoard.cpp
	ChessSquare.cpp
	main.cpp
)

TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
