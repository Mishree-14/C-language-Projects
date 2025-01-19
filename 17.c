// REAL TIME DIGITAL CLOCK
#include<stdio.h>
#include<time.h>
#include<unistd.h>  //for sleep()
#include<stdlib.h>    //to make it a timer. for #ifdef...#endif

int main(){
    int choice;

    printf("Enter 1 for 24-hour format and 2 for 12-hour format.\n");
    scanf("%d",&choice);

    while(1){
        #ifdef _WIN32  //Use if for conditions you know at runtime. For platform-specific features or compile-time configurations (like #ifdef), stick with #ifdef.
            system("cls");  //WIN32 (or _WIN32) is a predefined macro provided by compilers targeting the Windows operating system. It is used to indicate that the code is being compiled for a Windows platform.
            //system("cls"); it is used for real time timer (like in phone).

        #endif  //#endif is used to mark the end of a preprocessor conditional block started by #ifdef
        
            time_t current_time;       //time_t is a datatype under time.h library.
            struct tm *local_time;     //struct tm is a predefined datatype which contains time,min,sec,month,weekday,etc.,.
            
            const char *day[50] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};

            current_time = time(NULL);  //time(NULL): This function gets the current time in seconds. Passing NULL tells it to use the system's clock.

            local_time = localtime(&current_time);   //converts current time into human readable format.

            switch(choice){
                case 1: {
                printf("Current time: %02d:%02d:%02d\n", local_time->tm_hour,local_time->tm_min,local_time->tm_sec);
                printf("Date: %02d/%02d/%02d",local_time->tm_mday,local_time->tm_mon + 1,local_time->tm_year + 1900);
                printf("\nDay: %s",day[local_time->tm_wday]);
                break;
                }
                case 2: {
                    int hour = local_time->tm_hour;
                    char *period = (hour>=12) ? "PM" : "AM";
                    hour = (hour>=12) ? hour % 12 : (hour == 0) ? 12 : hour;

                    // ? is a ternary operator. The ternary operator in C is a compact way to write an if-else statement. The syntax is:
                    // (condition) ? value_if_true : value_if_false;

                    printf("Current time: %02d:%02d:%02d %s\n",hour,local_time->tm_min,local_time->tm_sec,period);
                    printf("Date: %02d/%02d/%02d",local_time->tm_mday,local_time->tm_mon + 1,local_time->tm_year + 1900);
                    printf("\nDay: %s",day[local_time->tm_wday]);
                    break;
                }
            }
        sleep(1);    //Pauses the program for 1 second to make the clock update at real-time intervals. Without it, the clock would refresh too fast to be usable or visible.
    }

    return 0;
}