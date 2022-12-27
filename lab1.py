import cv2

name = "kit.jpg"
img = cv2.imread(name)
cv2.namedWindow("kitten", cv2.WINDOW_NORMAL)
# чб
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
cv2.imshow('kitten', gray)
cv2.waitKey(0)
cv2.destroyAllWindows()

name = "output.mov"
cap = cv2.VideoCapture(name, cv2.CAP_ANY)
while True:
    ret, frame = cap.read()
    if not ret:
        cv2.waitKey(0)
        break
    cv2.imshow('video', frame)
    if cv2.waitKey(1) & 0xFF == 27:  # 0xFF ждёт escape
        break
cap.release()
cv2.destroyAllWindows()

# 0 - вебка, 2 - телефон
video = cv2.VideoCapture(2)
w = int(video.get(cv2.CAP_PROP_FRAME_WIDTH))
h = int(video.get(cv2.CAP_PROP_FRAME_HEIGHT))
fourcc = cv2.VideoWriter_fourcc(*'XVID')
video_writer = cv2.VideoWriter("output.mov", fourcc, 25, (w, h))
while True:
    ok, img = video.read()
    cv2.imshow('webcam', img)
    video_writer.write(img)
    if cv2.waitKey(1) & 0xFF == 27:
        break
video.release()
cv2.destroyAllWindows()