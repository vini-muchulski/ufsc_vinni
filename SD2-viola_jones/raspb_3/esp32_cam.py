import cv2 as cv

# URL do stream da câmera
ip = 'http://192.168.0.105'
stream_url = f"{ip}:81/stream"
cap = cv.VideoCapture(stream_url)

# Verificar se o vídeo está aberto
if not cap.isOpened():
    print("Não foi possível conectar ao stream da ESP32-CAM")
    exit()

# Loop de captura e exibição de vídeo
while True:
    ret, frame = cap.read()
    if not ret:
        print("Falha na captura de vídeo")
        break

    # Exibir o vídeo em uma janela
    cv.imshow('Stream de Vídeo', frame)

    # Fechar a janela ao pressionar 'q'
    if cv.waitKey(1) & 0xFF == ord('q'):
        break

# Liberar recursos
cap.release()
cv.destroyAllWindows()
