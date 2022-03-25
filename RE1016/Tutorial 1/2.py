# Consider a triangle with sides of length 3, 7, and 9. The law of cosines states that given three sides 
# of a triangle (a, b, and c) and the angle C between sides a and b: 
# 𝑐**2 = 𝑎**2 + 𝑏**2 − 2 ∗ 𝑎 ∗ 𝑏 ∗ cos (𝐶)
# Write Python code to calculate the three angles in the triangle.
# Hint: math module will be useful

import math

a = 3
b = 7
c = 9

angleC = math.acos((a**2+b**2-c**2)/(2*a*b))
angleB = math.acos((a**2+c**2-b**2)/(2*a*c))
angleA = math.acos((b**2+c**2-a**2)/(2*b*c))

print(f'Angle A: {angleA}, Angle B: {angleB}, Angle C: {angleC}')