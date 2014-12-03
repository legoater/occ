/******************************************************************************
// @file occ_sys_config.h
// @brief OCC System Configuration Structures sent down from HostBoot
//
// *** All config Structures *** must be defined in a completely self-contained
// file (i.e no #includes) so that it can be used by both OCC & Host Boot.  
*/
/******************************************************************************
 *
 *       @page ChangeLogs Change Logs
 *       @section occ_sys_config.h OCC_SYS_CONFIG.H
 *       @verbatim
 *
 *   Flag    Def/Fea    Userid    Date        Description
 *   ------- ---------- --------  ----------  ----------------------------------
 *   @th001             thallet   09/15/2011  Created
 *   @01                abagepa   09/17/2011  extern a global
 *   @pb008             pbavari   10/17/2011  Use Pstate define from SSX for
 *                                            OCC FW Compilation.
 *   @th005             thallet   11/23/2011  Sensor Initialization changes
 *   @rc002             rickylie  02/02/2012  Remove unused DPSS function 
 *   @rc003             rickylie  02/03/2012  Verify & Clean Up OCC Headers & Comments
 *   @th00b             thallet   02/28/2011  APSS Spec Changes            
 *   @th010             thallet   07/11/2012  Pstate Enablement
 *   @th014             thallet   08/02/2012  Moved default PstateSS occ_sys_config
 *   @th018  852950     thallet   09/12/2012  Added Centaur thermal readings       
 *   @th019  853007     thallet   09/12/2012  Power Sensors
 *   @th022             thallet   10/08/2012  Added way to init OCC w/o FSP for Simics
 *   @at010  859992     alvinwan  11/07/2012  Added oversubscription feature
 *   @th030             thallet   02/04/2013  Fixed a enum problem before external use
 *   @th034             thallet   04/18/2013  Broadcast Critical Power over PBAX
 *   @at013  878755     alvinwan  04/17/2013  OCC power capping implementation
 *   @at014  882077     alvinwan  05/09/2013  Support APSS and System Config data from TMGT
 *   @ly007  882183     lychen    05/21/2013  Send APSS and System Configuration commands to OCC
 *   @th040  887069     thallet   06/11/2013  Support Nom & FFO Freq Setting for Mnfg 
 *   @fk001  879727     fmkassem  04/16/2013  OCC powercap support.
 *   @ly008  894646     lychen    08/08/2013  Fix bugs in OCC handling of APSS tables for Brazos/Orlena
 *   @at016  891144     alvinwan  06/10/2013  OCC Power Cap Testing
 *   @gm008  SW226989   milesg    09/30/2013  Sapphire initial support
 *   @gm012  905097     milesg    10/31/2013  support mem throttle & mem config packets
 *   @gs015  905166     gjsilva   11/04/2013  Full support for IPS function
 *   @gs026  915840     gjsilva   02/13/2014  Support for Nvidia GPU power measurement
 *
 *  @endverbatim
 *
 *///*************************************************************************/

#ifndef _occ_sys_config_h
#define _occ_sys_config_h

//*************************************************************************
// Includes
//*************************************************************************
//@pb008a - SSX defined Pstate in pgp_common.h file. Without below ifdef
//compiler complains about redefinition for OCC.
#ifdef OCC_FIRMWARE
#include "pgp_common.h"
#else
#endif
#include <state.h>
#include <apss.h>  // @at014a

//*************************************************************************
// Externs
//*************************************************************************

//*************************************************************************
// Macros
//*************************************************************************

//*************************************************************************
// Defines/Enums
//*************************************************************************
#define MAX_NUM_OCC              8
#define MAX_NUM_NODES            4
#define MAX_NUM_CORES           12
#define MAX_THREADS_PER_CORE     8
#define MAX_NUM_CHIP_MODULES     4
#define MAX_NUM_POWER_SUPPLIES   4
#define MAX_NUM_MEM_CONTROLLERS  8
#define MAX_NUM_CENTAURS         8
#define NUM_PROC_VRMS            2

#define NUM_PROC_CHIPS_PER_OCC          1
#define NUM_CENTAURS_PER_MEM_CONTROLLER 1
#define NUM_PORT_PAIRS_PER_CENTAUR      2
#define NUM_DIMMS_PER_CENTAUR           8    /* @th018 */
#define NUM_MBAS_PER_CENTAUR            2

#define UPPER_LIMIT_PROC_FREQ_MHZ     6000

//Number of samples per second for performance-related algorithms (e.g. UTIL2MSP0Cy)
#define AMEC_DPS_SAMPLING_RATE         500
//Time interval for averaging utilization and frequency (IPS algorithm)
#define AMEC_IPS_AVRG_INTERVAL           3

