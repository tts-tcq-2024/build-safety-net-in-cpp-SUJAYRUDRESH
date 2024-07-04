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
    void padWithZeros(std::string& soundex) const;
};

#endif // SOUNDEX_H
