#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed 
{
    public:
        Fixed();
        Fixed(Fixed fixed);
        ~Fixed();

        // Add methods here

    private:
        // Add member variables here
        static const int    _bits = 8;
        int                 _numVal;
};

#endif // Fixed_HPP
