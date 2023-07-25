#ifndef GLOBAL_H
#define GLOBAL_H
#include <string>
#include <vector>

#define VChar std::vector<char>

extern const VChar PLAYFAIR_CHARACTER_LOWER_MAP;

extern const VChar CHARACTER_LOWER_MAP;

extern const VChar CHARACTER_UPPER_MAP;

extern char getBase(const char&);

extern std::string toStrLower(const std::string&);

extern std::string toStrUpper(const std::string&);
#endif