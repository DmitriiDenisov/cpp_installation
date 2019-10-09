# CLion

### Install cmake (local machine):
Download CLion and cmake will be installed simultaneously with CLion

### Install cmake (on remote machine):
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

### Add remote host:
1. Go to Settings / Preferences | Build, Execution, Deployment | Toolchains and click **plus icon** to create a new toolchain
2. Select Remote Host from the drop-down menu and click icons actions menu in the Credentials field. In the dialog that opens, provide the credentials for accessing you remote machine:
![alt text](https://www.jetbrains.com/help/img/idea/2019.2/cl_remote_toolchaincredentials.png)
3. After establishing the connection, CLion attempts to detect the tools in default remote locations /usr/bin/cmake and /usr/bin/gdb (or using the full paths, if you have provided manually). When the checks finish successfully, the toolchain is ready for use:
![alt text](https://www.jetbrains.com/help/img/idea/2019.2/cl_remote_toolchainsuccess.png)
4(optional). You can make the newly created toolchain the default one (for this, move it to the top of the toolchains list by clicking move upmove down). When set as default, the remote toolchain is used for all the projects you create and open in CLion.
5. Go to Settings / Preferences | Build, Execution, Deployment | CMake, click **plus icon** to create a new CMake profile, and connect it to your remote toolchain using the Toolchain field:
![alt text](https://www.jetbrains.com/help/img/idea/2019.2/cl_remote_cmakeprofile.png)
6. Check and adjust the deployment configuration (i.e remote host window)
7. Once you've done you will be able to choose local/remote here:
![alt text](https://drop3.dropmefiles.com/preview/a0H2O/453204774)

Source: https://www.jetbrains.com/help/clion/remote-projects-support.html
Source (video): https://youtu.be/g1zPcja3zAU?t=658

### Check if all is working:

file ```main.cpp``` prints out host name and local IP, example of print:
```
Hostname: instance-3
Host IP: 10.128.0.2
```
