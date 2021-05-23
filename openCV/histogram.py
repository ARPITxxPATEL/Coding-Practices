import cv2
import numpy as np
import matplotlib.pyplot as plt

img = cv2.resize(cv2.imread('openCV/parrot-image.py',-1), (0,0), fx=0.1, fy=0.1)
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
cv2.imshow('Gray_image',gray)

hist = cv2.calcHist([gray], [0], None, [256], [0,256])

plt.figure()
plt.title('Grayscale of histogram')
plt.xlabel('Bins')
plt.ylabel('# of pixels')

colors = ('b','g','r')
for i,col in enumerate(colors):
    col_hist = cv2.calcHist([img], [i], None, [256], [0,256])
    plt.plot(col_hist, color=col)
    plt.xlim([0,256])
    
plt.show()

cv2.waitKey(0)
cv2.destroyAllWindows()