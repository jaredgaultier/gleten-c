import sys
import os

from write_data import *

from time import sleep

from rich.console import Console
from rich.control import Control

DEBUG: bool = True

command_inst: list = []

# Inits rich library for visual reasons
console = Console()

def read_data(project_title: str) -> int:

    PARAMETER_TOKEN = ['\"']


    PROJ_PATH = f"gleten-projects/{project_title}/"
    PROJ_PATH_DATA = f"{PROJ_PATH}/data/data.glt"

    # ERROR 1
    if not os.path.exists(PROJ_PATH) or not os.path.exists(f"{PROJ_PATH}/data/"):
        return 1
    

    data_file_content: list = []
    
    with open(PROJ_PATH_DATA, 'r') as data_file:
        for i in data_file.read():
            data_file_content.append(i)

    token_start_idx: int = 0

    temp_command: str = ""
    temp_parameter: str = ""

    while data_file_content != []:

        for it in range(len(data_file_content)):

            if data_file_content[it] in PARAMETER_TOKEN:
                token_start_idx = it + 1

                # This iteration tries to find the same token
                # as the start token to find where it ends
                for j in range(token_start_idx, len(data_file_content)):
                    if data_file_content[j] == data_file_content[it]:
                        token_end_idx = j
                        break

                    # ADD ELSE CASE FOR NON-CLOSED TOKEN 

                temp_command = data_file_content[0:token_start_idx - 1]
                temp_parameter = data_file_content[token_start_idx:token_end_idx]


                # Looks for the EOF (\n) index to pop all the data file content
                # until that index

                for j in range(token_end_idx, len(data_file_content)):

                    if data_file_content[j] == '\n':
                        command_length = len(data_file_content[0:j + 1])


                for i in range(command_length):
                    data_file_content.pop(0)
                    
                break
            




if __name__ == '__main__':

    if DEBUG:
        console.print("DEBUG MODE IS ON", style="underline yellow")
        input()
        os.chdir('../../../')

    match read_data(sys.argv[1]):
        case 1:
            console.print("Project path was not found.", style="bold red")

    # more exceptions to add !