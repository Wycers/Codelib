import subprocess, shutil
from os import path, listdir, remove
def testDateUtil():
    filelist = ['DateUtil.java']
    for file in filelist:
        if not path.exists(path.join('.', 'user', file)):
            print('File [ %s ] not found while testing DateUtil' % file)
            return 0
        shutil.copyfile(path.join('.', 'user', file), path.join('.', file))
    shutil.copyfile(path.join('.', 'assets', 'TestDateUtil.java'), path.join('.', 'TestDateUtil.java'))
    code, output = subprocess.getstatusoutput('javac %s' % path.join('.', 'TestDateUtil.java'))
    if code is not 0: 
        print('test file can not be compiled')
        print(output)
        return 0
    for file in filelist:
        code, output = subprocess.getstatusoutput('javac %s' % path.join('.', file))
        if code is not 0:
            print('user file can not be compiled')
            return 0
    code, output = subprocess.getstatusoutput('java TestDateUtil')
    return int(output)

def testPointAndLine():
    filelist = ['Point.java', 'Line.java']
    for file in filelist:
        if not path.exists(path.join('.', 'user', file)):
            print('File [ %s ] not found while testing PointAndLine' % file)
            return 0
        shutil.copyfile(path.join('.', 'user', file), path.join('.', file))
    shutil.copyfile(path.join('.', 'assets', 'TestPointAndLine.java'), path.join('.', 'TestPointAndLine.java'))
    code, output = subprocess.getstatusoutput('javac %s' % path.join('.', 'TestPointAndLine.java'))
    if code is not 0: 
        print('test file can not be compiled')
        print(output)
        return 0
    for file in filelist:
        code, output = subprocess.getstatusoutput('javac %s' % path.join('.', file))
        if code is not 0:
            print('user file can not be compiled')
            return 0
    code, output = subprocess.getstatusoutput('java TestPointAndLine')
    return int(output)

def testContainerAndBall():
    filelist = ['Container.java', 'Ball.java']
    for file in filelist:
        if not path.exists(path.join('.', 'user', file)):
            print('File [ %s ] not found while testing ContainerAndBall' % file)
            return 0
        shutil.copyfile(path.join('.', 'user', file), path.join('.', file))
    shutil.copyfile(path.join('.', 'assets', 'TestContainerAndBall.java'), path.join('.', 'TestContainerAndBall.java'))
    code, output = subprocess.getstatusoutput('javac %s' % path.join('.', 'TestContainerAndBall.java'))
    if code is not 0: 
        print('test file can not be compiled')
        print(output)
        return 0
    for file in filelist:
        code, output = subprocess.getstatusoutput('javac %s' % path.join('.', file))
        if code is not 0:
            print('user file can not be compiled')
            return 0
    code, output = subprocess.getstatusoutput('java TestContainerAndBall')
    return int(output)

workspace = path.join('.', 'user')
filelist = ['Ball.java', 'Container.java', 'DateUtil.java', 'Line.java', 'Point.java']
files = listdir(workspace)
for file in files:
    if file not in filelist:
        remove(path.join(workspace, file))

task1 = testDateUtil()
task2 = testPointAndLine()
task3 = testContainerAndBall()
print(task1, task2, task3)
subprocess.getoutput('rm *.class *.java')
# print(path.join('.', filelist[0]))

# code, output = subprocess.getstatusoutput('javac TestDateUtil.java')
# print(code)
# print(output.split('\n'))

# files = listdir(workspace)
# for file in files:
    # remove(path.join(workspace, file))



