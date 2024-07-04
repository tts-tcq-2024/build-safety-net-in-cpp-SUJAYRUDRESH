#include "Soundex.h"
#include <cctype>
#include <unordered_map>

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

bool Soundex::shouldContinueProcessing(size_t nameLength, size_t soundexLength) const {
    return nameLength > 1 && soundexLength < 4;
}

void Soundex::generateRemainingSoundex(std::string& soundex, const std::string& name) const {
    if (name.length() <= 1) {
        return;
    }

    char prevCode = getSoundexCode(name[0]);
    char prevPrevChar = toupper(name[0]);

    for (size_t i = 1; i < shouldContinueProcessing(name.length(), soundex.length()) < 4; ++i) {
        processCurrentChar(soundex, name[i], prevCode, prevPrevChar);
    }
}

bool Soundex::shouldAddCode(char currentCode, char prevCode, char prevPrevCode) const {
    return isValidSoundexCode(currentCode) && 
           isNewCode(currentCode, prevCode) && 
           !isSeparatedByHorW(prevPrevCode);
}

void Soundex::processCurrentChar(std::string& soundex, char currentChar, char& prevCode, char& prevPrevCode) const {
    char currentCode = getSoundexCode(currentChar);

    if (shouldAddCode(currentCode, prevCode, prevPrevCode)) {
        processCharacter(soundex, currentCode, prevCode);
    }

    prevPrevChar = toupper(currentChar);
}

bool Soundex::shouldAddCode(char prevPrevChar, char currentChar) const {
    return !isSeparatedByHorW(prevPrevChar) || isVowel(prevPrevChar);
}

void Soundex::processCharacter(std::string& soundex, char code, char& prevCode) const {
    if (isValidSoundexCode(code) && isNewCode(code, prevCode)) {
        soundex += code;
        prevCode = code;
    }
}

bool Soundex::isValidSoundexCode(char code) const {
    return code != '0';
}

bool Soundex::isNewCode(char code, char prevCode) const {
    return code != prevCode;
}

bool Soundex::isSeparatedByHorW(char prevPrevChar) const {
    return prevPrevChar == 'H' || prevPrevChar == 'W';
}

void Soundex::padWithZeros(std::string& soundex) const {
    while (soundex.length() < 4) {
        soundex += '0';
    }
}

bool Soundex::isVowel(char c) const {
    c = toupper(c);
    return (getSoundexCode(c) == '0');
}

std::string Soundex::generateSoundex(const std::string& name) {
    if (name.empty()) return "";

    std::string soundex = startSoundex(name);
    generateRemainingSoundex(soundex, name);
    padWithZeros(soundex);

    return soundex;
}
