int WIND_SENSOR_CSN_PIN = 25;
int WIND_SENSOR_CLK_PIN = 27;
int WIND_SENSOR_DO_PIN = 29;
unsigned int value;
double angle;

void setup() {
    pinMode(WIND_SENSOR_CSN_PIN, OUTPUT);
    pinMode(WIND_SENSOR_CLK_PIN, OUTPUT);
    pinMode(WIND_SENSOR_DO_PIN, INPUT);
    Serial.begin(115200);
}


void loop() {
value=0;

	digitalWrite(WIND_SENSOR_CSN_PIN, LOW);
	delayMicroseconds(1); //Waiting for Tclkfe

	//Passing 10 times, from 0 to 9
	for(int x=0; x<10; x++){
		digitalWrite(WIND_SENSOR_CLK_PIN, LOW);
		delayMicroseconds(1); //Tclk/2
		digitalWrite(WIND_SENSOR_CLK_PIN, HIGH);
		delayMicroseconds(1); //Tdo valid, like Tclk/2
		value = (value << 1) | digitalRead(WIND_SENSOR_DO_PIN);   //shift all the entering data to the left and past the pin state to it. 1e bit is MSB
		//(value << 1) |
	}

	digitalWrite(WIND_SENSOR_CSN_PIN, HIGH);
	angle = correctForDeviance(map(calibrateWind(value), 0, 1023, 0, 359));
    Serial.println(angle);
}

int calibrateWind(int direction) {
	unsigned int offset = 501;
    if (direction >= offset) {
        return direction - offset;
    } else {
        return 1024 - (offset - direction);
    }
}

double correctForDeviance(int measuredValue) {
    double approximateDeviation = -0.4759023065384822 + measuredValue*5.35825521e-09 + pow(measuredValue, 2)*2.56776553e-07 + pow(measuredValue, 3)*1.08355370e-05 - pow(measuredValue, 4)*4.89308845e-08 - pow(measuredValue, 5)*2.25999687e-10 + pow(measuredValue, 6)*1.97994121e-12 - pow(measuredValue, 7)*4.79177029e-15 + pow(measuredValue, 8)*4.00137323e-18;
	if(measuredValue+approximateDeviation < 0) return 0;
	else return measuredValue + approximateDeviation;
}