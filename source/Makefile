CPPFLAGS= -c -g -Wall -pedantic -std=c++17 

__start__: dron
	./dron

dron: Dr3D_gnuplot_api.o main.o Dron.o Prostopadloscian.o Graniastoslup.o
	g++ -o dron main.o Graniastoslup.o Dr3D_gnuplot_api.o Dron.o Prostopadloscian.o  -lpthread

main.o: main.cpp Dr3D_gnuplot_api.hh Wektor.hh Macierz.hh Sruba.hh Dron.cpp Dron.hh Dno.hh Graniastoslup.hh
	g++ ${CPPFLAGS} -o main.o main.cpp

Dron.o: Bryla.hh Prostopadloscian.hh Dron.hh Dron.cpp Dr3D_gnuplot_api.hh
	g++ ${CPPFLAGS} -o Dron.o Dron.cpp

Prostopadloscian.o: Bryla.hh Prostopadloscian.hh Dron.hh Dron.cpp Dr3D_gnuplot_api.hh
	g++ ${CPPFLAGS} -o Prostopadloscian.o Prostopadloscian.cpp

Graniastoslup.o: Bryla.hh   Graniastoslup.hh Dr3D_gnuplot_api.hh
	g++ ${CPPFLAGS} -o Graniastoslup.o Graniastoslup.cpp

Dr3D_gnuplot_api.o: Dr3D_gnuplot_api.cpp Dr3D_gnuplot_api.hh
	g++ ${CPPFLAGS} -o Dr3D_gnuplot_api.o Dr3D_gnuplot_api.cpp

Dr3D_gnuplot_api.hh: Draw3D_api_interface.hh
	touch Dr3D_gnuplot_api.hh

clear:
	rm -f dron main.o Dr3D_gnuplot_api.o Dron.o 


