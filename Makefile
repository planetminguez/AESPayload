all:
	mkdir build
	make -C cyanide
	rm syringe/include/payloads/*.h
	cp cyanide/payloads/*.h syringe/include/payloads/
	make -C syringe
	rm build/AESPayload
	cp syringe/utilities/AESPayload build/
	cd libirecovery && ./autogen.sh && ./configure && make
	cd ../
	cp libirecovery/tools/irecovery build/
	cp libirecovery/tools/.libs/* build/.libs/
clean:
	make clean -C cyanide
	make clean_all -C syringe
	rm -r build