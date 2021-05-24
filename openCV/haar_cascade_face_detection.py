import cv2

img = cv2.imread('openCV/people.jpg',-1)
img = cv2.resize(img, (0,0), fx=0.1, fy=0.1)
cv2.imshow('People', img)

gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
cv2.imshow('People', gray)

haar_cascade = cv2.CascadeClassifier('openCV/haarcascade.xml')

faces_rect = haar_cascade.detectMultiScale(gray, scaleFactor=1.5, minNeighbors=1)
print(f'number of faces = {len(faces_rect)}')

for (x,y,w,h) in faces_rect:
    img = cv2.rectangle(img, (x,y), (x+w,y+h), (0,255,0), 2)

cv2.imshow('deteccted', img)

cv2.waitKey(0)
cv2.destroyAllWindows()