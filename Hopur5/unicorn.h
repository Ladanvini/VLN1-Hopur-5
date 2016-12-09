#ifndef UNICORN_H
#define UNICORN_H

#include <string>
#include <iostream>
#define clearScreen() cout<<("\033[H\033[J")
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
using namespace std;

class Unicorn
{
private:
    string unicorn();
    string unicornS1();
    string unicornS2();
    string unicornS3();
    string unicornS4();
    string unicornS5();
    string unicornS6();
    string unicornS7();
    string unicornS8();
    string unicornS9();
public:
    Unicorn();
    void moonWalk();

};

#endif // UNICORN_H
