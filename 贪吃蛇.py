from tkinter import *
import threading
import queue
import time
import random'''用于生成随机数'''
class GUI(Tk):
    def _init_(self,queue):
        Tk._init_(self)
        self.queue = queue
        self.is_game = queue
        self.is_game_over = False
        
