import cv2

img = cv2.imread('opencv/parrot-image.jpg',-1)
img = cv2.resize(img, (0,0), fx=0.1, fy=0.1)

cut = img[75:150, 155:205]
img[0:75,0:50] = cut

cv2.imshow('Image',img)
cv2.waitKey(0)
cv2.destroyAllWindows()