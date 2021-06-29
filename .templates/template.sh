#!/usr/bin/env bash
set -euo pipefail
p="$HOME/.profile" ; [[ -f "${p}" ]] && source "${p}" || { echo 'FileNotFound: `'"${p}"'`'; exit 1; }

TEMPLATE_DIR=".templates"
TEMPLATE_DIR=$(echo "$(git rev-parse --show-toplevel)/${TEMPLATE_DIR}")
MAIN_CPP=$(fd -e.cpp -tf -d1 -a "main.cpp" "${TEMPLATE_DIR}")
MAKEFILE_SRC=$(fd -tf -d1 -a -i "makefile" "${TEMPLATE_DIR}")
CLANG_FORMAT_SRC=$(fd --no-ignore --hidden -tf -d1 -a -i ".clang-format" "${TEMPLATE_DIR}")
MAIN_DEST="main.cpp"
MAKEFILE_DEST="Makefile"
CLANG_FORMAT_DEST=".clang-format"
URL=$(xclip -sel c -o )

echo "${URL}" | rg '(contest/\d+/)?problems?(/\d+)?/[\w\d]+/?$' -o | xargs -d $'\n' sh -c 'for arg do mkdir -p "$arg"; echo -n "$arg" | xclip -sel c; done' _
NEW_PWD=$(xclip -sel c -o)
cd "${NEW_PWD}"
curl "${URL}" | pup '.sample-tests' | codeforces_parse_input.py

[[ ! -f "${MAIN_DEST}" ]] && cp "${MAIN_CPP}" "${MAIN_DEST}" || echo "Avoid creation of file"
[[ ! -f "${MAKEFILE_DEST}" ]] && ln -rs "${MAKEFILE_SRC}" "${MAKEFILE_DEST}" || echo "Avoid creation of file"
[[ ! -f "${CLANG_FORMAT_DEST}" ]] && ln -rs "${CLANG_FORMAT_SRC}" "${CLANG_FORMAT_DEST}" || echo "Avoid creation of file"

emacsclient -a "" -c -n "${MAIN_DEST}"
echo -n "${NEW_PWD}" | xclip -sel c