/*****************************************************************************/
// System Structures
/*****************************************************************************/
typedef union // @gm008
{
    struct
    {
        uint8_t     kvm:        1;
        uint8_t     reserved:   5;
        uint8_t     ite:        1;
        uint8_t     single:     1;
    };
    uint8_t byte;
} eSystemType;

/*****************************************************************************/
// APSS Structures & Defines
/*****************************************************************************/
#define SYSCFG_INVALID_ADC_CHAN      0xff
#define SYSCFG_INVALID_PIN           0xff

#define MAX_VRFAN_SIGNALS       4
#define MAX_APSS_MEM_TEMPS      8
#define MAX_ADC_IO_DOMAINS      3
#define MAX_ADC_FAN_DOMAINS     2
#define MAX_ADC_STORAGE_DOMAINS 2
#define MAX_CENT_EN_VCACHE      4 // @ly007a
#define MAX_DOM_OC_LATCH        4 // @ly007a
#define MAX_CONN_OC_SIGNALS     5 // @fk001a

typedef enum
{
    ADC_RESERVED                = 0x00,
    ADC_MEMORY_PROC_0           = 0x01,
    ADC_MEMORY_PROC_1           = 0x02,
    ADC_MEMORY_PROC_2           = 0x03,
    ADC_MEMORY_PROC_3           = 0x04,
    ADC_VDD_PROC_0              = 0x05,
    ADC_VDD_PROC_1              = 0x06,
    ADC_VDD_PROC_2              = 0x07,
    ADC_VDD_PROC_3              = 0x08,
    ADC_VCS_VIO_VPCIE_PROC_0    = 0x09,
    ADC_VCS_VIO_VPCIE_PROC_1    = 0x0A,
    ADC_VCS_VIO_VPCIE_PROC_2    = 0x0B,
    ADC_VCS_VIO_VPCIE_PROC_3    = 0x0C,
    ADC_IO_A                    = 0x0D,
    ADC_IO_B                    = 0x0E,
    ADC_IO_C                    = 0x0F,
    ADC_FANS_A                  = 0x10,
    ADC_FANS_B                  = 0x11,
    ADC_STORAGE_A               = 0x12,
    ADC_STORAGE_B               = 0x13,
    ADC_12V_SENSE               = 0x14,
    ADC_GND_REMOTE_SENSE        = 0x15,
    ADC_TOTAL_SYS_CURRENT       = 0x16,
    ADC_MEM_CACHE               = 0x17, // @ly008a
    ADC_GPU_SENSE               = 0x18,
    NUM_ADC_ASSIGNMENT_TYPES    // This should always be the last member
} eApssAdcChannelAssignments;

typedef enum 
{
    GPIO_RESERVED               = 0x0000,
    GPIO_FAN_WATCHDOG_ERROR     = 0x0001,
    GPIO_FAN_FULL_SPEED         = 0x0002,
    GPIO_FAN_ERROR              = 0x0003,
    GPIO_FAN_RESERVED           = 0x0004,
    GPIO_VR_HOT_MEM_PROC_0      = 0x0005,
    GPIO_VR_HOT_MEM_PROC_1      = 0x0006,
    GPIO_VR_HOT_MEM_PROC_2      = 0x0007,
    GPIO_VR_HOT_MEM_PROC_3      = 0x0008,
    // @ly007a - start
    GPIO_CENT_EN_VCACHE0        = 0x0009,
    GPIO_CENT_EN_VCACHE1        = 0x000A,
    GPIO_CENT_EN_VCACHE2        = 0x000B,
    GPIO_CENT_EN_VCACHE3        = 0x000C,
    CME_THROTTLE_N              = 0x000D,
    GND_OC_N                    = 0x000E,
    DOM_A_OC_LATCH              = 0x000F,
    DOM_B_OC_LATCH              = 0x0010,
    DOM_C_OC_LATCH              = 0x0011,
    DOM_D_OC_LATCH              = 0x0012,
    // @ly007a - end
    NUM_GPIO_ASSIGNMENT_TYPES    // This should always be the last member
} eApssGpioAssignments;

typedef struct
{
  // Gain and Offset, Stored in a exponent/mantissa format (like P7 PS Gain/Offset)
  uint32_t gain;        // Think "multiplier"
  uint32_t offset;      // Will probably always be 0, since APSS is so accurate
  uint8_t  gnd_select;  // @at014a
} apssCalibrationData_t;

