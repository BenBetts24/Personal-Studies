#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Mar 14 22:51:13 2018

@author: benbetts24
"""
import numpy

annual_salary = int(input("Enter your annual salary: "))
semi_annual_raise = 0.07
r = 0.04/12
total_cost = 1000000
portion_down_payment = total_cost*0.25
hi = 10000
low = 0
guess = (hi + low)/2
epsilon = 100
guess_count = 0

def amount_saved(portion_saved):
    current_savings = 0
    monthly_salary = annual_salary/12
    for month_count in range(1, 37):
        current_savings += (portion_saved*monthly_salary)
        current_savings = (current_savings + (current_savings*r))
        if month_count % 6 == 0:
            monthly_salary += (monthly_salary*semi_annual_raise)
    return current_savings

while abs((amount_saved(guess/10000.0) - portion_down_payment)) >= epsilon and guess_count < numpy.log2(10000):
    if amount_saved(guess/10000.0) < portion_down_payment:
        low = guess
    else:
        hi = guess
    guess = (hi + low)/2
    guess_count += 1


if guess_count >= numpy.log2(10000):
    print("It is not possible to pay the down payment in three years.")    
else:
    print ("After ",str(guess_count)," guesses, the best rate is ",str(guess/10000.0),".")