class Time
{

public:
	Time();
	~Time();

	String getTimeMilitary(void);
	String getTimeClassic(void);

	void setTime(int h, int m, int s);

	int getHour(void);
	int getMinute(void);
	int getSecond(void);

	int convertToSeconds(int fullHour, int fullMinute, int fullSecond);

	String setAlarm(int lateHour, int lateMinute, int lateSecond);
	String kitchenTimer(int timerAmount);

private:
	static int hour;
	static int minute;
	static int second;
};
