#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Mar 14 21:54:49 2018

@author: benbetts24
"""

annual_salary = int(input("Enter your annual salary: "))
monthly_salary = annual_salary/12
portion_saved = float(input("Enter the percent of your salary to be saved, as a decimal: "))
total_cost = int(input("Enter the cost of your dream home: "))
portion_down_payment = total_cost*0.25
current_savings = 0
month_count = 0
r = 0.04/12

while current_savings < portion_down_payment:
    current_savings += (portion_saved*monthly_salary)
    current_savings = (current_savings + (current_savings*r))
    month_count += 1

print("Number of months: ",month_count)