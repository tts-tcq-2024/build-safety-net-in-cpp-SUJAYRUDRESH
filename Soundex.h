#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <string>

// Function to get the Soundex code for a given character.
char getSoundexCode(char c);

// Function to generate the Soundex code for a given name.
std::string generateSoundex(const std::string& name);



#endif // SOUNDEX_H
