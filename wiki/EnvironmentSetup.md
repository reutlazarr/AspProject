# Environment Setup

## Prerequisites
List all software, tools, and dependencies required.

## Installation Steps
Provide detailed steps for installing necessary software and tools.

Before you can run our applications, there are some environment setup steps you need to follow. This guide covers all the necessary tools and dependencies you'll need.

## Cloning Repositories
```bash
git clone URL_OF_REPOSITORY
git clone https://github.com/BarVinizky/FacebookServer.git
git clone --branch main_server https://github.com/reutlazarr/FacebookWeb.git
git clone --branch main_server https://github.com/BarVinizky/FacebookApp.git






# Environment Setup
Here we detail the steps to prepare your environment to run both the BloomFilter and FacebookServer applications.

## Requirements
- Git
- C++ Compiler
- Node.js
- MongoDB
- Android Studio (for FacebookApp)

## Setup Steps
Clone the necessary repositories to get started with our applications:
```bash
git clone https://github.com/BarVinizky/FacebookServer.git
git clone --branch main_server https://github.com/reutlazarr/FacebookWeb.git
git clone --branch main_server https://github.com/BarVinizky/FacebookApp.git
```

Install dependencies:
```bash
cd FacebookServer
npm install
```


# Compilation Instructions
Follow these steps to compile the BloomFilter application and prepare the FacebookServer.

## BloomFilter Compilation
Navigate to the BloomFilter directory and run:
```bash
cmake -B build -S .
cmake --build build
```


# Running the Applications
How to start and interact with the BloomFilter and FacebookServer applications.

## Running BloomFilter
```bash
./bloomFilter

Start the MongoDB server, then: