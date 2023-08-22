#! /bin/bash
# Author: 11711918

# copy arguments
TARGET_DIRECTORY=$(realpath "$1")
OUTPUT_FILE=$(realpath "$2")

recho() {
  echo "$@" >>"$OUTPUT_FILE"
}

# clean OUTPUT_FILE
: >$2

# check directory
if ! [ -d "$TARGET_DIRECTORY" ]; then
  recho "Maybe that is not a directory ?"
  exit -1
fi

# keep system language
lang_bak=$LANG
LANG=en_US.UTF-8

# keep IFS
ifs_bak=$IFS
IFS=$'\n'

pwd=($TARGET_DIRECTORY)
if [ "$TARGET_DIRECTORY" = "/" ]; then
  queue=("/")
else
  queue=(${TARGET_DIRECTORY##*/})
fi

i=0

f=0
d=0
while [ $i -ne ${#queue[@]} ]; do
  recho [${queue[$i]}]
  now=${pwd[$i]}
  for file in $(ls $now); do
    new=$now/$file
    recho $new
    if [ -d $new ]; then
      let d++
      queue+=($file)
      pwd+=($new)
    else
      let f++
    fi
  done
  recho ""
  let i++
done

recho "[Directories Count]:"${d}
recho "[Files Count]:"${f}

# The following code is confirmed to be useless.

# restore system language
# export $LANG=$lang_bak
# restore ifs
# export $IFS=$ifs_bak
