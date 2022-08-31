# load user source and header files
file(GLOB_RECURSE SOURCE_FILES "*.h" "*.cpp")

add_library(TinyTmx2_6_2
            STATIC 
            ${SOURCE_FILES})

# Configure the directories to search for header files.
target_include_directories(MyUtils PUBLIC "${CMAKE_CURRENT_LIST_DIR}")