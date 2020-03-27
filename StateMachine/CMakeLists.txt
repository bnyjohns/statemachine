file(GLOB HEADERS Sources/*.h Include/*.h)
file(GLOB SOURCES Sources/*.cpp)
file(GLOB RESOURCES *.png)

add_executable(StateMachine ${HEADERS} ${SOURCES} ${RESOURCES})
target_include_directories(StateMachine PUBLIC include)