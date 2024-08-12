#include <iostream>


// #################################### Keyword: friend ####################################
// Notes:   Friend can give access to private and protected members to a class or a function.
//          This is a one way relationship.
//          Friend keyword need to be avoided!

class PrivateSecurityInfo{
    // can friend a class too
    friend class UserDefinedType; 
    private:
    int password;
};

class UserDefinedType{
    // Declaration of the friend function,
    //  can be declared as public or private.
    friend void PrintPrivateMember(UserDefinedType u);
    public:
    UserDefinedType() : m_private_member(0) {
        m_info.password = 7;
    }

    private:
    int m_private_member;
    PrivateSecurityInfo m_info;

};

// Definition of the friend function
void PrintPrivateMember(UserDefinedType u){
    std::cout << "m_private_member: " << u.m_private_member << "\n";
}

int main(){

    UserDefinedType object;
    PrintPrivateMember(object);

    return 0;
}