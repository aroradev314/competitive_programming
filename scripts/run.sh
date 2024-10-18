# Check if the filename argument is provided
if [ -z "$1" ]; then
    echo "Usage: $0 <filename.cpp>"
    exit 1
fi

# Get the filename from the argument
FILENAME="$1"

if [[ "$FILENAME" != *.cpp ]]; then
    FILENAME="${FILENAME}.cpp"
fi

# Remove the file extension to get the base name
BASENAME=$(basename "$FILENAME" .cpp)

~/cp/scripts/compile.sh "$FILENAME"

if [ $? -ne 0 ]; then
    exit 1
fi

if [ -z "$2" ]; then
    ~/cp/scripts/execute.sh "$BASENAME"
else
    ~/cp/scripts/execute.sh "$BASENAME" "$2"
fi
