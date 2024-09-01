import cv2

# Substitua pelo IP real do seu ESP32
ip = "http://192.168.0.109"
# URL completa para acessar o stream de vídeo do ESP32-CAM
stream_url = f"{ip}:81/stream"
#http://192.168.0.109:81/stream
# Inicializa a captura de vídeo com o URL do stream
video = cv2.VideoCapture(stream_url)

while True:
    check, img = video.read()
    if not check:
        print("Não foi possível acessar o stream de vídeo.")
        break
    
    cv2.imshow("Imagem da ESP32-CAM", img)

    # Pressione 'q' para sair do loop
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

video.release()
cv2.destroyAllWindows()
