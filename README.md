### 安裝環境 : Ubuntu
**Step. 1 更新所有套件**
```
sudo apt update && sudo apt upgrade -y
```

**Step. 2 安裝docker compose**
```
sudo apt install docker-compose -y
```
**Step. 3 下載cms**
```
git clone https://github.com/erichung1113/cms.git && cd cms
```
**Step. 4 執行docker compose**
```
sudo docker-compose up -d
```
**Step. 5 建立Admin帳號**
```
sudo docker exec -t cms sudo cmsAddAdmin admin
```
接著打開瀏覽器並輸入以下網址就可使用啦


參賽者介面：`localhost:8888`

管理員介面：`localhost:8889`

計分板：`localhost:8890`

詳細請見 : [CMS Online Judge Docker安裝教學](https://hackmd.io/WKsC33XYRme4sM-Kkst_XA)
