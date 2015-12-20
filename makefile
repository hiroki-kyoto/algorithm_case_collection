priority_queue_search.app : priority_queue_search.o
	g++ priority_queue_search.o -o priority_queue_search.app
	
priority_queue_search.o : priority_queue_search.cpp

install-PQS :
	./priority_queue_search.app

test_quick_sort : main.o
	@echo ''
	@echo ================== LINK OBJECTS ======================
	g++ main.o -o test_quick_sort

main.o : main.cpp algorithm.h
	@echo ''
	@echo ================ COMPILE SOURCE FILES ================
	g++ -c main.cpp

.PHONY : clean
clean :
	@echo ''
	@echo ============= CLEAN OBJECTS AND TARGETS ==============
	@-rm *.o
	@-rm *.gch
	@-rm *.exe
	@-rm *.bin
	@-rm *.img
	@-rm *.app
check :
	@echo ''
	@echo ================== RUN TEST CASE =====================
	test_quick_sort rand_num.txt sort_num.txt

test :
	@echo ''
	@echo ============= GENERATE RANDOM NUMBERS ================
	g++ -o rand_num_generator rand_num_generator.cpp
	rand_num_generator rand_num.txt 100000
	@make clean & clear & make & make check & make clean

pso.app : particle_swarm_optimization.o
	g++ -o pso.app particle_swarm_optimization.o
particle_swarm_optimization.o : particle_swarm_optimization.cpp
pso :
	./pso.app
