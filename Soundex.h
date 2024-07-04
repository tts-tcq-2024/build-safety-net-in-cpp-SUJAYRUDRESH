#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <string>

// Function to get the Soundex code for a given character.
char getSoundexCode(char c);

// Function to generate the Soundex code for a given name.
std::string generateSoundex(const std::string& name);

// Function to get the initial character of the Soundex code.
std::string getInitialSoundex(const std::string& name);

// Function to process the remaining characters of the name to generate the Soundex code.
std::string processRemainingCharacters(const std::string& name, const std::string& initialSoundex);

// Function to pad the Soundex code to ensure it has exactly four characters.
std::string padSoundex(const std::string& soundex);

#endif // SOUNDEX_H
