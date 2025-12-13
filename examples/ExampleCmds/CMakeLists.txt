
add_executable(ExampleCmds main.cpp
        include/adapter-header.h        # user/prop-cp customization point
        include/FooPropertyHandler.h
        include/BarPropertyHandler.h
        include/SomeOtherPropertyHandler.h
        include/MyConfig.h
        include/CommandWithDispatch.h
        include/Command.h
        )
target_include_directories(ExampleCmds PRIVATE include)
target_link_libraries(ExampleCmds PRIVATE PropCP)
