# Project Setup Documentation

Welcome to the setup guide for the BloomFilter and FacebookServer applications. This document provides detailed instructions for setting up your environment, compiling the applications, and running them successfully.

## Environment Setup

### Prerequisites
Ensure you have the following tools and dependencies installed before you start:
- Git
- C++ Compiler (for compiling BloomFilter)
- Node.js and npm (for running FacebookServer)
- MongoDB
- Android Studio (only for running the FacebookApp client)

### Clone the Repositories
To get started, clone the necessary repositories using the specified branches:

```bash
git clone --branch main_server_tcp https://github.com/BarVinizky/FacebookServer.git
git clone --branch targil4 https://github.com/reutlazarr/FacebookWeb.git
git clone --branch targil4 https://github.com/BarVinizky/FacebookApp.git
```

## Compilation And Installation Instructions

### BloomFilter Compilation
Navigate to the AspProject directory containing the BloomFilter project and set up the build environment:

```bash
cd AspProject
cmake -B build -S .
cmake --build build
```
Alternatively, compile directly with g++ if not using CMake:

```bash
g++ -o bloomFilter -Iheaders src/main.cpp src/app.cpp src/bloomFilterManager.cpp src/menu.cpp src/hashFunction1.cpp src/hashFunction2.cpp src/addUrl.cpp src/isBlackList.cpp src/bloomFilter.cpp src/realBlackList.cpp src/checkInput.cpp -std=c++14 -pthread
```

### BloomFilter With Doker
For those preferring Docker, you can pull the BloomFilter container from DockerHub. Ensure you have Docker installed and use the following command to pull the container:
In order to build the docker, please make sure you are in the project directory, and run:
```bash
docker build -t bloom filter .
```
(Don't forget to add the dot in the end).

### Installation Steps for Node.js Applications
Install all required Node.js dependencies for the FacebookServer by navigating to the project directory containing the `package.json` file and running:

```bash
cd FacebookServer
npm install
```


## Installation Steps for Client Applications

### Installation Steps for FacebookWeb Applications
Install all required dependencies for the FacebookWeb application by navigating to the project directory containing the `package.json` file and running:

```bash
cd FacebookWeb
npm install
```

### Installation Steps for FacebookApp Applications
Ensure you have an emulator set up in Android Studio before running the FacebookApp.



## Additional Notes
- Ensure that MongoDB is running at mongodb://localhost:27017 before starting the FacebookServer.



- Verify that all paths and directory names are correct as per your project's directory structure.
- Make sure that the correct branches are used for cloning, especially for projects with multiple branches.
