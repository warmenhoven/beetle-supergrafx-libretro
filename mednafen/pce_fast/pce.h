#ifndef _PCE_H
#define _PCE_H

#include <vector>

#include "../mednafen-types.h"
#include "../mednafen.h"
#include "../state.h"
#include "../general.h"
#include "../mednafen-memory.h"
#include "psg.h"

#define MEDNAFEN_CORE_NAME_MODULE "pce_fast"
#define MEDNAFEN_CORE_NAME "Mednafen SuperGrafx"
#define MEDNAFEN_CORE_VERSION "v0.9.41"
#define MEDNAFEN_CORE_EXTENSIONS "pce|sgx|cue|ccd|chd"
#define MEDNAFEN_CORE_TIMING_FPS 59.82
#define MEDNAFEN_CORE_GEOMETRY_BASE_W 512
#define MEDNAFEN_CORE_GEOMETRY_BASE_H 243
#define MEDNAFEN_CORE_GEOMETRY_MAX_W 512
#define MEDNAFEN_CORE_GEOMETRY_MAX_H 243
#define MEDNAFEN_CORE_GEOMETRY_ASPECT_RATIO (6.0 / 5.0)
#define FB_WIDTH 512
#define FB_HEIGHT 243

#define PCE_MASTER_CLOCK        21477272.727273

#define DECLFR(x) uint8 MDFN_FASTCALL x (uint32 A)
#define DECLFW(x) void MDFN_FASTCALL x (uint32 A, uint8 V)

extern uint8 ROMSpace[0x88 * 8192 + 8192];

typedef void (MDFN_FASTCALL *writefunc)(uint32 A, uint8 V);
typedef uint8 (MDFN_FASTCALL *readfunc)(uint32 A);

extern uint8 PCEIODataBuffer;

bool PCE_InitCD(void) MDFN_COLD;

#include "huc6280.h"

extern bool PCE_ACEnabled; // Arcade Card emulation enabled?
void PCE_Power(void) MDFN_COLD;

extern int pce_overclocked;

extern uint8 BaseRAM[32768 + 8192];
extern bool PCE_IsCD;

int LoadCD(std::vector<CDIF *> *CDInterfaces);
void Load(const char *name, MDFNFILE *fp);
void DoSimpleCommand(int cmd);
void CloseGame(void);
void Emulate(EmulateSpecStruct *espec);

extern PCEFast_PSG *psg;
extern bool IsSGX;

extern uint8 ROMSpace[0x88 * 8192 + 8192];
extern uint8 BaseRAM[32768 + 8192];

#endif
