# P5
## Home Service Robot

### Environment setup
1. Activate the right conda environment
It seems that `/root/.bashrc` is setting up conda to work with Python3. But the default version of python for `ros-kinetic` is `python2`. For that reason, we start a conda environment that was created for our nanodegree. 
Open a `Terminator` and write:
```shell
conda init bash
```
Close this terminal and open a new one. There, write:
```shell
conda activate /opt/robond/py2
```

Now the line in the terminal starts with `(/opt/robond/py2)`. Great! Stay in this terminal :)
