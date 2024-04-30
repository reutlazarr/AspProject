# Environment Setup

## Prerequisites
List all software, tools, and dependencies required.

## Requirements
Before you start, ensure you have the following tools and dependencies installed:
- Git
- C++ Compiler (for compiling BloomFilter)
- Node.js and npm (for running FacebookServer)
- MongoDB
- Android Studio (only for running the FacebookApp client)

## Clone the Repositories
To get started, clone the necessary repositories:

```bash
git clone https://github.com/BarVinizky/FacebookServer.git
git clone --branch main_server https://github.com/reutlazarr/FacebookWeb.git
git clone --branch main_server https://github.com/BarVinizky/FacebookApp.git
```

# Compilation Instructions
Follow these steps to compile the BloomFilter application.
For usingthe BloomFilter you can use eathr dokerhub or the next instructions.

## BloomFilter Compilation
Navigate to the AspProject directory which containing the BloomFilter project and set up the build environment with these commands:

```bash
cd AspProject
cmake -B build -S .
cmake --build build
```

```bash
g++ -o bloomFilter -Iheaders src/main.cpp src/app.cpp src/bloomFilterManager.cpp src/menu.cpp src/hashFunction1.cpp src/hashFunction2.cpp src/addUrl.cpp src/isBlackList.cpp src/bloomFilter.cpp src/realBlackList.cpp src/checkInput.cpp -std=c++14 -pthread
```

## BloomFilter with doker


# Installation Steps for Client Applications
Follow these steps to install all required dependencies for the client application.

## Installation Steps for Node.js Applications
Before running the FacebookServer, install all required Node.js dependencies by navigating to the project directory containing the `package.json` file and running:

```bash
cd FacebookServer
npm install
```

## Installation Steps for FacebookWeb Applications
Before running the FacebookWeb, install all required dependencies by navigating to the project directory containing the `package.json` file and running:

```bash
cd FacebookWeb
npm install
```

## Installation Steps for FacebookApp Applications
Before running the FacebookApp, make sure you have emulatur in your Android Studio.



## Additional Notes
- Ensure that MongoDB is running at mongodb://localhost:27017 before starting the FacebookServer.



- Verify that all paths and directory names are correct as per your project's directory structure.
- Make sure that the correct branches are used for cloning, especially for projects with multiple branches.
