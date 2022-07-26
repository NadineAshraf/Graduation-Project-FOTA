**Hello, This project is about FOTA (Firmware Over the Air).**
# Team Members
-  Menna Ahmed Heshmat.
-  Nadine Ashraf Adeeb.
-  Tasneem Yassin Mostafa.
- Sara Gouda Rohaim.
- Kerolos Adel Fahiem.
- Mark Ehab Tawfiq.

# System Design 
![image](https://user-images.githubusercontent.com/91349300/181052244-69cf9821-d902-4721-ac10-32330ae87f1b.png)
### Hardware Components
This system consists of 2 main controllers as shown in figure:

•	Raspberry pi: acts as the gateway to the server and acts as an interface to the user by connected to HDMI touch screen. 

•	Application ECU: It acts as a faulty node whose software needs to update or have a feature added to it.

### Software Updates

1- The OEM uploads a new software to the server.

2-	On the next ignition cycle in the vehicle, the Raspberry pi requests the software versions IDs from the server, it also requests the software version IDs from the application ECU.

3-	The server replies with them in a sematic version format. 

5-	The raspberry pi compares the versions.

6-	If an update is found it sends a CAN Message to the GUI requesting for the user acceptance for the update. In case no update is found, nothing happens.

7-	Once the user accepts or rejects the update, the GUI sends a CAN Message in both cases.

8-	In case of user acceptance, the raspberry pi requests the new hex file from the server and sends an update request message through CAN to the application ECU to perform a soft reset and start executing the bootloader.

9-	The server sends the hex file to the raspberry by.

10-	The raspberry pi validates the file for errors.

11-	The raspberry pi sends the hex file through CAN Network to the application ECU, it also sends the update progress to the GUI to display it.

12-	The bootloader receives the file and checks for any error, flashes it in the flash memory then jumps to the new application.

# NOIP
► Raspberry Pi acts as a server which we want to connect it with a domain name. The Domain name needs static ip which isn’t available we have dynamic ip.

► We used NOIP which run some scripts periodically as we want to get global ip of the router that is connected to raspberry pi and send to noip server.

► NOIP connect with global ip and we need a device connected to the router so we did port forwarding to get HTTP request from the global ip of router.

► It begins to forward the raspberry pi ip (local ip). As the raspberry pi works with Apache server with is connected to the website.
# Website
### Why Django??
1) Built With Python So Easy to Learn.

2)  Open Source and Huge Community Support.

3) DRY (Don’t Repeat Yourself).

4) Good Documentation.

### Technology
![image](https://user-images.githubusercontent.com/91349300/181058487-df2b4363-af54-49c5-8591-71a89bbd882c.png)

### Django Project Structure and File Structure 
1) init.py: This is an empty file.

2) settings.py :It contains the Django project configuration.

3) urls.py :This file tells Django that if a user comes with this URL, direct them to that website.

![image](https://user-images.githubusercontent.com/91349300/181059590-262de7ea-8b59-415c-bae9-53be18ffe0a2.png)

### Application files 

1) init.py: This is an empty file.

2) admin.py : is used for registering the Django models into the Django administration. 

3) apps.py : is a file that is used to help the user include the application configuration for their app.

4) models.py : represents the models of web applications in the form of classes.

5) views.py: It contains all the views in the form of classes.

6) urls.py: works the same as that of the urls.py in the project file structure.

### User hierarchy and features

● Login Page:Login form to login to the web site.

