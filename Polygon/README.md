# Convert Polygon Package To CMS Format

1. Go to Polygon's Packages, click Full and Download Linux version.
<img width="1112" alt="image" src="https://user-images.githubusercontent.com/101823195/232975754-166b7831-db3c-4fbd-9975-38cb05f49e2c.png">

2. Extract the archive to a new folder (Remember to change file name, you can add multiple problems in that folder)

Next, there will be two conversion methods, which are `Full Contest Conversion` and `TestCase Only Conversion`.
## Full Contest Conversion
1. Copy pack_to_yaml.sh to your folder or use the following command
```
curl https://raw.githubusercontent.com/erichung9060/cms/main/Polygon/pack_to_yaml.sh -o pack_to_yaml.sh
```
<img width="564" alt="image" src="https://github.com/erichung1113/cms/assets/101823195/87570ab6-e875-497c-acaa-ecbcb9c1f6fe">

3. Run the following command, then a folder named Contest will be generated, which is a CMS contest package with problems you added.
```
chmod u+x pack_to_yaml.sh && ./pack_to_yaml.sh
```
<img width="565" alt="image" src="https://github.com/erichung1113/cms/assets/101823195/7d1abe87-d0aa-4e28-8dfa-7e382b96756d">

3. Go into the Contest folder and run the command to import contest to CMS.
```
chmod u+x import.sh && ./import.sh
```
4. After importing the contest, you still need to change some settings:\
    a. score mode \
    b. allowed language \
    c. contest's start time and end time

## TestCase Only Conversion
1. Copy pack_testcase.sh to that folder
<img width="565" alt="image" src="https://github.com/erichung1113/cms/assets/101823195/1699839a-45de-40e5-9601-8dd4569698c7">

2. Run the following command, then a folder named cmsTestCase will be generated, which contains zip files for each problem.
```
chmod u+x pack_testcase.sh && ./pack_testcase.sh
```
<img width="517" alt="image" src="https://user-images.githubusercontent.com/101823195/232981339-1042964f-0612-475c-9798-0d411ea68d14.png">

3. Go to `Test Case` at the bottom of Task on CMS, and click `Add multiple testcases` then select the zip file of the problem to upload.
<img width="524" alt="Screenshot 2023-08-02 at 5 00 27 AM" src="https://github.com/erichung1113/cms/assets/101823195/b071d1df-5405-4db9-a87e-527f11b3e4c6">
<img width="965" alt="image" src="https://user-images.githubusercontent.com/101823195/232983399-95e84d0e-5eaf-490d-8f2f-770c17d560c5.png">

4. Congratulations!🥳
