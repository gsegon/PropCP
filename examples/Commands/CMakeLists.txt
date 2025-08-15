
add_executable(CommandsExample main.cpp
        include/adapter-header.h
        include/FooPropertyHandler.h
        include/BarPropertyHandler.h
        include/MyConfig.h
        include/CommandWithDispatch.h
        include/SomeOtherPropertyHandler.h)
target_include_directories(CommandsExample PRIVATE include)
target_link_libraries(CommandsExample PRIVATE PropCP)