import cv2 as cv
from cvzone.HandTrackingModule import HandDetector

if __name__ == "__main__":
    cap = cv.VideoCapture(0)
    
    # Write Data to Serial
    def writeFingersToSerial(fingArr):
        strToSend = ""
        for fing in fingArr:
            strToSend += str(fing)

        # if(arduinoPortOpened):
        #     arduino.write(bytes(strToSend, 'utf-8'))
    
    detector = HandDetector(detectionCon=0.8, maxHands=1)
    while True:
        frame = cap.read()[1]
        
        hands, img = detector.findHands(frame) # Find Hand
        if hands:
            hand = hands[0]
            handType = hand["type"]  # Left or Right

            fingers = detector.fingersUp(hand)
            print(fingers, handType)
            writeFingersToSerial(fingers)
        
        cv.imshow("Image", img)
    
        if cv.waitKey(5) & 0xFF == 27:
            break
    
    cap.release()
    cv.destroyAllWindows()
        