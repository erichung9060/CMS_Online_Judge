import mosspy, sys

userid = 61861013

m = mosspy.Moss(userid, "python")

m.addFilesByWildcard("Problem_Submissions/" + sys.argv[1] + "/*")

url = m.send()
 
print (sys.argv[1] + " : " + url)
