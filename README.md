# AspProject

By make pull request into main() the code will run.
if you want to run our code,
this is the command line:
 g++ -o bloomFilter -Iheaders src/main.cpp src/app.cpp src/bloomFilterManager.cpp src/menu.cpp src/hashFunction1.cpp src/hashFunction2.cpp src/addUrl.cpp src/isBlackList.cpp src/bloomFilter.cpp src/realBlackList.cpp src/checkInput.cpp -std=c++14
 
Our work process:
First we read the exercise and started to divide tasks in JIRA. we divided them into three epics, according to the three steps in the instructions.
We did step 1 and checked that our work environment was ready for working.
Then while Reut created our workflow and dockerfile, Bar started to write our code by TDD method.
1. We started in creating bloomFilter test and then the class itself, with the relevant methods as addUrl and IsBlackList. we created HashFunctoin and checked it all works.
2. We refactored HashFunction, created another different HashFunction and their interface, all by TDD, first the test and then the code itself.
3. We wrote the classes that support are app like menu and initialize. we refactored bloomFilter and transferred addUrl and IsBlackList to derived from command interface.
4. We wrote bloomFilterManager that creat the bloomFilter according to the user input, we add realBlackList and refactored command. then we wrote app that execute the users command.
At the end we refactor are tests and are code in accordance. and checked it all works with the docker.
