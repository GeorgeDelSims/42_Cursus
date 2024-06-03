#!/bin/bash

if [ -z "$1" ]; then
    echo "Usage: $0 ClassName"
    exit 1
fi

CLASS_NAME=$1
HEADER_FILE="${CLASS_NAME}.hpp"
SOURCE_FILE="${CLASS_NAME}.cpp"

CLASS_NAME_UPPER=$(echo "${CLASS_NAME}" | tr '[:lower:]' '[:upper:]')

cat <<EOL > ${HEADER_FILE}
#ifndef ${CLASS_NAME_UPPER}_HPP
# define ${CLASS_NAME_UPPER}_HPP

class ${CLASS_NAME} 
{
    public:
        ${CLASS_NAME}();
        ~${CLASS_NAME}();

        // Add methods here

    private:
        // Add member variables here
};

#endif // ${CLASS_NAME}_HPP
EOL

cat <<EOL > ${SOURCE_FILE}
#include "${HEADER_FILE}"

${CLASS_NAME}::${CLASS_NAME}() 
{
    // Constructor implementation
}

${CLASS_NAME}::~${CLASS_NAME}() 
{
    // Destructor implementation
}

// Add methods implementation here
EOL

echo "Files ${HEADER_FILE} and ${SOURCE_FILE} created successfully."