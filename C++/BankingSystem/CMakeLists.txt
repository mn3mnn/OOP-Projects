cmake_minimum_required(VERSION 3.22)
project(Banking_system_)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Banking_system_
        BankAccount.cpp
        BankApplication.h
        BankingApplication.cpp
        Client.cpp
        main.cpp
        SavingBankAccount.cpp)
