all: md5 aes rsa sha256 sha512 Propuesta doxygen
CC = g++
CFLAGS = -Wall
md5: source/MD5/md5.cpp source/MD5/md5.h source/MD5/main.cpp
	$(CC) $(CFLAGS) -o build/md5 source/MD5/md5.cpp source/MD5/md5.h source/MD5/main.cpp
aes: source/AES/AES.cpp
	$(CC) $(CFLAGS) -o build/aes source/AES/AES.cpp
rsa: source/RSA/rsasirve1.cpp
	$(CC) $(CFLAGS) -o build/rsa source/RSA/rsasirve1.cpp
sha512: source/SHA2/SHA512/sha512.cpp
	$(CC) $(CFLAGS) -o build/sha512 source/SHA2/SHA512/sha512.cpp
sha256: source/SHA2/SHA256/sha256.cpp
	$(CC) $(CFLAGS) -o build/sha256 source/SHA2/SHA256/sha256.cpp
Propuesta: 
	(cd doc; pdflatex propuesta.tex)
Reporte:
	(cd doc; pdflatex reporte.tex)
Presentacion:
	(cd doc/pres; pdflatex presentacion.tex)
doxygen:
	(cd doc; doxygen)

clean:
	rm -f doc/propuesta.aux doc/propuesta.log doc/propuesta.out doc/reporte.pdf
	rm -f build/md5 build/aes build/rsa build/sha512 build/sha256
	rm -f -r doc/latex doc/html
	rm -f doc/propuesta.pdf doc/propuesta.aux doc/propuesta.log doc/propuesta.out
	 
