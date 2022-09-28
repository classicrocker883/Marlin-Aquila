/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2021 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

/**
 * DWIN general defines and data structs for PRO UI
 * Author: Miguel A. Risco-Castillo (MRISCOC)
 * Version: 3.11.2
 * Date: 2022/02/28
 */

#define HAS_GCODE_PREVIEW 1
#define HAS_PIDPLOT 1
#define HAS_ESDIAG 1
#define HAS_LOCKSCREEN 1
#define MESH_EDIT_MENU
//#define DEBUG_DWIN 1
//#define NEED_HEX_PRINT 1

#include "../../../inc/MarlinConfigPre.h"
#include "../common/dwin_color.h"
#if ENABLED(LED_CONTROL_MENU)
  #include "../../../feature/leds/leds.h"
#endif
#include <stddef.h>

#if defined(__STM32F1__) || defined(STM32F1)
  #define DASH_REDRAW 1
#endif

#define Def_Background_Color  Color_Bg_Black //
#define Def_Cursor_color      Color_Cyan //
#define Def_TitleBg_color     Color_Voxelab_Red //
#define Def_TitleTxt_color    Color_White
#define Def_Text_Color        Color_White
#define Def_Selected_Color    Select_Color
#define Def_SplitLine_Color   Color_White //
#define Def_Highlight_Color   Color_White
#define Def_StatusBg_Color    Color_Bg_Black //
#define Def_StatusTxt_Color   Color_Yellow
#define Def_PopupBg_color     Color_Bg_Window
#define Def_PopupTxt_Color    Popup_Text_Color
#define Def_AlertBg_Color     Color_Bg_Red
#define Def_AlertTxt_Color    Color_Yellow
#define Def_PercentTxt_Color  Percent_Color
#define Def_Barfill_Color     BarFill_Color
#define Def_Indicator_Color   Color_Cyan //
#define Def_Coordinate_Color  Color_Brown //
#define Def_Button_Color      Color_Voxelab_Red //
#if BOTH(LED_CONTROL_MENU, HAS_COLOR_LEDS)
  #define Def_Leds_Color      LEDColorWhite()
#endif

typedef struct {
  // Color settings
  uint16_t Background_Color = Def_Background_Color;
  uint16_t Cursor_color     = Def_Cursor_color;
  uint16_t TitleBg_color    = Def_TitleBg_color;
  uint16_t TitleTxt_color   = Def_TitleTxt_color;
  uint16_t Text_Color       = Def_Text_Color;
  uint16_t Selected_Color   = Def_Selected_Color;
  uint16_t SplitLine_Color  = Def_SplitLine_Color;
  uint16_t Highlight_Color  = Def_Highlight_Color;
  uint16_t StatusBg_Color   = Def_StatusBg_Color;
  uint16_t StatusTxt_Color  = Def_StatusTxt_Color;
  uint16_t PopupBg_color    = Def_PopupBg_color;
  uint16_t PopupTxt_Color   = Def_PopupTxt_Color;
  uint16_t AlertBg_Color    = Def_AlertBg_Color;
  uint16_t AlertTxt_Color   = Def_AlertTxt_Color;
  uint16_t PercentTxt_Color = Def_PercentTxt_Color;
  uint16_t Barfill_Color    = Def_Barfill_Color;
  uint16_t Indicator_Color  = Def_Indicator_Color;
  uint16_t Coordinate_Color = Def_Coordinate_Color;
  uint16_t Button_Color     = Def_Button_Color;
  // Temperatures
  #if HAS_HOTEND && defined(PREHEAT_1_TEMP_HOTEND)
    int16_t HotendPidT = PREHEAT_1_TEMP_HOTEND;
  #endif
  #if HAS_HEATED_BED && defined(PREHEAT_1_TEMP_BED)
    int16_t BedPidT = PREHEAT_1_TEMP_BED;
  #endif
  #if HAS_HOTEND || HAS_HEATED_BED
    int16_t PidCycles = 5;
  #endif
  #if ENABLED(PREVENT_COLD_EXTRUSION)
    int16_t ExtMinT = EXTRUDE_MINTEMP;
  #endif
  #if BOTH(HAS_HEATED_BED, PREHEAT_BEFORE_LEVELING)
    int16_t BedLevT = LEVELING_BED_TEMP;
  #endif
  TERN_(BAUD_RATE_GCODE, bool Baud250K = (BAUDRATE == 250000));
  bool FullManualTramming = false;
  #if ENABLED(MESH_BED_LEVELING)
    float ManualZOffset = 0;
  #endif
  // Led
  #if BOTH(LED_CONTROL_MENU, HAS_COLOR_LEDS)
    LEDColor Led_Color = Def_Leds_Color;
  #endif
  bool SetLiveMove = false;
} HMI_data_t;

static constexpr size_t eeprom_data_size = sizeof(HMI_data_t);
extern HMI_data_t HMI_data;
