#include "Date.h"

// Date constructor
Date::Date(int year, int month, int day) { 
	SetDate(year, month, day); // violates cppcoreguidelines to demonstrate a concept
}

// Date member function
void Date::SetDate(int year, int month, int day) noexcept {
  m_month = month;
  m_day =day;
  m_year= year;
}