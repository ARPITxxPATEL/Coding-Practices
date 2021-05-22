import cv2
import numpy as np

img = cv2.resize(cv2.imread('openCV/parrot-image.jpg',-1),(0,0),fx=0.1,fy=0.1)
cv2.imshow('Image',img)

blank = np.zeros(img.shape[:2],'uint8')

rect = cv2.rectangle(blank.copy(),(img.shape[1]//2-50,img.shape[0]//2-50),(img.shape[1]//2+50,img.shape[0]//2+50),255,-1)
cv2.imshow('rect',rect)

cv2.imshow('Masking',cv2.bitwise_and(img,img,mask=rect))

cv2.waitKey(0)
cv2.destroyAllWindows() 