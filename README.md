# AspProject
Date of submission: 30/4/24

Welcome to the exciting journey of developing the AspProject, a comprehensive suite designed to integrate advanced data filtering with the BloomFilter and robust client-server architecture using Node.js, aimed at enhancing Facebook interfacing capabilities.

## Introduction

This project is designed to demonstrate sophisticated data handling and user interaction capabilities. It has been structured into four key development phases:

1. **BloomFilter Development**: We developed a core component for efficient data management that serves as the backbone of our TCP server.
2. **Client Environment Setup**: Our team established accessible client interfaces, optimized for both web and mobile platforms.
3. **Server Environment Development**: A Node.js-based server environment was constructed to ensure seamless communication between the BloomFilter component and the client interfaces.
4. **Integration**: All components were meticulously integrated to function coherently, providing a seamless user experience across various platforms.

## Documentation

Comprehensive documentation detailing the setup, compilation, and operational instructions for the AspProject is housed within the `wiki` directory of this repository. These documents provide step-by-step guidance to help you effectively set up and utilize the applications:
- [Home](./wiki/Home.md) - Provides an overview and links to more detailed documentation.
- [Setup Instructions](./wiki/EnvironmentSetup.md) - Details the prerequisites and initial setup procedures.
- [Running the Applications](./wiki/ApplicationRunning.md) - - Explains how to start and manage the server and client applications.
- [User Guides](./wiki/) - Includes specific guides for using the web and Android applications:
  - [Web User Guide](./wiki/WebUserGuide.md) - Guidelines for the web application.
  - [Android App User Guide](./wiki/AppUserGuide.md) -  Guidelines for the Android application.

## Quick Start

### Setup Environment
Before proceeding, ensure you have the necessary tools and dependencies installed:

- Git
- C++ Compiler (for compiling BloomFilter)
- Node.js and npm (for running FacebookServer)
- MongoDB
- Android Studio (only for running the FacebookApp client)

### Clone the Project
Clone the main project repository and switch to the appropriate branch:
```bash
git clone --branch main_tcp https://github.com/reutlazarr/AspProject.git
cd AspProject
```
### Compile and Run BloomFilter
Navigate to the BloomFilter directory and compile it:
```bash
# If using CMake:
cmake -B build -S .
cmake --build build
# Run BloomFilter
./build/bloomFilter
```
Or compile directly with g++:
```bash
g++ -o bloomFilter -Iheaders src/main.cpp src/app.cpp src/bloomFilterManager.cpp src/menu.cpp src/hashFunction1.cpp src/hashFunction2.cpp src/addUrl.cpp src/isBlackList.cpp src/bloomFilter.cpp src/realBlackList.cpp src/checkInput.cpp -std=c++14 -pthread
./bloomFilter
```

### Additional Components
For setting up and running the FacebookServer and client applications, please clone and follow the instructions in their respective repositories:
```bash
# Clone and setup FacebookServer
git clone --branch main_server_tcp https://github.com/BarVinizky/FacebookServer.git
cd FacebookServer
npm install
npm start

# Setup web and Android clients
git clone --branch targil4 https://github.com/reutlazarr/FacebookWeb.git
git clone --branch targil4 https://github.com/BarVinizky/FacebookApp.git
```
### Additional Notes
- Ensure MongoDB is running at mongodb://localhost:27017 before starting the FacebookServer.
- Verify all paths and directory names are correct, and ensure that the correct branches are used for cloning, especially for projects with multiple branches.

For complete configuration and detailed setup instructions for all parts of the project, please refer to the [Project Wiki](./wiki/).
