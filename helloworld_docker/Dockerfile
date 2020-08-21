# Get the GCC preinstalled image from Docker Hub
FROM gcc:4.9 as build

# Copy the current folder which contains C++ source code to the Docker image under /usr/src
COPY . /usr/src/dockertest1

# Specify the working directory
WORKDIR /usr/src/dockertest1

# Use GCC to compile the Test.cpp source file
RUN g++ -static Test.cpp

# Stage 2 (in order jsut to copy binary to new Image)
# FROM ubuntu:18.04 as production
FROM alpine
COPY --from=build /usr/src/dockertest1 .
#RUN apk add build-base

# Run the program output from the previous step
CMD ["./a.out"]
