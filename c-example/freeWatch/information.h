#ifndef __information
#define __information


typedef enum 
{
    INF_LAT,
    INF_LON,
   
    INF_DEST_LAT,
    INF_DEST_LON,

    
    INF_GPS_YEAR_UTC,
    INF_GPS_MONTH_UTC,
    INF_GPS_DAY_UTC,

    INF_GPS_HOUR_UTC,
    INF_GPS_MINUTE_UTC,
    INF_GPS_SECOND_UTC,     
 
    INFORMATION_TYPE_COUNT
} Information;

void INFORMATION_init();
float INFORMATION_get(Information i);
void INFORMATION_set(Information i, float value);




#endif
