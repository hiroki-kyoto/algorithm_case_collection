test_quick_sort : main.o
	@echo.
	@echo ================== LINK OBJECTS ======================
	g++ main.o -o test_quick_sort

main.o : main.cpp algorithm.h
	@echo.
	@echo ================ COMPILE SOURCE FILES ================
	g++ -c main.cpp

.PHONY : clean
clean :
	@echo.
	@echo ============= CLEAN OBJECTS AND TARGETS ==============
	@rm *.o
	@rm *.gch
	@rm *.exe
	@rm *.bin
	@rm *.img
check :
	@echo.
	@echo ================== RUN TEST CASE =====================
	test_quick_sort 20 13 87 -25 96 17 -21 54 25 36 20

test :
	@make clean & clear & make & make check & make clean
