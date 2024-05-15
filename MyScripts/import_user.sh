paste id name account password | while read -r name id account password; do
    echo "$name, $id, $account, $password"
    cmsAddUser $name $id $account -p $password;
    cmsAddParticipation -c 1 $account   
done
