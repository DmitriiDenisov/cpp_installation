# Get the base Ubuntu image from Docker Hub
FROM ubuntu:18.04

# Update apps on the base image
RUN apt update -y

RUN apt install build-essential -y
RUN apt-get install manpages-dev -y


# Copy the current folder which contains C++ source code to the Docker image under /usr/src
COPY . /usr/src/dockertest1

# Specify the working directory
WORKDIR /usr/src/dockertest1

ENV TZ=Europe/Kiev
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone
RUN apt install libboost-all-dev libssl-dev -y
# RUN apt-get install -y libboost1.65-dev:amd64
# RUN apt-get install -y libssl-dev

# Use Clang to compile the Test.cpp source file
# RUN clang++ -o Test Test.cpp
RUN g++ Test.cpp -lboost_system -pthread
# RUN g++ -O3 -std=c++11 -lboost_thread -lboost_system -pthread -o Test Test.cpp

# Run the output program from the previous step
CMD ["./a.out"]
