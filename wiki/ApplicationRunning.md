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
<img width="734" alt="ScreenshotRunBloomfilter" src="https://github.com/reutlazarr/AspProject/assets/155451112/4eceb507-b2d7-45fa-8eb6-6d7579faad7d">


### BloomFilter With Doker
For those preferring Docker, you can pull the BloomFilter container from DockerHub. Ensure you have Docker installed and use the following command to pull the container.
Whenever we release a new version of the code, the Docker image is automatically updated on DockerHub. You can download and run the Docker image, which will set up a BloomFilter server. Below are screenshots to guide you:

![Screenshot 2024-04-30 213656](https://github.com/reutlazarr/AspProject/assets/132810027/0f90e9e5-1c63-4d19-bbf9-78c5dd9f26e4)

![Screenshot 2024-04-30 222026](https://github.com/reutlazarr/AspProject/assets/132810027/f74e7f63-b50d-4fe5-a254-50bda4d0fef3)

![Screenshot 2024-04-30 222047](https://github.com/reutlazarr/AspProject/assets/132810027/2fec4241-0101-47f2-9187-17426aa7e56b)

![Screenshot 2024-04-30 232320](https://github.com/reutlazarr/AspProject/assets/132810027/84fde50b-1359-45ca-8565-e304767b23d2)

![Screenshot 2024-04-30 232333](https://github.com/reutlazarr/AspProject/assets/132810027/332e96bf-2a57-4c34-b9ed-b1af8e2760da)

### Running Node Server
Start the FacebookServer by ensuring you are in the server directory and then executing the start command:
```bash
cd FacebookServer  # Make sure to be in the correct directory
npm start
```
<img width="775" alt="ScreenshotRunServer" src="https://github.com/reutlazarr/AspProject/assets/155451112/1862556a-feb2-44ea-b01e-80543b00eec7">


## Running the client Applications
After the applications of the server is running, you can run the applications of the client.

### Running FacebookWeb
To start the FacebookWeb client, ensure you are in the server directory and then execute the start command:
```bash
cd FacebookWeb  # Make sure to be in the correct directory
npm start
```
<img width="639" alt="ScreenshotRunWeb" src="https://github.com/reutlazarr/AspProject/assets/155451112/03b0c5a0-187b-4f74-af15-fe6f236562cd">


### Running FacebookApp
Ensure your Android emulator is set up and configured. Open Android Studio, navigate to the FacebookApp project, and run the application using the emulator.
<br>
<img width="755" alt="ScreenshotRunApp" src="https://github.com/reutlazarr/AspProject/assets/155451112/dfbb7bd0-fe6f-428a-b7db-f9b88918f3b8">


## Additional Notes
- Ensure all server dependencies and client dependencies are installed and up to date before running the applications.
- Verify network settings and database connections are configured correctly, particularly for MongoDB at mongodb://localhost:27017.
