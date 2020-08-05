import PIL.Image
import matplotlib.pyplot
import numpy


def process(file_path):
    img = PIL.Image.open(file_path).convert('L')
    if img.size[0] != 28 or img.size[1] != 28:
        img = img.resize((28, 28))
    arr = []
    for i in range(28):
        for j in range(28):
            pixel = (1.0 - float(img.getpixel((j, i))) / 255) * 0.99 + 0.01
            arr.append(pixel)
    # print(arr)
    # image_array = numpy.asfarray(arr).reshape((28, 28))
    # matplotlib.pyplot.imshow(image_array, cmap="Greys")
    # matplotlib.pyplot.show()
    return arr


