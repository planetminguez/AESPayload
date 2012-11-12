#/bin/sh
echo making cyanide
sleep 5
cd cyanide
make clean
make all
cd ../
clear
echo moving headers
rm ./syringe/include/payloads/*.h
sleep 2
cp ./cyanide/payloads/*.h ./syringe/include/payloads/
sleep 2
echo making syringe
cd syringe
make clean_all
make all
clear
sleep 2
cd ../
rm ./build/AESPayload
cp ./syringe/utilities/AESPayload ./build/
echo done! AESPayload executable in build folder
echo thanks to Haifisch for a 30 minutes of stupidity
# Took me about 30 minutes to change shit with Chronic-Dev's code and this
# shell :)