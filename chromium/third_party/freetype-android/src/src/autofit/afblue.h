/* This file has been generated by the Perl script `afblue.pl', */
/* using data from file `afblue.dat'.                           */

/***************************************************************************/
/*                                                                         */
/*  afblue.h                                                               */
/*                                                                         */
/*    Auto-fitter data for blue strings (specification).                   */
/*                                                                         */
/*  Copyright 2013-2015 by                                                 */
/*  David Turner, Robert Wilhelm, and Werner Lemberg.                      */
/*                                                                         */
/*  This file is part of the FreeType project, and may only be used,       */
/*  modified, and distributed under the terms of the FreeType project      */
/*  license, LICENSE.TXT.  By continuing to use, modify, or distribute     */
/*  this file you indicate that you have read the license and              */
/*  understand and accept it fully.                                        */
/*                                                                         */
/***************************************************************************/


#ifndef __AFBLUE_H__
#define __AFBLUE_H__


FT_BEGIN_HEADER


  /* an auxiliary macro to decode a UTF-8 character -- since we only use */
  /* hard-coded, self-converted data, no error checking is performed     */
#define GET_UTF8_CHAR( ch, p )                      \
          do                                        \
          {                                         \
            ch = (unsigned char)*p++;               \
            if ( ch >= 0x80 )                       \
            {                                       \
              FT_UInt  len_;                        \
                                                    \
                                                    \
              if ( ch < 0xE0 )                      \
              {                                     \
                len_ = 1;                           \
                ch  &= 0x1F;                        \
              }                                     \
              else if ( ch < 0xF0 )                 \
              {                                     \
                len_ = 2;                           \
                ch  &= 0x0F;                        \
              }                                     \
              else                                  \
              {                                     \
                len_ = 3;                           \
                ch  &= 0x07;                        \
              }                                     \
                                                    \
              for ( ; len_ > 0; len_-- )            \
                ch = ( ch << 6 ) | ( *p++ & 0x3F ); \
            }                                       \
          } while ( 0 )


  /*************************************************************************/
  /*************************************************************************/
  /*****                                                               *****/
  /*****                    B L U E   S T R I N G S                    *****/
  /*****                                                               *****/
  /*************************************************************************/
  /*************************************************************************/

  /* At the bottommost level, we define strings for finding blue zones. */


