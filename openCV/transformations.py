import cv2
import numpy as np

original = cv2.imread('openCV/parrot-image.jpg',-1)
img = cv2.resize(original,(0,0),fx=0.1,fy=0.1)

def translate(img,x,y):
    transMAT = np.float32([[1,0,x],[0,1,y]])
    dimensions = (img.shape[1],img.shape[0])
    return cv2.warpAffine(img,transMAT,dimensions)

def rotate(img,angle,rotPoint=None):
    width,height = img.shape[0],img.shape[1]
    dimensions = (width,height)
    if rotPoint is None:
        rotPoint = (width//2,height//2)

    rotMAT = cv2.getRotationMatrix2D(rotPoint,angle,1.0)
    return cv2.warpAffine(img,rotMAT,dimensions)

translated = translate(img,100,100)
cv2.imshow('translated',translated)

rotated = rotate(img,-45)
cv2.imshow('rotated',rotated)

flipped = cv2.flip(img,1)
cv2.imshow('flipped',flipped)

cv2.waitKey(0)
cv2.destroyAllWindows()