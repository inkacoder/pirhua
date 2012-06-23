/*
    <<Copyright 2012 Inkacoder>>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>
    or <http://github.com/inkacoder/pirhua/COPYING>
*/

#include "stdlib.h"
#include "string.h"

#include <iostream>
#include <tclap/CmdLine.h>

char alphaValidationCharacter(char *DNI);
int digitValidationCharacter(char *DNI);

int main(int argc, char* argv[])
{
	try {  

		// Command line object
		// [1] message that describes the program
		// [2] delimiter (usually space)
		// [3] version number. 
		TCLAP::CmdLine cmd("Peruvian DNI Validation Character Calculator", ' ', "0.1");

		//Arguments
		TCLAP::UnlabeledValueArg<std::string>  DNIArg( "dni", "Peruvian DNI", true, "00000000", "8-character string");
		cmd.add( DNIArg );

		//Switches	
		TCLAP::SwitchArg digitSwitch("d","digit-output","Prints the digit version of the validation character", false);
		cmd.add(digitSwitch);

		TCLAP::SwitchArg alphaSwitch("c","character-output","Prints the character version of the validation character", false);
		cmd.add(alphaSwitch);

		// Parse the argv array.
		cmd.parse( argc, argv );

		// Get the value parsed by each arg. 
		std::string DNI = DNIArg.getValue();
		bool digit = digitSwitch.getValue();
		bool alpha = alphaSwitch.getValue();

		char* dni = new char[DNI.length()+1];
		strcpy(dni,DNI.c_str());

		if ( digit )
		{
			std::cout << digitValidationCharacter(dni) << std::endl;
		}
		else if (alpha)
		{ 
			std::cout << alphaValidationCharacter(dni) << std::endl;
		}
		delete[] dni;
	} 
	catch (TCLAP::ArgException &e)  // catch any exceptions
	{ 
		std::cerr << "error: " << e.error() << " en el argumento " << e.argId() << std::endl; 
        }
 
	return EXIT_SUCCESS;

}

char alphaValidationCharacter(char *DNI)
{

  const char serie[] = "89456789";
  char const *t = serie;

  char *s = DNI;

  int suma = 0, parcial = 0;

  while(*s!='\0')
  {
    //std::cout << *s << " x " << *t << " = " << (parcial = (*s-'0')*(*t-'0')) << std::endl;
    parcial = (*s-'0')*(*t-'0');
    suma += parcial;
    s++;
    t++;
  } //std::cout << "suma = " << suma << std::endl;

  int modulo = 0;
  modulo = suma % 11;
  //std::cout << "modulo = " << modulo << std::endl;

  return 'A' + (modulo==0?11:modulo) - 1;

}

int digitValidationCharacter(char* DNI)
{

  const char stringSequence[] = "FGHIJKABCDE";
  char const *r = stringSequence;

  char c = alphaValidationCharacter(DNI);

  while(*r != c){ r++; }

  return (r - stringSequence + 1) % 10;
  
}

 
