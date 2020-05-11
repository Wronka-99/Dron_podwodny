CPPFLAGS= -c -g -Wall -pedantic -std=c++17 

__start__: dron
	./dron

dron: obj/Dr3D_gnuplot_api.o obj/main.o obj/Dron.o 
	g++ -o obj/dron main.o obj/Dr3D_gnuplot_api.o obj/Dron.o -lpthread

obj/main.o: src/main.cpp inc/Dr3D_gnuplot_api.hh inc/Wektor.hh inc/Macierz.hh src/Dron.cpp inc/Dron.hh
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/Dron.o: inc/Bryla.hh inc/Prostopadloscian.hh inc/Dron.hh src/Dron.cpp inc/Dr3D_gnuplot_api.hh
	g++ ${CPPFLAGS} -o obj/Dron.o src/Dron.cpp

obj/Dr3D_gnuplot_api.o: src/Dr3D_gnuplot_api.cpp inc/Dr3D_gnuplot_api.hh
	g++ ${CPPFLAGS} -o obj/Dr3D_gnuplot_api.o src/Dr3D_gnuplot_api.cpp

inc/Dr3D_gnuplot_api.hh: inc/Draw3D_api_interface.hh
	touch inc/Dr3D_gnuplot_api.hh

clear:
	rm -f dron obj/main.o obj/Dr3D_gnuplot_api.o obj/Dron.o


