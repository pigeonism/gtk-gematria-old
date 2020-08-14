#ifndef GEMATRIA_H
#define GEMATRIA_H

#include <string>


using namespace std;

class gematria
{
    public:
        gematria();
        virtual ~gematria();

        int check_alpha(char letter, string method);
        void testShorten();
        void numerate(string msg);
        void setMethod(string method);
        string getResult();

    protected:

    private:

        string alpha;
        int total;
        string useMethod;
        string numeratedText;
};

#endif // GEMATRIA_H
