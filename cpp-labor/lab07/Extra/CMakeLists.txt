cmake_minimum_required(VERSION 3.23)
project(Extra)

set(CMAKE_CXX_STANDARD 17)

add_executable(Extra main.cpp Polynomial.cpp Polynomial.h ../User.cpp ../User.h ../QuizGame.cpp ../QuizGame.h ../Quiz.cpp ../Quiz.h ../Question.h)
