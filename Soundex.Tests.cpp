#include "gtest/gtest.h"
#include "Soundex.h"

class SoundexTest : public ::testing::Test {
protected:
    Soundex soundex;
};

TEST_F(SoundexTest, BasicTests) {
    EXPECT_EQ(soundex.generateSoundex("Sujay"), "S530");
    EXPECT_EQ(soundex.generateSoundex("Rudresh"), "J525");
}

TEST_F(SoundexTest, ConsecutiveIdenticalCodes) {
    EXPECT_EQ(soundex.generateSoundex("Bb"), "B000");
    EXPECT_EQ(soundex.generateSoundex("Aaaa"), "A000");
}

TEST_F(SoundexTest, ShortNames) {
    EXPECT_EQ(soundex.generateSoundex("S"), "J000");
    EXPECT_EQ(soundex.generateSoundex("So"), "J000");
    EXPECT_EQ(soundex.generateSoundex("Son"), "J500");
}

TEST_F(SoundexTest, PaddingZeros) {
    EXPECT_EQ(soundex.generateSoundex("JAM"), "L500");
    EXPECT_EQ(soundex.generateSoundex("Fyn"), "F500");
    EXPECT_EQ(soundex.generateSoundex("Zz"), "Z000");
    EXPECT_EQ(soundex.generateSoundex("X"), "X000");
}

TEST_F(SoundexTest, CaseInsensitivity) {
    EXPECT_EQ(soundex.generateSoundex("Sujay"), soundex.generateSoundex("sujay"));
    EXPECT_EQ(soundex.generateSoundex("Rudresh"), soundex.generateSoundex("rudresh"));
}

TEST_F(SoundexTest, NonAlphabeticCharacters) {
    EXPECT_EQ(soundex.generateSoundex("Sujay-s"), "O640");
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
