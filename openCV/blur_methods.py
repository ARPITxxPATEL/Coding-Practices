import cv2
import numpy as np

img = cv2.resize(cv2.imread('openCV/parrot-image.jpg',-1),(0,0),fx=0.1,fy=0.1)
cv2.imshow('Image',img)

blur = cv2.blur(img,(3,3))
cv2.imshow('blur',blur)

gauss = cv2.GaussianBlur(img,(3,3),0)
cv2.imshow('gauss',gauss)

median = cv2.medianBlur(img,3)
cv2.imshow('median',median)

bilateral = cv2.bilateralFilter(img,10,35,25)
cv2.imshow('bilateral',bilateral)

cv2.waitKey(0)
cv2.destroyAllWindows()