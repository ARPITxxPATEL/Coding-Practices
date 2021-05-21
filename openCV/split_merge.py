import cv2
import numpy as np

img = cv2.resize(cv2.imread('openCV/parrot-image.jpg',-1),(0,0),fx=0.1,fy=0.1)
cv2.imshow('Image',img)
blank = np.zeros(img.shape[:2],'uint8')

b,g,r = cv2.split(img)
cv2.imshow('Blue',cv2.merge([b,blank,blank]))
cv2.imshow('Green',cv2.merge([blank,g,blank]))
cv2.imshow('Red',cv2.merge([blank,blank,r]))

cv2.waitKey(0)
cv2.destroyAllWindows()