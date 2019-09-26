#! /bin/sh

echo "\n ---- 更新git分支 end ---- \n"
git branch -f master HEAD
git checkout master
if [ ! $? -eq 0 ]; then
    echo "更新git分支失败"
    exit 0
fi


datetime=`date +"%Y%m%d%H%M"`
git_commit_des="daily build "$datetime

echo "\n ****** begin ****** \n"

echo "\n ---- 获取podspec文件 begin ---- \n"

# 获取到的文件路径
file_path=""
file_name=""
# 文件后缀名
file_extension="podspec"
# 文件夹路径，pwd表示当前文件夹
directory="$(pwd)"

# 参数1: 路径；参数2: 文件后缀名
function getFileAtDirectory(){
    for element in `ls $1`
    do  
        dir_or_file=$1"/"$element
        # echo "$dir_or_file"
        if [ -d $dir_or_file ]
        then 
            getFileAtDirectory $dir_or_file
        else
            file_extension=${dir_or_file##*.}
            if [[ $file_extension == $2 ]]; then
            	echo "$dir_or_file 是 $2 文件"
            	file_path=$dir_or_file
            	file_name=$element
            fi
        fi  
    done
}
getFileAtDirectory $directory $file_extension

echo "\n -------------"
echo "\n file_path: ${file_path}"
echo "\n file_name: ${file_name}"

echo "\n ---- 获取podspec文件 end ---- \n"



echo "\n ---- 读取podspec文件内容 begin ---- \n"

# 定义pod文件名称
pod_file_name=${file_name}
# 查找 podspec 的版本
search_str="s.version"

# 读取podspec的版本
podspec_version=""

#定义了要读取文件的路径
my_file="${pod_file_name}" 
while read my_line
do
#输出读到的每一行的结果
# echo $my_line

	# 查找到包含的内容，正则表达式获取以 ${search_str} 开头的内容
	result=$(echo ${my_line} | grep "^${search_str}")
	if [[ "$result" != "" ]]
	then
   		echo "\n ${my_line} 包含 ${search_str}"

   		# 分割字符串，是变量名称，不是变量的值; 前面的空格表示分割的字符，后面的空格不可省略
		array=(${result// / })  
		# 数组长度
		count=${#array[@]}
		# 获取最后一个元素内容
		version=${array[count - 1]}
		# 去掉 '
		version=${version//\'/}

		podspec_version=$version
	#else
   		# echo "\n ${my_line} 不包含 ${search_str}"
	fi

done < $my_file

echo "\n -------------"
echo "\n podspec_version: ${podspec_version}"

echo "\n ---- 读取podspec文件内容 end ---- \n"



pod_spec_name=${file_name}

 #修改版本号
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

sed -i '' "s/s.version          = '${podspec_version}'/s.version          = '${pod_spec_version}'/g" $pod_spec_name

if [ ! $? -eq 0 ]; then
    echo "版本号修改出错"
    exit 0
fi

echo "\n****** ${pod_spec_name} ${pod_spec_version} begin ****** \n"

echo "\n****** ${pod_spec_name} ${pod_spec_version} begin ****** \n"

echo "\n ------ 执行 pod install ------ \n"


echo "cd Example"
cd Example
echo "pod install"
pod install

# 回到上级目录
echo "cd .."
cd ..


echo "\n ------ 执行 git 本地提交代码操作 ------ \n"
# git 操作
echo "git add ."
git add $pod_spec_name
echo "git status"
git status
echo "git commit -m ${git_commit_des}"
git commit -m ${git_commit_des}
COMMIT_NUM=`git log -1 --pretty=%H`
echo "\n ------ 执行 git 本地提交代码操作 COMMIT_NUM:${COMMIT_NUM} ------ \n"
git push origin HEAD:refs/for/master
if [ ! $? -eq 0 ]; then
    echo "修改版本号代码push失败"
    exit 0
fi

ssh -p 29418 gerrit.ymfd.corp gerrit review --code-review 2 --submit $COMMIT_NUM
if [ ! $? -eq 0 ]; then
    echo "修改版本号代码自动submit失败"
    exit 0
fi

echo "\n ------ 执行 pod 本地校验 ------ \n"
# pod 本地校验
echo "pod lib lint --allow-warnings --verbose"
pod lib lint --use-libraries --allow-warnings --skip-import-validation --verbose --sources='ssh://gerrit.ymfd.corp:29418/YMSpecs,https://github.com/CocoaPods/Specs.git'

if [ ! $? -eq 0 ]; then
    echo "pod lib lint失败"
    exit 0
fi

echo "\n ------ 执行 git 打标签tag，并推送到远端 ------ \n"
# git推送到远端
echo "git tag ${pod_spec_version}"
git tag ${pod_spec_version}

if [ ! $? -eq 0 ]; then
    echo "打标签失败"
    exit 0
fi
echo "git push origin master --tags"
git push origin --tags

if [ ! $? -eq 0 ]; then
    echo "push标签失败"
    exit 0
fi


echo "\n ------ 执行 pod 远端校验 ------ \n"
# pod 远端校验
echo "pod spec lint --allow-warnings --verbose"
pod spec lint --allow-warnings --verbose --use-libraries --skip-import-validation --sources='ssh://gerrit.ymfd.corp:29418/YMSpecs,https://github.com/CocoaPods/Specs.git'

if [ ! $? -eq 0 ]; then
    echo "pod spec lint失败"
    exit 0
fi

echo "\n ------ 执行 pod 发布 ------ \n"
# 发布
echo "pod trunk push --allow-warnings"
pod repo push ymfd-ymspecs YMTCloudClassroom.podspec --skip-import-validation --use-libraries --allow-warnings --sources='ssh://gerrit.ymfd.corp:29418/YMSpecs,https://github.com/CocoaPods/Specs.git'

if [ ! $? -eq 0 ]; then
    echo "pod repo push lint失败"
    exit 0
fi

echo "\n****** ${pod_spec_name} ${pod_spec_version} end ****** \n"

echo "****** end ******"



