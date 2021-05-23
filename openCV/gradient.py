import cv2
import numpy as np

img = cv2.resize(cv2.imread('openCV/parrot-image.jpg',-1), (0,0), fx=0.1, fy=0.1)
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
cv2.imshow('Gray_image',gray)

lap = cv2.Laplacian(gray,cv2.CV_64F)
lap = np.uint8(np.absolute(lap))
cv2.imshow('Laplacian', lap)

sobelx = cv2.Sobel(gray, cv2.CV_64F, 1, 0)
sobely = cv2.Sobel(gray, cv2.CV_64F, 0, 1)
sobel_combine = cv2.bitwise_or(sobelx, sobely)

cv2.imshow('sobelx', sobelx)
cv2.imshow('sobely', sobely)
cv2.imshow('sobel_combined', sobel_combine)

cv2.waitKey(0)
cv2.destroyAllWindows()