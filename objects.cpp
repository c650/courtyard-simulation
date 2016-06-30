#include <vector>

class Object {      
  
    public:

    Object() {}
    virtual ~Object() {
        printf("[*] ~Object()\n");
    }
  
    virtual char symbol() = 0;
};

class Person : public Object {
    bool male; // true if male
    
    bool hot;
    
    int popularity;

    public:

    Person(bool _male, bool _hot, int _popularity)
        : Object(), male(_male), hot(_hot), popularity(_popularity)
    {
        printf("[*] Person() => %s, %s, with %i popularity\n",
                _male ? "boy" : "girl",
                _hot ? "hot" : "not hot",
                _popularity);
    }

    virtual ~Person() {
        printf("[*] ~Person()\n");
    }

    char symbol() {
        return male ? 'B' : 'G';
    }
};

class Table : public Object {
  
    public:
    
    Table() : Object() {
        printf("[*] Table()\n");
    }

    virtual ~Table() {
        printf("[*] ~Table()\n");
    }

    char symbol() {
        return 'T';
    }
};