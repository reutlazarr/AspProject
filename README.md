# AspProject

/////////////// need to explain how to compile and run the code!!


Our work process:
First we read the exercise and started to divide tasks in JIRA. we divided them into three epics, according to the three steps in the instructions.
we did step 1 and checked that our work environment is ready and working.
then while reut created our workflow and dockerfile, bar started to write our code.
1. we started in creating bloomFilter with the methods addUrl and IsBlackList. we created HashFunctoin and checked it all works.
2. we refactored HashFunction, created another different HashFunction and their interface.
3. we wrote the classes that support are app like menu and initialize. we refactored bloomFilter and transferred addUrl and IsBlackList to derived from command interface.
4. we wrote bloomFilterManager that creat the bloomFilter according to the user input, we add realBlackList and refactored command. then we wrote app that execute the users command.
at the end we refactor are tests and are code in accordance. and checked it all works with the docker.
