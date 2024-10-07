alias stopcms="sudo kill \$(ps aux | grep cms | awk '{print \$2}' | head -n -1) > /dev/null 2>&1"
alias startcms="sudo cmsResourceService -a"
alias restartcms="stopcms; startcms"
