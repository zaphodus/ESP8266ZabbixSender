#ifndef _ESP8266ZABBIXSENDER_H_
#define _ESP8266ZABBIXSENDER_H_

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <ESP8266WiFi.h>
#define ZABBIXMAXLEN 256 // max 256byte packet
#define ZABBIXMAXITEM 50 // max 50 items
#define ZABBIXTIMEOUT 1000 // 1000ms

class ESP8266ZabbixSender {
public:
	ESP8266ZabbixSender(void);
	void Init(IPAddress ZabbixServerAddr, uint16_t ZabbixServerPort, String ZabbixItemHostName);
	int Send(void);
	void ClearItem(void);
	void AddItem(String key, float value);

private:
	int createZabbixPacket(void);
	struct zabbixCell {
		String key;
		float val;
	};
	WiFiClient zClient;
	IPAddress zAddr;
	uint16_t zPort;
	String zItemHost;
	uint8_t zabbixPacket[ZABBIXMAXLEN];
	zabbixCell zabbixItemList[ZABBIXMAXITEM];
	int zabbixItemSize;
};

#endif