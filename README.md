# ESP8266ZabbixSender
Library to realize the zabbix-sender on ESP8266-Arduino

# How to install library to Arduino IDE
## Use git command
(Windows and default arduino setting)

    cd %USERPROFILE%\Documents\Arduino\libraries
    git clone https://github.com/erscl/ESP8266ZabbixSender.git
## Use ZIP import function of the Arduino IDE
Google it

# Usage
See `sample_ESP8266ZabbixSender/sample_ESP8266ZabbixSender.ino`
    ESP8266ZabbixSender zSender;
    zSender.Init(IPAddress(192, 168, 35, 14), 10051, "IOTBOARD_00"); // Init zabbix server address, port, and hostname of item
    zSender.ClearItem(); // clear item list
    zSender.AddItem("air.temp", 29.62); // add item such as air temperture
    zSender.AddItem("air.hum", 70.60); // add item such as air humidity
    if (zSender.Send() == EXIT_FAILURE){ // send packet
        // error handling
    }

Refer to the following repository for more information.  
  
https://github.com/erscl/esp8266_zabbixtemp
