import math

a = 3
b = 7
c = 9

angleC = math.acos((a**2+b**2-c**2)/(2*a*b))
angleB = math.acos((a**2+c**2-b**2)/(2*a*c))
angleA = math.acos((b**2+c**2-a**2)/(2*b*c))

print(f'Angle A: {angleA}, Angle B: {angleB}, Angle C: {angleC}')