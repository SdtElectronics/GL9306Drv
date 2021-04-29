/*
  Copyright (C) 2021 SdtElectronics <null@std.uestc.edu.cn>
  All rights reserved.
  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:
  * Redistributions of source code must retain the above copyright
  notice, this list of conditions and the following disclaimer.
  * Redistributions in binary form must reproduce the above copyright
  notice, this list of conditions and the following disclaimer in the
  documentation and/or other materials provided with the distribution.
  * Neither the name of the copyright holder nor the
  names of its contributors may be used to endorse or promote products
  derived from this software without specific prior written permission.
  THIS SOFTWARE IS PROVIDED BY  COPYRIGHT HOLDERS AND CONTRIBUTORS ''AS IS'' 
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
  ARE DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE 
  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL 
  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, 
  OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#pragma once
#include <cstddef>

class lightSS{
  public:
    /// `ssPath` is the path to the serial connected to the sensor
    /// e.g. "/dev/ttyS7"
    lightSS(const char* ssPath);
    /// Retrieve a frame excluding the head i.e. start from Delta_XL
    /// Return the pointer to the start of a frame in the RX buffer
    const unsigned char* getFrame();
    /// Retrieve the SQUAL field in a frame
    unsigned int getSQUAL();

    ~lightSS();
    
  private:
    int _sensorFd;
    unsigned char buffer[8192];
    unsigned char *buftop;
    unsigned char *bufesp;
    static const unsigned char* sstrrchr(const unsigned char *start, 
                                         const unsigned char *end, 
                                               unsigned char token);
    static unsigned char checkSum(const unsigned char *start, 
                                  const unsigned char *end);
};