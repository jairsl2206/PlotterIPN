Proyecto de graficador de señal continua leída desde un puerto de comuinicación serial de manera asíncrona.

Los requisitos previos antes de querer cargar el proyecto son:
1.- Tener instalada la versión de Qt Core 6.9.0 o superior.
2.- Verificar que en la instalación se tienen las siguientes bibliotecas agregadas: 
    Core
    Widgets
    SerialPort
    Charts

Cumpliendo los requisitos el proyecto puede ser ejecutado tanto en ambiente windows como en linux.

Actualmente este genera un chart con la graficación de 1000 puntos (configurable) que se recorren mientras se actualiza.
