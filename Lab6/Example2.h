#ifndef STROKA_H
#define STROKA_H

class Stroka {
    char str[80];
public:
    Stroka(const char *);
    Stroka() {}
    Stroka(const Stroka &);
    Stroka &operator=(const Stroka &);
    Stroka &operator+(const Stroka &);
    int operator==(const Stroka&);
    int dlina();
    void vvod();
    void vyvod();
};

#endif