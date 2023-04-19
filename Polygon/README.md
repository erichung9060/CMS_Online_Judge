# Package test case from polygon package to cms format

1. 把這份repo載下來，並進到Polygon資料夾。或是直接建立一個資料夾並把pack.sh放進去
2. 到Polygon的Packages點擊Full並下載Linux版。
<img width="1112" alt="image" src="https://user-images.githubusercontent.com/101823195/232975754-166b7831-db3c-4fbd-9975-38cb05f49e2c.png">

3. 解壓縮所有檔案到此資料夾(可順便更改檔名)
<img width="518" alt="image" src="https://user-images.githubusercontent.com/101823195/232982551-f85edceb-590e-413f-85c8-be15a4eef207.png">

4. 執行以下指令後會生成一個`cmsTestCase`資料夾，為每一題測資的zip檔。
```
sudo chmod a+x pack.sh && ./pack.sh
```
<img width="517" alt="image" src="https://user-images.githubusercontent.com/101823195/232981339-1042964f-0612-475c-9798-0d411ea68d14.png">

5.到CMS Task中下方Test Case的地方點擊` Add multiple testcases`並選擇該題的zip檔上傳
<img width="965" alt="image" src="https://user-images.githubusercontent.com/101823195/232983399-95e84d0e-5eaf-490d-8f2f-770c17d560c5.png">
