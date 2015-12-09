all: t_network.app t_vector.app
t_network.app: t_network.o
	g++ -o t_network.app t_network.o
t_network.o: t_network.cpp

t_vector.app: t_vector.o
	g++ -o t_vector.app t_vector.o
t_vector.o: t_vector.cpp

.PHONY:clean
clean :
	-rm *.o
	-rm *.app
.PHONY:install

install:
	./t_network.app
	./t_vector.app
