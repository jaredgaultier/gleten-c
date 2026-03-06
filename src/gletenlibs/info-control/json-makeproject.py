import json
import os

TITLE_LENGTH_MAX = 30
DESCRIPTION_LENGTH_MAX = 500
AUTHOR_LENGTH_MAX = 20

def main(project_title, project_description, project_author):
    
    project_info = {
        "title": project_title,
        "description": project_description,
        "author": project_author
    }

    os.mkdir(f"gleten-projects/{project_info['title']}")

    with open(f"gleten-projects/{project_info['title']}/info.json", 'w') as json_file:
        json.dump(project_info, json_file, indent=4)



if __name__ == "__main__":
    _project_title = str(input("Project title: "))
    _project_description = str(input("Project description: "))
    _project_author = str(input("Author: "))

    if len(_project_title) > TITLE_LENGTH_MAX:
        print(f"Project title exceeds the ({TITLE_LENGTH_MAX}) letters limit")
        exit();

    if len(_project_description) > DESCRIPTION_LENGTH_MAX:
        print(f"Project title exceeds the ({DESCRIPTION_LENGTH_MAX}) letters limit")
        exit();
    
    if len(_project_author) > AUTHOR_LENGTH_MAX:
        print(f"Project title exceeds the ({AUTHOR_LENGTH_MAX}) letters limit")
        exit();

    print("Making a new project...")
    main(_project_title, _project_description, _project_author)


    print("Project was successfully created!")