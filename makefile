CC=g++
CFLAGS=-Wall -Werror -ansi -pedantic

all: binFile
	$(CC) src/main.cc src/CommandBase.cc src/CommandComment.cc src/CommandContainer.cc src/CommandLine.cc src/CommandObject.cc src/Tokenizer.cc src/CommandFactory.cc src/CommandQuit.cc src/CommandTest.cc src/AndCommand.cc src/OrCommand.cc src/ErrorCommand.cc $(CFLAGS) -o bin/rshell
rshell: binFile
	$(CC) src/main.cc src/CommandBase.cc src/CommandComment.cc src/CommandContainer.cc src/CommandLine.cc src/CommandObject.cc src/Tokenizer.cc src/CommandFactory.cc src/CommandQuit.cc src/CommandTest.cc src/AndCommand.cc src/OrCommand.cc src/ErrorCommand.cc $(CFLAGS) -o bin/rshell
binFile:
	-mkdir -p bin
