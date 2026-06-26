#!/usr/bin/env python3

import os
import csv

def count_references(function_names):
    function_references = {name: 0 for name in function_names}

    for root, dirs, files in os.walk('./src'):
        for file in files:
            if file.endswith('.c'):
                file_path = os.path.join(root, file)
                with open(file_path, 'r') as f:
                    content = f.read()
                    for name in function_names:
                        function_references[name] += content.count(name)

    for root, dirs, files in os.walk('./asm/nonmatchings'):
        for file in files:
            if file.endswith('.s'):
                file_path = os.path.join(root, file)
                with open(file_path, 'r') as f:
                    content = f.read()
                    for name in function_names:
                        function_references[name] += content.count(name)

    return function_references

if __name__ == "__main__":
    with open("./progress/progress.total.csv", 'r') as f:
        reader = csv.reader(f)
        header = next(reader)
        function_names = [row[2] for row in reader]
        function_references = count_references(function_names)
        for reference in function_references:
            print(f'{reference},{function_references.get(reference)}')