CC=g++
LINK=g++
# SRCS = perfil.cpp main.cpp
# COMPILED_SRCS = perfil.o main.o

# Referencia: http://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html#Automatic-Variables

SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)

EPNAME = EP2

CFLAGS = -Wall -pedantic -fexceptions -std=c++11 -g
OFLAGS = -O2

all: build

%.o: %.cpp
	$(CC) $(CFLAGS) -MMD -MP -c $<


-include $(DEPS)

build: $(OBJS)
	$(LINK) -o $(EPNAME) $(OBJS)


.PHONY: clean

# $(RM) is rm -f by default
# Para Windows:
RM = del


clean:
	$(RM) $(EPNAME).exe $(OBJS) $(DEPS)
