#include "complex.h"
#include "math.h"
#include <iostream>

Complex::Complex(Complex_Axes axes)
{
    m_axis_i = axes.m_axis_i;
    m_axis_j = axes.m_axis_j;
    
    m_radius = sqrt(pow(m_axis_i, 2) + pow(m_axis_j, 2));
    m_angle_radian = atan2(m_axis_j, m_axis_i);
}

Complex::Complex(Complex_Exp exp)
{
    if(exp.m_radius < 0)
    {
        std::cout << "(Complex) radius < 0; was taked unsigned" << std::endl;
        exp.radius = abs(exp.radius);
    }
    m_angle_radian = exp.angle_degrees * (PI/180);
    m_radius = exp.radius;
    
    m_axis_i = cos(m_angle_radian) * m_radius;
    m_axis_j = sin(m_angle_radian) * m_radius;
}

Complex Complex::addNubers(Complex a, Complex b)
{
    
}
