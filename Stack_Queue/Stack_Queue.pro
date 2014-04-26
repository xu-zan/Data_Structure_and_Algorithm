TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    Stack_Queue_Main.c \
    Stack/Stack.c \
    Test.c \
    Stack/Test_Stack.c

HEADERS += \
    pre_definition.h \
    Stack/Stack.h \
    Test.h \
    Stack/Test_Stack.h

OTHER_FILES += \
    Makefile

