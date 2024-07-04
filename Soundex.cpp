#include "Soundex.h"
#include <cctype>
#include <string>


const char Soundex::soundexMap[26] = {
    //  A     B    C    D    E   F     G   H     I    J    K    L    M    N   O      P   Q    R    S    T    U    V   W     X   Y     Z
    '0', '1', '2', '3', '0', '1', '2', '0', '0', '2', '2', '4', '5', '5', '0', '1', '0', '6', '2', '3', '0', '1', '0', '2', '0', '2'
};

Soundex::Soundex() {}

char Soundex::getSoundexCode(char c) const {
    c = toupper(c);
    return (c >= 'A' && c <= 'Z') ? soundexMap[c - 'A'] : '0';
}

std::string Soundex::startSoundex(const std::string& name) const {
    return std::string(1, toupper(name[0]));
}

bool Soundex::isShortName(const std::string& name) const {
    return name.length() <= 1;
}

void Soundex::generateRemainingSoundex(std::string& soundex, const std::string& name) const {
    char prevCode = getSoundexCode(name[0]);
    char prevPrevCode = 0;

    for (size_t i = 1; i < name.length() && soundex.length() < 4; ++i) {
        processCurrentChar(soundex, name[i], prevCode, prevPrevCode);
    }
}

void Soundex::processCurrentChar(std::string& soundex, char currentChar, char& prevCode, char& prevPrevCode) const {
    char currentCode = getSoundexCode(currentChar);

    if (shouldAddCode(currentCode, prevCode, prevPrevCode)) {
        soundex += currentCode;
    }
    
    prevPrevCode = prevCode;
    prevCode = currentCode;
}

bool Soundex::shouldAddCode(char currentCode, char prevCode, char prevPrevCode) const {
    return isValidSoundexCode(currentCode) && 
           isNewCode(currentCode, prevCode) && 
           canAddCode(prevPrevCode, currentCode);
}

bool Soundex::canAddCode(char prevPrevCode, char currentCode) const {
    return !(isSeparatedByHorW(prevPrevCode) && !isVowel(currentCode));
}

bool Soundex::isValidSoundexCode(char code) const {
    return code != '0';
}

bool Soundex::isNewCode(char code, char prevCode) const {
    return code != prevCode;
}

bool Soundex::isSeparatedByHorW(char prevPrevCode) const {
    return prevPrevCode == 'H' || prevPrevCode == 'W';
}

void Soundex::padWithZeros(std::string& soundex) const {
    while (soundex.length() < 4) {
        soundex += '0';
    }
}



std::string Soundex::generateSoundex(const std::string& name) {
    if (name.empty()) return "";

    std::string soundex = startSoundex(name);
    if (!isShortName(name)) {
        generateRemainingSoundex(soundex, name);
    }
    padWithZeros(soundex);

    return soundex;
}

bool Soundex::isVowel(char c) const {
    c = toupper(c);
    return (getSoundexCode(c) == '0');
}
