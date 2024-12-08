all:
	cmake -B build
	make -j 12 -C build 

clean: 
	rm -rf build/*
