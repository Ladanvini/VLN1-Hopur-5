#include "unicorn.h"

Unicorn::Unicorn() {

}
string Unicorn::slimShady(){
    string temp = "\n"
"    O      O      O      O\n"
"   |_|_   |_|_   |_|_   |_|_ \n"
"     \\ \\    \\ \\    \\ \\    \\ \\ \n";
    return temp;

}
string Unicorn::standUp() {
    string temp = ""
"            0 \n"
"     O     /|\\     O      O\n"
"    |_|_    |     |_|_   |_|_\n"
"      \\ \\  / \\      \\ \\    \\ \\ \n";
    return temp;


}

void Unicorn::realSlimShady(){
    cout << slimShady();
     sleep(2);
     cout << "Will the real Slim Shady please stand up?" << endl;
     sleep(1);
     cout << standUp();
}

void Unicorn::moonWalk() {

    clearScreen();
    cout << unicorn();
    sleep(1);
    clearScreen();
    cout << unicornS1();
    sleep(1);
    clearScreen();
    cout << unicornS2();
    sleep(1);
    clearScreen();
    cout << unicornS3();
    sleep(1);
    clearScreen();
    cout << unicornS4();
    sleep(1);
    clearScreen();
    cout << unicornS5();
    sleep(1);
    clearScreen();
    cout << unicornS6();
    sleep(1);
    clearScreen();
    cout << unicornS7();
    sleep(1);
    clearScreen();
    cout << unicornS8();
    sleep(1);
    clearScreen();
    cout << unicornS9();

    clearScreen();
    cout << unicornS9();
    sleep(1);
    clearScreen();
    cout << unicornS8();
    sleep(1);
    clearScreen();
    cout << unicornS7();
    sleep(1);
    clearScreen();
    cout << unicornS6();
    sleep(1);
    clearScreen();
    cout << unicornS5();
    sleep(1);
    clearScreen();
    cout << unicornS4();
    sleep(1);
    clearScreen();
    cout << unicornS3();
    sleep(1);
    clearScreen();
    cout << unicornS2();
    sleep(1);
    clearScreen();
    cout << unicornS1();
    sleep(1);
    clearScreen();
    cout << unicorn();
    //wait();

}