typedef struct
{
  // Value stored will be APSS GPIO Number, if not present, set to INVALID = xFF.
  // Example:  vr_fan[0] = 4; (VR_FAN is APSS GPIO #4)
  // @ly007a - start
  uint8_t dom_oc_latch[MAX_DOM_OC_LATCH];
  uint8_t gnd_oc_n;
  uint8_t cme_throttle_n;
  uint8_t cent_en_vcache[MAX_CENT_EN_VCACHE];
  // @ly007a - end
  uint8_t vr_fan[MAX_VRFAN_SIGNALS];  
  uint8_t fans_watchdog_error;
  uint8_t fans_full_speed;
  uint8_t fans_error;
  uint8_t fans_reserved;  
} apssGpioPinData_t;

typedef struct 
{
  // Value stored will be APSS ADC Channel Number, if rail is not present, set 
  // to INVALID = xFF
  uint8_t memory[MAX_NUM_CHIP_MODULES];  
  uint8_t vdd[MAX_NUM_CHIP_MODULES];
  uint8_t io[MAX_ADC_IO_DOMAINS];
  uint8_t fans[MAX_ADC_FAN_DOMAINS];
  uint8_t storage_media[MAX_ADC_STORAGE_DOMAINS];
  uint8_t total_current_12v;
  uint8_t vcs_vio_vpcie[MAX_NUM_CHIP_MODULES]; 
  uint8_t sense_12v;
  uint8_t remote_gnd;
  uint8_t mem_cache; // @ly008a
  uint8_t gpu;
} apssAdcChannelData_t;

// @rc002  - Remove unused DPSS Structures & Defines

/*****************************************************************************/
// Master/Slave Configuration
/*****************************************************************************/
typedef struct
{
  // Bitmask that states if OCC is master capable 
  // (i.e. 0x11 = Chip_Id 000 & Chip_Id 100 can both be masters)
  uint8_t is_master_capable;  
  
  // Which Chip_Id should be initial master 
  // (i.e. default_master = 0x00 for almost all cases) 
  uint8_t default_master;

} masterCapability_t;


//*************************************************************************
// System Frequency
//*************************************************************************
typedef struct
{
    uint16_t table[OCC_MODE_COUNT];  // Table w/ freq for each mode
    uint8_t  update_count;           //  
    uint8_t  _reserved;              // Align to 2 b/c we may use it in PBAX broadcast
} freqConfig_t;   // @th040

//*************************************************************************
// Power Cap Structures
//*************************************************************************
// @th034  @fk001c
typedef struct
{
    uint16_t current_pcap;     // Node power cap requested by customer (AEM) in 1W units
    uint16_t soft_min_pcap;    // Minimum node power cap allowed in 1W units
    uint16_t hard_min_pcap;    // Minimum guaranteed node power cap in 1W units
    uint16_t max_pcap;         // Maximum customer settable node power cap in 1W units
    uint16_t oversub_pcap;     // Node power cap to be used for oversubscripion in 1W units
    uint16_t system_pcap;      // Fixed node power cap required by the system in 1W units
    uint8_t  unthrottle;       // Only used on ITEs -- is indicated from CMM
    uint8_t  pcap_data_count;  // Used by OCC only.  Initialized to 0 and incremented by 1 with every new packet.
} pcap_config_data_t;          

//*************************************************************************
// Memory Throttle settings
//*************************************************************************
typedef struct
{
    uint16_t    min_ot_n_per_mba;   //minimum value
    uint16_t    nom_n_per_mba;      //max mba value for nominal mode
    uint16_t    nom_n_per_chip;     //chip setting for nominal mode
    uint16_t    turbo_n_per_mba;    //max mba value for turbo mode
    uint16_t    turbo_n_per_chip;   //chip setting for nominal mode
    uint16_t    ovs_n_per_mba;      //max mba value for oversubscription
    uint16_t    ovs_n_per_chip;     //chip setting for oversubscription
} mem_throt_config_data_t;

//*************************************************************************
// Sys Config Structure
//*************************************************************************

// Needs to be 128 bytes aligned so we can do a DMA to transfer this to SRAM from
// Main Memory.

// One global structure which is the same in all OCCs 

// TODO: If we cannot dynamically change this structure and have it 
// picked up by host boot & occ, then we will want to add reserved 
// fields for each 'section' of the structure for future-proofing

