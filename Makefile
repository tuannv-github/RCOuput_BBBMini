ARCH = arm-linux-gnueabihf-
CXX  = g++

APP_SRC = RCOutput_AioPRU.cpp RCOutput_Test.cpp
APP 	= RCOutput_Test

CFLAGS= -fPIC -O0 -g -Wall -fpermissive -std=c++11
INC = -I.

all:
	$(ARCH)$(CXX) $(INC) $(CFLAGS) $(APP_SRC) -o $(APP)

clean:
	rm -f $(APP) Makefile.bak