import json
import os
import sys

TITLE_LENGTH_MAX = 30
DESCRIPTION_LENGTH_MAX = 500
AUTHOR_LENGTH_MAX = 20

def main(project_title, element_to_edit, new_value=None):
    with open(f"gleten-projects/{project_title}/info.json", 'r') as json_file:
        _project_info = json.load(json_file)

        json_structure = {
            "title": _project_info["title"],
            "description": _project_info["description"],
            "author": _project_info["author"]
        }

    if element_to_edit == "title" and len(element_to_edit) > TITLE_LENGTH_MAX:
        print("New value exceeds 30 characters")

    elif element_to_edit == "description" and len(new_value) > DESCRIPTION_LENGTH_MAX:
        print("New value exceeds 500 characters")

    elif element_to_edit == "author" and len(new_value) > AUTHOR_LENGTH_MAX:
        print("New value exceeds 20 characters")
        
    else:
        json_structure[element_to_edit] = new_value


    with open(f"gleten-projects/{project_title}/info.json", 'w') as json_file:
        json.dump(json_structure, json_file, indent=4)

    # Changes the dir name too
    os.rename(f"gleten-projects/{project_title}", f"gleten-projects/{json_structure["title"]}")


    if element_to_edit == "data":
        # Tells to main.c where project will the user work on
        with open("temp.txt", 'w+') as temp_file:
            temp_file.write(f"0;{project_title}<")

    else:
        with open("temp.txt", "w+") as temp_file:
            temp_file.write("1;")



if __name__ == "__main__":

    project_path = os.listdir("gleten-projects")
    projects_found = []

    for i in project_path:
        if os.path.isdir(f"gleten-projects/{i}") and os.path.isfile(f"gleten-projects/{i}/info.json"):
            with open(f"gleten-projects/{i}/info.json", 'r') as json_file:
                project_info = json.load(json_file)

            projects_found.append(project_info["title"])
            print(f"-{i}")

    while True:
        _option = str(input("\nProject to edit: "))
        if not _option in projects_found:
            print("\nProject doesn't exists")

        else:
            break
    
    while True:
        _element_to_edit = str(input("Element to edit: "))
        if not _element_to_edit in ["title", "description", "author", "data"]:
            print("\nNot valid element.")

        else:
            break

    if _element_to_edit != "data":
        _new_value = str(input("\nNew value: "))
        main(_option, _element_to_edit, _new_value)

    else:
        main(_option, _element_to_edit)
