#include "links.h"

Links::Links()
{
    _computer = Comps();
    _person = Person();
}
Links::Links(string computerID, string personID){
    int cID = stoi(computerID);
    int pID = stoi(personID);


}
Links::Links(Comps c, Person p){
    _computer = c;
    _person = p;
}
