        Time::Time(){
            hour = 24;
            minute = 0;
            second = 0;
        }

	Time::~Time()
	{
	}

        String Time::getTimeMilitary(void) {
                return hour + ":" + minute + ":" + second;
        }

        String Time::getTimeClassic(void) {
                if (hour >= 12){
                    return hour - 12 + ":" + minute + ":" + second "PM";
                }
                else {
                    return hour + ":" + minute + ":" + second "AM";
                }
        }

        void Time::setTime(int h, int m, int s) {
               hour = h;
               minute = m;
               second = s;
        }

        int Time::getHour(void){
            return hour;
        }

        int Time::getMinute(void){
            return minute;
        }

        int Time::getSecond(void){
            return second;
        }

        int Time::convertToSeconds(int fullHour, int fullMinute, int fullSecond){
            return (fullHour * 3600) + (fullMinute * 60) + (fullSecond);
        }



    //the 'late' variables will be the time that the alarm is set to go off
        String Time::setAlarm(int lateHour, int lateMinute, int lateSecond)
        {
                //This is our current time
                int h = hour;
                int m = minute;
                int s = second;

                //Convert to seconds, way easier to deal with
                timeInSeconds = 0;

                currentTimeInSeconds = convertToSeconds(h,m,s);
                alarmTimeInSeconds = convertToSeconds(lateHour,lateMinute,lateSecond);

                //What if I set alarm for 800 at 2300?
                if((currentTimeInSeconds - alarmTimeInSeconds) < 0)
                {
                    return "Invalid Alarm Entry";
                }
                else
                {
                        while(timer < (currentTimeInSeconds-alarmTimeInSeconds))
                        {
                                timer += 1;
                                sleep(1); //sleeps one second, adds +1 to timer.

                        } //end score while

                        return "Alarm!";
                } //end else statement

        } //end function

        //Returns a string when the seconds passed are reached
        String Time::kitchenTimer(int timerAmount)
        {
                //Filler variable to hold timer count
                int count = 0;

                //Check for moronic users trying to be funny
                if(timerAmount < 0)
                {
                        return "Invalid countdown amount!\n";
                }
                else
                {
                        //Add one to count and sleep for one second until target seconds are reached
                        while(count < timerAmount)
                        {
                                count += 1;
                                sleep(1);
                        }

                        return "Ring, ring! Timer done!\n";
                }
        }

} //end scope main
