# Use the official GCC image as the base image
FROM gcc:latest

# Set the working directory inside the container
WORKDIR /app

# Copy the source code into the container
COPY src /app

# Compile the C++ code using g++
RUN g++ -o main main.cpp

# Specify the command to run the executable when the container starts
CMD ["./main"]
