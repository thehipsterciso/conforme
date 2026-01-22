//
//  XSDatetime.hpp
//  conforme
//
//  Created by Thomas on 1/15/18.
//  Copyright © 2018 Thomas Jones. All rights reserved.
//

#pragma once
#ifndef XSDATETIME_HPP
#define XSDATETIME_HPP

#include "ConformeDefinitions.hpp"
#include "ExceptionBase.hpp"

namespace conforme
{
    
    const __int64 TicksPerSecond = 10000000;
    const __int64 SecondsPerDay = 86400;
    const __int64 TicksPerDay = SecondsPerDay * TicksPerSecond;
    
    class DateTime
    {
        __int64 m_value;
        short    m_reserved[3];
        short    m_timezone;
        
        
        static CONFORME_DECLSPECIFIER __int64 Init(int year, unsigned char month, unsigned char day,
                                                 unsigned char hour, unsigned char minute, double second);
        
    public:
        static CONFORME_DECLSPECIFIER bool IsLeapYear(int year);
        enum {
            NO_TIMEZONE = -32768
        };
        
        explicit DateTime(__int64 value) : m_value(value), m_timezone(NO_TIMEZONE) {}
        DateTime() : m_value(0), m_timezone(NO_TIMEZONE) {}
        DateTime(__int64 value, short timezone) : m_value(value), m_timezone(timezone) {}
        CONFORME_DECLSPECIFIER DateTime(int year, unsigned char month, unsigned char day,
                                      unsigned char hour, unsigned char minute, double second);
        CONFORME_DECLSPECIFIER DateTime(int year, unsigned char month, unsigned char day,
                                      unsigned char hour, unsigned char minute, double second, short timezone);
        
        CONFORME_DECLSPECIFIER int Year() const;
        CONFORME_DECLSPECIFIER unsigned char Month() const;
        CONFORME_DECLSPECIFIER unsigned char Day() const;
        CONFORME_DECLSPECIFIER unsigned char Hour() const;
        CONFORME_DECLSPECIFIER unsigned char Minute() const;
        CONFORME_DECLSPECIFIER double Second() const;
        CONFORME_DECLSPECIFIER short Timezone() const { return m_timezone; }
        CONFORME_DECLSPECIFIER void SetTimezone(short tz) { m_timezone = tz; }
        CONFORME_DECLSPECIFIER bool HasTimezone() const { return m_timezone != NO_TIMEZONE; }
        
        /** Returns the day of year. 1-366 */
        CONFORME_DECLSPECIFIER int DayOfYear() const;
        
        /** Returns the week of the month */
        CONFORME_DECLSPECIFIER int WeekOfMonth() const;
        
        /** Returns the weekday, monday is zero (ISO-8601). */
        CONFORME_DECLSPECIFIER int Weekday() const { return (int)(( m_value / TicksPerDay ) % 7); }
        
        /** Returns the week number according to ISO-8601. */
        CONFORME_DECLSPECIFIER int Weeknumber() const;
        
        
        __int64 Value() const { return m_value; }
        CONFORME_DECLSPECIFIER __int64 NormalizedValue() const;
        
        CONFORME_DECLSPECIFIER static void GetDateFromTimeValue(__int64 tvTime, int& rnYear, int& rnMonth, int& rnDay);
    };
    
    
    class DayTimeDuration
    {
        __int64 m_value;
        
    public:
        DayTimeDuration() : m_value(0) {}
        CONFORME_DECLSPECIFIER DayTimeDuration(int days, int hours, int minutes, double seconds);
        explicit DayTimeDuration(__int64 value) : m_value(value) {}
        
        CONFORME_DECLSPECIFIER int Days() const;
        CONFORME_DECLSPECIFIER int Hours() const;
        CONFORME_DECLSPECIFIER int Minutes() const;
        CONFORME_DECLSPECIFIER double Seconds() const;
        
        __int64 Value() const { return m_value; }
        
        bool IsNegative() const { return m_value < 0; }
        bool IsPositive() const { return m_value > 0; }
    };
    
    
    class YearMonthDuration
    {
        int m_value;
        
    public:
        YearMonthDuration() : m_value(0) {}
        CONFORME_DECLSPECIFIER YearMonthDuration(int years, int months);
        explicit YearMonthDuration(int value) : m_value(value) {}
        
        CONFORME_DECLSPECIFIER int Years() const;
        CONFORME_DECLSPECIFIER int Months() const;
        
        int Value() const { return m_value; }
        
        bool IsNegative() const { return m_value < 0; }
        bool IsPositive() const { return m_value > 0; }
    };
    
    
    class Duration
    {
        DayTimeDuration dayTime;
        YearMonthDuration yearMonth;
        
    public:
        enum ParseType { DURATION, YEARMONTH, DAYTIME };
        
        Duration() {}
        Duration(const DayTimeDuration& dt) : dayTime(dt) {}
        Duration(const YearMonthDuration& ym) : yearMonth(ym) {}
        CONFORME_DECLSPECIFIER Duration(const YearMonthDuration& ym, const DayTimeDuration& dt);
        
        DayTimeDuration DayTime() const { return dayTime; }
        YearMonthDuration YearMonth() const { return yearMonth; }
        
