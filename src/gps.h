#include <TinyGPS++.h>
#include <SoftwareSerial.h>

TinyGPSPlus gps;

// GPS Serial pins
#define GPS_RX 19
#define GPS_TX 18

HardwareSerial &gpsSerial = Serial1;

String getCoordinates()
{
    while (gpsSerial.available() > 0)
    {
        char c = gpsSerial.read();
        if (gps.encode(c))
        {
            if (gps.location.isValid())
            {
                String latitude = String(gps.location.lat(), 6);
                String longitude = String(gps.location.lng(), 6);
                return "Lat: " + latitude + ", Lon: " + longitude;
            }
        }
    }
    return "";
}
