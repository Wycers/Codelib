import subprocess, shutil
from os import path, listdir, remove

def test(name, filelist):
    global workspace
    for file in filelist:
        if not path.exists(path.join('.', 'user', file)):
            print('[%s] File [ %s ] not found.' % (name, file))
            return 0
        shutil.copyfile(path.join('.', 'user', file), path.join('.', file))
    shutil.copyfile(path.join('.', 'assets', '%s.java' % name), path.join('.', '%s.java' % name))
    code, output = subprocess.getstatusoutput('javac %s' % path.join('.', '%s.java' % name))
    if code is not 0: 
        print('[%s] test file can not be compiled' % name)
        return 0
    for file in filelist:
        code, output = subprocess.getstatusoutput('javac %s' % path.join('.', file))
        if code is not 0:
            print('[%s] user file can not be compiled' % name)
            return 0
    code, output = subprocess.getstatusoutput('java %s' % name)
    if code is not 0:
        print('%s failed' % name)
        return 0
    for file in filelist:
        remove(path.join(workspace, file))
    return int(output.split('\n')[-1])

workspace = path.join('.', 'user')
filelist = ['Ball.java', 'Container.java', 'DateUtil.java', 'Line.java', 'Point.java']
files = listdir(workspace)
for file in files:
    if file not in filelist:
        remove(path.join(workspace, file))

task1 = test('TestDateUtil', ['DateUtil.java'])
task2 = test('TestPointAndLine', ['Point.java', 'Line.java'])
task3 = test('TestContainerAndBall', ['Container.java', 'Ball.java'])
print(task1, task2, task3, '==>', task1 * 0.3 + task2 * 0.3 + task3 * 0.4)
subprocess.getoutput('rm *.class *.java')