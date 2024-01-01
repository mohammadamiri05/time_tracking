/*
mohammad amiri      16/9/1402
*/

#include<iostream>
#include<windows.h>
using namespace std;

//_______________________________________________________________________________________________________

/// @brief فاصله ی زمانی بین ساعت شروع و پایان را بر حسب دقیقه محاسبه می کند
/// @param start_hour 
/// @param start_minute 
/// @param end_hour 
/// @param end_minute 
/// @return مدت زمانی که طول کشیده است بر حسب دقیقه
int count_delta_time( int start_hour , int start_minute , int end_hour , int end_minute );

//--------------------------------------------------------

/// @brief مجموع دقایق را بر ورودی سوم تقسیم و آن را به ساعت و دقیقه تبدیل می کند و بعد از متن مورد نظر چاپ میکند
/// @param total 
/// @param titel 
/// @param diviser=1 
void print_standard( int total , string titel , int diviser = 1 );

//---------------------------------------------------------

/// @brief if number > a :ary[0] += number ; if  a > number > b:ary[1] += number ;  else : ary[2] += number .
/// @param number 
/// @param a_plus 
/// @param b_plus 
/// @param ary 
void plus_number_to_3_period( int number , int a_plus , int b_plus , int ary[] );

//---------------------------------------------------------


//_______________________________________________________________________________________________________

int main()
{
    int  day = 0 , time_work  , delta_time_work; // مقادیر روزانه
    const int  standard_time_work = 8 * 60 ; // حداقل ساعت کار کرد لازم شرکت
    const int  allowable_delay_time = 15 , allowable_leave_soon = 15 ; //  زمان تاخیر و تعجیل مجاز
    int  hour_start , hour_end  , minute_start , minute_end ; // اطلاعات ورودی از کاربر
    int  total = 0 ; // محاسبه مجموع ساعات کار
    int  total_low_time = 0 , total_overtime = 0 ; // محاسبه مجموع ساعات کسر کار و اضافه کار
    int  average  ; // محاسبه میانگین ساعات کار
    int  total_of_start = 0  ; // محاسبه ساعت معمول شروع
    int  total_of_end = 0 ;  // محاسبه ساعت معمول پایان
    int  start_ary[3] = { 0, 0 , 0 } , delta_time_start  ; //   محاسبه مجموع ساعات تاخیر مجاز و غیر مجاز و زودتر رسیدن
    int  end_ary[3] = { 0 , 0 , 0 } , delta_time_end ; // محاسبه مجموع ساعات تعجیل مجاز و غیر مجاز و دیرتر از سرکار رفتن
    int  work_ary[3] = { 0 , 0 ,0 } ;
    int  max_work = 0 , min_work = 24 * 60 ; // ماکسیمم و مینیمم کار در یک روز
    string  date_today ;
    string  date_max , date_min;  // دریافت تاریخ هایی که بیشتر و کمتر سر کار رفته است

    while(1)
    {
        cout << "please enter date of today. \nafter the end of the working period enter (end) . \n" ;
        cin >> date_today ;
        if( date_today == "end" )
        {
            break; 
        }

        while(1)
        {
            cout << "please enter your start time: \n" ;
            cin >> hour_start >> minute_start ;
            if( hour_start >= 24 || hour_start < 0 || minute_start < 0 || minute_start > 60 )
            {
                system("color 4");
                cout << "[ERROR]:please enter the correct time!!!";
                Sleep(3000) ;
                system("cls") ;
                system("color 7") ;
                continue ;
            }
            else 
            {
                system("color 2") ;
                cout << "have a good day.\n" ;
                Sleep(2000) ;
            }

            break ;
        }

        while(1)
        {
            system("color 7") ;
            cout << "please enter your end time: \n" ;
            cin >> hour_end >> minute_end ; 
            if( hour_end > 24 || hour_end < 0 || minute_end < 0 || minute_end > 60 )
            {
                system("color 4") ;
                cout << "[ERROR]:please enter the correct time!!!";
                Sleep(3000) ;
                system("cls") ;
                continue ;

            }
            else 
            {
                system("cls") ;
            }
            break ;
        }

        time_work = count_delta_time( hour_start , minute_start , hour_end , minute_end ) ;//مجموع دقایق کار در یک روز
        total += time_work ; // مجموع دقایق کار در کل بازه

        total_of_start += count_delta_time(  0 , 0 ,  hour_start , minute_start ) ;
        total_of_end += count_delta_time(  0 , 0 ,  hour_end , minute_end ) ;

        // محاسبه مجموع اضافه کار و کسر کار -----------------------------

        delta_time_work = time_work - standard_time_work ;// اختلاف ساعت کار کرد با حداقل ساعت کار کرد لازم شرکت
        plus_number_to_3_period( delta_time_work , 0 , 0 , work_ary ) ;

        // محاسبه مجموع دقایق تاخیر مجاز و غیر مجاز و زودتر سرکار حاظر شدن -----------------------------

        delta_time_start = count_delta_time( 7 , 30  , hour_start , minute_start) ;
        plus_number_to_3_period( delta_time_start , allowable_delay_time , 0 , start_ary ) ;
        
        // محاسبه مجموع دقایق تعجیل مجاز و غیر مجاز و دیرتر از سرکار رفتن -----------------------------

        delta_time_end = count_delta_time( hour_end , minute_end , 15 , 30  ) ;
        plus_number_to_3_period( delta_time_end , allowable_leave_soon , 0 , end_ary ) ;

        // ---------------------------------------------

        if( time_work >= max_work )
        {
            max_work = time_work ;
            date_max = date_today ;

        }

        if( time_work <= min_work )
        {
            min_work = time_work ;
            date_min = date_today ;

        }



        day += 1 ;
    }

    system("cls") ;

    
    //==================================================================================================

    // مجموع روز های کاری : ---------------------------------------

    cout << "in total,you worked for "<< day << " days. \n" ;

    //- مجموع ساعت کار : -------------------------------------------

    print_standard( total , "your total working hours is" , 1) ;

    //-- مجموع ساعت اضافه کار : ------------------------------------

    print_standard( work_ary[0] , "your total overtime work is" , 1 ) ;

    //--- مجموع ساعت کسر کار : -------------------------------------

    print_standard( -work_ary[2] , "your total low time work is" , 1 ) ;

    //---- میانگین ساعت کار در یک روز : -------------------------------

    print_standard( total , "your average working hours is" , day ) ; 

    //----- ماکسیمم ساعت کار در یک روز : ---------------------------

    print_standard( max_work , "your maximum time work in a day is" , 1 ) ;
    cout << "on " << date_max << endl ;

    //------ مینیمم ساعت کار در یک روز : ----------------------------

    print_standard (min_work , "your minimum time work in a day is" , 1 ) ;
    cout << "on " << date_min << endl ;

    //------- ساعت معمول شروع کار : -----------------------------------

    print_standard( total_of_start , "your usual start time is" , day ) ;

    //-------- ساعت معمول پایان کار : ----------------------------------

    print_standard( total_of_end , "your usual end time is" , day ) ;
    
    //--------- مجموع ساعات تاخیر مجاز : -------------------------------

    print_standard( start_ary[1] , "your total allowed delay are", 1 ) ;

    
    //---------- مجموع ساعات تاخیر غیر مجاز : --------------------------

    print_standard( start_ary[0] , "your total illegal delay are", 1 ) ;

    //----------- مجموع ساعاتی که زود تر سر کار حاظر شده است : --------

    print_standard( -start_ary[2] , "the total numnber of hours you have come to work earlier is ", 1 ) ;

    //----------- مجموع ساعات تعجیل مجاز : -----------------------------

    print_standard( end_ary[1] , "your total allowed leave soon is ", 1 ) ;

   //------------ مجموع ساعات تعجیل غیر مجاز : -------------------------

    print_standard( end_ary[0] , "your total illegal leave soon is ", 1 ) ;

    //-------------- مجموع ساعاتی که دیرتر از سرکار برگشته است : -------

    print_standard( -end_ary[2] , "your total number of hours you have left the office late is ", 1 ) ;

    return 0;
}

