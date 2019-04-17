#!/sbin/python

import os
import argparse
import subprocess

# helper function to write text to stdout, without additional newlines
def write(text):
	print(text, end='', flush=True)


wated_folders = ["06","07","08","09","10","11"]

# find all files in the base directory and include them
for folder in os.listdir("./"):
	if any(wanted_folder in folder for wanted_folder in wated_folders):
		src_path = os.path.join(".",folder,"src")
		print(src_path)
		mains = []
		other = []
		for file in os.listdir(src_path):
			if "main" in file:
				mains.append(file)
			else:
				other.append(file)

		cmake_path = os.path.join(".",folder,"CMakeLists.txt")
		f = open(cmake_path,"w")

		f.write("cmake_minimum_required(VERSION 3.13)\n\n")

		for main in mains:
			f.write('project({}_{})\n'.format(folder, main.replace(".cpp","").replace(".c","")))

		f.write('''
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

''')

		for main in mains:
			f.write('add_executable({}_{}\n'.format(folder, main.replace(".cpp","").replace(".c","")))
			f.write('\t\t\tsrc/{}\n'.format(main))
			for file in other:
				f.write('\t\t\tsrc/{}\n'.format(file))
			f.write(")\n")

		f.write("""
include_directories(
        ../helpers/
        src/
)

""")

		for main in mains:
			f.write('set_target_properties({}_{} PROPERTIES SUFFIX ".out")'.format(folder, main.replace(".cpp","").replace(".c","")))

		f.close()