typedef struct 
{
  // ------------------------------------  
  // Identification & Debug Flags
  // ------------------------------------  
  
  // Gives us a version number of this structure for ease of debug 
  uint8_t version;

  // Gives us a lot of debug flags that we can use to change OCC behavior
  // at startup.  
  uint8_t debug_reserved[7];



  // ------------------------------------ 
  // System Configuration 
  // ------------------------------------

  // Instead of system-type, lets try to send all system attributes 
  // that matter instead of having tables in OCC code.
  // @at014a - start
  eSystemType system_type;  // OCC usage of this byte is TBD

  // Processor HUID - HUID for this OCC processor, used by OCC for processor error call out
  uint64_t proc_huid;

  // Backplane HUID - Used by OCC for system backplane error call out (i.e. VRM errors will call out backplane)
  uint64_t backplane_huid;

  // APSS HUID - Used by OCC for APSS error call out
  uint64_t apss_huid;

  // DPSS HUID - Used by OCC for DPSS error call out
  uint64_t dpss_huid;
  // @at014a - end

  // Contains how many OCCs & how many proc modules are present.
  uint8_t sys_num_proc_present;
  
  // ------------------------------------
  // Max Frequency for each mode
  // ------------------------------------
  freqConfig_t sys_mode_freq;   // @th040

  // ------------------------------------  
  // APSS Configuration Data
  // ------------------------------------
  
  // Holds the gain/offset needed to translate from raw ADC to actual power 
  // measurements
  apssCalibrationData_t apss_cal[MAX_APSS_ADC_CHANNELS];

  // Holds the mapping of GPIO signals to APSS pins 
  apssGpioPinData_t apss_gpio_map;

  // Holds the mapping of ADC signals to APSS adc channels 
  apssAdcChannelData_t apss_adc_map;

  // GPIO Port Mode
  uint8_t apssGpioPortsMode[MAX_APSS_GPIO_PORTS];  // @at014a

  // ------------------------------------
  // Power Cap Configuration Data updated by Slaves
  // ------------------------------------
  pcap_config_data_t pcap;   // @th034

  // ------------------------------------
  // Master/Slave OCC Configuration Data
  // ------------------------------------

  // Information Needed to translate from PowerBus ID to PBAX Id (OCC Id)
  //   - Index = Powerbus Id will get you PBAX Id as value at that index 
  //   - Example pob2pbax_chip[1] = 4; (PowerBus ID 001 = PBAX ID 100
  uint8_t pob2pbax_chip[MAX_NUM_OCC];
  uint8_t pob2pbax_node[MAX_NUM_NODES];

  // Bitmask that states if OCC is present 
  // (i.e. 0x11 = Chip_Id 000 & Chip_Id 100 are only OCCs present)
  uint8_t is_occ_present;

  // Tells us which OCCs can be master & which OCC should start out as master
  masterCapability_t master_config;

  // ------------------------------------
  // Oversubscription Configuration Data
  // ------------------------------------
  // If it's ITE or non-ITE (enabled:ITE, non-enalbe: non-ITE)
  uint8_t failsafe_enabled;  // @at010a

  // ppb_fmax as set by Master OCC.  Initialized to 0xFFFF
  uint32_t master_ppb_fmax;   // @fk001a @at016c

  // --------------------------------------
  // HUID's for centaurs and dimms
  // --------------------------------------
  uint64_t centaur_huids[MAX_NUM_CENTAURS];
  uint64_t dimm_huids[MAX_NUM_CENTAURS][NUM_DIMMS_PER_CENTAUR];

  // --------------------------------------
  // Memory Throttle limits
  // --------------------------------------
  mem_throt_config_data_t mem_throt_limits[MAX_NUM_CENTAURS][NUM_MBAS_PER_CENTAUR];

} occSysConfigData_t;  __attribute__ ((__aligned__ (128)))

// @01a
extern occSysConfigData_t G_sysConfigData;


//*************************************************************************
// End of Sys Config Structure
//*************************************************************************

//*************************************************************************
// Individual OCC Config Structure
//*************************************************************************

// Needs to be 128 bytes aligned so we can do a DMA to transfer this to SRAM from
// Main Memory.

// One global structure per OCC (so there will be 8 up in main memory)

// TODO: If we cannot dynamically change this structure and have it 
// picked up by host boot & occ, then we will want to add reserved 
// fields for each 'section' of the structure for future-proofing

typedef struct 
{
  int dummy;  // @th010 - Removed un-needed Pstate Structure

} occModuleConfigData_t;  __attribute__ ((__aligned__ (128)))

//*************************************************************************
// End of Individual OCC Config Structure
//*************************************************************************

//*************************************************************************
// Globals
//*************************************************************************

// Default PstateSuperStructure that can be used instead of TMGT provided one.
extern const unsigned char G_defaultOccPstateSuperStructure[];

// MASTER PCAP values.  @at013a, @fk001c
extern pcap_config_data_t G_master_pcap_data;

//
extern uint16_t    G_conn_oc_pins_bitmap;

//*************************************************************************
// Function Prototypes
//*************************************************************************

//*************************************************************************
// Functions
//*************************************************************************
#ifdef FSPLESS_SIMICS
void sysConfigFspLess(void);
#endif 

/*****************************************************************************/
#endif // _occ_sys_config_h