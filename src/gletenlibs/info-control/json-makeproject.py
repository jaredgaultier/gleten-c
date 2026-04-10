import json
import os

TITLE_LENGTH_MAX: int = 30

DESCRIPTION_LENGTH_MAX: int = 500

AUTHOR_LENGTH_MAX: int = 20



def input_length_limit(
        
        message: str,
        limit: int

        ) -> str:
    

    ans: str = ""

    while ans != "quit":
        ans = input(message)

        if len(ans) <= limit:
            break

        else:
            print(f"Input exceeds the ({limit}) char limit!")
            pass


    return ans




def main(
        project_title: str,
        project_description: str, 
        project_author: str
        ) -> None:

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

    _project_title: str = input_length_limit(
        "Project title: ",
        TITLE_LENGTH_MAX
    )

    _project_description: str = input_length_limit(
        "Project description: ",
        DESCRIPTION_LENGTH_MAX
    )

    _project_author: str  = input_length_limit(
        "Project author: ",
        AUTHOR_LENGTH_MAX
    )
    
                        

    print("Making a new project...")
    main(_project_title, _project_description, _project_author)


    print("Project was successfully created!")
