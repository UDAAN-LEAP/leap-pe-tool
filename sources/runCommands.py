# Get list of all directories in the current directory
# and run the command in each directory
# Usage: python runCommands.py <command>

import os

# list of commands to run
commands = [
    'rm -rf build && mkdir build && cd build && cmake -DCMAKE_INSTALL_PREFIX=/Volumes/Lake/Projects/scratchpad/udaan-exp/deps/macos/arm64 -DCMAKE_OSX_DEPLOYMENT_TARGET=11.0 .. && cmake --build . --clean-first --parallel && cmake --install .',
]

# Get the list of directories
dirs = os.listdir(os.getcwd())
# print (dirs)

# Run the command in each directory
for dir in dirs:
    if os.path.isdir(dir):
        os.chdir(dir)
        # if the file CMakeLists.txt is not present in the directory
        # then skip the directory
        print (os.getcwd())
        # save log to a file
        os.system(commands[0] + ' > ' + dir + '.log')