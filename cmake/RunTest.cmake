# Runs one exercise executable with INPUT on stdin and compares stdout with EXPECTED.
# Usage: cmake -DEXE=<exe> -DINPUT=<file.in> -DEXPECTED=<file.out> -P RunTest.cmake

function(normalize var)
    set(text "${${var}}")
    string(REPLACE "\r\n" "\n" text "${text}")
    string(REGEX REPLACE "[ \t]+\n" "\n" text "${text}")
    string(STRIP "${text}" text)
    set(${var} "${text}" PARENT_SCOPE)
endfunction()

execute_process(
    COMMAND "${EXE}"
    INPUT_FILE "${INPUT}"
    OUTPUT_VARIABLE actual
    RESULT_VARIABLE rc
    TIMEOUT 5)

file(READ "${EXPECTED}" expected)

normalize(actual)
normalize(expected)

if(NOT rc EQUAL 0)
    message(FATAL_ERROR "Program failed (${rc})\n--- output ---\n${actual}")
endif()

if(NOT actual STREQUAL expected)
    message(FATAL_ERROR "Output mismatch\n--- expected ---\n${expected}\n--- actual ---\n${actual}")
endif()
