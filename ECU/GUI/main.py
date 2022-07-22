import sys
import serial
import requests as req
import PyQt5
from PyQt5 import QtWidgets, QtGui
from PyQt5.QtWidgets import QDialog, QApplication, QLineEdit, QLabel, QSplashScreen, QTabWidget
from PyQt5.QtGui import QPixmap
from PyQt5.uic import loadUi
from PyQt5.QtCore import Qt
import sqlite3
import time
import img_rc

class WelcomeScreen (QDialog):
    def __init__(self):
        super(WelcomeScreen, self).__init__()
        loadUi("welcome.ui", self)
        self.loginButton.clicked.connect(self.gotologin)
        self.signupButton.clicked.connect(self.gotosignup)

    def gotologin (self):
        login = loginScreen()
        widget.addWidget(login)
        widget.setCurrentIndex(widget.currentIndex()+1)

    def gotosignup(self):
        signup = signupScreen()
        widget.addWidget(signup)
        widget.setCurrentIndex(widget.currentIndex() + 1)


class loginScreen (QDialog):
    def __init__(self):
        super(loginScreen, self).__init__()
        loadUi("login.ui", self)
        self.password.setEchoMode(QtWidgets.QLineEdit.Password)
        self.loginButton.clicked.connect(self.loginfunction)

    def loginfunction (self):
        user = self.username.text()
        password  = self.password.text()
        if len(user)==0 or len(password)==0:
            self.error.setText("please, input all fields")

        else:
            connection = sqlite3.connect("data.db")
            cursor = connection.cursor()
            query = 'SELECT password FROM login_info WHERE username=\''+user+"\'"
            cursor.execute(query)
            result_pass = cursor.fetchone()[0]
            if result_pass == password:
                print("Successfully logged in")
                self.error.setText("")
                mainpage = mainPage()
                widget.addWidget(mainpage)
                widget.setCurrentIndex(widget.currentIndex() + 1)
            else:
                self.error.setText("Invalid username or password")

class signupScreen (QDialog):
    def __init__(self):
        super(signupScreen, self).__init__()
        loadUi("signup.ui", self)
        self.password.setEchoMode(QtWidgets.QLineEdit.Password)
        self.password2.setEchoMode(QtWidgets.QLineEdit.Password)
        self.signupButton.clicked.connect(self.signupfunction)

    def signupfunction(self):
        user = self.username.text()
        password = self.password.text()
        conpassword = self.password2.text()
        if len(user) == 0 or len(password) == 0 or len(conpassword) == 0:
            self.error.setText("please, fill in all inputs.")

        elif password != conpassword:
            self.error.setText("passwords do not match.")

        else:
            connection = sqlite3.connect("data.db")
            cursor = connection.cursor()
            user_info = [user, password]
            cursor.execute('INSERT INTO login_info (username, password) VALUES (?, ?)', user_info)
            connection.commit()
            connection.close()
            fillprofile = fillprofileScreen()
            widget.addWidget(fillprofile)
            widget.setCurrentIndex(widget.currentIndex() + 1)

class fillprofileScreen (QDialog):
    def __init__(self):
        super(fillprofileScreen, self).__init__()
        loadUi("fillprofile.ui", self)
        self.signupButton.clicked.connect(self.signupFunction)

    def signupFunction(self):
        fname = self.Fname.text()
        lname = self.Lname.text()
        email = self.Email.text()
        mobile = self.mobile.text()
        if len(fname) == 0 or len(lname) == 0 or len(email) == 0 or len(mobile) == 0:
            self.error.setText("please, fill in all inputs.")
        else:
            mainpage = mainPage()
            widget.addWidget(mainpage)
            widget.setCurrentIndex(widget.currentIndex() + 1)

class mainPage (QDialog):
    def __init__(self):
        super(mainPage, self).__init__()
        loadUi("mainpage.ui", self)
        self.updateButton.clicked.connect(self.updateFunction)
        self.laterButton.clicked.connect(self.laterfunction)
        self.tableWidget.setColumnWidth(0, 100)
        self.tableWidget.setColumnWidth(1, 400)

    def updateFunction(self):
        update = updateScreen()
        widget.addWidget(update)
        widget.setCurrentIndex(widget.currentIndex() + 1)
        update.show()
        
        url = 'http://192.168.137.132/download/GPIO.txt'
        with req.get(url) as f:
            with open('lupdate.txt', 'wb') as file:
                file.write(f.content)
        
        file = open('lupdate.txt')
        # lin_num = file.readlines()
        ser = serial.Serial ()    #Open port with baud rate
        ser.port = "/dev/serial0"
        ser.baudrate = 9600
        ser.open()
        while True:
            data = file.readline()
            if data == '':
                file.close()
                ser.close()
                break
            else:
                print(data)
                data = str.encode(data)
                ser.write(data)
                s = ser.read(2)
                ok = str.encode('ok')
                if s != ok:
                    file.close()
                    ser.close()
                    break
        
        update.progress()

    def laterfunction(self):
        later = WelcomeScreen()
        widget.addWidget(later)
        widget.setCurrentIndex(widget.currentIndex() + 1)
        
    # def update(self):
    #     url = 'http://192.168.137.173/download/lupdate.txt'
    #     with req.get(url) as f:
    #         with open('lupdate.txt', 'wb') as file:
    #             file.write(f.content)
        
    #     file = open('lupdate.txt')
    #     ser = serial.Serial ()    #Open port with baud rate
    #     ser.port = "/dev/serial0"
    #     ser.baudrate = 9600
    #     ser.open()
    #     while True:
    #         data = file.readline()
    #         if data == '':
    #             file.close()
    #             ser.close()
    #             break
    #         else:
    #             print(data)
    #             data = str.encode(data)
    #             serial.write(data)
    #             s = ser.read(2)
    #             ok = str.encode('ok')
    #             if s != ok:
    #                 file.close()
    #                 ser.close()
    #                 break
        

class updateScreen (QDialog, QSplashScreen):
    def __init__(self):
        super(updateScreen, self).__init__()
        loadUi("update.ui", self)
        self.setWindowFlag(Qt.FramelessWindowHint)
    def progress (self):
        for i in range(40):
            time.sleep(0.1)
            self.progressBar.setValue(i)

        

        for i in range(41, 101):
            time.sleep(0.1)
            self.progressBar.setValue(i)
            if i == 100:
                done = doneScreen()
                widget.addWidget(done)
                widget.setCurrentIndex(widget.currentIndex() + 1)

class doneScreen (QDialog):
    def __init__(self):
        super(doneScreen, self).__init__()
        loadUi("Done.ui", self)
        self.doneButton.clicked.connect(self.doneFunction)

    def doneFunction(self):
        done2 = WelcomeScreen()
        widget.addWidget(done2)
        widget.setCurrentIndex(widget.currentIndex() + 1)

#main
app = QApplication(sys.argv)
widget = QtWidgets.QStackedWidget()
mainwindow = WelcomeScreen()
widget.addWidget(mainwindow)
widget.setFixedWidth(700)
widget.setFixedHeight(430)
widget.show()
try:
    sys.exit(app.exec_())
except:
    print("Exiting")
