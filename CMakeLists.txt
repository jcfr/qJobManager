cmake_minimum_required(VERSION 2.8.7)

project(qJobManager)

find_package(Qt4)
include(${QT_USE_FILE})

set(KIT_SRCS
  qJob.h qJob.cpp qJobManager.h qJobManager.cpp
  )

set(KIT_MOC_SRCS
  qJob.h qJobManager.h
  )

QT4_WRAP_CPP(KIT_SRCS ${KIT_MOC_SRCS})

add_executable(qjobmanager main.cpp ${KIT_SRCS})
target_link_libraries(qjobmanager ${QT_LIBRARIES})
