from Digital_recognition import NeuralNetwork
import image_processing
import numpy
import os
import matplotlib.pyplot


i_nodes = 784
o_nodes = 10
h_nodes = 200
l_rates = 0.1

neural = NeuralNetwork(i_nodes, h_nodes, o_nodes, l_rates)


# training neural network
def training(path):
    file_training = open(path)
    file_training_list = []
    while True:
        text = file_training.readline()
        if not text:
            break
        file_training_list.append(text)
    file_training.close()
    for i in range(len(file_training_list)):
        value = file_training_list[i].split(",")

        input_data = numpy.asfarray(value[1:]) / 255 * 0.99 + 0.01
        targets = numpy.zeros(o_nodes) + 0.01
        targets[int(value[0])] = 0.99
        neural.training(input_data, targets)


# test neural network
def test(path):
    file_test = open(path)
    file_test_list = []
    while True:
        text = file_test.readline()
        if not text:
            break
        file_test_list.append(text)
    file_test.close()
    top = 0
    bottom = len(file_test_list)
    for i in range(len(file_test_list)):
        value = file_test_list[i].split(",")
        # print(value[0], end=" : ")
        input_data = numpy.asfarray(value[1:]) / 255 * 0.99 + 0.01
        outputs = neural.query(input_data)
        num = numpy.argmax(outputs)
        if i < 10:
            image_array = numpy.asfarray(input_data).reshape((28, 28))
            matplotlib.pyplot.imshow(image_array, cmap="Greys")
            matplotlib.pyplot.show()
        # print(num)
        if num == int(value[0]):
            top = top + 1
    print(top/bottom)


def query(file):
    arr = image_processing.process(file)
    out = neural.query(arr)
    print(numpy.argmax(out))


training("C:\\Users\\ren_r\\Desktop\\python\\mnist\\mnist_train.csv")
training("C:\\Users\\ren_r\\Desktop\\python\\mnist\\mnist_test.csv")
test("C:\\Users\\ren_r\\Desktop\\python\\mnist\\mnist_test.csv")
file_path = "C:\\Users\\ren_r\\Desktop\\python\\num_pic\\"
for n in range(10):
    query(file_path + str(n) + ".png")
query('C:\\Users\\ren_r\\Desktop\\7.jpg')