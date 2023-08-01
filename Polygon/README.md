# Convert Polygon Package To CMS Format

1. Go Polygon's Packages, click Full and Download the Linux version 
<img width="1112" alt="image" src="https://user-images.githubusercontent.com/101823195/232975754-166b7831-db3c-4fbd-9975-38cb05f49e2c.png">

2. Extract the archive to a new folder (Remember to change file name)
<img width="518" alt="image" src="https://user-images.githubusercontent.com/101823195/232982551-f85edceb-590e-413f-85c8-be15a4eef207.png">

## Convert Whole Package
1. Copy pack_to_yaml.sh to that folder 

Score mode 
allowed language
start time end time

## Convert Package Only
1. Copy pack_testcase.sh to that folder
2. Run the following command, then a folder named cmsTestCase will be generated, which contains zip files for each problem.
2. 執行以下指令後會生成一個`cmsTestCase`資料夾，為每一題測資的zip檔。
```
sudo chmod a+x pack_testcase.sh && ./pack_testcase.sh
```
<img width="517" alt="image" src="https://user-images.githubusercontent.com/101823195/232981339-1042964f-0612-475c-9798-0d411ea68d14.png">

3.到CMS Task中下方Test Case的地方點擊` Add multiple testcases`並選擇該題的zip檔上傳
<img width="965" alt="image" src="https://user-images.githubusercontent.com/101823195/232983399-95e84d0e-5eaf-490d-8f2f-770c17d560c5.png">
