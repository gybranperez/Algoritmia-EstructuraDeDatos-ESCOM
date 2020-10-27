OBJS = main.o lista.o
BINARIO = s

HW = Bienvenido a Makefile

all: imprimir out

out: $(OBJS)
	g++ $(OBJS) -o $(BINARIO)
	@echo
#main compilado
main.o: main.cpp
	g++ -c main.cpp

lista.o: lista.c
	g++ -c lista.c

clean:
	rm -rf $(BINARIO) $(OBJS)

imprimir:
	@echo $(HW)
	@echo