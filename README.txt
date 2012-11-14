Cool, AESPayload syringe… Woot?
Run the make.sh file 
Wait
Wait
Run the executable in the build folder and plugin a DFU mode device (A4 and below only)
Wait till you see a blue screen with white text
Use 'xpwntool file.img3 /dev/null' to extract the KBAG hex string from file.img3
Start irecovery console: irecovery -s
Execute 'go aes dec _KBAG_STRING_' in irecovery console
~Haifisch

Uses code from Chronic-Dev syringe & cyanide
Nuff' said.