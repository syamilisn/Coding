JC=javac
JVM=java
JFLAGS= -g
RM = rm -f
CFLAGS =
CXX = gcc
NAME = *
.SUFFIXES: .java .class

all: run

NAME: 
	$(CXX) $(CFLAGS) -o $^ $@
	echo $(NAME)

$(NAME).class: $(NAME)
        $(JC) $(JFLAGS) $(NAME).java

run: $(NAME).class
        $(JVM) $(NAME)

.PHONY: clean
clean:
	$(RM) $(NAME).class
