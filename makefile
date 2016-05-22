CC = g++ 
prog: main.o EnglishMorseTranslator.o
	$(CC) main.o EnglishMorseTranslator.o -o translator
main.o: main.cpp EnglishMorseTranslator.h
	$(CC) -c main.cpp
EnglishMorseTranslator.o: EnglishMorseTranslator.h EnglishMorseTranslator.cpp
	$(CC) -c EnglishMorseTranslator.cpp
