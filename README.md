# C++ installation

### (MacOS) Install cmake (local machine):
Download CLion and cmake will be installed simultaneously with CLion

### (Ubuntu) Install cmake
1. Uninstall the default version provided by Ubuntu's package manager and configuration by using:
```sudo apt remove --purge --auto-remove cmake```
2. Go to the official CMake webpage (http://www.cmake.org/download), then download and extract the latest version. Update the version and build variables in the following command to get the desired version:
```version=3.15
build=4
mkdir ~/temp
cd ~/temp
wget https://cmake.org/files/v$version/cmake-$version.$build.tar.gz
tar -xzvf cmake-$version.$build.tar.gz
cd cmake-$version.$build/
```
3. Install the extracted source by running:
```./bootstrap
make -j$(nproc)
sudo make install
```
4. Test your new cmake version:
```cmake --version```
5. Usually paths make/c/c++:
make: ```/usr/bin/make```
C Compiler: ```/usr/bin/cc```
C++ Compiler: ```/usr/bin/c++```


Source: https://askubuntu.com/questions/355565/how-do-i-install-the-latest-version-of-cmake-from-the-command-line

### Add remote host in CLion:
1. Go to Settings / Preferences | Build, Execution, Deployment | Toolchains and click **plus icon** to create a new toolchain

2. Select Remote Host from the drop-down menu and click icons actions menu in the Credentials field. In the dialog that opens, provide the credentials for accessing you remote machine:
<img src="https://www.jetbrains.com/help/img/idea/2019.2/cl_remote_toolchaincredentials.png" width="500"/>

3. After establishing the connection, CLion attempts to detect the tools in default remote locations /usr/bin/cmake and /usr/bin/gdb (or using the full paths, if you have provided manually). When the checks finish successfully, the toolchain is ready for use:
<img src="https://www.jetbrains.com/help/img/idea/2019.2/cl_remote_toolchainsuccess.png" width="500"/>

4.(optional) You can make the newly created toolchain the default one (for this, move it to the top of the toolchains list by clicking move upmove down). When set as default, the remote toolchain is used for all the projects you create and open in CLion.

5. Go to Settings / Preferences | Build, Execution, Deployment | CMake, click **plus icon** to create a new CMake profile, and connect it to your remote toolchain using the Toolchain field:
<img src="https://www.jetbrains.com/help/img/idea/2019.2/cl_remote_cmakeprofile.png" width="500"/>

6. Check and adjust the deployment configuration (i.e remote host window)

7. Once you've done you will be able to choose local/remote here:
<img src="https://picua.org/images/2019/10/09/d669d34e3f62bdb7d4e82f9672e07821.png" width="500"/>


Source: https://www.jetbrains.com/help/clion/remote-projects-support.html

Source (video): https://youtu.be/g1zPcja3zAU?t=658

### Check if CLion is working with remote host:

file ```main.cpp``` prints out host name and local IP, example of print:
```
Hostname: instance-3
Host IP: 10.128.0.2
```

### (Ubuntu) Install C++ environment
1. `sudo apt update`
2. `sudo apt install build-essential`
3. `sudo apt-get install manpages-dev`
4. `gcc --version`
5. `mkdir cpp_ex`
6. `cd cpp_ex`
7. `vim hello.cpp` (take `base_ex/hello.cpp` from this repo)
8. `sudo g++ hello.cpp`
9. `./a.out`

### (Ubuntu) Install Crow library (flask analog)
Source: https://github.com/ipkn/crow
Source: https://github.com/ipkn/crow/wiki/Installation
1. Download and include file: https://github.com/ipkn/crow/releases/download/v0.1/crow_all.h (or take it from this repo `crow.h`)
2. If you try to run `sudo g++ hello_crow.cpp` (take it from this repo `base_ex/hello_crow.cpp`) you will see "fatal error: boost/optional.hpp: No such file or directory" => need to install dependecies
3. `sudo apt install libboost-all-dev libssl-dev`
4. `sudo g++ crw_server.cpp -lboost_system -pthread` or if it does not run then `g++ -O3 -std=c++11 server.cpp -lboost_thread -lboost_system -pthread`
5. `./a.out`
6. `curl -X GET http://localhost:18080/hi`

Source: https://medium.com/@raghavrastogi594/get-set-go-with-crow-a-micro-web-framework-for-web-in-c-570f99091983

### (Ubuntu) Advanced Crow Library
In order to do more advanced example and pass some parameters inside (list/double/int/string) and to return full json:
1. `cd advanced_crow` (take it from this repo)
2. `sudo g++ crw_server.cpp -lboost_system -pthread`
3. `./a.out`
4. Example to pass inside string/int/double/list parameters: `curl -X GET "http://localhost:18080/ex_json?foo='blabla'&pew=32&count[]=a&count[]=b&double_param=2.31"`
5. Just another example: `curl -X GET "http://localhost:18080/ex_json_arr"`

Source and more examples: https://github.com/ART-Robot-Release/arobot/blob/1a9a1ea31ea6ccbc206b0b38737588894611f16c/src/robot_control/core/database/src/crow_server.cpp

### (Ubuntu) Run Docker service with C++

Install Docker: https://docs.docker.com/engine/install/ubuntu/

1. Clone this repo and go to `helloworld_docker` folder
2. `sudo docker build --rm -f Dockerfile -t dockerhello:latest .`
3. `sudo docker run --rm -it dockerhello:latest`

Source: https://devblogs.microsoft.com/cppblog/c-development-with-docker-containers-in-visual-studio-code/

### (Ubuntu) Docker + Crow (flask analog)

1. Clone this repo and go to `crow_docker` fodler
2. `sudo docker build --rm -f Dockerfile -t crowdocker:latest .`
3. `sudo docker run -p 300:18080 --rm -it crowdocker:latest` (match port 300 to 18080)
4. `curl -X GET http://localhost:300/hi`
