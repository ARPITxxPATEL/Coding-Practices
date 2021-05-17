import cv2
import numpy as np

cap = cv2.VideoCapture(0)

while True:
    ret,frame = cap.read()
    width = int(cap.get(3))
    height = int(cap.get(4))

    img = cv2.line(frame, (0,0), (width,height), (0,255,0), 5)
    img = cv2.rectangle(img, (0,height), (width,0), (128,128,0), 3)
    img = cv2.circle(img, (width//2,height//2), 100, (50,50,200), 4)
    img = cv2.putText(img, 'Arpit is OP', (width//4,height-10), cv2.FONT_HERSHEY_SIMPLEX, 0.8, (0,0,0), 4, cv2.LINE_AA)

    cv2.imshow('Image',img)
    if cv2.waitKey(1)==ord('q'):
        break

cap.release()
cv2.destroyAllWindows()