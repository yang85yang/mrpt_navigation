/***********************************************************************************
 * Revised BSD License                                                             *
 * Copyright (c) 2014, Markus Bader <markus.bader@tuwien.ac.at>                    *
 * All rights reserved.                                                            *
 *                                                                                 *
 * Redistribution and use in source and binary forms, with or without              *
 * modification, are permitted provided that the following conditions are met:     *
 *     * Redistributions of source code must retain the above copyright            *
 *       notice, this list of conditions and the following disclaimer.             *
 *     * Redistributions in binary form must reproduce the above copyright         *
 *       notice, this list of conditions and the following disclaimer in the       *
 *       documentation and/or other materials provided with the distribution.      *
 *     * Neither the name of the Vienna University of Technology nor the           *
 *       names of its contributors may be used to endorse or promote products      *
 *       derived from this software without specific prior written permission.     *
 *                                                                                 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND *
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED   *
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE          *
 * DISCLAIMED. IN NO EVENT SHALL Markus Bader BE LIABLE FOR ANY                    *
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES      *
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;    *
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND     *
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT      *
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS   *
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.                    *                       *
 ***********************************************************************************/

#include <iostream>
#include <stdint.h>
#include <boost/interprocess/sync/interprocess_mutex.hpp>

#ifndef MRPT_RAWLOG_RECORD_H
#define MRPT_RAWLOG_RECORD_H



#include <mrpt/slam.h>
#include <mrpt_bridge/mrpt_log_macros.h>

class RawlogRecord {
    MRPT_VIRTUAL_LOG_MACROS;
public:
	struct Parameters{
		Parameters();
	    bool debug;
        std::string raw_log_folder;
        std::string raw_log_name;
        std::string raw_log_name_asf;
        mrpt::slam::CActionRobotMovement2D::TMotionModelOptions motionModelOptions;
	};
    RawlogRecord (Parameters *parm);
    ~RawlogRecord();
protected:
    Parameters *param_; 
    mrpt::slam::CRawlog *pRawLog;
    mrpt::slam::CRawlog *pRawLogASF;
    mrpt::poses::CPose2D odomLastPose_;
    void updateRawLogName(const mrpt::system::TTimeStamp &t);
    void observation(mrpt::slam::CObservation2DRangeScanPtr laser, mrpt::slam::CObservationOdometryPtr _odometry);
    boost::interprocess::interprocess_mutex mutexRawLog;
};

#endif // MRPT_RAWLOG_RECORD_H
