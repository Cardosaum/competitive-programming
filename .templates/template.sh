#!/usr/bin/env bash
set -euo pipefail

TEMPLATE_DIR=".templates"
TEMPLATE_DIR=$(echo "$(git rev-parse --show-toplevel)/${TEMPLATE_DIR}")
MAIN_CPP=$(fd -e.cpp -tf -d1 -a "main.cpp" "${TEMPLATE_DIR}")
MAKEFILE_SRC=$(fd -tf -d1 -a -i "makefile" "${TEMPLATE_DIR}")
MAIN_DEST="main.cpp"
MAKEFILE_DEST="Makefile"

xclip -sel c -o | rg 'problem/\d+/[\w\d]+$' -o | xargs -d $'\n' sh -c 'for arg do mkdir -p "$arg"; echo -n "$arg" | xclip -sel c; done' _
NEW_PWD=$(xclip -sel c -o)
cd "${NEW_PWD}"

[[ ! -f "${MAIN_DEST}" ]] && cp "${MAIN_CPP}" "${MAIN_DEST}" || echo "Avoid creation of file"
[[ ! -f "${MAKEFILE_DEST}" ]] && ln -rs "${MAKEFILE_SRC}" "${MAKEFILE_DEST}" || echo "Avoid creation of file"

emacsclient -a "" -c -n "${MAIN_DEST}"
echo -n "${NEW_PWD}" | xclip -sel c
