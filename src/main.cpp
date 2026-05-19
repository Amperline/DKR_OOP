#include <iostream>
#include "m_complex.h"
#include <fstream>
#include <filesystem>
#include <sstream>
#include <stdexcept>
#include <string>

#define M_KEY 0b10001001

using namespace std;

void write_Obj_Data(Complex& obj, std::string file_name);

string data_directory("Obj_data");

int main()
{
    int variant = 0;

    std::cout << "Enter 1 to execute main programm\n"
    << "Enter 2 to show previous Data\n"
    <<"Enter: ";
    cin >> variant;
    
try
{
    if(variant == 1)
    {
        filesystem::remove_all(data_directory);

        cout << "\n----Example: " << endl;
        Complex a(Complex::Complex_Axes(1, 3), "a_log");
        Complex b(Complex::Complex_Axes(-1, 2), "b_log");

        Complex c = Complex::addNubers(a, b);

        cout << "Algebraic: ";
        cout << c.get_Complex_Axes() << endl;

        cout << "Exponential: ";
        cout << c.get_Complex_Exp() << endl;

        cout << "\n----Type in (a + b):" << endl;

        double a_r;
        double a_i;
        double b_r;
        double b_i;

        cout << "(a) real: ";
        cin >> a_r;
        cout << "(a) imaginary: ";
        cin >> a_i;

        std::cout << "(b) real: ";
        cin >> b_r;
        cout << "(b) imaginary: ";
        cin >> b_i;
        
        Complex res = Complex::addNubers(Complex::Complex_Axes(a_r, a_i), Complex::Complex_Axes(b_r, b_i));

        cout << "\nAlgebraic: ";
        cout << res.get_Complex_Axes() << endl;
        
        cout << "Exponential: ";
        cout << res.get_Complex_Exp() << endl;

        //encryption
        write_Obj_Data(res, "result");

        static_logger.log("END LOG");

    }
    else if(variant == 2)
    {
        if(!filesystem::exists(data_directory))
            throw logic_error("directory does not exist");

        for(auto const & i_file : filesystem::directory_iterator(data_directory))
        {
            if(!i_file.is_regular_file()) continue;
            
            fstream file(i_file.path(), ios::in | ios::binary);
        
            string data = i_file.path().filename().string();
            data += ":\n";

            char c;
            while(file.get(c))
            {
                c ^= M_KEY;
                data.push_back(c); 
            }

            cout << data << endl;
        }
    }
    else{cout << "Wrong variant!\n";}
    
}
    catch(std::exception &e)
    {
       std::cout << std::endl << e.what() << std::endl;
    }
    return 0;
}

void write_Obj_Data(Complex& obj, std::string file_name)
{
    if(file_name.empty()) return;

    if (!std::filesystem::exists(data_directory)) {
        std::filesystem::create_directory(data_directory);
    }

    std::fstream file(data_directory + "/" + file_name + ".txt", ios::out | ios::binary);
    stringstream stream;
    stream << "Radius: " << obj.get_Complex_Exp().m_radius << "\n"
    << "Angle(deg): " << obj.get_Complex_Exp().m_angle_degrees << "\n"
    << "Real: " << obj.get_Complex_Axes().m_axis_R << "\n"
    << "Imaginal: " << obj.get_Complex_Axes().m_axis_I;

    string to_encrypt = stream.str();

    for(auto & c : to_encrypt)
    {
        c ^= M_KEY;
    }

    file << to_encrypt;

    file.close();
}