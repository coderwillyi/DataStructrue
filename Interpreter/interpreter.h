#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <iostream>
#include <list>
#include <algorithm>
#include "cstring"
using namespace std;

class IdNode {
public :
    IdNode (char * s ="",double e=0) {
        id = strdup(s);
        value =e;
    }
    bool operator == (const IdNode & node) const {
        return strcmp(id,node.id)==0;
    }
private:
    char * id;
    double value;
    friend class Statement;
    friend ostream & operator << (ostream & out,const IdNode & node) ;
};
class Statement {
public :
    Statement(){

    }
    void getStatement();
private:
    list<IdNode> idList;
    char ch;
    double factor();
    double term();
    double expression();
    void readId(char *);
    void issueError(const char * s){
        cerr<<s<<endl;
        exit(1);
    }
    double findValue(char * );
    void processNode(char *,double);
    friend ostream & operator << (ostream &, const Statement &);

};

#endif // INTERPRETER_H
