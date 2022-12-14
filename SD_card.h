//JsonConfigFile.ino for reading config file !!!
#ifndef SD_CARD_H
#define SD_CARD_H
#include "Ublox.h"
#include "GPS_data.h"
#include <SD.h>
#include "ArduinoJson.h"

 
extern struct tm tmstruct ;
extern int Time_Set_OK;
extern int first_fix_GPS;
extern int wifi_search;
extern byte checksumA;
extern byte checksumB;
extern int sdTrouble;
extern bool sdOK,button;
extern bool GPS_logging;
extern float Mean_heading,heading_SD;
extern float calibration_bat;
extern float calibration_speed;
extern int time_out_nav_pvt;
extern byte mac[6];
extern char SW_version[16];
extern char RTC_Sleep_txt[32];
extern GPS_speed M100;
extern GPS_speed M250;
extern GPS_speed M1852;
extern GPS_time S2;
extern GPS_time s2;
extern GPS_time S10;
extern GPS_time s10;
extern Alfa_speed A250;
extern GPS_data Ublox; // create an object storing GPS_data, definition in RTOS
extern int nav_pvt_message_nr; 
extern int RTC_Board_Logo;
extern int RTC_Sail_Logo;
extern int RTC_SLEEP_screen;
extern int RTC_OFF_screen;
struct Config {
  float cal_bat=1.74;//calibration for read out bat voltage
  float cal_speed=3.6;//conversion m/s to km/h, for knots use 1.944
  int sample_rate=1;//gps_rate in Hz, 1, 5 or 10Hz !!!
  int gnss=2;//default setting 2 GNSS, GPS & GLONAS
  int field=1;//choice for first field in speed screen !!!
  int speed_large_font=0;//fonts on the first line are bigger, actual speed font is smaller
  int dynamic_model=0;//choice for dynamic model "Sea",if 0 model "portable" is used !!
  int timezone=2;//choice for timedifference in hours with UTC, for Belgium 1 or 2 (summertime)
  int Stat_screens=123;//choice for stats field when no speed, here stat_screen 1, 2 and 3 will be active
  int GPIO12_screens=123;//choice for stats field when gpio12 is activated (pull-up high, low = active)
  int Stat_screens_persist=123;//choice for stats field when no speed, here stat_screen 1, 2 and 3 will be active / for resave the config
  int GPIO12_screens_persist=123;//choice for stats field when gpio12 is activated (pull-up high, low = active) / for resave the config
  int Board_Logo=1;
  int Sail_Logo=1;
  int stat_screen[10];//which stat_screen you want to see ?
  int gpio12_screen[10];//which stat_screen when gpio 12 toggles ?
  int screen_count=0;
  int gpio12_count=0;
  int sleep_off_screen=11;
  int stat_speed=1;//max speed in m/s for showing Stat screens
  int bar_length=1852;//choice for bar indicator for length of run in m (nautical mile)
  bool logCSV=0;//not used anymore...
  bool logUBX=1;//log to .ubx
  bool logSBP=1;//log to .sbp
  bool logGPY=1;//log to .gps
  bool logGPX=0;//log to .gpx
  char UBXfile[32]="BN220A000";//your preferred filename
  char Sleep_info[32]="Your ID";//your preferred sleep text
  char ssid[32];//your SSID
  char password[32];//your password
  int config_fail=0;
  } ;
extern Config config;
extern void AddString();
void logERR( const char * message);
void Open_files(void);
void Close_files(void);
void Flush_files(void);
void Log_to_SD(void); 
void loadConfiguration(const char *filename, const char *filename_backup, Config &config) ;
void Model_info(int model);
void printFile(const char *filename);
void Session_info(GPS_data G);
void Session_results_M(GPS_speed M);
void Session_results_S(GPS_time S);
void Session_results_Alfa(Alfa_speed A,GPS_speed M);
/*
void log_header_SBP(void);
void log_SBP(void);
*/
#endif
