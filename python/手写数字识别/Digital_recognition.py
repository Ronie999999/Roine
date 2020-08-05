import numpy
import scipy.special
import imageio


class NeuralNetwork:
    def __init__(self, input_nodes, hidden_nodes, output_nodes, learning_rates):
        self.input_notes = input_nodes
        self.hidden_nodes = hidden_nodes
        self.output_nodes = output_nodes
        self.learn_rates = learning_rates
        self.i_h_matrix = numpy.random.rand(self.hidden_nodes, self.input_notes) - 0.5
        self.h_o_matrix = numpy.random.rand(self.output_nodes, self.hidden_nodes) - 0.5
        self.s_function = lambda x: scipy.special.expit(x)

    def training(self, input_list, target_list):
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

    def query(self, input_list):
        inputs = numpy.array(input_list, ndmin=2).T
        hidden_inputs = numpy.dot(self.i_h_matrix, inputs)
        hidden_outputs = self.s_function(hidden_inputs)
        final_inputs = numpy.dot(self.h_o_matrix, hidden_outputs)
        final_outputs = self.s_function(final_inputs)
        return final_outputs


