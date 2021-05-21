import cv2

img = cv2.resize(cv2.imread('openCV/parrot-image.jpg',-1),(0,0),fx=0.1,fy=0.1)

gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
cv2.imshow('Gray',gray)

hsv = cv2.cvtColor(img,cv2.COLOR_BGR2HSV)
cv2.imshow('hsv',hsv)

lab = cv2.cvtColor(img,cv2.COLOR_BGR2LAB)
cv2.imshow('lab',lab)

rgb = cv2.cvtColor(img,cv2.COLOR_BGR2RGB)
cv2.imshow('rgb',rgb)

cv2.waitKey(0)
cv2.destroyAllWindows()