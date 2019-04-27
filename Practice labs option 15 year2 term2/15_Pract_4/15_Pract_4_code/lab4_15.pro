TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXX_FLAGS += /EHa

SOURCES += \
        main.cpp \
    decimal.cpp

HEADERS += \
    decimal.h
