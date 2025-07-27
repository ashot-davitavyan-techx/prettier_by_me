FTYPE=".css"
FOLDER_NAME="save"
FOLDER_COUNT="1"
CSS_FILES=$(find ../ -name "*.css" -not -path "*save*")

if [ ! -d "$FOLDER_NAME" ]; then
    mkdir "$FOLDER_NAME"
else
    while [ -d "${FOLDER_NAME}_$FOLDER_COUNT" ]; do
        ((FOLDER_COUNT++))
    done
    FOLDER_NAME="${FOLDER_NAME}_$FOLDER_COUNT"
    mkdir "$FOLDER_NAME"
fi

cp ${CSS_FILES} ${FOLDER_NAME}

for file in $CSS_FILES
do
    PRETTIER_CSS=$(./prettier < "$file")
	echo "$PRETTIER_CSS" > "$file"
done
