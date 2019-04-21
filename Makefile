EXECS = testAnimator
OBJS = testAnimator.o Animator.o VehicleBase.o

CC = g++
CCFLAGS = -std=c++11

all: $(EXECS)

testAnimator: $(OBJS)
	$(CC) $(CCFLAGS) $^ -o $@

%.o: %.cpp *.h
	$(CC) $(CCFLAGS) -c $<

%.o: %.cpp
	$(CC) $(CCFLAGS) -c $<

clean
	/bin/rm -f a.out $(OBJS) $(EXECS)

DEBUG_FLAG= -DDEBUG -g -Wall
CFLAGS=-DDEBUG -g -Wall

.SUFFIXES: .cpp .o

.cpp.o:
	g++ $(CFLAGS) -c $<


testSimulation: testSimulation 
	g++ -o testSimulation

#MachLangParser.o: MachLangParser.h Instruction.h

#Instruction.o: OpcodeTable.h RegisterTable.h Instruction.h 

#OpcodeTable.o: OpcodeTable.cpp OpcodeTable.h

#RegisterTable.o: RegisterTable.cpp RegisterTable.h  

clean:
	/bin/rm -f testSimulation *.o core