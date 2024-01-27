# Use the official GCC image as the base image
FROM gcc:latest

# Set the working directory inside the container
WORKDIR /app

# Copy the source code and headers into the container
COPY src /app/src
COPY headers /app/headers

# Compile the C++ code using g++
RUN g++ -o bloomFilter -Iheaders src/main.cpp src/app.cpp src/bloomFilterManager.cpp src/menu.cpp src/hashFunction1.cpp src/hashFunction2.cpp src/addUrl.cpp src/isBlackList.cpp src/bloomFilter.cpp src/realBlackList.cpp src/checkInput.cpp -std=c++14

# Specify the command to run the executable when the container starts
CMD ["./bloomFilter"]
