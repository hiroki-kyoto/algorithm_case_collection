# create git environment
git init
# set current repository address
git remote add algorithm https://github.com/xiangchao027/algorithm_case_collection.git
# pull branch of project into local path
git pull algorithm master
# make git remember credential
git config --global credential.helper store
# now try to modify your local branch
# then you should push your changes to merge with remote branch
git add *
git commit
git push algorithm master
# helper shell demo is over, thanks!
