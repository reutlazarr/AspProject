# AspProject

Welcome to the exciting journey of developing BloomFilter!

Here's how we approached the project:
Initially, we analyzed the project requirements and organized tasks in JIRA, categorizing them into three epics based on the instruction's key steps.
Our first move was to ensure a smooth setup of our working environment.
During the development phase, Reut was in charge of crafting our workflow and Dockerfile, while Bar engaged in coding through the Test-Driven Development (TDD) approach.
The development process unfolded as follows:

We commenced by drafting tests for the bloomFilter, followed by constructing the class and its essential methods like addUrl and IsBlackList. We developed a HashFunction and verified the seamless integration of all components.
Next, we refined the HashFunction, introduced an alternative HashFunction and their interface, adhering to the TDD principle of testing first, then coding.
Subsequently, we developed supporting classes for our application, such as menu. We refined the bloomFilter class and restructured addUrl and IsBlackList methods to inherit from the ICommand interface.
We then crafted the bloomFilterManager, which initializes the bloomFilter based on user inputs. We also added realBlackList and improved the command structure. Finally, we developed the app class to execute user commands.
To conclude, we refined our tests and code, ensuring compatibility and functionality with Docker, as orchestrated by the YAML files.
To integrate changes into the main branch, simply create a pull request.

**Important Notice:**
We accidentally uploaded the build directory to the main branch. Pulling this file may cause some problems. We have tried to contact you via email because we are uncertain about editing after submission. To ensure the app runs smoothly on your machine, please follow these steps after cloning the project:

After cloning the repository, immediately remove the build directory to prevent it from interfering with your setup:
```
rm -rf build/
```
create the configuration instructions needed to generate the build files, and then compile the source code according to the build configuration:
```
cmake -B build -S .
cmake --build build
```

for running our tests:
```
ctest --test-dir build --output-on-failure
```
if necessary make sure you in the build directory before:
```
cd build
ctest --test-dir build --output-on-failure
```

If you're keen to run our code with your input, here’s the command line:
```
g++ -o bloomFilter -Iheaders src/main.cpp src/app.cpp src/bloomFilterManager.cpp src/menu.cpp src/hashFunction1.cpp src/hashFunction2.cpp src/addUrl.cpp src/isBlackList.cpp src/bloomFilter.cpp src/realBlackList.cpp src/checkInput.cpp -std=c++14 -pthread

./bloomFilter
```
and then you can write your input
 
