#include <iostream>
#include <string>

void string_processing(std::string &s) {
    s.append("Tail");
    std::cout << "lref: " << s << std::endl;
}


void string_processing(std::string const &s) {
    //s.append("Tail");
    std::cout << "lref: " << s << std::endl;
}



void string_processing(std::string &&s) { //r-value reference  
    s.append("Tail");
    std::cout << "rref: " << s << std::endl;
}


int main(){

    std::string s1("Head"), s2("Head");
    string_processing(std::move(s1));

    // (s2 + "_") -- временный объект, единсветвенный способ продлить время жизни верменного объекта 
    // до стандатра С++-11 это константная ссылка. В новом стандарте эту проблему решили через перемещение.
    
    string_processing(s2 + s1);
    
    return 0;
}