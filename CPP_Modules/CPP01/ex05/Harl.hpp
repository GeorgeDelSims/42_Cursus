#ifndef HARL_HPP
# define HARL_HPP

#include <string>
#include <iostream>

class Harl 
{
    public:
        Harl();
        ~Harl();

        // Methods: 
        void    complain(std::string level);

    private:
        // Member variables & utils functions:
        void    debug(void);
        void    info(void);
        void    warning(void);
        void    error(void);
};

#endif // Harl_HPP
