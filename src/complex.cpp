#include "complex.h"
#include "math.h"
#include <iostream>

Complex::Complex(Complex_Axes axes, std::string name_for_logger)
{
    m_axis_R = axes.m_axis_R;
    m_axis_I = axes.m_axis_I;
    
    m_radius = sqrt(pow(m_axis_R, 2) + pow(m_axis_I, 2));
    m_angle_radian = atan2(m_axis_I, m_axis_R);

    m_logger = new Logger(name_for_logger);
}

Complex::Complex(Complex_Exp exp, std::string name_for_logger)
{
    if(exp.m_radius < 0)
    {
        std::cout << "(Complex) radius < 0; was taked unsigned" << std::endl;
        exp.m_radius = abs(exp.m_radius);
    }
    m_angle_radian = exp.m_angle_degrees * (PI/180);
    m_radius = exp.m_radius;
    
    m_axis_R = cos(m_angle_radian) * m_radius;
    m_axis_I = sin(m_angle_radian) * m_radius;
    
    m_logger = new Logger(name_for_logger);
}

Complex Complex::addNubers(Complex a, Complex b)
{
    double new_axis_R = a.m_axis_R + b.m_axis_R;
    double new_axis_I = a.m_axis_I + b.m_axis_I;

    Complex result(Complex::Complex_Axes(new_axis_R, new_axis_I));
    return result;
}

void Complex::show(bool exp)
{
    double angle_degrees = get_Complex_Exp().m_angle_degrees;


    if(exp)
    {
        std::cout << m_radius << "e^" << (angle_degrees < 0 ? "-" : "+") << "j" << abs(angle_degrees) << "deg";
    }
    else
    {
        std::cout << m_axis_R << " " << (m_axis_I < 0 ? "-" : "+") << " " << abs(m_axis_I) << "i";
    }
    std::cout << std::endl;
}

//nothing to delete or process
Complex::~Complex()
{
    if(m_logger != nullptr)
        delete m_logger;
}