#define AF_BLUE_STRING_MAX_LEN  51

  /* The AF_Blue_String enumeration values are offsets into the */
  /* `af_blue_strings' array.                                   */

  typedef enum  AF_Blue_String_
  {
    AF_BLUE_STRING_ARABIC_TOP = 0,
    AF_BLUE_STRING_ARABIC_BOTTOM = 18,
    AF_BLUE_STRING_ARABIC_JOIN = 33,
    AF_BLUE_STRING_CYRILLIC_CAPITAL_TOP = 36,
    AF_BLUE_STRING_CYRILLIC_CAPITAL_BOTTOM = 60,
    AF_BLUE_STRING_CYRILLIC_SMALL = 84,
    AF_BLUE_STRING_CYRILLIC_SMALL_DESCENDER = 108,
    AF_BLUE_STRING_DEVANAGARI_BASE = 117,
    AF_BLUE_STRING_DEVANAGARI_TOP = 149,
    AF_BLUE_STRING_DEVANAGARI_HEAD = 181,
    AF_BLUE_STRING_DEVANAGARI_BOTTOM = 213,
    AF_BLUE_STRING_GREEK_CAPITAL_TOP = 221,
    AF_BLUE_STRING_GREEK_CAPITAL_BOTTOM = 242,
    AF_BLUE_STRING_GREEK_SMALL_BETA_TOP = 260,
    AF_BLUE_STRING_GREEK_SMALL = 278,
    AF_BLUE_STRING_GREEK_SMALL_DESCENDER = 302,
    AF_BLUE_STRING_HEBREW_TOP = 326,
    AF_BLUE_STRING_HEBREW_BOTTOM = 350,
    AF_BLUE_STRING_HEBREW_DESCENDER = 368,
    AF_BLUE_STRING_KHMER_TOP = 383,
    AF_BLUE_STRING_KHMER_SUBSCRIPT_TOP = 407,
    AF_BLUE_STRING_KHMER_BOTTOM = 447,
    AF_BLUE_STRING_KHMER_DESCENDER = 479,
    AF_BLUE_STRING_KHMER_LARGE_DESCENDER = 513,
    AF_BLUE_STRING_KHMER_SYMBOLS_WAXING_TOP = 600,
    AF_BLUE_STRING_KHMER_SYMBOLS_WANING_BOTTOM = 608,
    AF_BLUE_STRING_LAO_TOP = 616,
    AF_BLUE_STRING_LAO_BOTTOM = 648,
    AF_BLUE_STRING_LAO_ASCENDER = 680,
    AF_BLUE_STRING_LAO_LARGE_ASCENDER = 696,
    AF_BLUE_STRING_LAO_DESCENDER = 708,
    AF_BLUE_STRING_LATIN_CAPITAL_TOP = 732,
    AF_BLUE_STRING_LATIN_CAPITAL_BOTTOM = 748,
    AF_BLUE_STRING_LATIN_SMALL_F_TOP = 764,
    AF_BLUE_STRING_LATIN_SMALL = 778,
    AF_BLUE_STRING_LATIN_SMALL_DESCENDER = 792,
    AF_BLUE_STRING_LATIN_SUBS_CAPITAL_TOP = 802,
    AF_BLUE_STRING_LATIN_SUBS_CAPITAL_BOTTOM = 822,
    AF_BLUE_STRING_LATIN_SUBS_SMALL_F_TOP = 842,
    AF_BLUE_STRING_LATIN_SUBS_SMALL = 862,
    AF_BLUE_STRING_LATIN_SUBS_SMALL_DESCENDER = 898,
    AF_BLUE_STRING_LATIN_SUPS_CAPITAL_TOP = 918,
    AF_BLUE_STRING_LATIN_SUPS_CAPITAL_BOTTOM = 949,
    AF_BLUE_STRING_LATIN_SUPS_SMALL_F_TOP = 978,
    AF_BLUE_STRING_LATIN_SUPS_SMALL = 1004,
    AF_BLUE_STRING_LATIN_SUPS_SMALL_DESCENDER = 1029,
    AF_BLUE_STRING_MYANMAR_TOP = 1040,
    AF_BLUE_STRING_MYANMAR_BOTTOM = 1072,
    AF_BLUE_STRING_MYANMAR_ASCENDER = 1104,
    AF_BLUE_STRING_MYANMAR_DESCENDER = 1132,
    AF_BLUE_STRING_TELUGU_TOP = 1164,
    AF_BLUE_STRING_TELUGU_BOTTOM = 1192,
    AF_BLUE_STRING_THAI_TOP = 1220,
    AF_BLUE_STRING_THAI_BOTTOM = 1244,
    AF_BLUE_STRING_THAI_ASCENDER = 1272,
    AF_BLUE_STRING_THAI_LARGE_ASCENDER = 1284,
    AF_BLUE_STRING_THAI_DESCENDER = 1296,
    AF_BLUE_STRING_THAI_LARGE_DESCENDER = 1312,
    AF_BLUE_STRING_THAI_DIGIT_TOP = 1320,
    af_blue_1_1 = 1331,
#ifdef AF_CONFIG_OPTION_CJK
    AF_BLUE_STRING_CJK_TOP = af_blue_1_1 + 1,
    AF_BLUE_STRING_CJK_BOTTOM = af_blue_1_1 + 203,
    af_blue_1_1_1 = af_blue_1_1 + 404,
#ifdef AF_CONFIG_OPTION_CJK_BLUE_HANI_VERT
    AF_BLUE_STRING_CJK_LEFT = af_blue_1_1_1 + 1,
    AF_BLUE_STRING_CJK_RIGHT = af_blue_1_1_1 + 204,
    af_blue_1_1_2 = af_blue_1_1_1 + 405,
#else
    af_blue_1_1_2 = af_blue_1_1_1 + 0,
#endif /* AF_CONFIG_OPTION_CJK_BLUE_HANI_VERT */
    af_blue_1_2 = af_blue_1_1_2 + 0,
#else
    af_blue_1_2 = af_blue_1_1 + 0,
#endif /* AF_CONFIG_OPTION_CJK                */


    AF_BLUE_STRING_MAX   /* do not remove */

  } AF_Blue_String;


  FT_LOCAL_ARRAY( char )
  af_blue_strings[];


  /*************************************************************************/
  /*************************************************************************/
  /*****                                                               *****/
  /*****                 B L U E   S T R I N G S E T S                 *****/
  /*****                                                               *****/
  /*************************************************************************/
  /*************************************************************************/

  /* The next level is to group blue strings into style-specific sets. */


  /* Properties are specific to a writing system.  We assume that a given  */
  /* blue string can't be used in more than a single writing system, which */
  /* is a safe bet.                                                        */
