import numpy
import scipy.special
import matplotlib.pyplot
import image_processing


class NeuralNetwork:
    def __init__(self, input_nodes, hidden_nodes, output_nodes, learning_rates):
        self.input_notes = input_nodes
        self.hidden_nodes = hidden_nodes
        self.output_nodes = output_nodes
        self.learn_rates = learning_rates
        self.i_h_matrix = numpy.random.rand(self.hidden_nodes, self.input_notes) - 0.5
        self.h_o_matrix = numpy.random.rand(self.output_nodes, self.hidden_nodes) - 0.5
        self.s_function = lambda x: scipy.special.expit(x)

    def __training(self, input_list, target_list):
        inputs = numpy.array(input_list, ndmin=2).T
        target = numpy.array(target_list, ndmin=2).T
        hidden_inputs = numpy.dot(self.i_h_matrix, inputs)
        hidden_outputs = self.s_function(hidden_inputs)
        final_inputs = numpy.dot(self.h_o_matrix, hidden_outputs)
        final_outputs = self.s_function(final_inputs)
        output_error = target - final_outputs
        hidden_error = numpy.dot(self.h_o_matrix.T, output_error)
        self.h_o_matrix += self.learn_rates * numpy.dot((output_error * final_outputs * (1 - final_outputs)), numpy.transpose(hidden_outputs))
        self.i_h_matrix += self.learn_rates * numpy.dot((hidden_error * hidden_outputs) * (1 - hidden_outputs), numpy.transpose(inputs))
        pass

    def __query(self, input_list):
        inputs = numpy.array(input_list, ndmin=2).T
        hidden_inputs = numpy.dot(self.i_h_matrix, inputs)
        hidden_outputs = self.s_function(hidden_inputs)
        final_inputs = numpy.dot(self.h_o_matrix, hidden_outputs)
        final_outputs = self.s_function(final_inputs)
        return final_outputs

    def training(self, path):
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
            targets = numpy.zeros(self.output_nodes) + 0.01
            targets[int(value[0])] = 0.99
            self.__training(input_data, targets)

    def test(self, path):
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
            print(value[0], end=" : ")
            input_data = numpy.asfarray(value[1:]) / 255 * 0.99 + 0.01
            outputs = self.__query(input_data)
            num = numpy.argmax(outputs)
            print(num)
            if num == int(value[0]):
                top = top + 1
        print(top / bottom)

    def query(self, file):
        arr = image_processing.process(file)
        out = self.__query(arr)
        print(numpy.argmax(out))
