export PYTHONPATH=./:/home/pengshanzhen/caffe/python:$PYTHONPATH
LOG=/data_2/my_bishe_experiment/part-B4/snapshot/log-`date +%Y-%m-%d-%H-%M-%S`.log 
/home/pengshanzhen/caffe/build/tools/caffe train -solver solver.prototxt  2>&1  | tee $LOG $@






