# usage : python3 dependency.py pA

import xml.etree.ElementTree as ET
import json, sys

file_path = sys.argv[1] + "/problem.xml"

# Load the XML file
tree = ET.parse(file_path)
root = tree.getroot()

groups = []
group_points = {}
group_dependencies = {}
group_counts = {}
group_testcase_regex = {}

for group in root.findall(".//group"):
    group_name = group.get('name')
    groups.append(group_name)
    
    points = group.get('points', '0')
    group_points[group_name] = int(float(points))

    dependencies = [dep.get('group') for dep in group.findall('.//dependency')]
    group_dependencies[group_name] = dependencies

for test in root.findall(".//test"):
    group = test.get('group')
    if group in group_counts:
        group_counts[group] += 1
    else:
        group_counts[group] = 1

for group in groups:
    print(f"Group {group} : number: {group_counts[group]}, points: {group_points[group]}, dependency: {group_dependencies[group]}")

#---------------------------------------------------

cur = 0
for group in groups:
    count = group_counts[group]
    print(f"{cur:03d} {cur + count - 1:03d}")
    cur += count
    regex = input()
    # regex = group
    group_testcase_regex[group] = regex


score_parameters = []
for group in groups:
    testcase_regex = group_testcase_regex[group]
    for dependency in group_dependencies[group]:
        testcase_regex += "|" + group_testcase_regex[dependency]
    
    score_parameters.append((group_points[group],testcase_regex))

json_string = json.dumps(score_parameters)
print('\n\n' + json_string)
