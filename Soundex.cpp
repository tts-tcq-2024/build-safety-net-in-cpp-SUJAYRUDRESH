#include "Soundex.h"
#include <cctype>

char getSoundexCode(char c) {
    // Array to store the Soundex code for each character ('A'-'Z')
    static const char soundexCodes[] = {
        // A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
          '0', '1', '2', '3', '0', '1', '2', '0', '0', '2', '2', '4', '5', '5', '0', '1', '2', '6', '2', '3', '0', '1', '0', '2', '0', '2'
    };

    // Convert character to uppercase
    c = toupper(c);

    // Calculate index based on ASCII value ('A' is 65, so index is c - 65)
    int index = c - 'A';
    
    // Return corresponding Soundex code, or '0' if character is out of range
    return (index >= 0 && index < 26) ? soundexCodes[index] : '0';
}


std::string generateSoundex(const std::string& name) {
    if (name.empty()) return "";

    std::string soundex = getInitialSoundex(name);
    soundex = processRemainingCharacters(name, soundex);

    return padSoundex(soundex);
}

std::string getInitialSoundex(const std::string& name) {
    return std::string(1, toupper(name[0]));
}

std::string processRemainingCharacters(const std::string& name, const std::string& initialSoundex) {
    std::string soundex = initialSoundex;
    char prevCode = getSoundexCode(name[0]);

    for (size_t i = 1; i < name.size() && soundex.size() < 4; ++i) {
        char code = getSoundexCode(name[i]);
        if (code != '0' && code != prevCode) {
            soundex += code;
            prevCode = code;
        }
    }

    return soundex;
}

std::string padSoundex(const std::string& soundex) {
    std::string paddedSoundex = soundex;
    paddedSoundex.append(4 - soundex.size(), '0');
    return paddedSoundex.substr(0, 4);
}
