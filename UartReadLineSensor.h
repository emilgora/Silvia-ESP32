class boilerSensor : public PollingComponent,  public UARTDevice, public TextSensor {
 public:
  boilerSensor(UARTComponent *parent) : PollingComponent(1000), UARTDevice(parent) {}

  String line;
  String lastpublished;
  
  void setup() override {
    // nothing to do here
  }
  void loop() override {
    while (available() > 0) {
      line = readStringUntil('\n');
      line.trim();
      ESP_LOGD("custom", "RFID read.");
      yield();
    }
  }

  void update() override {
    if (line != lastpublished) {
      publish_state(line.c_str());
      lastpublished = line;
    }
  }
  
};

class groupSensor : public PollingComponent,  public UARTDevice, public TextSensor {
 public:
  groupSensor(UARTComponent *parent) : PollingComponent(1000), UARTDevice(parent) {}

  String line;
  String lastpublished;
  
  void setup() override {
    // nothing to do here
  }
  void loop() override {
    while (available() > 0) {
      line = readStringUntil('\n');
      line.trim();
      ESP_LOGD("custom", "RFID read.");
      yield();
    }
  }

  void update() override {
    if (line != lastpublished) {
      publish_state(line.c_str());
      lastpublished = line;
    }
  }
  
};