//
// Created by ub1404 on 16. 11. 15.
//

#ifndef UR_TELEOP_MASTER_OMEGA6_H
#define UR_TELEOP_MASTER_OMEGA6_H
#include "HapticDevice.h"
#include <boost/thread/condition_variable.hpp>
#include <boost/thread/mutex.hpp>
#include <Eigen/Geometry>
class Omega6 :public HapticDevice{
public:
    static size_t getNumberOfDevices();
public:
    Omega6(int device_id);
    ~Omega6();
    bool open();
    void close();
    bool isOrientationAvailable() const;
    bool getTranslation(double& x, double& y, double& z);
    bool getLinearVelocity(double& vx, double& vy, double& vz);
    size_t numberOfButtons() const;
    bool getButtonPressed(const size_t& button_idx);
    bool getOrientation(double& qx, double& qy, double& qz, double& qw);
    bool setForce(const double& fx, const double& fy, const double& fz);
    bool isTorqueAvilable() const;
    bool setTorque(const double& tx, const double& ty, const double& tz);
protected:
    void initReferenceFrame();
protected:
    Button button;
    int device_id;

    Eigen::Matrix3d R_origin_to_ref;//rotation matrix to rotate the reference frame
    Eigen::Matrix3d R_origin_to_ref_inv;
    Eigen::Matrix3d rot45;
};


#endif //UR_TELEOP_MASTER_OMEGA6_H
