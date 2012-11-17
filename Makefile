all:
	make -C cyanide
	rm syringe/include/payloads/*.h
	cp cyanide/payloads/*.h syringe/include/payloads/
	make -C syringe
	mkdir build
	cp syringe/utilities/AESPayload build/
	cd libirecovery && ./autogen.sh && ./configure && make
	cd ../
	cp libirecovery/tools/irecovery build/
	mkdir build/.libs
	cp libirecovery/tools/.libs/* build/.libs/
clean:
	make clean -C cyanide
	make clean_all -C syringe
	rm -r build