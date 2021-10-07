#pragma once

double calculate_total_price(double meal_price) {

    double const LEE_COUNTY_SALES_TAX_RATE = .07;
    double const TIP_RATE = .2;
    // processing
    double tax{ };
    tax = meal_price * LEE_COUNTY_SALES_TAX_RATE;
    double tip{ };
    tip = meal_price * TIP_RATE;
    double total_price{ };
    total_price = meal_price + tax + tip;
    return total_price;

}