#ifndef FILEREPLACER_HPP
# define FILEREPLACER_HPP

#include <string>
#include <iostream>
#include <fstream>

class FileReplacer 
{
    public:
        // constructor function with initialisation list 
        // (filename(filename) means member_variable(constructor parameter))
        // ==> the member variable is given the parameter's value
        FileReplacer(const std::string& filename, const std::string& s1, const std::string& s2) : _filename(filename), _s1(s1), _s2(s2) {}
        ~FileReplacer();
        void    replace();

    private:
        // member variables
        std::string     _filename;
        std::string     _s1;
        std::string     _s2;
        // private methods:
        std::string    replaceString(const std::string& str, const std::string& src, const std::string& dest);
};

#endif 
