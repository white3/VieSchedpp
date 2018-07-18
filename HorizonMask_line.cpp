//
// Created by matth on 11.04.2018.
//

#include "HorizonMask_line.h"
using namespace std;
using namespace VieVS;

HorizonMask_line::HorizonMask_line(const vector<double> &azimuths, const vector<double> &elevations):
        azimuth_{azimuths}, elevation_{elevations} {
}

bool HorizonMask_line::visible(const PointingVector &pv) const noexcept {
    double az = pv.getAz();
    az = fmod(az,twopi);
    if(az<0){
        az+=twopi;
    }

    double el = pv.getEl();
    double el_mask = az2el(az);

    return el >= el_mask;
}

string HorizonMask_line::vexOutput() const noexcept {
    return string();
}

std::pair<std::vector<double>, std::vector<double>> HorizonMask_line::getHorizonMask() const noexcept {
    vector<double> az_;
    vector<double> el_;

    for(int az = 0; az <=360; az+=1){
        double azrad = static_cast<double>(az)*deg2rad;
        double el = az2el(azrad);

        az_.push_back(azrad);
        el_.push_back(el);
    }

    return {az_,el_};
}

double HorizonMask_line::az2el(double az) const noexcept {
    unsigned long i = 1;
    while(az>azimuth_.at(i)){
        ++i;
    }
    unsigned long begin = i - 1;
    unsigned long end = i;
    double delta = az-azimuth_.at(begin);
    return elevation_.at(begin) + (elevation_.at(end)-elevation_.at(begin))/(azimuth_.at(end)-azimuth_.at(begin))*delta;
}

