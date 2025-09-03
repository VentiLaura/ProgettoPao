#include "Enums.h"
#include <stdexcept>
#include <algorithm>
namespace product{

std::string ConsoleTypeToString(Console_type console) {
    switch(console) {
        case Console_type::GameBoy: return "GameBoy";
        case Console_type::GameBoyAdvance: return "GameBoy Advance";
        case Console_type::GameCube: return "GameCube";
        case Console_type::Ninendo_64: return "Nintendo 64";
        case Console_type::Nintendo_2DS: return "Nintendo 2DS";
        case Console_type::Nintendo_3DS: return "Nintendo 3DS";
        case Console_type::Nintendo_DS: return "Nintendo DS";
        case Console_type::Nintendo_DSi: return "Nintendo DSi";
        case Console_type::Nintendo_Switch: return "Nintendo Switch";
        case Console_type::Nintendo_Switch_2: return "Nintendo Switch 2";
        case Console_type::Nintendo_Switch_Lite: return "Nintendo Switch Lite";
        case Console_type::Nintendo_Switch_OLED: return "Nintendo Switch Oled";
        case Console_type::PlayStation2: return "PlayStation 2";
        case Console_type::PlayStation3: return "PlayStation 3";
        case Console_type::PlayStation4: return "PlayStation 4";
        case Console_type::PlayStation5: return "PlayStation 5";
        case Console_type::PlayStation: return "PlayStation";
        case Console_type::PlayStation_Vita: return "PlayStation Vita";
        case Console_type::steam: return "Steam";
        case Console_type::SteamDeck: return "Steam Deck";
        case Console_type::Wii: return "Wii";
        case Console_type::Wii_U: return "Wii U";
        case Console_type::Xbox: return "Xbox";
        case Console_type::Xbox_360: return "Xbox 360";
        case Console_type::Xbox_One: return "Xbox One";
        case Console_type::Xbox_Series_S: return "Xbox Series S";
        case Console_type::Xbox_Series_X: return "Xbox Series X";
        throw std::invalid_argument("Not a Console type");
    }
}

Console_type StringToConsoleType(const std::string& c) {
    std::string console=c;
    std::transform(console.begin(), console.end(), console.begin(), ::tolower);
    if (console == "gameboy") return Console_type::GameBoy;
    if (console == "gameboy advance") return Console_type::GameBoyAdvance;
    if (console == "gamecube") return Console_type::GameCube;
    if (console == "nintendo 64") return Console_type::Ninendo_64;
    if (console == "nintendo 2ds") return Console_type::Nintendo_2DS;
    if (console == "nintendo 3ds") return Console_type::Nintendo_3DS;
    if (console == "nintendo ds") return Console_type::Nintendo_DS;
    if (console == "nintendo dsi") return Console_type::Nintendo_DSi;
    if (console == "nintendo switch") return Console_type::Nintendo_Switch;
    if (console == "nintendo switch 2") return Console_type::Nintendo_Switch_2;
    if (console == "nintendo switch lite") return Console_type::Nintendo_Switch_Lite;
    if (console == "nintendo switch oled") return Console_type::Nintendo_Switch_OLED;
    if (console == "playstation 2") return Console_type::PlayStation2;
    if (console == "playstation 3") return Console_type::PlayStation3;
    if (console == "playstation 4") return Console_type::PlayStation4;
    if (console == "playstation 5") return Console_type::PlayStation5;
    if (console == "playstation") return Console_type::PlayStation;
    if (console == "playstation vita") return Console_type::PlayStation_Vita;
    if (console == "steam") return Console_type::steam;
    if (console == "steam deck") return Console_type::SteamDeck;
    if (console == "wii") return Console_type::Wii;
    if (console == "wii u") return Console_type::Wii_U;
    if (console == "xbox") return Console_type::Xbox;
    if (console == "xbox 360") return Console_type::Xbox_360;
    if (console == "xbox one") return Console_type::Xbox_One;
    if (console == "xbox series s") return Console_type::Xbox_Series_S;
    if (console == "xbox series x") return Console_type::Xbox_Series_X;

    throw std::invalid_argument("Not a Console type: " + c);
}

std::string GenreToString(Genre genre) {
    switch (genre) {
        case Genre::Action: return "Action";
        case Genre::RPG: return "RPG";
        case Genre::Platform: return "Platform";
        case Genre::Puzzle: return "Puzzle";
        case Genre::JRPG: return "JRPG";
        case Genre::Hack_and_Slash: return "Hack and Slash";
        case Genre::Metroid_venia: return "Metroidvania";
        case Genre::Rogue_like: return "Roguelike";
        case Genre::Tactic: return "Tactic";
        case Genre::Third_Person_shooter: return "Third Person Shooter";
        case Genre::First_person_shooter: return "First Person Shooter";
        case Genre::Horror: return "Horror";
        case Genre::Gacha: return "Gacha";
        case Genre::Simulator: return "Simulator";
        case Genre::Battle_royale: return "Battle Royale";
        throw std::invalid_argument("Not a genre");
    }
}
Genre StringToGenre(const std::string& s) {
    std::string genre=s;
    std::transform(genre.begin(), genre.end(), genre.begin(), ::tolower);
    if (genre == "action") return Genre::Action;
    if (genre == "rpg") return Genre::RPG;
    if (genre == "platform") return Genre::Platform;
    if (genre == "puzzle") return Genre::Puzzle;
    if (genre == "jrpg") return Genre::JRPG;
    if (genre == "hack and slash" || genre == "hack_and_slash") return Genre::Hack_and_Slash;
    if (genre == "metroidvania" || genre == "metroid_venia") return Genre::Metroid_venia;
    if (genre == "roguelike" || genre == "rogue_like") return Genre::Rogue_like;
    if (genre == "tactic") return Genre::Tactic;
    if (genre == "third person shooter" || genre == "third_person_shooter") return Genre::Third_Person_shooter;
    if (genre == "first person shooter" || genre == "first_person_shooter") return Genre::First_person_shooter;
    if (genre == "horror") return Genre::Horror;
    if (genre == "gacha") return Genre::Gacha;
    if (genre == "simulator") return Genre::Simulator;
    if (genre == "battle royale" || genre == "battle_royale") return Genre::Battle_royale;
    throw std::invalid_argument("Not a genre" + s);
}
std::string SizeToString(Sizes size) {
    switch (size) {
        case Sizes::XS: return "XS";
        case Sizes::S:  return "S";
        case Sizes::M:  return "M";
        case Sizes::L:  return "L";
        case Sizes::XL: return "XL";
        throw std::invalid_argument("Not a size");
    }
}

Sizes StringToSize(const std::string& s) {
    std::string size=s;
    std::transform(size.begin(), size.end(), size.begin(), ::tolower);
    if (size == "xs") return Sizes::XS;
    if (size == "s")  return Sizes::S;
    if (size == "m")  return Sizes::M;
    if (size == "l")  return Sizes::L;
    if (size == "xl") return Sizes::XL;
    throw std::invalid_argument("Not a size: " + s);
}
}