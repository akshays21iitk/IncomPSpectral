
#include <sstream>
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

struct para {
    int dimension;

    int Nx;
    int Ny;
    int Nz;

    float Lx;
    float Ly;
    float Lz;

    float nu;

    float tinit;
    float tfinal;
    float dt;

    float file_save_interval;
};

int main()
{
    std::ifstream para_file("para.json");

    //https://stackoverflow.com/a/2602258
    std::stringstream buffer;
    buffer << para_file.rdbuf();
    json j = json::parse(buffer.str());

    // cout << j << endl;

    para p {
        j["dimension"].get<int>(),

        j["Nx"].get<int>(),
        j["Ny"].get<int>(),
        j["Nz"].get<int>(),

        j["Lx"].get<float>(),
        j["Ly"].get<float>(),
        j["Lz"].get<float>(),

        j["nu"].get<float>(),

        j["tinit"].get<float>(),
        j["tfinal"].get<float>(),
        j["dt"].get<float>(),

        j["file_save_interval"].get<float>()
    };

    cout << "dimension: " << p.dimension << endl;
    cout << "Nx: " << p.Nx << endl;
    cout << "Ny: " << p.Ny << endl;
    cout << "Nz: " << p.Nz << endl;
    cout << "Lx: " << p.Lx << endl;
    cout << "Ly: " << p.Ly << endl;
    cout << "Lz: " << p.Lz << endl;
    cout << "nu: " << p.nu << endl;
    cout << "tinit: " << p.tinit << endl;
    cout << "tfinal: " << p.tfinal << endl;
    cout << "dt: " << p.dt << endl;
    cout << "file_save_interval: " << p.file_save_interval << endl;
}
