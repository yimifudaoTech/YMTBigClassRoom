#!/bin/bash
 #修改版本号
podspec_version=0.1.8.1
SDK_MAIN_VERSION=1
SDK_SUB_VERSION_1=0
SDK_SUB_VERSION_2=0
SDK_SUB_VERSION_3=0

old=¥IFS
IFS=.
versionCharIndex=0
for versionChar in $podspec_version
do
    printf "%s\n" $versionChar
    if [[ "$versionCharIndex" = 0 ]];then
        SDK_MAIN_VERSION=$versionChar
    elif [[ "$versionCharIndex" = 1 ]];then
        SDK_SUB_VERSION_1=$versionChar
    elif [[ "$versionCharIndex" = 2 ]];then
        SDK_SUB_VERSION_2=$versionChar
    elif [[ "$versionCharIndex" = 3 ]];then
        SDK_SUB_VERSION_3=$versionChar
    fi
    versionCharIndex=$[versionCharIndex+1]
done
IFS=$old
SDK_SUB_VERSION_3=$[SDK_SUB_VERSION_3+1]

pod_spec_version=${SDK_MAIN_VERSION}.${SDK_SUB_VERSION_1}.${SDK_SUB_VERSION_2}.${SDK_SUB_VERSION_3}

echo "\n****** ${pod_spec_name} ${pod_spec_version} begin ****** \n"
