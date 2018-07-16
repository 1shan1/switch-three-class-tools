import cv2
import numpy as np
import os
import pandas as pd
import random
import shutil



f = open('/data_1/data/formatted_trainval/shanghaitech_part_A_patches_100/train.txt','r')
fold_path = '/data_1/data/formatted_trainval/shanghaitech_part_A_patches_100/exact-class'
out_fold_path = '/data_1/data/formatted_trainval/shanghaitech_part_A_patches_100/exact-img'
for line in f.readlines():
  line = line.strip()
  ff = line.split('/')[7]
  img_name = ff.split(' ')[0]
  label = ff.split(' ')[1]
  img_path = fold_path + '/' + img_name
  out_img_path = out_fold_path + '/' + label + '/' + img_name
  shutil.copyfile(img_path,out_img_path)
  
  
  
