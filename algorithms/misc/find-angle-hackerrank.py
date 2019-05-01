# -*- coding: utf-8 -*-
import math
x = int(raw_input())
y = int(raw_input())

angle = math.acos(y*1.0/math.sqrt(x*x + y*y))
print str(int(round(math.degrees(angle))))+"°"
