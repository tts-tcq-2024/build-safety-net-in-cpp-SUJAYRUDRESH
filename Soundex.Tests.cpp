#include "gtest/gtest.h"
#include "Soundex.h"

class SoundexTest : public ::testing::Test {
protected:
    Soundex soundex;
};

TEST_F(SoundexTest, BasicTests) {
    EXPECT_EQ(soundex.generateSoundex("Sujay"), "S200");
    EXPECT_EQ(soundex.generateSoundex("Rudresh"), "R362");
    EXPECT_EQ(soundex.generateSoundex("Pratiksha"), "P632");
    EXPECT_EQ(soundex.generateSoundex("Suraj"), "S620");
    EXPECT_EQ(soundex.generateSoundex("Manjunath"), "M525");
    
}


TEST_F(SoundexTest, ShortNames) {
    EXPECT_EQ(soundex.generateSoundex("S"), "S000");
    EXPECT_EQ(soundex.generateSoundex("So"), "S000");
    EXPECT_EQ(soundex.generateSoundex("Son"), "S500");
}

TEST_F(SoundexTest, PaddingZeros) {
    EXPECT_EQ(soundex.generateSoundex("Jam"), "J500");
    EXPECT_EQ(soundex.generateSoundex("Fyn"), "F500");
    EXPECT_EQ(soundex.generateSoundex("Zz"), "Z000");
    EXPECT_EQ(soundex.generateSoundex("X"), "X000");
}

TEST_F(SoundexTest, CaseInsensitivity) {
    EXPECT_EQ(soundex.generateSoundex("Sujay"), soundex.generateSoundex("sujay"));
    EXPECT_EQ(soundex.generateSoundex("Rudresh"), soundex.generateSoundex("rudresh"));
}

TEST_F(SoundexTest, GenerateSoundexNamesWithOnlyVowels) {
    EXPECT_EQ(soundex.generateSoundex("Ae"), "A000");
    EXPECT_EQ(soundex.generateSoundex("Io"), "I000");
}
TEST_F(SoundexTest, GenerateSoundexVeryShortNames) {
    EXPECT_EQ(soundex.generateSoundex("A"), "A000");
    EXPECT_EQ(soundex.generateSoundex("B"), "B000");
}


TEST_F(SoundexTest, NonAlphabeticCharacters) {
    EXPECT_EQ(soundex.generateSoundex("Sujay-s"), "S220");
}
TEST_F(SoundexTest, GenerateSoundexEmptyName) {
    EXPECT_EQ(soundex.generateSoundex(""), "");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
