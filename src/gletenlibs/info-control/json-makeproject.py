import json
import os

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


    print("Making a new project...")
    main(_project_title, _project_description, _project_author)


    print("Project was successfully created!")


if __name__ == '__main__':
    main()