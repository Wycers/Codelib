# 导入必要的软件包
import cv2
import numpy as np

# 视频文件输入初始化
filename = "output.mp4"
camera = cv2.VideoCapture(filename)

# 初始化当前帧的前帧
last_frame = None

# 遍历视频的每一帧
cnta, cntb = 0, 0
while camera.isOpened():

    # 读取下一帧
    (ret, frame) = camera.read()

    if ret == False:
        break

    if last_frame is None:
        last_frame = frame
        continue


    cntb += 1
    if cntb % 100 == 0:
        print("{}%".format(round(cntb / 10700, 2)))
    diff = np.sum(frame - last_frame)
    last_frame = frame

    if (diff < 1e7):
        continue

    cv2.namedWindow("Image")
    cv2.imshow("Image", frame)
    cv2.waitKey (0)

# 清理资源并关闭打开的窗口
camera.release()
cv2.destroyAllWindows()
