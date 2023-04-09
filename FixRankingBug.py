#/usr/local/lib/python3.10/dist-packages/cms-1.5.dev0-py3.10.egg/cmsranking/RankingWebServer.py

#global
new_task_id=1

# line 196
            print(data)

            global new_task_id
            global task_id_second
            for task_id in list(data.keys()):
                if task_id.isdigit():
                    data[str(new_task_id)] = data.pop(task_id)
                    new_task_id+=1
                elif task_id[-1]=='s':
                    data[task_id]['submission']=str(task_id_second);
                    task_id_second+=1
            print(data)
