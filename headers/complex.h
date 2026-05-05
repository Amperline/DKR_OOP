#ifndef M_COMPLEX
#define M_COMPLEX
#include <ostream>

#define PI 3.14159265359

class Complex
{
private:

    double m_axis_i;
    double m_axis_j;
    double m_angle_radian;
    double m_radius;
    
public:
    struct Complex_Axes
    {
        double m_axis_i;
        double m_axis_j;
        
        Complex_Axes(double axis_i, double axis_j)
        :m_axis_i(axis_i), m_axis_j(axis_j){}
    };
    struct Complex_Exp
    {
        double m_radius;
        double m_angle_degrees;

        Complex_Exp(double radius, double angle_degrees)
        :m_radius(radius), m_angle_degrees(angle_degrees){}
    };
    Complex(Complex_Axes axes);
    Complex(Complex_Exp exp);
    ~Complex();

    Complex_Exp get_Complex_Exp() 
    {return Complex_Exp(m_radius, m_angle_radian);}

    Complex_Axes get_Complex_Axes() 
    {return Complex_Axes(m_axis_i, m_axis_j);}

    static Complex addNubers(Complex a, Complex b);
};
#endif