/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/ssx/pgp/registers/ocb_register_addresses.h $              */
/*                                                                        */
/* OpenPOWER OnChipController Project                                     */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2016                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#ifndef __OCB_REGISTER_ADDRESSES_H__
#define __OCB_REGISTER_ADDRESSES_H__

/// \file ocb_register_addresses.h
/// \brief Symbolic addresses for the OCB unit

// *** WARNING *** - This file is generated automatically, do not edit.


#define OCB_OCI_BASE 0x40050000
#define OCB_OITR0 0x40050040
#define OCB_OIEPR0 0x40050048
#define OCB_OCIR0 0x40050050
#define OCB_ONISR0 0x40050058
#define OCB_OUDER0 0x40050060
#define OCB_OCISR0 0x40050068
#define OCB_ODHER0 0x40050070
#define OCB_OISR0 0x40050000
#define OCB_OISR0_AND 0x40050008
#define OCB_OISR0_OR 0x40050010
#define OCB_OIMR0 0x40050020
#define OCB_OIMR0_AND 0x40050028
#define OCB_OIMR0_OR 0x40050030
#define OCB_OITR1 0x400500c0
#define OCB_OIEPR1 0x400500c8
#define OCB_OCIR1 0x400500d0
#define OCB_ONISR1 0x400500d8
#define OCB_OUDER1 0x400500e0
#define OCB_OCISR1 0x400500e8
#define OCB_ODHER1 0x400500f0
#define OCB_OISR1 0x40050080
#define OCB_OISR1_AND 0x40050088
#define OCB_OISR1_OR 0x40050090
#define OCB_OIMR1 0x400500a0
#define OCB_OIMR1_AND 0x400500a8
#define OCB_OIMR1_OR 0x400500b0
#define OCB_OCCMISC 0x40050100
#define OCB_OCCMISC_AND 0x40050108
#define OCB_OCCMISC_OR 0x40050110
#define OCB_OTRN(n) (OCB_OTR0 + ((OCB_OTR1 - OCB_OTR0) * (n)))
#define OCB_OTR0 0x40050800
#define OCB_OTR1 0x40050808
#define OCB_OHTMCR 0x40050118
#define OCB_OEHDR 0x40050120
#define OCB_OCBSLBRN(n) (OCB_OCBSLBR0 + ((OCB_OCBSLBR1 - OCB_OCBSLBR0) * (n)))
#define OCB_OCBSLBR0 0x40051000
#define OCB_OCBSLBR1 0x40051080
#define OCB_OCBSLBR2 0x40051100
#define OCB_OCBSHBRN(n) (OCB_OCBSHBR0 + ((OCB_OCBSHBR1 - OCB_OCBSHBR0) * (n)))
#define OCB_OCBSHBR0 0x40051018
#define OCB_OCBSHBR1 0x40051098
#define OCB_OCBSHBR2 0x40051118
#define OCB_OCBSLCSN(n) (OCB_OCBSLCS0 + ((OCB_OCBSLCS1 - OCB_OCBSLCS0) * (n)))
#define OCB_OCBSLCS0 0x40051008
#define OCB_OCBSLCS1 0x40051088
#define OCB_OCBSLCS2 0x40051108
#define OCB_OCBSHCSN(n) (OCB_OCBSHCS0 + ((OCB_OCBSHCS1 - OCB_OCBSHCS0) * (n)))
#define OCB_OCBSHCS0 0x40051020
#define OCB_OCBSHCS1 0x400510a0
#define OCB_OCBSHCS2 0x40051120
#define OCB_OCBSLIN(n) (OCB_OCBSLI0 + ((OCB_OCBSLI1 - OCB_OCBSLI0) * (n)))
#define OCB_OCBSLI0 0x40051010
#define OCB_OCBSLI1 0x40051090
#define OCB_OCBSLI2 0x40051110
#define OCB_OCBSHIN(n) (OCB_OCBSHI0 + ((OCB_OCBSHI1 - OCB_OCBSHI0) * (n)))
#define OCB_OCBSHI0 0x40051028
#define OCB_OCBSHI1 0x400510a8
#define OCB_OCBSHI2 0x40051128
#define OCB_OCBSESN(n) (OCB_OCBSES0 + ((OCB_OCBSES1 - OCB_OCBSES0) * (n)))
#define OCB_OCBSES0 0x40051030
#define OCB_OCBSES1 0x400510b0
#define OCB_OCBSES2 0x40051130
#define OCB_OCBICRN(n) (OCB_OCBICR0 + ((OCB_OCBICR1 - OCB_OCBICR0) * (n)))
#define OCB_OCBICR0 0x40051038
#define OCB_OCBICR1 0x400510b8
#define OCB_OCBICR2 0x40051138
#define OCB_OCBLWCRN(n) (OCB_OCBLWCR0 + ((OCB_OCBLWCR1 - OCB_OCBLWCR0) * (n)))
#define OCB_OCBLWCR0 0x40051040
#define OCB_OCBLWCR1 0x400510c0
#define OCB_OCBLWCR2 0x40051140
#define OCB_OCBLWSRN(n) (OCB_OCBLWSR0 + ((OCB_OCBLWSR1 - OCB_OCBLWSR0) * (n)))
#define OCB_OCBLWSR0 0x40051050
#define OCB_OCBLWSR1 0x400510d0
#define OCB_OCBLWSR2 0x40051150
#define OCB_OCBLWSBRN(n) (OCB_OCBLWSBR0 + ((OCB_OCBLWSBR1 - OCB_OCBLWSBR0) * (n)))
#define OCB_OCBLWSBR0 0x40051060
#define OCB_OCBLWSBR1 0x400510e0
#define OCB_OCBLWSBR2 0x40051160
#define OCB_OCICHSW 0x40050128
#define OCB_PIB_BASE 0x0006a000
#define OCB_OCR 0x0006b000
#define OCB_OCR_AND 0x0006b001
#define OCB_OCR_OR 0x0006b002
#define OCB_OCDBG 0x0006b003
#define OCB_OCBARN(n) (OCB_OCBAR0 + ((OCB_OCBAR1 - OCB_OCBAR0) * (n)))
#define OCB_OCBAR0 0x0006b010
#define OCB_OCBAR1 0x0006b030
#define OCB_OCBAR2 0x0006b050
#define OCB_OCBAR3 0x0006b070
#define OCB_OCBCSRN(n) (OCB_OCBCSR0 + ((OCB_OCBCSR1 - OCB_OCBCSR0) * (n)))
#define OCB_OCBCSR0 0x0006b011
#define OCB_OCBCSR1 0x0006b031
#define OCB_OCBCSR2 0x0006b051
#define OCB_OCBCSR3 0x0006b071
#define OCB_OCBCSRN_AND(n) (OCB_OCBCSR0_AND + ((OCB_OCBCSR1_AND - OCB_OCBCSR0_AND) * (n)))
#define OCB_OCBCSR0_AND 0x0006b012
#define OCB_OCBCSR1_AND 0x0006b032
#define OCB_OCBCSR2_AND 0x0006b052
#define OCB_OCBCSR3_AND 0x0006b072
#define OCB_OCBCSRN_OR(n) (OCB_OCBCSR0_OR + ((OCB_OCBCSR1_OR - OCB_OCBCSR0_OR) * (n)))
#define OCB_OCBCSR0_OR 0x0006b013
#define OCB_OCBCSR1_OR 0x0006b033
#define OCB_OCBCSR2_OR 0x0006b053
#define OCB_OCBCSR3_OR 0x0006b073
#define OCB_OCBESRN(n) (OCB_OCBESR0 + ((OCB_OCBESR1 - OCB_OCBESR0) * (n)))
#define OCB_OCBESR0 0x0006b014
#define OCB_OCBESR1 0x0006b034
#define OCB_OCBESR2 0x0006b054
#define OCB_OCBESR3 0x0006b074
#define OCB_OCBDRN(n) (OCB_OCBDR0 + ((OCB_OCBDR1 - OCB_OCBDR0) * (n)))
#define OCB_OCBDR0 0x0006b015
#define OCB_OCBDR1 0x0006b035
#define OCB_OCBDR2 0x0006b055
#define OCB_OCBDR3 0x0006b075
#define OCB_OSBCR 0x0006b100
#define OCB_OTDCR 0x0006b110
#define OCB_OPPCINJ 0x0006b111
#define OCB_FIRPIB_BASE 0x01010800
#define OCB_OCCLFIR 0x01010800
#define OCB_OCCLFIR_AND 0x01010801
#define OCB_OCCLFIR_OR 0x01010802
#define OCB_OCCLFIRMASK 0x01010803
#define OCB_OCCLFIRMASK_AND 0x01010804
#define OCB_OCCLFIRMASK_OR 0x01010805
#define OCB_OCCLFIRACT0 0x01010806
#define OCB_OCCLFIRACT1 0x01010807
#define OCB_OCCERRRPT 0x0101080a

#endif // __OCB_REGISTER_ADDRESSES_H__

