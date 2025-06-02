# PlotterIPN - Documentación del Proyecto

## 📊 Descripción General

PlotterIPN es un graficador de señal continua desarrollado en Qt6 que permite visualizar datos en tiempo real leídos desde un puerto de comunicación serial de manera asíncrona. El proyecto está diseñado para aplicaciones de monitoreo y análisis de señales provenientes de dispositivos externos como microcontroladores, sensores o sistemas embebidos.

![Qt6](https://img.shields.io/badge/Qt-6.9.0+-brightgreen)
![C++](https://img.shields.io/badge/C++-82.9%25-blue)
![CMake](https://img.shields.io/badge/CMake-17.1%25-red)
![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux-lightgrey)

## 🏗️ Arquitectura del Proyecto

### Tecnologías Principales
- **Framework:** Qt 6.9.0 o superior
- **Lenguaje:** C++ (Standard C++17)
- **Sistema de Construcción:** CMake
- **Bibliotecas Qt Requeridas:**
  - Qt Core
  - Qt Widgets
  - Qt SerialPort
  - Qt Charts

### Estructura del Proyecto
```
PlotterIPN/
├── main.cpp              # Punto de entrada de la aplicación
├── mainwindow.cpp/.h/.ui  # Ventana principal y lógica de interfaz
├── CMakeLists.txt         # Configuración de compilación
├── app.rc                 # Recursos de Windows
├── plotter_icon.png       # Icono de la aplicación
├── resouces.qrc          # Archivo de recursos Qt
├── .gitignore            # Archivos ignorados por Git
└── README.md             # Documentación básica
```

## 🎯 Características Principales

### Visualización en Tiempo Real
- **Graficación Continua:** Visualización de hasta 1000 puntos de datos (configurable)
- **Actualización Dinámica:** Los datos se desplazan mientras se actualiza la gráfica
- **Interfaz Responsive:** Ventana principal con controles intuitivos

### Comunicación Serial
- **Protocolo Asíncrono:** Lectura no bloqueante desde puerto serial
- **Configuración Flexible:** Parámetros de comunicación configurables
- **Compatibilidad Multiplataforma:** Funciona en Windows y Linux

### Capacidades Técnicas
- **Alta Frecuencia de Actualización:** Optimizado para datos en tiempo real
- **Gestión de Memoria Eficiente:** Buffer circular para manejo de datos
- **Interfaz Gráfica Moderna:** Utilizando Qt Charts para visualización profesional

## 🛠️ Requisitos del Sistema

### Requisitos de Desarrollo
1. **Qt Framework:** Versión 6.9.0 o superior
2. **Compilador:** Compatible con C++17
   - GCC 7+ (Linux)
   - MSVC 2019+ (Windows)
   - MinGW 7+ (Windows)
3. **CMake:** Versión 3.20 o superior
4. **Qt Designer:** Última versión (para edición de interfaz)

### Dependencias Qt
```cmake
find_package(Qt6 REQUIRED COMPONENTS Core Widgets SerialPort Charts)
```

### Sistemas Operativos Soportados
- **Windows:** 10/11 (x64)
- **Linux:** Distribuciones modernas con Qt6
  - Ubuntu 22.04+
  - Fedora 36+
  - openSUSE Leap 15.4+

## 📦 Instalación y Configuración

### 1. Clonar el Repositorio
```bash
git clone https://github.com/jairsl2206/PlotterIPN.git
cd PlotterIPN
```

### 2. Configurar el Entorno de Desarrollo

#### En Linux:
```bash
# Instalar Qt6 y dependencias
sudo apt-get install qt6-base-dev qt6-serialport-dev qt6-charts-dev cmake build-essential

# O usando el instalador oficial de Qt
wget https://download.qt.io/official_releases/online_installers/qt-unified-linux-x64-online.run
chmod +x qt-unified-linux-x64-online.run
./qt-unified-linux-x64-online.run
```

#### En Windows:
1. Descargar Qt6 desde [qt.io](https://www.qt.io/download)
2. Instalar con componentes: Qt Charts, Qt SerialPort
3. Configurar variables de entorno PATH
4. Instalar CMake y compilador compatible

### 3. Compilación

#### Usando CMake (Recomendado):
```bash
mkdir build
cd build
cmake ..
cmake --build . --config Release
```

#### Usando Qt Creator:
1. Abrir el archivo `CMakeLists.txt` en Qt Creator
2. Configurar el kit de desarrollo
3. Compilar y ejecutar (Ctrl+R)

## 🚀 Uso de la Aplicación

### Configuración de Puerto Serial
1. **Selección de Puerto:** Identificar el puerto COM (Windows) o /dev/ttyUSB (Linux)
2. **Parámetros de Comunicación:**
   - Baud Rate: Configurable según dispositivo
   - Data Bits: 8 bits (por defecto)
   - Parity: None (por defecto)
   - Stop Bits: 1 (por defecto)
   - Flow Control: None (por defecto)

### Protocolo de Datos
El sistema espera datos numéricos enviados vía serial, idealmente:
- **Formato:** Valores separados por nueva línea o coma
- **Rango:** Valores numéricos válidos
- **Frecuencia:** Hasta 1000 Hz (según configuración)

### Ejemplo de Código para Microcontrolador
```cpp
// STM32 Ejemplo
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  MX_ADC1_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */
  int sim_value = 0;
  bool Simulacion = true; //true para simular, false para obtener datos del puerto ADC

  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_ADC1_Init();
  MX_USART2_UART_Init();

  HAL_ADC_Start(&hadc1); // Inicia ADC

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */


	  if(Simulacion){
      //Datos Simulados Onda seno
	  static float angle = 0;
      sim_value = (uint16_t)((sin(angle) + 1.0f) * 2047);  // 0-4095
      angle += 0.025f;

      char buffer[16];
      sprintf(buffer, "%u\n", sim_value);  // convierte el número en texto + newline
      HAL_UART_Transmit(&huart2, (uint8_t*)buffer, strlen(buffer), HAL_MAX_DELAY);
      HAL_Delay(10);
	  }
	  else{
	  //Datos de ADC de la tarjeta
	  HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
	  adcValue = HAL_ADC_GetValue(&hadc1);

	  // Enviar por UART
	  sprintf(buffer, "%lu\n", adcValue);
	  HAL_UART_Transmit(&huart2, (uint8_t*)buffer, strlen(buffer), HAL_MAX_DELAY);
	  //HAL_Delay(10); // Envía cada 200 ms

	  }



    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}
```

## 🏛️ Arquitectura de Software

### Patrón Arquitectónico
El proyecto implementa el patrón **Model-View-Controller (MVC)** adaptado para Qt:

#### Model (Datos)
- **QSerialPort:** Gestión de comunicación serial
- **QVector/QList:** Almacenamiento de datos en buffer circular
- **QTimer:** Control de actualización temporal

#### View (Interfaz)
- **MainWindow:** Ventana principal de la aplicación
- **QChartView:** Área de visualización de gráficos
- **QLineSeries:** Serie de datos para el gráfico

#### Controller (Lógica)
- **MainWindow Slots:** Manejo de eventos de interfaz
- **Serial Data Handler:** Procesamiento de datos entrantes
- **Chart Update Logic:** Actualización de visualización

### Flujo de Datos
1. **Recepción:** QSerialPort recibe datos asincrónamente
2. **Procesamiento:** Parsing y validación de datos
3. **Almacenamiento:** Buffer circular con límite configurable
4. **Visualización:** Actualización de QLineSeries
5. **Renderizado:** QChartView actualiza la interfaz

## 🧪 Consideraciones de Desarrollo

### Optimización de Rendimiento
- **Buffer Circular:** Evita realocaciones frecuentes de memoria
- **Actualización Selectiva:** Solo redibuja cuando hay nuevos datos
- **Threading Apropiado:** Operaciones I/O en thread principal con eventos

### Manejo de Errores
- **Timeouts de Comunicación:** Detección de pérdida de conexión
- **Validación de Datos:** Filtrado de valores inválidos
- **Reconexión Automática:** Intento de reestablecer comunicación

### Extensibilidad
- **Configuración Modular:** Fácil adición de nuevos parámetros
- **Plugins Potential:** Arquitectura preparada para extensiones
- **Formato de Datos Flexible:** Adaptable a diferentes protocolos

## 🔧 Desarrollo y Contribución

### Configuración del Entorno de Desarrollo
```bash
# Instalar herramientas de desarrollo
sudo apt-get install git cmake ninja-build gdb valgrind

# Configurar pre-commit hooks
git config core.hooksPath .githooks
chmod +x .githooks/pre-commit
```

### Estándares de Código
- **Estilo:** Qt Coding Style
- **Documentación:** Doxygen comments para funciones públicas
- **Testing:** Unit tests usando Qt Test Framework

### Roadmap de Desarrollo
- [ ] Soporte para múltiples canales simultáneos
- [ ] Exportación de datos a CSV/Excel
- [ ] Filtros digitales configurables
- [ ] Análisis espectral (FFT)
- [ ] Interfaz web para monitoreo remoto

## 📄 Licencia y Distribución

### Licencia Qt
Este proyecto utiliza Qt bajo licencia LGPL v3, lo que permite:
- **Uso Comercial:** Con cumplimiento de términos LGPL
- **Distribución:** Incluir bibliotecas Qt dinámicamente
- **Modificación:** Del código propio, no de Qt

### Distribución Multiplataforma
#### Windows:
```bash
# Usando windeployqt
windeployqt.exe --qmldir . PlotterIPN.exe
```

#### Linux:
```bash
# Usando linuxdeployqt o AppImage
linuxdeployqt PlotterIPN -appimage
```

## 📞 Soporte y Contacto

### Repositorio
- **GitHub:** [https://github.com/jairsl2206/PlotterIPN](https://github.com/jairsl2206/PlotterIPN)
- **Issues:** Reportar bugs y solicitar características
- **Wiki:** Documentación extendida y tutoriales

### Desarrollador
- **Usuario GitHub:** jairsl2206
- **Última Actualización:** Junio 2025

### Recursos Adicionales
- [Qt Documentation](https://doc.qt.io/qt-6/)
- [Qt SerialPort Guide](https://doc.qt.io/qt-6/qtserialport-index.html)
- [Qt Charts Tutorial](https://doc.qt.io/qt-6/qtcharts-index.html)

---

*Documentación generada para PlotterIPN v1.0 - Proyecto de graficación en tiempo real con Qt6*
