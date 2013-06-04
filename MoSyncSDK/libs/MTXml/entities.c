/* ANSI-C code produced by gperf version 3.0.4 */
/* Command-line: gperf -tCE --language=ANSI-C --lookup-function-name=entity_lookup entities.txt  */
/* Computed positions: -k'1-3,5,$' */

#if !((' ' == 32) && ('!' == 33) && ('"' == 34) && ('#' == 35) \
      && ('%' == 37) && ('&' == 38) && ('\'' == 39) && ('(' == 40) \
      && (')' == 41) && ('*' == 42) && ('+' == 43) && (',' == 44) \
      && ('-' == 45) && ('.' == 46) && ('/' == 47) && ('0' == 48) \
      && ('1' == 49) && ('2' == 50) && ('3' == 51) && ('4' == 52) \
      && ('5' == 53) && ('6' == 54) && ('7' == 55) && ('8' == 56) \
      && ('9' == 57) && (':' == 58) && (';' == 59) && ('<' == 60) \
      && ('=' == 61) && ('>' == 62) && ('?' == 63) && ('A' == 65) \
      && ('B' == 66) && ('C' == 67) && ('D' == 68) && ('E' == 69) \
      && ('F' == 70) && ('G' == 71) && ('H' == 72) && ('I' == 73) \
      && ('J' == 74) && ('K' == 75) && ('L' == 76) && ('M' == 77) \
      && ('N' == 78) && ('O' == 79) && ('P' == 80) && ('Q' == 81) \
      && ('R' == 82) && ('S' == 83) && ('T' == 84) && ('U' == 85) \
      && ('V' == 86) && ('W' == 87) && ('X' == 88) && ('Y' == 89) \
      && ('Z' == 90) && ('[' == 91) && ('\\' == 92) && (']' == 93) \
      && ('^' == 94) && ('_' == 95) && ('a' == 97) && ('b' == 98) \
      && ('c' == 99) && ('d' == 100) && ('e' == 101) && ('f' == 102) \
      && ('g' == 103) && ('h' == 104) && ('i' == 105) && ('j' == 106) \
      && ('k' == 107) && ('l' == 108) && ('m' == 109) && ('n' == 110) \
      && ('o' == 111) && ('p' == 112) && ('q' == 113) && ('r' == 114) \
      && ('s' == 115) && ('t' == 116) && ('u' == 117) && ('v' == 118) \
      && ('w' == 119) && ('x' == 120) && ('y' == 121) && ('z' == 122) \
      && ('{' == 123) && ('|' == 124) && ('}' == 125) && ('~' == 126))
/* The character set is not based on ISO-646.  */
#error "gperf generated tables don't work with this execution character set. Please report a bug to <bug-gnu-gperf@gnu.org>."
#endif

//line 2 "entities.txt"

#include "entities.h"
//line 1 "entities.txt"
struct ENTITY;
/* maximum key range = 731, duplicates = 0 */

#if (defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || defined(__cplusplus) || defined(__GNUC_STDC_INLINE__)
inline
#elif defined(__GNUC__)
__inline
#endif
static unsigned int
hash (register const char *str, register unsigned int len)
{
  static const unsigned short asso_values[] =
    {
      739, 739, 739, 739, 739, 739, 739, 739, 739, 739,
      739, 739, 739, 739, 739, 739, 739, 739, 739, 739,
      739, 739, 739, 739, 739, 739, 739, 739, 739, 739,
      739, 739, 739, 739, 739, 739, 739, 739, 739, 739,
      739, 739, 739, 739, 739, 739, 739, 739, 739,  10,
       35,  20,   0, 739, 739, 739, 739, 739, 739, 739,
      739, 739, 739, 739, 739, 175, 135,  30,  60,  95,
        5,   0,   5, 180, 739,  15,   5,   0,  15, 110,
      110, 739,   5,   5,   5, 100, 739, 739,   0,  20,
        0, 739, 739, 739, 739, 739, 739,   5,  60,  50,
        0,  15, 144, 115, 215,  10, 225,  10,  95, 125,
       25,   0,   5, 218,  90,  20,   0,  65,  35,  55,
       45, 115,   5,  15, 739, 739, 739, 739, 739, 739,
      739, 739, 739, 739, 739, 739, 739, 739, 739, 739,
      739, 739, 739, 739, 739, 739, 739, 739, 739, 739,
      739, 739, 739, 739, 739, 739, 739, 739, 739, 739,
      739, 739, 739, 739, 739, 739, 739, 739, 739, 739,
      739, 739, 739, 739, 739, 739, 739, 739, 739, 739,
      739, 739, 739, 739, 739, 739, 739, 739, 739, 739,
      739, 739, 739, 739, 739, 739, 739, 739, 739, 739,
      739, 739, 739, 739, 739, 739, 739, 739, 739, 739,
      739, 739, 739, 739, 739, 739, 739, 739, 739, 739,
      739, 739, 739, 739, 739, 739, 739, 739, 739, 739,
      739, 739, 739, 739, 739, 739, 739, 739, 739, 739,
      739, 739, 739, 739, 739, 739, 739, 739, 739, 739,
      739, 739, 739, 739, 739, 739, 739
    };
  register int hval = len;

  switch (hval)
    {
      default:
        hval += asso_values[(unsigned char)str[4]];
      /*FALLTHROUGH*/
      case 4:
      case 3:
        hval += asso_values[(unsigned char)str[2]];
      /*FALLTHROUGH*/
      case 2:
        hval += asso_values[(unsigned char)str[1]+1];
      /*FALLTHROUGH*/
      case 1:
        hval += asso_values[(unsigned char)str[0]];
        break;
    }
  return hval + asso_values[(unsigned char)str[len - 1]];
}

