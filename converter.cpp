#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unicode/uclean.h>
#include <unicode/translit.h>
#include <unicode/unistr.h>

using namespace icu;
using namespace std;

void checkWidth(const UChar32 c);

int main(int argc, char** argv)
{
    UParseError parseErr;
    UErrorCode status = U_ZERO_ERROR;
    UnicodeString s("1１");
    // checkWidth(s.char32At(0));
    // checkWidth(s.char32At(1));

    u_init(&status);
    printf("u_init() status: %s\n", u_errorName(status));

    status = U_ZERO_ERROR;
    try
    {
        Transliterator* t = Transliterator::createInstance("Halfwidth-Fullwidth", UTRANS_FORWARD, parseErr, status);
        printf("Transliterator::createInstance() status: %s\n", u_errorName(status));
        if (t)
        {
            UnicodeString us("123");
            string s;
            us.toUTF8String(s);
            cout << s << endl;

            delete t;
        }
    }
    catch(std::exception& e)
    {
        printf("what(): %s\n", e.what());
    }

    return 0;
}

void checkWidth(const UChar32 c)
{
    int prop = u_getIntPropertyValue(c, UCHAR_EAST_ASIAN_WIDTH);
    if ((prop == U_EA_FULLWIDTH) || (prop == U_EA_WIDE))
    {
        cout << c << " is full width" << endl;
    }
    else
    {
        cout << c << " is half width" << endl;
    }
}
