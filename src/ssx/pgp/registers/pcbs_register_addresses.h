/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/ssx/pgp/registers/pcbs_register_addresses.h $             */
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
#ifndef __PCBS_REGISTER_ADDRESSES_H__
#define __PCBS_REGISTER_ADDRESSES_H__

/// \file pcbs_register_addresses.h
/// \brief Symbolic addresses for the PCBS unit

// *** WARNING *** - This file is generated automatically, do not edit.


#define PCBS_PIB_BASE 0x100f0100
#define PCBS_PMGP0_REG 0x100f0100
#define PCBS_PMGP0_REG_AND 0x100f0101
#define PCBS_PMGP0_REG_OR 0x100f0102
#define PCBS_PMGP1_REG 0x100f0103
#define PCBS_PMGP1_REG_AND 0x100f0104
#define PCBS_PMGP1_REG_OR 0x100f0105
#define PCBS_PFVDDCNTLSTAT_REG 0x100f0106
#define PCBS_PFVCSCNTLSTAT_REG 0x100f010e
#define PCBS_PFSENSE_REG 0x100f0107
#define PCBS_PMERRSUM_REG 0x100f0108
#define PCBS_PMERR_REG 0x100f0109
#define PCBS_PMERRMASK_REG 0x100f010a
#define PCBS_PMSPCWKUPFSP_REG 0x100f010b
#define PCBS_PMSPCWKUPOCC_REG 0x100f010c
#define PCBS_PMSPCWKUPPHYP_REG 0x100f010d
#define PCBS_PMSTATEHISTPHYP_REG 0x100f0110
#define PCBS_PMSTATEHISTFSP_REG 0x100f0111
#define PCBS_PMSTATEHISTOCC_REG 0x100f0112
#define PCBS_PMSTATEHISTPERF_REG 0x100f0113
#define PCBS_IDLEFSMGOTOCMD_REG 0x100f0114
#define PCBS_COREPFPUDLY_REG 0x100f012c
#define PCBS_COREPFPDDLY_REG 0x100f012d
#define PCBS_COREPFVRET_REG 0x100f0130
#define PCBS_ECOPFPUDLY_REG 0x100f014c
#define PCBS_ECOPFPDDLY_REG 0x100f014d
#define PCBS_ECOPFVRET_REG 0x100f0150
#define PCBS_FREQ_CTRL_REG 0x100f0151
#define PCBS_DPLL_CPM_PARM_REG 0x100f0152
#define PCBS_POWER_MANAGEMENT_STATUS_REG 0x100f0153
#define PCBS_IVRM_CONTROL_STATUS_REG 0x100f0154
#define PCBS_IVRM_VALUE_SETTING_REG 0x100f0155
#define PCBS_PCBSPM_MODE_REG 0x100f0156
#define PCBS_IVRM_PFETSTR_SENSE_REG 0x100f0157
#define PCBS_POWER_MANAGEMENT_IDLE_CONTROL_REG 0x100f0158
#define PCBS_POWER_MANAGEMENT_CONTROL_REG 0x100f0159
#define PCBS_PMC_VF_CTRL_REG 0x100f015a
#define PCBS_UNDERVOLTING_REG 0x100f015b
#define PCBS_PSTATE_INDEX_BOUND_REG 0x100f015c
#define PCBS_POWER_MANAGEMENT_BOUNDS_REG 0x100f015d
#define PCBS_PSTATE_TABLE_CTRL_REG 0x100f015e
#define PCBS_PSTATE_TABLE_REG 0x100f015f
#define PCBS_PSTATE_STEP_TARGET_REG 0x100f0160
#define PCBS_DPLL_STATUS_REG 0x100f0161
#define PCBS_IVRM_VID_CONTROL_REG0 0x100f0162
#define PCBS_IVRM_VID_CONTROL_REG1 0x100f0163
#define PCBS_OCC_HEARTBEAT_REG 0x100f0164
#define PCBS_RESONANT_CLOCK_CONTROL_REG0 0x100f0165
#define PCBS_RESONANT_CLOCK_CONTROL_REG1 0x100f0166
#define PCBS_RESONANT_CLOCK_STATUS_REG 0x100f0167
#define PCBS_LOCAL_PSTATE_FREQUENCY_TARGET_CONTROL_REG 0x100f0168
#define PCBS_LOCAL_PSTATE_FREQUENCY_TARGET_STATUS_REG 0x100f0169
#define PCBS_FSM_MONITOR1_REG 0x100f0170
#define PCBS_FSM_MONITOR2_REG 0x100f0171

#endif // __PCBS_REGISTER_ADDRESSES_H__

