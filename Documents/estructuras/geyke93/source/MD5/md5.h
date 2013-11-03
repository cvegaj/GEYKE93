/* MD5
 converted to C++ class by Frank Thilo (thilo@unix-ag.org)
 for bzflag (http://www.bzflag.org)

   based on:

   md5.h and md5.c
   reference implementation of RFC 1321

   Copyright (C) 1991-2, RSA Data Security, Inc. Created 1991. All
rights reserved.

License to copy and use this software is granted provided that it
is identified as the "RSA Data Security, Inc. MD5 Message-Digest
Algorithm" in all material mentioning or referencing this software
or this function.

License is also granted to make and use derivative works provided
that such works are identified as "derived from the RSA Data
Security, Inc. MD5 Message-Digest Algorithm" in all material
mentioning or referencing the derived work.

RSA Data Security, Inc. makes no representations concerning either
the merchantability of this software or the suitability of this
software for any particular purpose. It is provided "as is"
without express or implied warranty of any kind.

These notices must be retained in any copies of any part of this
documentation and/or software.

*/

#ifndef BZF_MD5_H
#define BZF_MD5_H

#include <string>
#include <iostream>


class MD5
{
public:
	
  typedef unsigned int size_type; /// must be 32bit

///Constructor
  MD5();
  MD5(const std::string& text);
  /**Hace un update a un bloque. Continua con la operacion de digestion del mensaje,
 * procesando otro bloque */
  void update(const unsigned char *buf, size_type length);
  void update(const char *buf, size_type length);
 /** MD5 finalize. Termina message-digest operation, escribiendo
  * el digest y zeroizando el contexto**/
  MD5& finalize();
///retorna la representacion HEX del digest como un string
  std::string hexdigest() const;
  friend std::ostream& operator<<(std::ostream&, MD5 md5);

  void init();
  typedef unsigned char uint1; /// 8bit
  typedef unsigned int uint4;  /// 32bit
  enum {blocksize = 64}; // VC6 won't eat a const static int here

/** Funcion de transformacion, la funcion que aplica el algoritmo a un bloque
 * @param block el blocke a transformar
 * Aplica las funciones de transformacion FF(ronda 1), GG(ronda 2) HH(ronda 3) e II(ronda 4)
 * @see MD5::FF **/
  void transform(const uint1 block[blocksize]);
  ///	Decodifica un unsigned char a un uint4
  static void decode(uint4 output[], const uint1 input[], size_type len);
  ///Codifica un uint4 a un unsigned char. Opuesto a la funcion 'decode'
  static void encode(uint1 output[], const uint4 input[], size_type len);

  bool finalized;
  /// bytes que no cupieron en el ultimo bloque de 64 bytes
  uint1 buffer[blocksize]; 
  /// 64bit counter for number of bits (lo, hi)
  uint4 count[2]; 
  /// matriz de estado (el mensaje durante el proceso de digest)
  uint4 state[4];  
///el resultado
  uint1 digest[16]; 

///Funciones logicas basicas 
  static inline uint4 F(uint4 x, uint4 y, uint4 z);
  static inline uint4 G(uint4 x, uint4 y, uint4 z);
  static inline uint4 H(uint4 x, uint4 y, uint4 z);
  static inline uint4 I(uint4 x, uint4 y, uint4 z);
  static inline uint4 rotate_left(uint4 x, int n);
 /** Funciones de transformacion para las rondas 1, 2, 3 y 4
 * @param a,b,c,d elementos de la matriz State. 
 * Utiliza la funcion de rotacion citada anteriormente
 * @see MD5::rotate_left*/
  static inline void FF(uint4 &a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac);
  static inline void GG(uint4 &a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac);
  static inline void HH(uint4 &a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac);
  static inline void II(uint4 &a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac);
};

std::string md5(const std::string str);

#endif
