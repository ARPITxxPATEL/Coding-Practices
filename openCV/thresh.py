import cv2

img = cv2.resize(cv2.imread('openCV/parrot-image.jpg',-1), (0,0), fx=0.1, fy=0.1)
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
cv2.imshow('Gray_image',gray)

ret, thresh = cv2.threshold(gray, 150, 255, cv2.THRESH_BINARY)
cv2.imshow('thresh',thresh)

ret, thresh_inv = cv2.threshold(gray, 150, 255, cv2.THRESH_BINARY_INV)
cv2.imshow('thresh',thresh_inv)

adaptive_thresh = cv2.adaptiveThreshold(gray, 255, cv2.ADAPTIVE_THRESH_MEAN_C, cv2.THRESH_BINARY, 11, 3)
cv2.imshow('adaptive',adaptive_thresh)

cv2.waitKey(0)
cv2.destroyAllWindows()