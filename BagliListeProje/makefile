hepsi: derle calistir

derle: 
	g++ -I ./include/ -o ./lib/Gen.o -c ./src/Gen.cpp
	g++ -I ./include/ -o ./lib/Kromozom.o -c ./src/Kromozom.cpp
	g++ -I ./include/ -o ./lib/Dna.o -c ./src/Dna.cpp
	g++ -I ./include/ -o ./bin/Main ./lib/Gen.o ./lib/Kromozom.o ./lib/Dna.o ./src/Main.cpp

calistir:
	./bin/Main



	