#define AF_BLUE_PROPERTY_LATIN_TOP       ( 1U << 0 )  /* must have value 1 */
#define AF_BLUE_PROPERTY_LATIN_SUB_TOP   ( 1U << 1 )
#define AF_BLUE_PROPERTY_LATIN_NEUTRAL   ( 1U << 2 )
#define AF_BLUE_PROPERTY_LATIN_X_HEIGHT  ( 1U << 3 )
#define AF_BLUE_PROPERTY_LATIN_LONG      ( 1U << 4 )

#define AF_BLUE_PROPERTY_CJK_TOP    ( 1U << 0 )       /* must have value 1 */
#define AF_BLUE_PROPERTY_CJK_HORIZ  ( 1U << 1 )       /* must have value 2 */
#define AF_BLUE_PROPERTY_CJK_RIGHT  AF_BLUE_PROPERTY_CJK_TOP


#define AF_BLUE_STRINGSET_MAX_LEN  8

  /* The AF_Blue_Stringset enumeration values are offsets into the */
  /* `af_blue_stringsets' array.                                   */

  typedef enum  AF_Blue_Stringset_
  {
    AF_BLUE_STRINGSET_ARAB = 0,
    AF_BLUE_STRINGSET_CYRL = 4,
    AF_BLUE_STRINGSET_DEVA = 10,
    AF_BLUE_STRINGSET_GREK = 16,
    AF_BLUE_STRINGSET_HEBR = 23,
    AF_BLUE_STRINGSET_KHMR = 27,
    AF_BLUE_STRINGSET_KHMS = 33,
    AF_BLUE_STRINGSET_LAO = 36,
    AF_BLUE_STRINGSET_LATN = 42,
    AF_BLUE_STRINGSET_LATB = 49,
    AF_BLUE_STRINGSET_LATP = 56,
    AF_BLUE_STRINGSET_MYMR = 63,
    AF_BLUE_STRINGSET_TELU = 68,
    AF_BLUE_STRINGSET_THAI = 71,
    af_blue_2_1 = 79,
#ifdef AF_CONFIG_OPTION_CJK
    AF_BLUE_STRINGSET_HANI = af_blue_2_1 + 0,
    af_blue_2_1_1 = af_blue_2_1 + 2,
#ifdef AF_CONFIG_OPTION_CJK_BLUE_HANI_VERT
    af_blue_2_1_2 = af_blue_2_1_1 + 2,
#else
    af_blue_2_1_2 = af_blue_2_1_1 + 0,
#endif /* AF_CONFIG_OPTION_CJK_BLUE_HANI_VERT */
    af_blue_2_2 = af_blue_2_1_2 + 1,
#else
    af_blue_2_2 = af_blue_2_1 + 0,
#endif /* AF_CONFIG_OPTION_CJK                */


    AF_BLUE_STRINGSET_MAX   /* do not remove */

  } AF_Blue_Stringset;


  typedef struct  AF_Blue_StringRec_
  {
    AF_Blue_String  string;
    FT_UShort       properties;

  } AF_Blue_StringRec;


  FT_LOCAL_ARRAY( AF_Blue_StringRec )
  af_blue_stringsets[];

/* */

FT_END_HEADER


#endif /* __AFBLUE_H__ */


/* END */