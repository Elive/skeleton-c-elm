#!/bin/bash
echo -e temporally disabled ; exit 1
# short name
XXappnameXX="spoon"
# Caps name
XXAppnameXX="Spoon"
XXAPPNAMEXX="SPOON"
# visible/public name
XXAppNamePublicXX="My Spoon App"
#your name
XXname1XX="John"
XXname2XX="Smith"
#email
XXemailXX="john.smith@nowhere.com"
# validate the next variable before to proceed
valid="no"


# Checks
if [[ -d .git ]] ; then
	echo -e "E: .git dir exists, please remove it before to create a new project"
	exit 1
fi

if [[ "${valid}" = "no" ]] ; then
   echo -e "E: variables not validated yet"
   exit 1
fi


# run
find . -name .git -prune -o -type f ! -name rename.sh -exec sed -i "s/XXname1XX/$NAME1/g" {} \;
find . -name .git -prune -o -type f ! -name rename.sh -exec sed -i "s/XXname2XX/$NAME2/g" {} \;

find . -name .git -prune -o -type f ! -name rename.sh -exec sed -i "s/XXemailXX/$XXemailXX/g" {} \;
find . -name .git -prune -o -type f ! -name rename.sh -exec sed -i "s/XXAppNamePublicXX/$XXAppNamePublicXX/g" {} \;
find . -name .git -prune -o -type f ! -name rename.sh -exec sed -i "s/XXAPPNAMEXX/$XXAPPNAMEXX/g" {} \;
find . -name .git -prune -o -type f ! -name rename.sh -exec sed -i "s/XXAppnameXX/$XXAppnameXX/g" {} \;
find . -name .git -prune -o -type f ! -name rename.sh -exec sed -i "s/XXappnameXX/$XXappnameXX/g" {} \;


while read -ru 3 line
do
	[[ -f "$line" ]] && mv "$line" "${line/XXAppnameXX/$XXAppnameXX}"
done 3<<<"$( find . -type f -name '*'XXAppnameXX'*' )"

while read -ru 3 line
do
	[[ -f "$line" ]] && mv "$line" "${line/XXAPPNAMEXX/$XXAPPNAMEXX}"
done 3<<<"$( find . -type f -name '*'XXAPPNAMEXX'*' )"

while read -ru 3 line
do
	[[ -f "$line" ]] && mv "$line" "${line/XXappnameXX/$XXappnameXX}"
done 3<<<"$( find . -type f -name '*'XXappnameXX'*' )"

echo -e "${XXAppnameXX}\n===================\n\n${XXAppNamePublicXX}" > README.md

# trashy files
echo -e "${XXname1XX} ${XXname2XX} - ${XXemailXX}" >> AUTHORS
touch NEWS ChangeLog

