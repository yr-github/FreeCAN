# This Python file uses the following encoding: utf-8
import os
if __name__ == "__main__":   
    print(os.getcwd())
    f = open(".\\..\\test.log","r+")
    print(f.read())
