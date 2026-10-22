#pragma once
#include <WiFi.h>
#include <HTTPClient.h>

class Kolko 
{
public:
  void setup();
  int send(float);
  String get();
};
