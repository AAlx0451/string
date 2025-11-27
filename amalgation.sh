#!/bin/bash

OUTPUT_FILE="string.c"

grep -h '^#include' src/*.c | sort -u > "$OUTPUT_FILE"

grep -h -v '^#include' src/*.c | awk '
!/^\s*(if|for|while|switch)\s*\(/ && match($0, /([a-zA-Z_][a-zA-Z0-9_]*)\s*\([^)]*\)\s*\{$/, m) {
    func_name = m[1]
    uc_func_name = toupper(func_name)
    if (func_name == "strerror" || func_name == "strdup") {
        print "#if !defined(NO_" uc_func_name ") && !defined(NO_DEPEND)"
    } else {
        print "#ifndef NO_" uc_func_name
    }
    in_function = 1
}

{ print }

in_function && /^\s*\}\s*$/ {
    print "#endif"
    in_function = 0
}
' >> "$OUTPUT_FILE"
