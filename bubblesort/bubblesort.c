#include "devscc.h"
#include "e-types.h"
#include "sf-types.h"
#include "sh7708.h"

int main(void) {
    uchar bsort_input[] = {
        240, 219, 60,  161, 247, 31,  132, 99,  78,  28,  66,  184, 201, 209,
        26,  135, 217, 64,  119, 222, 79,  236, 52,  145, 205, 152, 96,  22,
        47,  137, 242, 104, 175, 131, 89,  5,   199, 108, 176, 155, 86,  136,
        249, 233, 61,  250, 197, 255, 214, 117, 211, 240, 1,   16,  101, 155,
        161, 2,   158, 97,  234, 194, 213, 73,  253, 93,  208, 231, 56,  42,
        36,  147, 237, 196, 187, 196, 116, 173, 64,  6,   20,  101, 161, 146,
        103, 64,  238, 234, 171, 42,  119, 173, 137, 82,  82,  9,   82,  38,
        239, 40,  201, 19,  204, 126, 127, 56,  110, 45,  70,  11,  69,  223,
        29,  79,  11,  100, 184, 180, 37,  36,  236, 116, 112, 210, 221, 74,
        236, 140, 28,  164, 124, 1,   160, 230, 76,  77,  238, 211, 92,  231,
        198, 203, 52,  191, 213, 221, 139, 203, 149, 133, 252, 17,  152, 172,
        31,  3,   163, 151, 37,  11,  158, 213, 11,  93,  214, 110, 167, 57,
        77,  138, 225, 144, 138, 53,  148, 181, 230, 208, 255, 11,  247, 5,
        117, 88,  132, 96,  123, 155, 196, 162, 108, 233, 23,  188, 113, 12,
        242, 29,  254, 135, 79,  253, 112, 223, 164, 240, 139, 167, 143, 100,
        218, 22,  97,  218, 152, 128, 37,  119, 221, 205, 191, 166, 145, 30,
        126, 84,  219, 98,  177, 12,  77,  23,  173, 141, 160, 27,  236, 154,
        62,  116, 60,  41,  68,  159, 83,  192, 105, 103, 89,  151, 46,  174,
        167, 153, 29,  60,  76,  69,  221, 65,  239, 227, 188, 212, 216, 141,
        98,  9,   127, 174, 131, 88,  59,  190, 13,  191, 193, 164, 78,  32,
        88,  86,  153, 5,   97,  173, 20,  160, 16,  141, 65,  208, 5,   16,
        139, 11,  193, 181, 7,   71,  21,  94,  76,  108, 21,  5,   85,  78,
        113, 60,  18,  175, 32,  214, 122, 234, 202, 14,  173, 128, 219, 47,
        139, 105, 203, 102, 190, 157, 144, 109, 110, 170, 246, 89,  140, 50,
        220, 10,  31,  198, 36,  204, 251, 245, 150, 162, 60,  146, 137, 32,
        211, 11,  197, 239, 35,  155, 10,  108, 105, 171, 171, 161, 186, 43,
        139, 201, 121, 32,  202, 125, 42,  88,  120, 53,  134, 146, 175, 10,
        9,   225, 195, 1,   236, 29,  121, 213, 187, 126, 218, 125, 127, 8,
        146, 0,   245, 171, 124, 50,  232, 61,  76,  20,  5,   64,  230, 163,
        209, 234, 81,  251, 143, 148, 1,   148, 169, 69,  167, 97,  70,  140,
        214, 137, 142, 166, 167, 165, 82,  254, 27,  64,  180, 108, 41,  230,
        91,  227, 65,  125, 66,  133, 239, 91,  110, 140, 184, 88,  88,  128,
        101, 55,  163, 154, 223, 99,  64,  57,  126, 112, 91,  190, 112, 160,
        18,  170, 83,  230, 193, 244, 66,  46,  39,  189, 125, 28,  130, 0,
        216, 42,  249, 224, 215, 222, 51,  253, 84,  67,  210, 4,   185, 62,
        195, 168, 142, 78,  2,   205, 243, 178, 213, 163, 155, 249, 159, 234,
        112, 93,  142, 250, 171, 187, 47,  194, 225, 170, 133, 159, 144, 239,
        116, 117, 242, 86,  77,  213, 151, 47,  115, 146, 136, 199, 136, 208,
        203, 26,  219, 60,  224, 70,  14,  28,  161, 150, 108, 199, 154, 230,
        4,   224, 14,  185, 140, 231, 255, 16,  247, 185, 2,   82,  66,  119,
        220, 58,  69,  125, 172, 63,  8,   71,  143, 237, 204, 246, 75,  207,
        220, 131, 176, 66,  220, 215, 184, 26,  198, 86,  227, 43,  147, 224,
        114, 217, 174, 36,  41,  221, 202, 36,  204, 36,  141, 227, 83,  11,
        2,   168, 239, 71,  210, 74,  189, 101, 177, 22,  111, 210, 190, 25,
        174, 164, 29,  154, 21,  151, 69,  90,  1,   217, 166, 190, 29,  30,
        147, 233, 234, 95,  34,  33,  59,  31,  90,  17,  53,  122, 219, 51,
        216, 149, 189, 133, 205, 100, 192, 163, 107, 73,  237, 188, 67,  209,
        70,  25,  234, 30,  214, 10,  122, 105, 235, 165, 87,  235, 30,  191,
        207, 120, 144, 129, 192, 29,  223, 204, 130, 223, 160, 74,  207, 236,
        182, 25,  19,  235, 154, 213, 100, 54,  115, 133, 60,  23,  127, 139,
        84,  60,  106, 192, 232, 97,  39,  89,  50,  153, 93,  103, 134, 125,
        36,  136, 164, 129, 157, 128, 13,  255, 197, 222, 134, 146, 42,  181,
        158, 6,   54,  52,  124, 148, 87,  232, 197, 147, 233, 64,  49,  207,
        206, 52,  248, 141, 76,  100, 3,   109, 177, 170, 184, 251, 233, 236,
        75,  147, 166, 101, 223, 45,  168, 237, 59,  248, 144, 213, 207, 89,
        205, 220, 148, 85,  50,  139, 194, 249, 99,  10,  30,  204, 79,  221,
        100, 236, 57,  177, 95,  232, 161, 31,  87,  26,  117, 67,  194, 190,
        230, 241, 246, 248, 3,   150, 126, 64,  158, 19,  101, 159, 253, 81,
        61,  36,  7,   44,  25,  114, 70,  11,  186, 134, 138, 185, 60,  38,
        87,  165, 169, 17,  203, 14,  19,  50,  11,  132, 72,  38,  53,  140,
        248, 83,  182, 194, 61,  253, 64,  251, 198, 40,  105, 64,  112, 80,
        139, 89,  158, 248, 177, 13,  80,  183, 166, 142, 121, 246, 69,  102,
        89,  93,  122, 187, 141, 98,  79,  21,  15,  20,  127, 194, 98,  248,
        172, 37,  56,  120, 214, 8,   224, 227, 89,  213, 183, 106, 69,  56,
        135, 204, 230, 183, 72,  76,  206, 240, 182, 22,  197, 76,  12,  9,
        195, 223, 94,  193, 90,  153, 60,  64,  20,  112, 33,  191, 197, 159,
        40,  27,  242, 25,  16,  159, 26,  194, 242, 135, 103, 134, 162, 70,
        95,  77,  178, 78,  73,  235, 4,   175, 22,  160, 205, 197, 165, 255,
        25,  227, 132, 49,  139, 252, 110, 239, 11,  57,  130, 139, 84,  130,
        248, 77,  24,  180, 252, 151, 86,  52,  203, 10,  176, 235, 233, 141,
        96,  9,   79,  25,  181, 187, 183, 55,  48,  87,  211, 244, 98,  114,
        232, 92,  119, 0,   211, 105, 99,  145, 159, 10,  239, 60,  66,  211,
        244, 44,  77,  204, 31,  0,   92,  85,  157, 226, 33,  10,  182, 156,
        151, 254, 214, 1,   6,   145, 161, 104, 3,   41,  126, 194, 227, 96,
        134, 112, 59,  47,  115, 139, 26,  75,  156, 82,  0,   73,  82,  244,
        76,  0,   139, 233, 71,  79,  46,  215, 22,  74,  71,  53,  73,  217,
        172, 156, 84,  39,  98,  156, 172, 82,  205, 75,  159, 97,  79,  66,
        35,  251, 38,  151, 63,  48,  233, 146, 57,  117, 93,  105, 169, 131,
        80,  250, 83,  46,  94,  162, 69,  239, 204, 187, 247, 231, 101, 129,
        80,  219, 194, 105, 94,  255, 18,  47,  39,  140, 223, 45,  129, 16,
        6,   59,  190, 167, 75,  148, 135, 118, 163, 209, 183, 182, 143, 49,
        166, 104, 213, 52,  181, 25,  83,  55,  211, 117, 123, 219, 35,  92,
        156, 149, 227, 240, 2,   87,  120, 27,  138, 209, 64,  233, 16,  175,
        155, 114, 96,  139, 211, 163, 210, 84,  225, 169, 175, 100, 117, 24,
        46,  105, 155, 158, 99,  144, 119, 11,  128, 67,  35,  66,  150, 252,
        193, 255, 73,  233, 219, 172, 29,  32,  48,  74,  47,  126, 188, 219,
        225, 27,  72,  104, 166, 227, 37,  92,  36,  2,   89,  231, 194, 212,
        93,  37,  240, 44,  111, 218, 201, 129, 184, 83,  83,  106, 158, 131,
        10,  75,  82,  202, 207, 90,  39,  209, 101, 53,  129, 217, 152, 170,
        85,  161, 183, 252, 63,  88,  12,  7,   81,  175, 226, 208, 76,  112,
        113, 45,  12,  161, 235, 109, 244, 183, 118, 128, 74,  193, 13,  81,
        121, 100, 104, 38,  197, 83,  72,  216, 14,  171, 40,  209, 175, 141,
        110, 229, 174, 48,  230, 165, 130, 246, 153, 229, 209, 21,  36,  118,
        122, 0,   63,  67,  8,   31,  14,  146, 139, 212, 14,  92,  40,  208,
        105, 177, 188, 173, 94,  180, 198, 155, 212, 111, 151, 213, 57,  239,
        108, 163, 50,  36,  226, 114, 247, 187, 229, 167, 56,  147, 130, 173,
        236, 140, 75,  147, 67,  111, 220, 130, 67,  143, 201, 34,  156, 143,
        19,  236, 161, 156, 215, 223, 72,  114, 177, 95,  211, 180, 4,   145,
        249, 134, 214, 127, 25,  85,  103, 86,  124, 150, 26,  231, 108, 182,
        13,  11,  124, 241, 233, 49,  83,  200, 180, 228, 143, 148, 156, 128,
        79,  239, 182, 211, 205, 244, 104, 49,  42,  44,  182, 220, 131, 137,
        232, 254, 223, 217, 223, 220, 134, 173, 198, 108, 157, 83,  50,  29,
        253, 163, 165, 201, 48,  2,   73,  17,  22,  179, 226, 5,   55,  196,
        156, 209, 207, 157, 226, 207, 166, 171, 74,  252, 2,   46,  82,  9,
        166, 238, 249, 20,  105, 219, 215, 152, 60,  134, 155, 106, 109, 148,
        55,  28,  48,  105, 201, 24,  187, 3,   229, 161, 33,  12,  255, 243,
        181, 248, 228, 150, 82,  238, 229, 115, 208, 155, 103, 109, 137, 60,
        152, 179, 156, 198, 14,  178, 134, 189, 179, 166, 99,  211, 167, 206,
        43,  199, 29,  236, 189, 255, 151, 187, 52,  224, 144, 156, 30,  145,
        178, 247, 199, 212, 249, 11,  11,  177, 25,  154, 81,  249, 56,  168,
        8,   63,  97,  210, 174, 11,  196, 22,  220, 127, 130, 187, 216, 115,
        125, 61,  15,  156, 68,  142, 68,  28,  70,  96,  227, 57,  126, 68,
        159, 27,  44,  196, 192, 132, 248, 156, 0,   222, 226, 185, 73,  232,
        59,  155, 16,  49,  163, 42,  91,  119, 150, 136, 79,  127, 179, 153,
        200, 53,  203, 92,  253, 168, 90,  12,  182, 154, 5,   115, 90,  239,
        91,  62,  8,   58,  88,  29,  166, 131, 38,  64,  143, 177, 208, 216,
        211, 99,  101, 216, 121, 56,  205, 123, 18,  160, 204, 60,  82,  196,
        131, 49,  170, 134, 150, 186, 248, 207, 233, 216, 50,  78,  50,  43,
        4,   212, 44,  87,  15,  221, 177, 113, 255, 44,  50,  213, 196, 75,
        143, 166, 17,  143, 142, 175, 136, 230, 153, 202, 106, 170, 77,  55,
        48,  244, 227, 102, 82,  135, 53,  59,  212, 143, 94,  125, 106, 37,
        122, 97,  173, 109, 53,  18,  2,   189, 230, 4,   65,  170, 236, 70,
        195, 220, 75,  186, 228, 199, 238, 139, 6,   202, 223, 211, 179, 135,
        109, 129, 111, 93,  159, 103, 206, 14,  247, 173, 60,  30,  232, 207,
        132, 225, 40,  211, 125, 23,  219, 47,  19,  240, 154, 86,  87,  81,
        26,  59,  145, 173, 84,  175, 222, 55,  221, 202, 8,   81,  153, 145,
        230, 15,  227, 40,  104, 183, 50,  158, 102, 212, 172, 153, 85,  212,
        161, 184, 244, 252, 167, 9,   168, 240, 228, 44,  149, 187, 22,  46,
        143, 212, 86,  80,  162, 18,  169, 146, 121, 242, 238, 22,  177, 150,
        201, 6,   154, 231, 62,  229, 90,  0,   156, 36,  29,  14,  45,  253,
        155, 100, 199, 123, 92,  225, 5,   14,  223, 32,  41,  44,  93,  133,
        133, 178, 242, 23,  18,  199, 39,  5,   80,  38,  205, 21,  65,  164,
        26,  119, 218, 220, 122, 230, 21,  12,  53,  253, 155, 70,  129, 161,
        6,   86,  247, 255, 214, 156, 60,  67,  150, 217, 106, 116, 30,  96,
        109, 3,   244, 208, 232, 136, 0,   77,  152, 116, 249, 144, 100, 180,
        143, 50,  119, 215, 3,   3,   99,  75,  120, 146, 180, 236, 70,  124,
        80,  27,  134, 94,  167, 211, 125, 32,  170, 9,   90,  152, 247, 215,
        190, 201, 250, 166, 44,  114, 25,  188, 140, 169, 220, 111, 39,  97,
        253, 240, 110, 115, 19,  237, 121, 119, 239, 164, 82,  155, 10,  218,
        159, 248, 89,  141, 210, 97,  181, 40,  11,  20,  35,  77,  176, 246,
        4,   103, 61,  31,  154, 227, 98,  61,  22,  151, 47,  251, 81,  157,
        78,  57,  222, 38,  80,  223, 67,  36,  189, 19,  199, 26,  19,  127,
        135, 111, 201, 253, 222, 145, 87,  156, 27,  56,  166, 195};

    const int bsort_input_len = 2000;
    const int kSpinDelay = 800000;

    volatile unsigned int *gDebugLedsMemoryMappedRegister =
        (unsigned int *)0x2000;

    int i;
    int maxindex = bsort_input_len - 1;

    *gDebugLedsMemoryMappedRegister = 0x00;
    for (int j = 0; j < kSpinDelay; j++);
    *gDebugLedsMemoryMappedRegister = 0xFF;
    
    while (maxindex > 0) {
        for (i = 0; i < maxindex; i++) {
            if (bsort_input[i] > bsort_input[i + 1]) {
                /*		swap		*/
                bsort_input[i] ^= bsort_input[i + 1];
                bsort_input[i + 1] ^= bsort_input[i];
                bsort_input[i] ^= bsort_input[i + 1];
            }
        }

        maxindex--;
    }

    *gDebugLedsMemoryMappedRegister = 0x00;

    // while (1);
    return 0;
}