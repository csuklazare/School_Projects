JFLAGS = -g
JC = javac
.SUFFIXES: .java .class
.java.class:
	$(JC) $(JFLAGS) $*.java

CLASSES = \
        Producer.java \
        Consumer.java \
        Bdbuffer.java \
        Invoker.java 

default: classes

classes: $(CLASSES:.java=.class)

clean:
	$(RM) *.class
build:
	tar -czvf Brock-Fisher-HW5.tar *.java *.txt Makefile
