#/usr/local/lib/python3.10/dist-packages/cms-1.5.dev0-py3.10.egg/cmsranking/RankingWebServer.py

#global
new_task_id=1

# line 196
for task_id in data.keys():
    #task_id=list(data.keys())[0]
    if task_id.isdigit():
        global new_task_id
        data[str(new_task_id)] = data.pop(task_id)
    elif task_id[-1]=='s':
        data[task_id]['submission']=str(new_task_id);
        new_task_id+=1
