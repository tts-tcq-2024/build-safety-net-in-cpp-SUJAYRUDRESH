#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <string>

class Soundex {
public:
    Soundex();
    std::string generateSoundex(const std::string& name);

private:
    static const char soundexMap[26];
    
    char getSoundexCode(char c) const;
    std::string startSoundex(const std::string& name) const;
    void generateRemainingSoundex(std::string& soundex, const std::string& name) const;
    void processCurrentChar(std::string& soundex, char currentChar, char& prevCode, char& prevPrevCode) const;
    void processCharacter(std::string& soundex, char code, char& prevCode) const;
    bool isValidSoundexCode(char code) const;
    bool isNewCode(char code, char prevCode) const;
    bool shouldAddCode(char prevPrevCode, char currentChar) const;
    bool isSeparatedByHorW(char prevPrevCode) const;
    void padWithZeros(std::string& soundex) const;
    bool isVowel(char c) const;
};

#endif // SOUNDEX_H
