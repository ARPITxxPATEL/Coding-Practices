import cv2

img = cv2.imread('openCV/parrot-image.jpg',-1)
#cv2.imshow('Image',img)

resized = cv2.resize(img, (int(img.shape[1]*0.1),int(img.shape[0]*0.1)), interpolation=cv2.INTER_CUBIC)
cv2.imshow('resized', resized)

cropped = resized[200:400,120:240]
cv2.imshow('cropped', cropped)

blur = cv2.GaussianBlur(resized,(3,3),cv2.BORDER_DEFAULT)
cv2.imshow('Blur',blur)

edges = cv2.Canny(blur,125,175)
cv2.imshow('edges',edges)

dilated = cv2.dilate(edges,(3,3),iterations=3)
cv2.imshow('dilated',dilated)

eroded = cv2.erode(dilated,(3,3),iterations=3)
cv2.imshow('eroded',eroded)

cv2.waitKey(0)
cv2.destroyAllWindows()