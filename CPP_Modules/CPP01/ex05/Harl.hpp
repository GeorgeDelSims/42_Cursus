#ifndef HARL_HPP
# define HARL_HPP

#include <string>
#include <iostream>

#define DEBUG 0
#define INFO 1
#define WARNING 2
#define ERROR 4

class Harl 
{
    public:
        Harl();
        ~Harl();

        // Methods: 
        void                        complain(std::string level);

    private:
        // Member variables & utils functions:
        void                        debug(void);
        void                        info(void);
        void                        warning(void);
        void                        error(void);

        typedef void                (Harl::*HarlMemFn)();
        static const std::string    levels[4];
        static const HarlMemFn      functions[4];
};

#endif // Harl_HPP
