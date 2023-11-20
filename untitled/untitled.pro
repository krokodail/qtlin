QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += sources/


SOURCES += \
    sources/CommandLineInterface.cpp \
    sources/Database.cpp \
    sources/Message.cpp \
    sources/Parsing.cpp \
    sources/User.cpp \
    sources/sha1.cpp \
    loginform.cpp \
    main.cpp \
    mainwindow.cpp \
    registrationform.cpp \
    startscreen.cpp

HEADERS += \
    sources/CommandLineInterface.h \
    sources/Database.h \
    sources/Message.h \
    sources/Parsing.h \
    sources/User.h \
    sources/sha1.h \
    loginform.h \
    mainwindow.h \
    registrationform.h \
    startscreen.h \

FORMS += \
    loginform.ui \
    mainwindow.ui \
    registrationform.ui \
    startscreen.ui

TRANSLATIONS += \
    untitled_en_150.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
