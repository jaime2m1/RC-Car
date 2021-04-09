## AutoRCCar
### Python3 + OpenCV3

Ver conducción autonática en acción



![CocheStop](https://user-images.githubusercontent.com/31405248/114218845-4057a180-996a-11eb-8812-bdd67ab1b3c5.mp4)




Este proyecto construye un auto RC auto-manejado usando Raspberry Pi, Arduino y software de código abierto. Raspberry Pi recopila las entradas de un módulo de cámara y un sensor ultrasónico, y envía datos a una computadora de forma inalámbrica. La computadora procesa las imágenes de entrada y los datos del sensor para la detección de objetos (señal de stop y semáforo) y para evitar colisiones, respectivamente. Un modelo de red neuronal se ejecuta en la computadora y hace predicciones para la dirección en función de las imágenes de entrada. Las predicciones se envían al Arduino para el control del auto RC.
  
### Creando environment con Anaconda
  1. Instalar [`miniconda`](https://conda.io/miniconda.html) en el ordenador
  
      ```conda install -c cogsci pygame```
      
      ```conda install numpy```
      
      ```pip install opencv-python```
      
  2. Crear `auto-rccar` environment con todas las librerías necesarias para el proyecto 
     ```conda env create -f environment.yml```
     
  3. Activar `auto-rccar` environment  
     ```source activate auto-rccar```
  
  &ensp; Para salir, simplemente cierra la terminal. Más información para manejar Anaconda environment, por favor, ver [here](https://conda.io/docs/user-guide/tasks/manage-environments.html).
  
### Sobre los archivos
**test/**  
  &emsp; &emsp; `rc_control_test.py`: Controlar el coche con el teclado 
  &emsp; &emsp;  `stream_server_test.py`: video streaming de la raspberry al ordenador  
  &emsp; &emsp;  `ultrasonic_server_test.py`: streaming de los datos del sensor de la raspberry al ordenador 
  &emsp; &emsp;  **model_train_test/**  
      &emsp; &emsp;  &emsp; &emsp; `data_test.npz`: datos de ejemplo  
      &emsp; &emsp;  &emsp; &emsp; `train_predict_test.ipynb`: a jupyter notebook that goes through neural network model in OpenCV3  
  
**raspberryPi/**    
  &emsp; &emsp;  `stream_client.py`:        stream video frames en jpeg al host del ordenador 
  &emsp; &emsp;  `ultrasonic_client.py`:    envían los datos del sensor al host del ordenador
  
**arduino/**  
  &emsp; &emsp;  `rc_keyboard_control2.ino`: Controla el envío de datos bluetooth del arduino UNO al MEGA
  
**computer/**    
  &emsp; &emsp;  **cascade_xml/**  
      &emsp; &emsp;  &emsp; &emsp;  trained cascade classifiers  
  &emsp; &emsp;  **chess_board/**   
      &emsp; &emsp;  &emsp; &emsp;  images for calibration, captured by pi camera  
      
  &emsp; &emsp;  `picam_calibration.py`:     Calibración de la cámara PY  
  &emsp; &emsp;  `collect_training_data.py`: Colecciona la imagen en escala de grises, los datos son guardados como `*.npz`  
  &emsp; &emsp;  `model.py`:                 Modelo de red neuronal  
  &emsp; &emsp;  `model_training.py`:        model training and validation  
  &emsp; &emsp;  `rc_driver_helper.py`:      helper classes/functions for `rc_driver.py`  
  &emsp; &emsp;  `rc_driver.py`:             recibe los datos de la raspberry pi y conduce el coche ba
  
**Traffic_signal**  
  &emsp; &emsp;  trafic signal sketch contributed by [@geek111](https://github.com/geek1111)


### Como conducir
1. **Puebas:** Flash `rc_keyboard_control.ino` to Arduino and run `rc_control_test.py` to drive the RC car with keyboard. Run `stream_server_test.py` on computer and then run `stream_client.py` on raspberry pi to test video streaming. Similarly, `ultrasonic_server_test.py` and `ultrasonic_client.py` can be used for sensor data streaming testing.   

2. **Calibración de la cámara PY (opcional):** Captura múltiples imágenes de la tabla de ajedrez usando la cámara PY en varios ángulos y las pone en la carpeta **`chess_board`** , ejecutar `picam_calibration.py` y retornar los parametros de la cámara matrix serán usados en `rc_driver.py`.

3. **Guardar datos training/validation:** Primero ejecute `collect_training_data.py` y luego ejecute `stream_client.py` en la raspberry pi. Pulsa las flechas para dirigir el coche, pulse `q` para salir. Frames are saved only when there is a key press action. Una vez cerrado, los datos serán guardados en un nuevo srchivo llamado **`training_data`** .

4. **Prueba de red neuronal:** Ejecutar `model_training.py` para probar el modelo de red neuronal. Porfavor, sientese libre para cambiar architecture/parameters para obtener mejores resultados. Después de probar, será guardado en un nuevo archivo **`saved_model`** .

5. **Prueba de la cascada de clasificadores (opcional):** Las pruebas de los clasificadores de señal de stop y semáforo son incluidos en el archivo **`cascade_xml`** , si estás interesado en encontrar tus propios clasificadores, please refer to [OpenCV doc](http://docs.opencv.org/doc/user_guide/ug_traincascade.html) and this great [tutorial](http://coding-robin.de/2013/07/22/train-your-own-opencv-haar-classifier.html).

6. **Autoconducción del coche en acción**: Primero ejecute `rc_driver.py` para iniciar el servidor en el ordenador, y luego ejecute `stream_client.py` y `ultrasonic_client.py` en la raspberry pi. 