        int Years() const { return yearMonth.Years(); }
        int Months() const { return yearMonth.Months(); }
        int Days() const { return dayTime.Days(); }
        int Hours() const { return dayTime.Hours(); }
        int Minutes() const { return dayTime.Minutes(); }
        double Seconds() const { return dayTime.Seconds(); }
        
        bool IsNegative() const { return dayTime.IsNegative() || yearMonth.IsNegative(); }
        bool IsPositive() const { return dayTime.IsPositive() || yearMonth.IsPositive(); }
    };
    
    
    // dateTime arithmetics
    CONFORME_DECLSPECIFIER DayTimeDuration operator- (const DateTime& first, const DateTime& second);
    
    CONFORME_DECLSPECIFIER DayTimeDuration operator- (const DayTimeDuration& x);
    CONFORME_DECLSPECIFIER DayTimeDuration operator+ (const DayTimeDuration& first, const DayTimeDuration& second);
    CONFORME_DECLSPECIFIER DayTimeDuration operator- (const DayTimeDuration& first, const DayTimeDuration& second);
    
    CONFORME_DECLSPECIFIER YearMonthDuration operator- (const YearMonthDuration& x);
    CONFORME_DECLSPECIFIER YearMonthDuration operator+ (const YearMonthDuration& first, const YearMonthDuration& second);
    CONFORME_DECLSPECIFIER YearMonthDuration operator- (const YearMonthDuration& first, const YearMonthDuration& second);
    
    CONFORME_DECLSPECIFIER DateTime operator+ (const DateTime& first, const DayTimeDuration& second);
    CONFORME_DECLSPECIFIER DateTime operator- (const DateTime& first, const DayTimeDuration& second);
    CONFORME_DECLSPECIFIER DateTime operator+ (const DateTime& first, const YearMonthDuration& second);
    CONFORME_DECLSPECIFIER DateTime operator- (const DateTime& first, const YearMonthDuration& second);
    
    CONFORME_DECLSPECIFIER DateTime operator+ (const DateTime& first, const Duration& second);
    CONFORME_DECLSPECIFIER DateTime operator- (const DateTime& first, const Duration& second);
    
    inline Duration operator-(const Duration& a) { return Duration(-a.YearMonth(), -a.DayTime()); }
    
    inline Duration operator+(const Duration& a, const Duration& b)
    {
        return Duration(a.YearMonth() + b.YearMonth(), a.DayTime() + b.DayTime() );
    }
    
    inline Duration operator-(const Duration& a, const Duration& b)
    {
        return Duration(a.YearMonth() - b.YearMonth(), a.DayTime() - b.DayTime() );
    }
    
    // these have their complexities...
    CONFORME_DECLSPECIFIER bool operator== (const DateTime& first, const DateTime& second);
    CONFORME_DECLSPECIFIER bool operator!= (const DateTime& first, const DateTime& second);
    CONFORME_DECLSPECIFIER bool operator< (const DateTime& first, const DateTime& second);
    inline bool operator> (const DateTime& first, const DateTime& second) { return second < first; }
    CONFORME_DECLSPECIFIER bool operator<= (const DateTime& first, const DateTime& second);
    inline bool operator>= (const DateTime& first, const DateTime& second) { return second <= first; }
    
    inline bool operator== (const DayTimeDuration& first, const DayTimeDuration& second) { return first.Value() == second.Value(); }
    inline bool operator!= (const DayTimeDuration& first, const DayTimeDuration& second) { return first.Value() != second.Value(); }
    inline bool operator< (const DayTimeDuration& first, const DayTimeDuration& second) { return first.Value() < second.Value(); }
    inline bool operator> (const DayTimeDuration& first, const DayTimeDuration& second) { return first.Value() > second.Value(); }
    inline bool operator<= (const DayTimeDuration& first, const DayTimeDuration& second) { return first.Value() <= second.Value(); }
    inline bool operator>= (const DayTimeDuration& first, const DayTimeDuration& second) { return first.Value() >= second.Value(); }
    
    inline bool operator== (const YearMonthDuration& first, const YearMonthDuration& second) { return first.Value() == second.Value(); }
    inline bool operator!= (const YearMonthDuration& first, const YearMonthDuration& second) { return first.Value() != second.Value(); }
    inline bool operator< (const YearMonthDuration& first, const YearMonthDuration& second) { return first.Value() < second.Value(); }
    inline bool operator> (const YearMonthDuration& first, const YearMonthDuration& second) { return first.Value() > second.Value(); }
    inline bool operator<= (const YearMonthDuration& first, const YearMonthDuration& second) { return first.Value() <= second.Value(); }
    inline bool operator>= (const YearMonthDuration& first, const YearMonthDuration& second) { return first.Value() >= second.Value(); }
    
    CONFORME_DECLSPECIFIER bool operator== (const Duration& first, const Duration& second);
    inline bool operator!= (const Duration& first, const Duration& second) { return !(first == second); }
    CONFORME_DECLSPECIFIER bool operator< (const Duration& first, const Duration& second);
    inline bool operator> (const Duration& first, const Duration& second) { return second < first; }
    CONFORME_DECLSPECIFIER bool operator<= (const Duration& first, const Duration& second);
    inline bool operator>= (const Duration& first, const Duration& second) { return second <= first; }
}

#endif /* XSDATETIME_H */


