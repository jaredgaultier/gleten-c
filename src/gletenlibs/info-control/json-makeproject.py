import json
import os

TITLE_LENGTH_MAX = 30
DESCRIPTION_LENGTH_MAX = 500
AUTHOR_LENGTH_MAX = 20

def main(project_title, project_description, project_author):

    PROJ_PATH = f"gleten-projects/{project_info["title"]}"

    project_info = {
        "title": project_title,
        "description": project_description,
        "author": project_author
    }

    os.mkdir(PROJ_PATH)

    with open(f"{PROJ_PATH}/info.json", 'w') as json_file:
        json.dump(project_info, json_file, indent=4)



if __name__ == "__main__":

    continue_to_main = False

    while True:
        _project_title = str(input("Project title: "))
        if len(_project_title) > TITLE_LENGTH_MAX:
            print(f"Project title exceeds the ({TITLE_LENGTH_MAX}) letters limit")

        else:
            break

    while True:    
        _project_description = str(input("Project description: "))
        if len(_project_description) > DESCRIPTION_LENGTH_MAX:
            print(f"Project title exceeds the ({DESCRIPTION_LENGTH_MAX}) letters limit")
    
        else:
            break
        
    while True:
        _project_author = str(input("Author: "))
        if len(_project_author) > AUTHOR_LENGTH_MAX:
            print(f"Project title exceeds the ({AUTHOR_LENGTH_MAX}) letters limit")

        else:
            break
    
                        

    print("Making a new project...")
    main(_project_title, _project_description, _project_author)


    print("Project was successfully created!")
