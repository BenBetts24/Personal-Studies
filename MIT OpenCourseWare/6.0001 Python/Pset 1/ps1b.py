#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Mar 14 22:36:17 2018

@author: benbetts24
"""

annual_salary = int(input("Enter your annual salary: "))
monthly_salary = annual_salary/12
portion_saved = float(input("Enter the percent of your salary to be saved, as a decimal: "))
total_cost = int(input("Enter the cost of your dream home: "))
semi_annual_raise = float(input("Enter the semi-annual raise, as a decimal: "))
portion_down_payment = total_cost*0.25
current_savings = 0
month_count = 0
r = 0.04/12

while current_savings < portion_down_payment:
        current_savings += (portion_saved*monthly_salary)
        current_savings = (current_savings + (current_savings*r))
        month_count += 1
        if month_count % 6 == 0:
            monthly_salary = (monthly_salary + (monthly_salary*semi_annual_raise))

print("Number of months: ",month_count)