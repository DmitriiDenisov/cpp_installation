# We will use multistage building, because in the final Docker cont we need only binary file + headers
# ----------------STAGE 1---------------
# Get the base Ubuntu image from Docker Hub
FROM ubuntu:18.04 as build
LABEL stage=builder

# Set timezone for installation of Boost library
ENV DEBIAN_FRONTEND=noninteractive

# Update apps on the base image + install dependencies for Crow
RUN apt update -y &&  apt install build-essential -y && apt install libboost-all-dev libssl-dev -y

# Copy the current folder which contains C++ source code to the Docker image under /usr/src
COPY . /usr/src/dockertest1

# Specify the working directory
WORKDIR /usr/src/dockertest1

# Compile binary file:
RUN g++ Test.cpp -lboost_system -pthread
# RUN g++ -O3 -std=c++11 -lboost_thread -lboost_system -pthread -o Test Test.cpp

# ----------------STAGE 2---------------
FROM ubuntu:18.04 as production
COPY --from=build /usr/src/dockertest1 .

RUN apt-get update && apt-get install -y libboost-system1.65.1 && rm -rf /var/lib/apt/lists/*

CMD ["./a.out"]

