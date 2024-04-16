import mosspy

userid = 61861013

m = mosspy.Moss(userid, "python")


m.addFilesByWildcard("pH/*")

url = m.send() # Submission Report URL

print ("Report Url: " + url)
