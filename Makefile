GCC=gcc
GXX=g++
LD=ld

CXXFLAGS=-g -Wall -Wattributes

INC_PATH=-I/usr/include $(shell pkg-config opencv --cflags) -I/usr/include/opencv2
LDFLAGS=$(shell pkg-config opencv --libs)

TARGET=learn_opencv

SRCS = test.cpp

OBJS = $(SRCS:.cpp=.o)

%.o : %.cpp
	$(GXX) -std=c++11 -c $^ $(CXXFLAGS) $(INC_PATH) -o $@

learn_opencv : $(OBJS)
	$(GXX) -o $@ $(OBJS) $(LDFLAGS)
	
