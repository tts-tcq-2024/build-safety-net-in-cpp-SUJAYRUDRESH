#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <string>

class Soundex {
public:
    // Constructor
    Soundex();

    // Generates the full Soundex code for a given name
    std::string generateSoundex(const std::string& name);

private:
    // Static array mapping characters to Soundex codes
    static const char soundexMap[26];

    // Get the Soundex code for a given character
    char getSoundexCode(char c) const;

    // Start the Soundex code with the first letter of the name
    std::string startSoundex(const std::string& name) const;

    // Generate the remaining Soundex code
    void generateRemainingSoundex(std::string& soundex, const std::string& name) const;

    // Process the current character in the name
    void processCurrentChar(std::string& soundex, char currentChar, char& prevCode, char& prevPrevChar) const;

    // Check if the code should be added
    bool shouldAddCode(char prevPrevChar, char currentChar) const;

    // Add the character to the Soundex code
    void processCharacter(std::string& soundex, char code, char& prevCode) const;

    // Check if the Soundex code is valid (not '0')
    bool isValidSoundexCode(char code) const;

    // Check if the code is different from the previous one
    bool isNewCode(char code, char prevCode) const;

    // Check if characters are separated by 'H' or 'W'
    bool isSeparatedByHorW(char prevPrevChar) const;

    // Pad the Soundex code with zeros to ensure it's 4 characters long
    void padWithZeros(std::string& soundex) const;

    // Check if the character is a vowel
    bool isVowel(char c) const;

    bool shouldContinueProcessing(size_t nameLength, size_t soundexLength) const;

    bool shouldAddCode(char currentCode, char prevCode, char prevPrevCode) const;

    bool isShortName(const std::string& name) const;
    bool canAddCode(char prevPrevCode, char currentCode) const ;
    void handleZeroTransition(char currentCode, char& prevCode, char& prevPrevCode) const;
};

#endif // SOUNDEX_H
