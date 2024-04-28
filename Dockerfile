# Use the official GCC image as the base image
FROM gcc:latest

# Set the working directory inside the container
WORKDIR /app

# Copy the source code and headers into the container
COPY src /app/src
COPY headers /app/headers

# Compile the C++ code using g++
RUN g++ -o bloomFilter -I/app/headers /app/src/main.cpp /app/src/app.cpp /app/src/bloomFilterManager.cpp /app/src/menu.cpp /app/src/hashFunction1.cpp /app/src/hashFunction2.cpp /app/src/addUrl.cpp /app/src/isBlackList.cpp /app/src/bloomFilter.cpp /app/src/realBlackList.cpp /app/src/checkInput.cpp -std=c++14 -pthread

# Specify the command to run the executable when the container starts
CMD ["./bloomFilter"]