string Unicorn::unicorn() {
    string uni = "";
    uni = uni +
"                   ." + '\n' +
"                  /|" + '\n'+
"                 /_|" + '\n'+
"             (0)/__|__" + '\n'+
"               |/ (.) \\  " + '\n'     +
"               | / / /:> " + '\n'+
"               |/ / /_/  " + '\n'+
"               // / | " + '\n'+
"  ____________/ / / | " + '\n'+
" / / / / / / / / / /| " + '\n'+
" | / / / / / / / / /| " + '\n'+
" |/ /_/_/_/_/_/_/ / | " + '\n'+
" |_0|            |_0| " + '\n';

    return uni;
}
string Unicorn::unicornS1() {
    string uni = "";
    uni = uni +
"                    ." + '\n' +
"                   /|" + '\n'+
"                  /_|" + '\n'+
"              (0)/__|__" + '\n'+
"                |/ (.) \\  " + '\n'     +
"                | / / /:> " + '\n'+
"                |/ / /_/  " + '\n'+
"                // / | " + '\n'+
"   ____________/ / / | " + '\n'+
"  / / / / / / / / / /| " + '\n'+
"  | / / / / / / / / /| " + '\n'+
"  |/ /_/_/_/_/_/_/ / | " + '\n'+
"  \\_0\\            \\_0\\ " + '\n';

    return uni;
}
string Unicorn::unicornS2() {
    string uni = "";
    uni = uni +
"                     ." + '\n' +
"                    /|" + '\n'+
"                   /_|" + '\n'+
"               (0)/__|__" + '\n'+
"                 |/ (.) \\  " + '\n'     +
"                 | / / /:> " + '\n'+
"                 |/ / /_/  " + '\n'+
"                 // / | " + '\n'+
"    ____________/ / / | " + '\n'+
"   / / / / / / / / / /| " + '\n'+
"   | / / / / / / / / /| " + '\n'+
"   |/ /_/_/_/_/_/_/ / | " + '\n'+
"   |_0|            |_0| " + '\n';

    return uni;
}
string Unicorn::unicornS3() {
    string uni = "";
    uni = uni +
"                       ." + '\n' +
"                      /|" + '\n'+
"                     /_|" + '\n'+
"                 (0)/__|__" + '\n'+
"                   |/ (.) \\  " + '\n'     +
"                   | / / /:> " + '\n'+
"                   |/ / /_/  " + '\n'+
"                   // / | " + '\n'+
"      ____________/ / / | " + '\n'+
"     / / / / / / / / / /| " + '\n'+
"     | / / / / / / / / /| " + '\n'+
"     |/ /_/_/_/_/_/_/ / | " + '\n'+
"     \\_0\\            \\_0\\ " + '\n';

    return uni;
}
string Unicorn::unicornS4() {
    string uni = "";
    uni = uni +
"                       ." + '\n' +
"                      /|" + '\n'+
"                     /_|" + '\n'+
"                 (0)/__|__" + '\n'+
"                   |/ (.) \\  " + '\n'     +
"                   | / / /:> " + '\n'+
"                   |/ / /_/  " + '\n'+
"                   // / | " + '\n'+
"      ____________/ / / | " + '\n'+
"     / / / / / / / / / /| " + '\n'+
"     | / / / / / / / / /| " + '\n'+
"     |/ /_/_/_/_/_/_/ / | " + '\n'+
"     |_0|            |_0| " + '\n';

    return uni;
}
string Unicorn::unicornS5() {
    string uni = "";
    uni = uni +
"                         ." + '\n' +
"                        /|" + '\n'+
"                       /_|" + '\n'+
"                   (0)/__|__" + '\n'+
"                     |/ (.) \\  " + '\n'     +
"                     | / / /:> " + '\n'+
"                     |/ / /_/  " + '\n'+
"                     // / | " + '\n'+
"        ____________/ / / | " + '\n'+
"       / / / / / / / / / /| " + '\n'+
"       | / / / / / / / / /| " + '\n'+
"       |/ /_/_/_/_/_/_/ / | " + '\n'+
"       \\_0\\            \\_0\\ " + '\n';

    return uni;
}
string Unicorn::unicornS6() {
    string uni = "";
    uni = uni +
"                         ." + '\n' +
"                        /|" + '\n'+
"                       /_|" + '\n'+
"                   (0)/__|__" + '\n'+
"                     |/ (.) \\  " + '\n'     +
"                     | / / /:> " + '\n'+
"                     |/ / /_/  " + '\n'+
"                     // / | " + '\n'+
"        ____________/ / / | " + '\n'+
"       / / / / / / / / / /| " + '\n'+
"       | / / / / / / / / /| " + '\n'+
"       |/ /_/_/_/_/_/_/ / | " + '\n'+
"       |_0|            |_0| " + '\n';

    return uni;
}
string Unicorn::unicornS7() {
    string uni = "";
    uni = uni +
"                           ." + '\n' +
"                          /|" + '\n'+
"                         /_|" + '\n'+
"                     (0)/__|__" + '\n'+
"                       |/ (.) \\  " + '\n'     +
"                       | / / /:> " + '\n'+
"                       |/ / /_/  " + '\n'+
"                       // / | " + '\n'+
"          ____________/ / / | " + '\n'+
"         / / / / / / / / / /| " + '\n'+
"         | / / / / / / / / /| " + '\n'+
"         |/ /_/_/_/_/_/_/ / | " + '\n'+
"         \\_0\\            \\_0\\ " + '\n';

    return uni;
}
string Unicorn::unicornS8() {
    string uni = "";
    uni = uni +
"                           ." + '\n' +
"                          /|" + '\n'+
"                         /_|" + '\n'+
"                     (0)/__|__" + '\n'+
"                       |/ (.) \\  " + '\n'     +
"                       | / / /:> " + '\n'+
"                       |/ / /_/  " + '\n'+
"                      // / | " + '\n'+
"         ____________/ / / | " + '\n'+
"        / / / / / / / / / /| " + '\n'+
"        | / / / / / / / / /| " + '\n'+
"        |/ /_/_/_/_/_/_/ / | " + '\n'+
"        |_0|            |_0| " + '\n';

    return uni;
}
string Unicorn::unicornS9() {
    string uni = "";
    uni = uni +
"                             ." + '\n' +
"                            /|" + '\n'+
"                           /_|" + '\n'+
"                       (0)/__|__" + '\n'+
"                         |/ (.) \\  " + '\n'     +
"                         | / / /:> " + '\n'+
"                         |/ / /_/  " + '\n'+
"                         // / | " + '\n'+
"            ____________/ / / | " + '\n'+
"           / / / / / / / / / /| " + '\n'+
"           | / / / / / / / / /| " + '\n'+
"           |/ /_/_/_/_/_/_/ / | " + '\n'+
"           \\_0\\            \\_0\\ " + '\n';

    return uni;
}
