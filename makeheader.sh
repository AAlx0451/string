#!/bin/sh

SOURCE_FILE="string.c"
HEADER_FILE="string.h"
HEADER_GUARD="STRING_H"

if [ ! -f "$SOURCE_FILE" ]; then
    ./amalgation.sh || exit 1
fi

echo Generating string.h header

{
    echo "#ifndef $HEADER_GUARD"
    echo "#define $HEADER_GUARD"
    echo ""
    echo "#include <stddef.h> /* size_t, NULL */"
    echo ""
} > "$HEADER_FILE"

awk '
/^[a-zA-Z_].*\([^;]*\)\s*\{?$/ {
    if ($1 == "if" || $1 == "while" || $1 == "for" || $1 == "switch") {
        next
    }
    if ($1 == "static") {
        next
    }
    line = $0
    sub(/\s*\{\s*$/, "", line)
    print line ";"
}
' "$SOURCE_FILE" >> "$HEADER_FILE"

{
    echo ""
    echo "#endif /* $HEADER_GUARD */"
} >> "$HEADER_FILE"

echo "Done."
