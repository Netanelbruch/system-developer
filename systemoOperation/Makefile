



all: targil1 targil2 targil3 targil4 targil5 targil6

targil1: 
	cd ./targil_1/ && make
targil2:
	cd ./targil_2/ && make
targil3:
	cd ./targil_3/ && make
targil4: 
	cd ./targil_4/ && make 

targil5: 
	cd ./targil_5/ && make

targil6: 
	cd ./targil_6/ && make


#run
targil_1_run:
	cd ./targil_1/ && make run

targil_4_run:
	cd ./targil_4/ && ./main

targil_5_run:
	cd ./targil_5/ && make run 


.PHONY: all clean

clean:
	-(cd ./targil_1 && make clean)
	-(cd ./targil_2 && make clean)
	-(cd ./targil_3 && make clean)
	-(cd ./targil_4 && make clean)
	-(cd ./targil_5 && make clean)
	-(cd ./targil_6 && make clean) 

	   