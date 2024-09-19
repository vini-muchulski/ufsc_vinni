# pip install opencv-python onnxruntime numpy

import cv2
import numpy as np
import onnxruntime as ort

# Load the pre-trained YUNet model
model_path = 'yunet.onnx'
session = ort.InferenceSession(model_path)

# Get input and output names
input_name = session.get_inputs()[0].name
output_names = [out.name for out in session.get_outputs()]

def detect_faces(image, confidence_threshold=0.5):
    # Preprocess the image
    height, width = image.shape[:2]
    blob = cv2.dnn.blobFromImage(image, 1.0, (416, 416), [0, 0, 0], True, crop=False)

    # Run inference
    outputs = session.run(output_names, {input_name: blob})

    # Postprocess the results
    faces = []
    for output in outputs[0]:
        confidences = output[5:]
        class_id = np.argmax(confidences)
        confidence = confidences[class_id]

        if confidence > confidence_threshold:
            box = output[:4] * np.array([width, height, width, height])
            (centerX, centerY, boxW, boxH) = box.astype("int")
            x = int(centerX - (boxW / 2))
            y = int(centerY - (boxH / 2))

            faces.append((x, y, boxW, boxH))

    return faces

# Load an image for detection
image_path = 'imagem2.jpg'
img = cv2.imread(image_path)
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

# Detect faces
faces = detect_faces(gray)

# Draw rectangles around detected faces and center points
for i, (x, y, w, h) in enumerate(faces):
    cv2.rectangle(img, (x, y), (x + w, y + h), (0, 255, 0), 2)
    
    # Calculate the center of mass
    center_x = x + w // 2
    center_y = y + h // 2
    
    cv2.line(img, (center_x - 10, center_y), (center_x + 10, center_y), (0, 255, 0), 2)
    cv2.line(img, (center_x, center_y - 10), (center_x, center_y + 10), (0, 255, 0), 2)

# Display the image
cv2.imshow('Face Detection', img)
cv2.waitKey(0)
cv2.destroyAllWindows()
