from Digital_recognition import NeuralNetwork
import numpy
import os

file_path = os.path.dirname(os.path.abspath(__file__))
test_path = file_path + "\\mnist\\mnist_test.csv"
training_path = file_path + "\\mnist\\mnist_train.csv"

i_nodes = 784
o_nodes = 10
h_nodes = 200
l_rates = 0.1

neural = NeuralNetwork(i_nodes, h_nodes, o_nodes, l_rates)
# csv文件
neural.training(training_path)
neural.test(test_path)
# 图片文件 正方形
neural.query("C:\\Users\\ren_r\\Desktop\\python\\num_pic\\0.png")

