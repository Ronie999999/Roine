import numpy as np
from PIL import Image

import os
from wordcloud import WordCloud
mask = np.array(Image.open("C:\\Users\\ren_r\\Desktop\\python\\untitled.png"))
text = ''
font = "C:\\Windows\\Fonts\\STKAITI.TTF"
with open("C:\\Users\\ren_r\\Desktop\\python\\text.txt", "r", encoding='utf8') as f:
    while True:
        str_text = f.readline()
        if str_text == "":
            break
        text += str_text

my_wordcloud = WordCloud(scale=4,
                         mask=mask,
                         max_font_size=80,
                         random_state=30,
                         font_path=font,
                         stopwords=None,
                         repeat=True,
                         background_color="white"
                         ).generate(text)
my_wordcloud.to_file("a_new_hope.png")

