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

## BloomFilter Compilation
Navigate to the AspProject directory which containing the BloomFilter project and set up the build environment with these commands:

```bash
cd AspProject
cmake -B build -S .
cmake --build build
```

## Installation Steps for Node.js Applications
Before running the FacebookServer, install all required Node.js dependencies by navigating to the project directory and running:

```bash
cd FacebookServer
npm install
```

# Running the Applications
How to start and interact with the BloomFilter and FacebookServer applications.

## Running BloomFilter
Execute the BloomFilter application by navigating to the build directory and running the executable:
```bash
./bloomFilte
```

## Running Node Server
Start the FacebookServer by ensuring you are in the server directory and then executing the start command:
```bash
cd FacebookServer  # Make sure to be in the correct directory
npm start
```

## Additional Notes
- Ensure that MongoDB is running at mongodb://localhost:27017 before starting the FacebookServer.
- Verify that all paths and directory names are correct as per your project's directory structure.
- Make sure that the correct branches are used for cloning, especially for projects with multiple branches.
