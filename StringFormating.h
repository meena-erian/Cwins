/**                                StringFormating.h                               **/
/**  Source:https://github.com/meena-hanna/Cwins                                   **/
/**  Required Libraries: <sstream.h>                                               **/
/**  License: GNU GPL v3                                                           **/
#include <sstream>

const std::string STR; //global string object
const std::string str; //global string object

/** Functions declaration                                                          **/
std::string UCase(std::string Str); //copy and change to upper case
std::string LCase(std::string Str); //copy and change to lower case
std::string ReversOrder(const std::string&s1); //copy and reverse character order
std::string CutStr(const std::string&Str, unsigned FirstChar, const unsigned LastChar=-1); //copy a substring from a string by specifying starting point and ending point
std::string Remove(const std::string&s, const char&c); //copy and remove the first occurrence of a specific character value
std::string Remove(const std::string&s, const unsigned&FirstChar, const unsigned&LastChar); //copy and remove a specific substring specified by two indexes
std::string Remove(const std::string&s, const std::string&s2); //copy and remove the first occurrence of the substring s2
std::string GetFirstWord(std::string & Statement); //Returns the first group of characters separated by space, '\t' or '\r' and removes it from the original string
/** End Functions declarations                                                     **/

/** Operators declaration                                                          **/
std::string operator+(const std::string s, const int i);
std::string operator+(const int i, const std::string s); //Example: "(" + 2 + "+" + 3 + ")*4 = " + (2+3)*4    results is the string "(2+3)*4 = 20"
std::string operator-(const std::string&s, const std::string&s1); //Example: "Hello World" - "Wor"  returns  "Hello ld"
std::string operator-(const std::string&s, const char&c); //Example: "Hello World" - 'l'  returns  "Helo World"
std::string operator*(const std::string&s, const unsigned&times); //Example "Hello"*3  returns  "HelloHelloHello"
std::string operator!(const std::string&s); //Example: !"Hello World"  returns  "dlroW olleH"
std::string operator++(const std::string&s); //Example: ++"Hello World" returns "HELLO WORLD"
std::string operator--(const std::string&s); //Example: --"Hello World" returns "hello world"
std::string operator<<(const std::string&s, const unsigned&i); //copy s and removes the last i characters
std::string operator>>(const unsigned&i, const std::string&s); //copy s and removes the first i characters
void operator<<(std::string&to, std::string&from); //removes the first word (characters separated by space[s]) from "from" and stores it in "to"
/** End Operators declaration                                                          **/




std::string UCase(std::string Str)
{
    for(unsigned i=0; i<Str.size(); i++)
    {
        if(Str[i]>=97&&Str[i]<=122) Str[i]-=32;
    }
    return Str;
}

std::string LCase(std::string Str)
{
    for(unsigned i=0; i<Str.size(); i++)
    {
        if(Str[i]>=65&&Str[i]<=90) Str[i]+=32;
    }
    return Str;
}

std::string ReversOrder(const std::string&s1)
{
    std::string s2;
    for(unsigned i=0; i<s1.size(); i++)
    {
        s2=s1[i]+s2;
    }
    return s2;
}

std::string CutStr(const std::string&Str, unsigned FirstChar, const unsigned LastChar)
{
    std::string Str2;
    while(FirstChar<=LastChar)
    {
        if(FirstChar>(Str.size()-1))break;
        Str2+=Str[FirstChar];
        FirstChar++;
    }
    return Str2;
}

std::string Remove(const std::string&s, const char&c)
{
    std::string s2;
    bool found=0;
    for(unsigned i=0; i<s.size(); i++)
    {
        if(!found && s[i]==c)found=1;
        else s2+=s[i];
    }
    return s2;
}

std::string Remove(const std::string&s, const unsigned&FirstChar, const unsigned&LastChar)
{
    std::string s2;
    char stat=0;
    for(unsigned i=0; i<s.size(); i++)
    {
        if(!stat)
        {
            if(i==FirstChar)stat=1;
            else s2+=s[i];
        }
        else if(stat==1)
        {
            if(i==LastChar) stat=2;
        }
        else s2+=s[i];
    }
    return s2;
}

std::string Remove(const std::string&s, const std::string&s2)
{
    for(unsigned i=0; i<s.size(); i++)
    {
        if(s[i]==s2[0])
        {
            if(CutStr(s, i, i+s2.size()-1)==s2)
            {
                return Remove(s, i, i+s2.size()-1);
            }
        }
    }
    return s;
}

std::string GetFirstWord(std::string & Statement)
{
    std::string FirstWord;
    unsigned FirstChar, LastChar;
    char WordState=0;
    for(unsigned i=0; i<Statement.size(); i++)
    {
        if(!WordState)
        {
            if(Statement[i]!=' '&&Statement[i]!='\t'&&Statement[i]!='\r')
            {
                FirstChar=i;
                WordState=1;
                FirstWord+=Statement[i];
            }
        }
        else if(WordState==1)
        {
            if(Statement[i]==' '||Statement[i]=='\t'||Statement[i]=='\r')//the last character in the word was passed
            {
                LastChar=(i-1);
                WordState=2;
                break;
            }
            else
            {
                FirstWord+=Statement[i];
            }
        }
    }
    if(WordState==2)Statement=CutStr(Statement, LastChar+2);
    else Statement="";
    return FirstWord;
}



std::string operator+(const std::string s, const int i)
{
    std::stringstream ss;
    ss<<s<<i;
    return ss.str();
}

std::string operator+(const int i, const std::string s)
{
    std::stringstream ss;
    ss<<i<<s;
    return ss.str();
}

std::string operator-(const std::string&s, const std::string&s1)
{
    return Remove(s, s1);
}

std::string operator-(const std::string&s, const char&c)
{
    return Remove(s,c);
}

std::string operator*(const std::string&s, const unsigned&times)
{
    std::string r;
    for(unsigned i=0; i<times; i++)
    {
        r+=s;
    }
    return r;
}

std::string operator!(const std::string&s)
{
    return ReversOrder(s);
}

std::string operator++(const std::string&s)
{
    return UCase(s);
}

std::string operator--(const std::string&s)
{
    return LCase(s);
}

std::string operator<<(const std::string&s, const unsigned&i)
{
    return CutStr(s, 0, s.size()-1-i);
}

std::string operator>>(const unsigned&i, const std::string&s)
{
    return CutStr(s, i, s.size()-1);
}

void operator<<(std::string&to, std::string&from)
{
    to = GetFirstWord(from);
}
