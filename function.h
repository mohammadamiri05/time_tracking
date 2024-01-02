/*
Author : mohammad amiri  
date: 16/9/1402
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

//--------------------------------------------------------------------------------------

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