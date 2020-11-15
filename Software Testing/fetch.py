import requests
import json
import urllib
from pathlib import Path
import os


class Project(object):

    def __init__(self, tag):
        self.tag = tag
        self.get_info()

    def get_info(self):
        res = requests.get('http://118.31.34.71:8080/workspaces/%s' % self.tag)
        self.attributes = json.loads(res.text)

    def get_project_name(self):
        return self.attributes['projectName']

    def get_path(self, path):
        res = requests.get('http://118.31.34.71:8080/workspaces/%s/files?path=%s&order=true&group=true' %
                           (self.tag, urllib.parse.quote(path)))
        return json.loads(res.text)

    def get_file(self, path):
        res = requests.get('http://118.31.34.71:8080/workspaces/%s/file/read?path=%s&base64=false' %
                           (self.tag, urllib.parse.quote(path)))
        return json.loads(res.text)


class Downloader(object):

    def __init__(self, project, working_directory='.'):
        self.project = project
        self.working_directory = working_directory

    def work(self):
        real_path = Path('./%s' % project.get_project_name())

        if real_path.exists():
            print('Path %s exists.' % real_path.resolve())
            exit(1)

        self.fetch_path('/', real_path)

    def fetch_path(self, uri, real_path):
        print(real_path)

        real_path.mkdir()

        try:
            res = self.project.get_path(uri)

            for item in res:
                if item['isDir']:
                    self.fetch_path(item['path'], real_path / item['name'])
                else:
                    self.fetch_file(item['path'], real_path / item['name'])
        except Exception as e:
            print('Exception when download %s to %s' % (uri, real_path))
            print(e)

    def fetch_file(self, uri, real_path):
        print(real_path)

        if real_path.exists():
            print('%s exists! Pass' % real_path)
            return

        try:
            res = self.project.get_file(uri)
            if uri.endswith('.class'):
                with real_path.open(mode='wb') as f:
                    f.write(res['content'].encode('utf-16be'))
            else:
                with real_path.open(mode='w') as f:
                    f.write(res['content'])
        except Exception as e:
            print('Exception when download %s to %s' % (uri, real_path))
            print(e)




if __name__ == '__main__':
    project = Project('bhkvpj')
    downloader = Downloader(project)

    downloader.work()