#ifdef __GNUC__
__inline
#if defined __GNUC_STDC_INLINE__ || defined __GNUC_GNU_INLINE__
__attribute__ ((__gnu_inline__))
#endif
#endif
const struct ENTITY *
entity_lookup (register const char *str, register unsigned int len)
{
  enum
    {
      TOTAL_KEYWORDS = 253,
      MIN_WORD_LENGTH = 2,
      MAX_WORD_LENGTH = 8,
      MIN_HASH_VALUE = 8,
      MAX_HASH_VALUE = 738
    };

  static const struct ENTITY wordlist[] =
    {
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
//line 226 "entities.txt"
      {"and", 0x2227},
      {""}, {""}, {""}, {""},
//line 230 "entities.txt"
      {"int", 0x222B},
      {""}, {""}, {""}, {""},
//line 152 "entities.txt"
      {"Rho", 0x03A1},
      {""}, {""}, {""}, {""}, {""},
//line 168 "entities.txt"
      {"iota", 0x03B9},
      {""}, {""}, {""},
//line 183 "entities.txt"
      {"psi", 0x03C8},
//line 218 "entities.txt"
      {"prod", 0x220F},
      {""}, {""}, {""},
//line 23 "entities.txt"
      {"not", 0xAC},
//line 223 "entities.txt"
      {"prop", 0x221D},
      {""}, {""}, {""},
//line 181 "entities.txt"
      {"phi", 0x03C6},
//line 247 "entities.txt"
      {"sdot", 0x22C5},
//line 167 "entities.txt"
      {"theta", 0x03B8},
//line 109 "entities.txt"
      {"Scaron", 0x0160},
      {""},
//line 7 "entities.txt"
      {"amp", 0x26},
//line 114 "entities.txt"
      {"ensp", 0x2002},
//line 143 "entities.txt"
      {"Theta", 0x0398},
//line 231 "entities.txt"
      {"there4", 0x2234},
      {""}, {""},
//line 215 "entities.txt"
      {"isin", 0x2208},
      {""},
//line 116 "entities.txt"
      {"thinsp", 0x2009},
      {""}, {""}, {""},
//line 184 "entities.txt"
      {"omega", 0x03C9},
//line 110 "entities.txt"
      {"scaron", 0x0161},
      {""}, {""}, {""},
//line 197 "entities.txt"
      {"trade", 0x2122},
      {""}, {""},
//line 157 "entities.txt"
      {"Chi", 0x03A7},
      {""},
//line 105 "entities.txt"
      {"thorn", 0xFE},
      {""}, {""},
//line 240 "entities.txt"
      {"sup", 0x2283},
//line 115 "entities.txt"
      {"emsp", 0x2003},
//line 190 "entities.txt"
      {"prime", 0x2032},
      {""}, {""}, {""},
//line 36 "entities.txt"
      {"sup1", 0xB9},
//line 195 "entities.txt"
      {"image", 0x2111},
      {""}, {""}, {""},
//line 243 "entities.txt"
      {"supe", 0x2287},
//line 14 "entities.txt"
      {"pound", 0xA3},
      {""}, {""},
//line 182 "entities.txt"
      {"chi", 0x03C7},
//line 30 "entities.txt"
      {"sup3", 0xB3},
//line 216 "entities.txt"
      {"notin", 0x2209},
      {""}, {""}, {""}, {""},
//line 169 "entities.txt"
      {"kappa", 0x03BA},
      {""}, {""},
//line 166 "entities.txt"
      {"eta", 0x03B7},
      {""},
//line 145 "entities.txt"
      {"Kappa", 0x039A},
//line 96 "entities.txt"
      {"otilde", 0xF5},
      {""},
//line 229 "entities.txt"
      {"cup", 0x222A},
//line 29 "entities.txt"
      {"sup2", 0xB2},
      {""},
//line 78 "entities.txt"
      {"atilde", 0xE3},
//line 147 "entities.txt"
      {"Mu", 0x039C},
//line 176 "entities.txt"
      {"rho", 0x03C1},
//line 11 "entities.txt"
      {"nbsp", 0xA0},
//line 31 "entities.txt"
      {"acute", 0xB4},
      {""}, {""}, {""}, {""}, {""},
//line 60 "entities.txt"
      {"Ntilde", 0xD1},
//line 227 "entities.txt"
      {"or", 0x2228},
//line 254 "entities.txt"
      {"loz", 0x25CA},
      {""},
//line 95 "entities.txt"
      {"ocirc", 0xF4},
//line 245 "entities.txt"
      {"otimes", 0x2297},
//line 148 "entities.txt"
      {"Nu", 0x039D},
      {""}, {""},
//line 77 "entities.txt"
      {"acirc", 0xE2},
//line 92 "entities.txt"
      {"ntilde", 0xF1},
      {""},
//line 228 "entities.txt"
      {"cap", 0x2229},
      {""},
//line 89 "entities.txt"
      {"icirc", 0xEE},
      {""},
//line 172 "entities.txt"
      {"nu", 0x03BD},
      {""}, {""},
//line 85 "entities.txt"
      {"ecirc", 0xEA},
//line 94 "entities.txt"
      {"oacute", 0xF3},
      {""},
//line 158 "entities.txt"
      {"Psi", 0x03A8},
//line 242 "entities.txt"
      {"sube", 0x2286},
//line 234 "entities.txt"
      {"asymp", 0x2248},
//line 76 "entities.txt"
      {"aacute", 0xE1},
      {""}, {""}, {""}, {""},
//line 88 "entities.txt"
      {"iacute", 0xED},
      {""},
//line 156 "entities.txt"
      {"Phi", 0x03A6},
//line 134 "entities.txt"
      {"euro", 0x20AC},
//line 212 "entities.txt"
      {"exist", 0x2203},
//line 84 "entities.txt"
      {"eacute", 0xE9},
      {""}, {""},
//line 37 "entities.txt"
      {"ordm", 0xBA},
//line 160 "entities.txt"
      {"alpha", 0x03B1},
//line 72 "entities.txt"
      {"Yacute", 0xDD},
      {""},
//line 141 "entities.txt"
      {"Zeta", 0x0396},
//line 241 "entities.txt"
      {"nsub", 0x2284},
      {""},
//line 50 "entities.txt"
      {"Ccedil", 0xC7},
//line 174 "entities.txt"
      {"omicron", 0x03BF},
//line 165 "entities.txt"
      {"zeta", 0x03B6},
//line 211 "entities.txt"
      {"part", 0x2202},
//line 214 "entities.txt"
      {"nabla", 0x2207},
      {""},
//line 9 "entities.txt"
      {"lt", 0x3C},
//line 185 "entities.txt"
      {"thetasym", 0x03D1},
//line 33 "entities.txt"
      {"para", 0xB6},
//line 159 "entities.txt"
      {"Omega", 0x03A9},
//line 133 "entities.txt"
      {"rsaquo", 0x203A},
      {""},
//line 21 "entities.txt"
      {"ordf", 0xAA},
      {""},
//line 192 "entities.txt"
      {"oline", 0x203E},
//line 132 "entities.txt"
      {"lsaquo", 0x2039},
      {""},
//line 142 "entities.txt"
      {"Eta", 0x0397},
      {""},
//line 191 "entities.txt"
      {"Prime", 0x2033},
//line 82 "entities.txt"
      {"ccedil", 0xE7},
      {""},
//line 239 "entities.txt"
      {"sub", 0x2282},
//line 20 "entities.txt"
      {"copy", 0xA9},
//line 102 "entities.txt"
      {"ucirc", 0xFB},
//line 221 "entities.txt"
      {"lowast", 0x2217},
//line 10 "entities.txt"
      {"gt", 0x3E},
      {""}, {""},
//line 39 "entities.txt"
      {"frac14", 0xBC},
//line 235 "entities.txt"
      {"ne", 0x2260},
      {""}, {""}, {""}, {""},
//line 42 "entities.txt"
      {"iquest", 0xBF},
      {""},
//line 179 "entities.txt"
      {"tau", 0x03C4},
//line 144 "entities.txt"
      {"Iota", 0x0399},
//line 41 "entities.txt"
      {"frac34", 0xBE},
//line 101 "entities.txt"
      {"uacute", 0xFA},
      {""},
//line 154 "entities.txt"
      {"Tau", 0x03A4},
//line 233 "entities.txt"
      {"cong", 0x2245},
//line 138 "entities.txt"
      {"Gamma", 0x0393},
//line 146 "entities.txt"
      {"Lambda", 0x039B},
      {""}, {""}, {""}, {""},
//line 64 "entities.txt"
      {"Otilde", 0xD5},
      {""},
//line 59 "entities.txt"
      {"ETH", 0xD0},
//line 224 "entities.txt"
      {"infin", 0x221E},
//line 53 "entities.txt"
      {"Ecirc", 0xCA},
      {""}, {""},
//line 161 "entities.txt"
      {"beta", 0x03B2},
      {""},
//line 70 "entities.txt"
      {"Ucirc", 0xDB},
//line 17 "entities.txt"
      {"brvbar", 0xA6},
      {""},
//line 18 "entities.txt"
      {"sect", 0xA7},
      {""},
//line 40 "entities.txt"
      {"frac12", 0xBD},
//line 15 "entities.txt"
      {"curren", 0xA4},
      {""},
//line 13 "entities.txt"
      {"cent", 0xA2},
      {""},
//line 63 "entities.txt"
      {"Ocirc", 0xD4},
//line 52 "entities.txt"
      {"Eacute", 0xC9},
//line 171 "entities.txt"
      {"mu", 0x03BC},
      {""}, {""}, {""},
//line 69 "entities.txt"
      {"Uacute", 0xDA},
      {""}, {""}, {""}, {""}, {""},
//line 149 "entities.txt"
      {"Xi", 0x039E},
//line 225 "entities.txt"
      {"ang", 0x2220},
      {""}, {""},
//line 62 "entities.txt"
      {"Oacute", 0xD3},
//line 175 "entities.txt"
      {"pi", 0x03C0},
      {""},
//line 202 "entities.txt"
      {"darr", 0x2193},
//line 236 "entities.txt"
      {"equiv", 0x2261},
//line 104 "entities.txt"
      {"yacute", 0xFD},
//line 8 "entities.txt"
      {"apos", 0x27},
//line 246 "entities.txt"
      {"perp", 0x22A5},
      {""}, {""}, {""}, {""}, {""},
//line 163 "entities.txt"
      {"delta", 0x03B4},
//line 222 "entities.txt"
      {"radic", 0x221A},
//line 237 "entities.txt"
      {"le", 0x2264},
//line 6 "entities.txt"
      {"quot", 0x22},
      {""},
//line 97 "entities.txt"
      {"ouml", 0xF6},
//line 204 "entities.txt"
      {"crarr", 0x21B5},
      {""},
//line 217 "entities.txt"
      {"ni", 0x220B},
//line 24 "entities.txt"
      {"shy", 0xAD},
//line 79 "entities.txt"
      {"auml", 0xE4},
      {""}, {""},
//line 150 "entities.txt"
      {"Omicron", 0x039F},
      {""},
//line 90 "entities.txt"
      {"iuml", 0xEF},
//line 80 "entities.txt"
      {"aring", 0xE5},
//line 46 "entities.txt"
      {"Atilde", 0xC3},
      {""}, {""},
//line 86 "entities.txt"
      {"euml", 0xEB},
//line 258 "entities.txt"
      {"diams", 0x2666},
//line 238 "entities.txt"
      {"ge", 0x2265},
      {""}, {""},
//line 111 "entities.txt"
      {"Yuml", 0x0178},
//line 213 "entities.txt"
      {"empty", 0x2205},
//line 98 "entities.txt"
      {"divide", 0xF7},
//line 173 "entities.txt"
      {"xi", 0x03BE},
//line 19 "entities.txt"
      {"uml", 0xA8},
//line 255 "entities.txt"
      {"spades", 0x2660},
//line 256 "entities.txt"
      {"clubs", 0x2663},
//line 129 "entities.txt"
      {"dagger", 0x2020},
      {""},
//line 137 "entities.txt"
      {"Beta", 0x0392},
//line 188 "entities.txt"
      {"bull", 0x2022},
//line 45 "entities.txt"
      {"Acirc", 0xC2},
//line 170 "entities.txt"
      {"lambda", 0x03BB},
//line 135 "entities.txt"
      {"fnof", 0x0192},
//line 125 "entities.txt"
      {"sbquo", 0x201A},
//line 253 "entities.txt"
      {"rang", 0x232A},
//line 57 "entities.txt"
      {"Icirc", 0xCE},
      {""},
//line 198 "entities.txt"
      {"alefsym", 0x2135},
//line 128 "entities.txt"
      {"bdquo", 0x201E},
//line 252 "entities.txt"
      {"lang", 0x2329},
//line 249 "entities.txt"
      {"rceil", 0x2309},
      {""}, {""},
//line 187 "entities.txt"
      {"piv", 0x03D6},
//line 117 "entities.txt"
      {"zwnj", 0x200C},
//line 248 "entities.txt"
      {"lceil", 0x2308},
//line 44 "entities.txt"
      {"Aacute", 0xC1},
      {""},
//line 219 "entities.txt"
      {"sum", 0x2211},
//line 200 "entities.txt"
      {"uarr", 0x2191},
//line 194 "entities.txt"
      {"weierp", 0x2118},
//line 56 "entities.txt"
      {"Iacute", 0xCD},
//line 16 "entities.txt"
      {"yen", 0xA5},
//line 124 "entities.txt"
      {"rsquo", 0x2019},
//line 139 "entities.txt"
      {"Delta", 0x0394},
//line 162 "entities.txt"
      {"gamma", 0x03B3},
      {""}, {""},
//line 123 "entities.txt"
      {"lsquo", 0x2018},
//line 208 "entities.txt"
      {"dArr", 0x21D3},
//line 136 "entities.txt"
      {"Alpha", 0x0391},
      {""}, {""}, {""},
//line 103 "entities.txt"
      {"uuml", 0xFC},
      {""}, {""}, {""},
//line 127 "entities.txt"
      {"rdquo", 0x201D},
//line 26 "entities.txt"
      {"macr", 0xAF},
//line 73 "entities.txt"
      {"THORN", 0xDE},
      {""}, {""},
//line 126 "entities.txt"
      {"ldquo", 0x201C},
//line 201 "entities.txt"
      {"rarr", 0x2192},
      {""},
//line 99 "entities.txt"
      {"oslash", 0xF8},
      {""},
//line 196 "entities.txt"
      {"real", 0x211C},
//line 199 "entities.txt"
      {"larr", 0x2190},
      {""}, {""}, {""}, {""}, {""}, {""},
//line 130 "entities.txt"
      {"Dagger", 0x2021},
//line 151 "entities.txt"
      {"Pi", 0x03A0},
      {""}, {""},
//line 131 "entities.txt"
      {"permil", 0x2030},
//line 28 "entities.txt"
      {"plusmn", 0xB1},
      {""}, {""},
//line 54 "entities.txt"
      {"Euml", 0xCB},
//line 113 "entities.txt"
      {"tilde", 0x02DC},
//line 34 "entities.txt"
      {"middot", 0xB7},
      {""},
//line 244 "entities.txt"
      {"oplus", 0x2295},
//line 71 "entities.txt"
      {"Uuml", 0xDC},
//line 153 "entities.txt"
      {"Sigma", 0x03A3},
//line 93 "entities.txt"
      {"ograve", 0xF2},
      {""}, {""},
//line 193 "entities.txt"
      {"frasl", 0x2044},
//line 74 "entities.txt"
      {"szlig", 0xDF},
//line 75 "entities.txt"
      {"agrave", 0xE0},
      {""},
//line 119 "entities.txt"
      {"lrm", 0x200E},
//line 65 "entities.txt"
      {"Ouml", 0xD6},
      {""},
//line 87 "entities.txt"
      {"igrave", 0xEC},
      {""},
//line 38 "entities.txt"
      {"raquo", 0xBB},
//line 106 "entities.txt"
      {"yuml", 0xFF},
//line 178 "entities.txt"
      {"sigma", 0x03C3},
//line 83 "entities.txt"
      {"egrave", 0xE8},
//line 27 "entities.txt"
      {"deg", 0xB0},
//line 22 "entities.txt"
      {"laquo", 0xAB},
      {""},
//line 164 "entities.txt"
      {"epsilon", 0x03B5},
      {""}, {""}, {""},
//line 206 "entities.txt"
      {"uArr", 0x21D1},
      {""}, {""}, {""}, {""},
//line 35 "entities.txt"
      {"cedil", 0xB8},
//line 257 "entities.txt"
      {"hearts", 0x2665},
      {""}, {""}, {""},
//line 12 "entities.txt"
      {"iexcl", 0xA1},
//line 66 "entities.txt"
      {"times", 0xD7},
//line 251 "entities.txt"
      {"rfloor", 0x230B},
      {""}, {""}, {""}, {""},
//line 250 "entities.txt"
      {"lfloor", 0x230A},
      {""}, {""}, {""},
//line 32 "entities.txt"
      {"micro", 0xB5},
      {""}, {""}, {""},
//line 207 "entities.txt"
      {"rArr", 0x21D2},
      {""}, {""}, {""}, {""},
//line 205 "entities.txt"
      {"lArr", 0x21D0},
      {""}, {""}, {""}, {""},
//line 112 "entities.txt"
      {"circ", 0x02C6},
//line 220 "entities.txt"
      {"minus", 0x2212},
      {""}, {""}, {""}, {""}, {""},
//line 100 "entities.txt"
      {"ugrave", 0xF9},
      {""}, {""}, {""},
//line 180 "entities.txt"
      {"upsilon", 0x03C5},
      {""}, {""}, {""},
//line 47 "entities.txt"
      {"Auml", 0xC4},
//line 210 "entities.txt"
      {"forall", 0x2200},
      {""}, {""}, {""},
//line 58 "entities.txt"
      {"Iuml", 0xCF},
//line 48 "entities.txt"
      {"Aring", 0xC5},
      {""}, {""}, {""}, {""},
//line 107 "entities.txt"
      {"OElig", 0x0152},
//line 67 "entities.txt"
      {"Oslash", 0xD8},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
//line 51 "entities.txt"
      {"Egrave", 0xC8},
      {""}, {""},
//line 203 "entities.txt"
      {"harr", 0x2194},
//line 140 "entities.txt"
      {"Epsilon", 0x0395},
//line 68 "entities.txt"
      {"Ugrave", 0xD9},
      {""}, {""}, {""},
//line 155 "entities.txt"
      {"Upsilon", 0x03A5},
      {""},
//line 25 "entities.txt"
      {"reg", 0xAE},
//line 120 "entities.txt"
      {"rlm", 0x200F},
      {""}, {""},
//line 61 "entities.txt"
      {"Ograve", 0xD2},
      {""}, {""},
//line 108 "entities.txt"
      {"oelig", 0x0153},
//line 189 "entities.txt"
      {"hellip", 0x2026},
      {""}, {""}, {""},
//line 81 "entities.txt"
      {"aelig", 0xE6},
//line 121 "entities.txt"
      {"ndash", 0x2013},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
//line 232 "entities.txt"
      {"sim", 0x223C},
      {""}, {""}, {""}, {""},
//line 118 "entities.txt"
      {"zwj", 0x200D},
      {""}, {""}, {""}, {""}, {""}, {""},
//line 49 "entities.txt"
      {"AElig", 0xC6},
      {""}, {""},
//line 91 "entities.txt"
      {"eth", 0xF0},
      {""},
//line 177 "entities.txt"
      {"sigmaf", 0x03C2},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
//line 209 "entities.txt"
      {"hArr", 0x21D4},
      {""},
//line 43 "entities.txt"
      {"Agrave", 0xC0},
      {""}, {""}, {""}, {""},
//line 55 "entities.txt"
      {"Igrave", 0xCC},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""},
//line 122 "entities.txt"
      {"mdash", 0x2014},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
//line 186 "entities.txt"
      {"upsih", 0x03D2}
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      register int key = hash (str, len);

      if (key <= MAX_HASH_VALUE && key >= 0)
        {
          register const char *s = wordlist[key].name;

          if (*str == *s && !strcmp (str + 1, s + 1))
            return &wordlist[key];
        }
    }
  return 0;
}
