cmake_minimum_required(VERSION 2.8)

PROJECT(opengl-test C CXX)

SET(SRCS
    example1.cpp
    midCircle.cpp
    scanFill.cpp
    matrix2d.cpp
    animation.cpp
    bezier.cpp
    recurBezier.cpp
    intersection.cpp
    2DTransform.cpp
    circulation.cpp
    3DTransform.cpp
    hansel.cpp
    home.cpp
    stair.cpp
    viewProj.cpp
    cows.cpp
    sphere.cpp
    fileTest.cpp
    Taekwondo.cpp
    crossRiver.cpp
    box.cpp
    thread1.cpp
    alarmProcess.cpp
    alarmThread.cpp
    meeting.cpp
    #thread_error.cpp
    city.cpp
    tex.cpp
    bomb.cpp
    square.cpp
    bombMarker.cpp
    exceed.cpp
    natural.cpp
    match.cpp
    lifeCycle.cpp
    average.cpp
    stencilTest.cpp
    treeHeight.cpp
    testmemset.cpp
    testGlew.cpp
    testShader.cpp
    tree.cpp
    hayPoint.cpp
    testAutoPtr.cpp
    nightShift.cpp
    alphaBlend.cpp
    alpha.cpp
    testRef.cpp
    vertexArray.cpp
    cubic.cpp
    pixelBuffer.cpp
    textureShader.cpp
    notifier.cpp
    cast.cpp
    vec.cpp
    #grid.cpp
    listener.cpp
    command.cpp
    bridge.cpp
    busStop.cpp
    palindromic.cpp
    luckyList.cpp
    honeyComb.cpp
    parenthese.cpp
    marbles.cpp
    firstOrder.cpp
    rightView.cpp
    prim.cpp
    cairoDemo.cpp
    cryptographic.cpp
    cairo_pattern_transform.cpp
    BstIterator.cpp
    cryptoGraphics2.cpp
    reverseList.cpp
    reverseBetween.cpp
    #cryptoGraphicsExt.cpp
    mergeSortedArray.cpp
    wordBreak.cpp
    string.cpp
    cairo-generate.cpp
    juice.cpp
    StrTest.cpp
    cairo_roundRectangle.cpp
    )


INCLUDE_DIRECTORIES(/usr/include/cairo)  

ADD_DEFINITIONS("-DDEBUG")

FOREACH(SRC ${SRCS})
    get_filename_component(TARGET_NAME ${SRC} NAME_WE)
    ADD_EXECUTABLE(${TARGET_NAME} ${SRC})
    TARGET_LINK_LIBRARIES(${TARGET_NAME}  -lglut -lGL -lGLU -lGLEW -lpthread 
    -lcairo -lX11)
ENDFOREACH(SRC)


MESSAGE(${PROJECT_SOURCE_DIR})
SET(APP_SRCS callPlugin.cpp)
SET(LIB_SRCS student.cpp)
ADD_LIBRARY(libstudent SHARED ${LIB_SRCS})
ADD_EXECUTABLE(callPlugin ${APP_SRCS})

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fvisibility=hidden -std=c++11 -g")

TARGET_LINK_LIBRARIES(callPlugin libstudent -ldl)