![image](https://user-images.githubusercontent.com/91349300/181062011-35f60928-1223-424d-9d23-304ec6bb8515.png)

● Registration 

![image](https://user-images.githubusercontent.com/91349300/181062296-b60e78d2-5bbb-4117-ae8b-85d397be91a5.png)

● Team Members :Views all users or team members working on firmwares. 

![image](https://user-images.githubusercontent.com/91349300/181062587-1e7f27b3-2d41-4562-9743-16f0d47a7a64.png)

●  Diagnostics data:This page shows the diagnostics data sent by vehicles to be reviewed 
   and collected for bug fixes.
   
![image](https://user-images.githubusercontent.com/91349300/181062793-55b46e04-d0c8-4909-94fe-ea52aeda225f.png)

●  Upload Screen:It has all the info needed for firmware upload and description for it. 

![image](https://user-images.githubusercontent.com/91349300/181062945-50d1dc79-1366-483e-8bd1-a574ad109d8a.png)

# GUI System
- GUI system is Raspberry pi connected with touch screen.
- To connect the GUI system, we need to SPI to CAN module to convert the SPI signals that the Raspberry pi understood to CAN signal to connect with CAN network.

### GUI Toolkit:

  ** PyQt: ** 
   - Coding Versatility: is built around the idea of signals and slots for creating contact between objects.
   
   - More than a framework: uses a broad variety of native platform APIs for networking, database development, and more.
   
   - Various UI components: multiple widgets, such as buttons or menus, all designed with a basic interface for all platforms.
   
   - Various learning resources: PyQt is one of the most commonly used UI systems for Python.
   
### The main scenario implemented:

   ► FOTA update where the server sends an update to the user to appear on the touch screen waiting for the confirmation from the user by yes or no. 

   ►The communication channel between the ECUs in the car gone through CAN.

   ► Python used in the design due to its simplicity where you can handle multi modules on the same time using 2 main modules which make it more comfortable to the developer to use it in GUI applications. 

### The main modules:

- **Main.py:**  to control the appearance of the GUI, widgets shapes and the organization of the design.
To control the flow and interaction between the main parts and the process of the project.

- **Img.qrc:** contains all the media used in GUI which is transformed to be read in python (img.rc). 

### Welcome page:

![image](https://user-images.githubusercontent.com/91349300/181068680-87ca2a00-9a4e-4e9c-9e18-da4e04800176.png)

### Login page:

![image](https://user-images.githubusercontent.com/91349300/181068874-25f61373-6c12-4d9a-b866-9083fa08622a.png)

### Signup page:

![image](https://user-images.githubusercontent.com/91349300/181068995-21d79a5e-2941-4948-b59f-3b38315f4e37.png)

### Fill profile information

![image](https://user-images.githubusercontent.com/91349300/181069111-8840d143-6861-4fc4-91ec-5525c79a9112.png)

### FOTA Page 

![image](https://user-images.githubusercontent.com/91349300/181069233-c75f37b9-96f5-4261-9989-ce0ac7f8c10e.png)

# APP ECU 
### Flash Memory Arrangement
- Total size: 128 KB
- Bootloader: 10 KB
- First Bank: 59 KB
- Second Bank: 59 KB

![image](https://user-images.githubusercontent.com/91349300/181075149-f1344587-94b8-4888-80db-47aa018010a9.png)

### Bootloader 

**Case 1: Only Bootloader present in Flash Memory**

► Program stays in bootloader section waiting for hex file to be received.

► Program is received and stored in Bank 1.

► Bootloader updates option bytes and jumps to new application.

**Case 2: Application running on Bank 1 and software update is received**

► Soft reset is performed and PC returns to Bootloader

► Bank 2 is erased.

► New Application is programmed in Bank 2.

► Bootloader updates option bytes and jumps to new application.

**Case 3: Interruption during flashing**

► Application is running on Bank 2 and software update is received.

► Soft reset is performed and PC returns to Bootloader.

► Bank 1 is erased.

► Program is being flashed in Bank 1.

► Process is interrupted by power off.

► On next power on, application in bank 2 starts running.

![image](https://user-images.githubusercontent.com/91349300/181075532-5055d9c6-d08a-4839-aad4-7be3f4fd4b18.png)

### Application 

![image](https://user-images.githubusercontent.com/91349300/181069488-32fd3573-53c1-4f55-affa-e4087356db2c.png)

► The parking assistant consists of two main components: an IR sensor and a piezoelectric buzzer.

► The IR sensor is a digital sensor which sends an IR wave in front of it and senses the medium, if the wave was reflected this means a barrier is in front it, so it returns a high signal on its out pin.

► The application procedure is as follows: If a high signal is received, a buzzer is turned on to alert the driver that there is a barrier during parking, otherwise the buzzer is off.

► As a proof of concept, the first application has this feature is turned off, after the update, the parking assistant works fine.

![image](https://user-images.githubusercontent.com/91349300/181069867-a69b09c7-98cc-461e-bd2b-3058305742d7.png)

![image](https://user-images.githubusercontent.com/91349300/181069955-ba786f0d-29e8-41c0-80e2-45ffa1ca6b3c.png)

# Security

![image](https://user-images.githubusercontent.com/91349300/181073489-a18b6927-bb7e-4e9c-adea-303f6a10a507.png)



















































