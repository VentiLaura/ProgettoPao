#ifndef ENUMS_H
#define ENUMS_H
#include <string>
namespace product {

enum class Genre {
    Action,
    RPG,
    Platform,
    Puzzle,
    JRPG,
    Hack_and_Slash,
    Metroid_venia,
    Rogue_like,
    Tactic,
    Third_Person_shooter,
    First_person_shooter,
    Horror,
    Gacha,
    Simulator,
    Battle_royale
};
enum class Console_type {
    Xbox,
    Xbox_360,
    Xbox_One,
    Xbox_Series_X,
    Xbox_Series_S,
    PlayStation,
    PlayStation2,
    PlayStation3,
    PlayStation4,
    PlayStation5,
    PlayStation_Vita,
    steam,
    SteamDeck,
    Ninendo_64,
    GameCube,
    Wii,
    Wii_U,
    GameBoy,
    GameBoyAdvance,
    Nintendo_DS,
    Nintendo_DSi,
    Nintendo_3DS,
    Nintendo_2DS,
    Nintendo_Switch,
    Nintendo_Switch_Lite,
    Nintendo_Switch_OLED,
    Nintendo_Switch_2
};
enum class Sizes {
    XS,
    S,
    M,
    L,
    XL
};
std::string ConsoleTypeToString(Console_type);
Console_type StringToConsoleType(const std::string&);
std::string GenreToString(Genre);
Genre StringToGenre(const std::string&);
std::string SizeToString(Sizes);
Sizes StringToSize(const std::string&);
}
#endif