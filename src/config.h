/**
 * @file config.h
 * @author Kudryashov Ilya (kudriashov.it@phystech.edu)
 * @brief Project-wide constants
 * @version 0.1
 * @date 2023-07-05
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

#include <stdlib.h>

static const char PROGRAM_VERSION[] = "v0.1";
static const char PROGRAM_BUG_ADDRESS[] = "<kudriashov.it@phystech.edu>";

static const char PROGRAM_NAME[] =
    "PLACEHOLDER PROGRAM NAME! REPLACE ME IN THE CONFIG FILE \"" __FILE__ "\"!";

static const char PROGRAM_DESCRIPTION[] =
    "Build from " __DATE__ " " __TIME__
    "\n"
    R"""(WARNING: THIS IS A PLACEHOLDER DESCRIPTION!
REPLACE ME IN THE CONFIG FILE ")""" __FILE__ R"""("!
These owls were tasked with insuring you remove the
template description before publishing your work.
    A_,,,_A        A_,,,_A        A_,,,_A    
   ((O)V(O))      ((O)V(O))      ((O)V(O))   
  (w\W|W|W/w)    (w\W|W|W/w)    (w\W|W|W/w)  
   \v|W|W|v/      \v|W|W|v/      \v|W|W|v/   
     "|v|"          "|v|"          "|v|"     
      ^ ^            ^ ^            ^ ^      )""";

static const unsigned LOG_THRESHOLD = 0;

static const double CMP_EPS = 1e-5;

static const unsigned CONN_PORT = 12131;

static const size_t MAX_CLIENT_COUNT = 1024;
static const size_t MAX_PACKAGE_SIZE = 128;

static const char INPUT_PREFIX[] = ">>> ";
