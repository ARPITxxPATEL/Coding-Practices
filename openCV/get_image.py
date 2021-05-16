import cv2

img = cv2.imread('opencv\parrot-image.jpg',-1)
img = cv2.resize(img, (0,0), fx=0.1, fy=0.1)
img = cv2.rotate(img, cv2.cv2.ROTATE_90_CLOCKWISE)

cv2.imshow('Image',img)

cv2.waitKey(0)
cv2.destroyAllWindows()