Proyecto de graficador de señal continua leída desde un puerto de comuinicación serial de manera asíncrona.

Los requisitos previos antes de querer cargar el proyecto son:
1.- Tener instalada la versión de Qt Core 6.9.0 o superior.
2.- Verificar que en la instalación se tienen las siguientes bibliotecas agregadas: 
    Core
    Widgets
    SerialPort
    Charts

Por el momento es requisito instalar también el QtDesigner en su última versión (Para no tener problemas con la declaración de ui)

Cumpliendo los requisitos el proyecto puede ser ejecutado tanto en ambiente windows como en linux.

Actualmente este genera un chart con la graficación de 1000 puntos (configurable) que se recorren mientras se actualiza.
![image](https://github.com/user-attachments/assets/73df2426-2ded-4d84-b7c4-5605801eb2c7)


Nueva actualización, se agrega configuración para comunicación serial:
![image](https://github.com/user-attachments/assets/42c328ea-784f-4c98-ad2a-946e6fcfd943)
