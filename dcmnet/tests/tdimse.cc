/*
 *
 *  Copyright (C) 2020, J. Riesmeier, Oldenburg, Germany
 *  All rights reserved.  See COPYRIGHT file for details.
 *
 *  This software and supporting documentation are maintained by
 *
 *    OFFIS e.V.
 *    R&D Division Health
 *    Escherweg 2
 *    D-26121 Oldenburg, Germany
 *
 *
 *  Module:  dcmnet
 *
 *  Author: Joerg Riesmeier
 *
 *  Purpose: test program for DIMSE Status Codes and Classes
 *
 */


#include "dcmtk/config/osconfig.h"    /* make sure OS specific configuration is included first */

#include "dcmtk/ofstd/oftest.h"
#include "dcmtk/dcmnet/dimse.h"


OFTEST(dcmnet_dimseStatusClass)
{
    // success
    OFCHECK( DICOM_SUCCESS_STATUS(0x0000));
    OFCHECK(!DICOM_SUCCESS_STATUS(0xabce));
    // failure
    OFCHECK( DICOM_FAILURE_STATUS(0xa000));
    OFCHECK( DICOM_FAILURE_STATUS(0xa001));
    OFCHECK( DICOM_FAILURE_STATUS(0xabcd));
    OFCHECK(!DICOM_FAILURE_STATUS(0xb000));
    OFCHECK(!DICOM_FAILURE_STATUS(0xbeaf));
    OFCHECK( DICOM_FAILURE_STATUS(0xc000));
    OFCHECK( DICOM_FAILURE_STATUS(0xc0c0));
    OFCHECK( DICOM_FAILURE_STATUS(0xcfff));
    OFCHECK(!DICOM_FAILURE_STATUS(0xd000));
    OFCHECK(!DICOM_FAILURE_STATUS(0xd00f));
    OFCHECK( DICOM_FAILURE_STATUS(0x0100));
    OFCHECK(!DICOM_FAILURE_STATUS(0x0107));
    OFCHECK( DICOM_FAILURE_STATUS(0x0108));
    OFCHECK(!DICOM_FAILURE_STATUS(0x0116));
    OFCHECK( DICOM_FAILURE_STATUS(0x0117));
    OFCHECK( DICOM_FAILURE_STATUS(0x01ff));
    OFCHECK( DICOM_FAILURE_STATUS(0x0200));
    OFCHECK( DICOM_FAILURE_STATUS(0x0222));
    OFCHECK( DICOM_FAILURE_STATUS(0x02ff));
    OFCHECK(!DICOM_FAILURE_STATUS(0x0300));
    OFCHECK(!DICOM_FAILURE_STATUS(0x2200));
    // warning
    OFCHECK(!DICOM_WARNING_STATUS(0x0000));
    OFCHECK( DICOM_WARNING_STATUS(0x0001));
    OFCHECK(!DICOM_WARNING_STATUS(0x0002));
    OFCHECK( DICOM_WARNING_STATUS(0x0107));
    OFCHECK(!DICOM_WARNING_STATUS(0x0108));
    OFCHECK( DICOM_WARNING_STATUS(0x0116));
    OFCHECK(!DICOM_WARNING_STATUS(0x0117));
    OFCHECK( DICOM_WARNING_STATUS(0xb000));
    OFCHECK( DICOM_WARNING_STATUS(0xb001));
    OFCHECK( DICOM_WARNING_STATUS(0xbfff));
    OFCHECK(!DICOM_WARNING_STATUS(0xc000));
    // cancel
    OFCHECK( DICOM_CANCEL_STATUS (0xfe00));
    OFCHECK(!DICOM_CANCEL_STATUS (0xfe01));
    OFCHECK(!DICOM_CANCEL_STATUS (0xfefe));
    // pending
    OFCHECK( DICOM_PENDING_STATUS(0xff00));
    OFCHECK( DICOM_PENDING_STATUS(0xff01));
    OFCHECK(!DICOM_PENDING_STATUS(0xff02));
    OFCHECK(!DICOM_PENDING_STATUS(0xffff));
    // any of the standard codes
    OFCHECK( DICOM_STANDARD_STATUS(0x0000));
    OFCHECK( DICOM_STANDARD_STATUS(0x0001));
    OFCHECK( DICOM_STANDARD_STATUS(0x0111));
    OFCHECK( DICOM_STANDARD_STATUS(0x0222));
    OFCHECK(!DICOM_STANDARD_STATUS(0x0300));
    OFCHECK(!DICOM_STANDARD_STATUS(0x9999));
    OFCHECK( DICOM_STANDARD_STATUS(0xabcd));
    OFCHECK( DICOM_STANDARD_STATUS(0xbcde));
    OFCHECK( DICOM_STANDARD_STATUS(0xc0de));
    OFCHECK(!DICOM_STANDARD_STATUS(0xdead));
    OFCHECK(!DICOM_STANDARD_STATUS(0xffff));
}