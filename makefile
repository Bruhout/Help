build:
	g++ -o input_image.o input_image.cpp -c
	g++ -o output_image.o output_image.cpp -c
	g++ -o main.o main.cpp -c
	g++ -o main main.o input_image.o output_image.o

run:
	./main

clean:
	rm input_image.o
	rm output_image.o
	rm main.o
	rm main
	rm output.bmp