import cv2
import numpy as np

org = cv2.imread('openCV/parrot-image.jpg',-1)
img = cv2.resize(org, (0,0), fx=0.1, fy=0.1)
cv2.imshow('Image',img)
blank = np.zeros(img.shape,dtype='uint8')

gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
cv2.imshow('Gray',gray)

ret,thresh = cv2.threshold(gray,100,255,cv2.THRESH_BINARY)
cv2.imshow('Thresh',thresh)

contours, hierarchies = cv2.findContours(thresh, cv2.RETR_LIST, cv2.CHAIN_APPROX_SIMPLE)
cv2.drawContours(blank, contours, -1, (0,0,255), 1)

cv2.imshow('contours',blank)

cv2.waitKey(0)
cv2.destroyAllWindows()