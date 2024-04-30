# Project Wiki

Welcome to the Project Wiki! This documentation covers everything you need to set up, run, and use the applications involved in our project.

## Table of Contents
- [Environment Setup](EnvironmentSetup.md)
- [Running the Applications](ApplicationRunning.md)
- [User Guide for using the web](WebUserGuide.md)
- [User Guide for using the android app](AppUserGuide.md)
- [Troubleshooting](Troubleshooting.md)





# Environment Setup
Here we detail the steps to prepare your environment to run both the BloomFilter and FacebookServer applications.

## Requirements
- Git
- C++ Compiler
- Node.js
- MongoDB
- Android Studio (for FacebookApp)

## Setup Steps
Clone the repositories:
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



# User Guide
Instructions for logging in, registering, and managing posts in the FacebookServer applications.

## Login and Registration
Detailed steps for users to register and log in through the web and app clients.

## Creating, Editing, and Deleting Posts
How to create, edit, and delete posts on the web and app platforms.



# Troubleshooting
Common issues encountered during the setup or use of our applications and how to resolve them.

## Issue: Dependency errors in Node.js
Ensure that you have run `npm install` as detailed in the Environment Setup.