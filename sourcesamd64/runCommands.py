# Get list of all directories in the current directory
# and run the command in each directory
# Usage: python runCommands.py <command>

import os
from multiprocessing import Pool

# list of commands to run
commands = [
    f'''rm -rf build && mkdir build && cd build && cmake -DCMAKE_INSTALL_PREFIX=/Volumes/Lake/Projects/scratchpad/udaan-exp/deps/macos/x86_64 -DCMAKE_OSX_ARCHITECTURES='x86_64' -DCMAKE_OSX_DEPLOYMENT_TARGET=11.0 -DCMAKE_BUILD_TYPE=Release .. && cmake --build . --clean-first --parallel && cmake --install . && cd ..''',]

def run_command(dir):
    if os.path.isdir(dir):
        os.chdir(dir)
        # if the file CMakeLists.txt is not present in the directory
        # then skip the directory
        print(os.getcwd())
        # save log to a file
        os.system(commands[0] + ' > ' + dir + '.log')

if __name__ == '__main__':

    # Get the list of directories
    dirs = os.listdir(os.getcwd())
    # print(dirs)

    # Create a pool of worker processes
    pool = Pool()

    # Run the command in each directory in parallel
    pool.map(run_command, dirs)

    # Close the pool to prevent any more tasks from being submitted
    pool.close()

    # Wait for all the worker processes to finish
    pool.join()