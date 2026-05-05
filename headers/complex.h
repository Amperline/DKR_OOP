#ifndef M_COMPLEX
#define M_COMPLEX
#include <ostream>
#include "logger.h"

#define PI 3.14159265359

class Complex
{
private:

    double m_axis_R;
    double m_axis_I;
    double m_angle_radian;
    double m_radius;
    Logger* m_logger = nullptr;
    
public:
    struct Complex_Axes
    {
        double m_axis_R;
        double m_axis_I;

        Complex_Axes(double axis_R, double axis_I)
        :m_axis_R(axis_R), m_axis_I(axis_I){}
    };
    struct Complex_Exp
    {
        double m_radius;
        double m_angle_degrees;

        Complex_Exp(double radius, double angle_degrees)
        :m_radius(radius), m_angle_degrees(angle_degrees){}
    };
    Complex(Complex_Axes axes, std::string name_for_logger = "");
    Complex(Complex_Exp exp, std::string name_for_logger = "");
    ~Complex();

    Complex_Exp get_Complex_Exp() 
    {return Complex_Exp(m_radius, m_angle_radian * (180/PI));}

    Complex_Axes get_Complex_Axes() 
    {return Complex_Axes(m_axis_R, m_axis_I);}

    static Complex addNubers(Complex a, Complex b);

    void show(bool exp = false);
};
#endif