//_____________________________________________________________________________________________________

int count_delta_time( int start_hour , int start_minute , int end_hour , int end_minute)
{
    int delta_hour , delta_minutes , sum  ;

    delta_hour = end_hour - start_hour ;
    delta_minutes = end_minute - start_minute ; 
    sum = 60 * delta_hour + delta_minutes ; 

    return sum ;
}

 //-------------------------------------------------------------

void print_standard( int total , string titel , int diviser  )
{
    int hour , minute ;

    total = total / diviser ;
    hour = total / 60 ;
    minute = total % 60 ; 
    cout <<  titel << " " << hour << " hour and " << minute << " minute.\n" ;

}

//---------------------------------------------------------------

void plus_number_to_3_period( int number , int a_plus , int b_plus , int ary[] )
{
    if( number > a_plus )
    {
        ary[0] += number ;
    }
    else if( number > b_plus )
    {
        ary[1] += number ;
    }
    else 
    {
        ary[2] += number ;
    }

}

// void plus_to_period_a_or_b_or_C( int number , int a_plus , int b_plus , int& period_a , int& period_b , int& period_c )
// {
//     if( number > a_plus )
//     {
//         period_a += number ;
//     }
//     else if( number > b_plus )
//     {
//         period_b += number ;
//     }
//     else 
//     {
//         period_c += number ;
//     }

// }

//---------------------------------------------------------------


 