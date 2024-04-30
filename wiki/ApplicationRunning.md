# Running the Applications

This guide provides instructions on how to start and interact with each part of the application, including both server-side and client-side components.

## Running Server Applications
First run the applications of the server.

### Running BloomFilter
Navigate to the directory containing the BloomFilter executable and run the application:

```bash
cd AspProject  # Make sure to be in the correct directory
./bloomFilter
```

### Running BloomFilter with the doker
To run BloomFilter using Docker, execute the following command. Ensure your Docker environment is set up and the BloomFilter image is available:


### Running Node Server
Before starting the FacebookServer, ensure MongoDB is running at mongodb://localhost:27017:
```bash
mongo --eval "db.runCommand({ connectionStatus: 1 })"
```

Start the FacebookServer by ensuring you are in the server directory and then executing the start command:
```bash
cd FacebookServer  # Make sure to be in the correct directory
npm start
```

## Running the client Applications
After the applications of the server is running, you can run the applications of the client.

### Running FacebookWeb
To start the FacebookWeb client, ensure you are in the server directory and then execute the start command:
```bash
cd FacebookWeb  # Make sure to be in the correct directory
npm start
```

### Running FacebookApp
Ensure your Android emulator is set up and configured. Open Android Studio, navigate to the FacebookApp project, and run the application using the emulator.


## Additional Notes
- Ensure all server dependencies and client dependencies are installed and up to date before running the applications.
- Verify network settings and database connections are configured correctly, particularly for MongoDB at mongodb://localhost:27017.