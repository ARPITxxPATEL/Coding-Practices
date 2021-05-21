import cv2
import numpy as np

blank = np.zeros((400,400),'uint8')
rect = cv2.rectangle(blank.copy(), (30,30), (370,370), 255, -1)
cv2.imshow('rectangle',rect)
circ = cv2.circle(blank.copy(), (200,200), 200, 255, -1)
cv2.imshow('circle',circ)

bitand = cv2.bitwise_and(rect,circ)
cv2.imshow('bitwise_and',bitand)

bitor = cv2.bitwise_or(rect,circ)
cv2.imshow('bitwise_or',bitor)

bitxor = cv2.bitwise_xor(rect,circ)
cv2.imshow('bitwise_xor',bitxor)

bitnot = cv2.bitwise_not(rect)
cv2.imshow('bitwise_not',bitnot)

cv2.waitKey(0)
cv2.destroyAllWindows()