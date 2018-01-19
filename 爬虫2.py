import urllib2
response = urllib2.urlopen('http://www.baidu.com/')'''调用urllib2的urlopen()方法加载网址信息赋值给response'''
html = response.read()'''调用read()方法读取来输=输出 赋值给变量html'''
print html
