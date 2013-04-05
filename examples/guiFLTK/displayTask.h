/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-    */
/* ex: set filetype=cpp softtabstop=4 shiftwidth=4 tabstop=4 cindent expandtab: */
/* $Id$ */

#ifndef _displayTask_h
#define _displayTask_h

#include <cisstCommon.h>
#include <cisstVector.h>
#include <cisstMultiTask.h>
#include <cisstParameterTypes.h>
#include <cisstParameterTypes/prmPositionJointGet.h>


#include "displayUI.h"

class displayTask: public mtsTaskPeriodic {
    // set log level to 5
    CMN_DECLARE_SERVICES(CMN_NO_DYNAMIC_CREATION, CMN_LOG_LOD_RUN_ERROR);
    volatile bool ExitFlag;
    
 protected:
    // local copy of data used in commands
    prmPositionCartesianGet CartesianPosition;
    prmVelocityCartesianGet CartesianVelocity;
    prmPositionJointGet JointPosition;

    // pointer on tip as provided by the transformation manager
    prmTransformationBasePtr TipTransformationPointer, BaseTransformationPointer;
    prmTransformationFixed * ReferenceTransformationPointer;
    vctFrm3 TipWrtReference;

    // functions which will be bound to commands
    mtsFunctionRead GetCartesianPosition;
    mtsFunctionRead GetCartesianVelocity;
    mtsFunctionRead GetJointPosition;
    
    // check if the device can provide velocities
    bool DeviceProvidesCartesianVelocity;
    bool DeviceProvidesJointPosition;

    // user interface generated by FTLK/fluid
    displayUI UI;
    
    // event handlers
    void Button1EventHandler(const prmEventButton & buttonEvent);
    void Button2EventHandler(const prmEventButton & buttonEvent);

 public:
    // see sineTask.h documentation
    displayTask(const std::string & taskName, double period);
    ~displayTask() {};
    void Configure(const std::string & CMN_UNUSED(filename) = "");
    void Startup(void);
    void Run(void);
    void Cleanup(void) {};
    bool GetExitFlag (void) { return ExitFlag;}
};

CMN_DECLARE_SERVICES_INSTANTIATION(displayTask);

#endif // _displayTask_h

/*
  Author(s):  Ankur Kapoor, Peter Kazanzides, Anton Deguet
  Created on: 2004-04-30

  (C) Copyright 2004-2008 Johns Hopkins University (JHU), All Rights
  Reserved.

--- begin cisst license - do not edit ---

This software is provided "as is" under an open source license, with
no warranty.  The complete license can be found in license.txt and
http://www.cisst.org/cisst/license.txt.

--- end cisst license ---

*/
