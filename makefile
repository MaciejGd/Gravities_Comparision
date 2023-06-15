all: compile link

compile: 
	g++ -c main.cpp object.cpp -I"E:\pliki pobrane\SFML_lib_files\SFML-2.5.1\include" -DSFML_STATIC

link:
	g++ main.o object.o -o main -L"E:\pliki pobrane\SFML_lib_files\SFML-2.5.1\lib" -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -mwindows 

clean: 
	del /F main.exe *.o