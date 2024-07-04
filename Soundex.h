#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <string>

class Soundex {
public:
    Soundex();

    // Generates the Soundex code for a given name
    std::string generateSoundex(const std::string& name);

private:
    // Maps characters to their Soundex codes
    static const char soundexMap[26];

    // Returns the Soundex code for a given character
    char getSoundexCode(char c) const;

    // Returns the initial character for Soundex encoding
    std::string startSoundex(const std::string& name) const;

    // Generates the remaining Soundex codes for the name
    void generateRemainingSoundex(std::string& soundex, const std::string& name) const;

    // Checks if a Soundex code is valid (not '0')
    bool isValidSoundexCode(char code) const;

    // Checks if a new Soundex code is different from the previous one
    bool isNewCode(char code, char prevCode) const;

    // Checks if a Soundex code should be added based on separation rules
    bool shouldAddCode(char prevPrevChar, char currentChar) const;

    // Checks if a character is a vowel
    bool isVowel(char c) const;

    // Pads the Soundex code with zeros to ensure it's 4 characters long
    void padWithZeros(std::string& soundex) const;

    // Checks if a character is separated by 'h' or 'w' from the current character
    bool isSeparatedByHOrW(char prevChar, char currentChar) const;
};

#endif // SOUNDEX_H
