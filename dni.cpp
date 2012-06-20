#include <iostream>

int main(int nargs, char* argv[])
{

  char* s = argv[1];	


  //char dni[] = "21532376";
  //char* s = dni;

  char serie[] = "89456789";
  char* t = serie;

  int suma = 0, parcial = 0;

  while(*s!='\0')
  {
    std::cout << *s << " x " << *t << " = " << (parcial = (*s-'0')*(*t-'0')) << std::endl;
    suma += parcial;
    s++;
    t++;
  }
  std::cout << "suma = " << suma << std::endl;

  int modulo = 0;
  modulo = suma % 11;

  std::cout << "modulo = " << modulo << std::endl;

  char caracter = 'A';
  caracter += (modulo==0?11:modulo) - 1;

  std::cout << "caracter : " << caracter << std::endl;

  char cadena[] = "FGHIJKABCDE";
  char* r = cadena;

  int numero = 0;

  while(*r != caracter)
  {
    r++;
  }

  numero = (r - cadena + 1) % 10;
  std::cout << "numero : " << numero << std::endl;

  return 0;

}
