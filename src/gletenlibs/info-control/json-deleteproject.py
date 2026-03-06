import os
import shutil

def main(project_title):
	if not project_title in os.listdir("gleten-projects/"):
		return f"Project <{project_title}> not found."

	else:
		_confirmation = str(input("Are you sure? Y/N: "))
		if _confirmation == 'Y':

			# Be careful with the given path
			# shutil.rmtree makes the same thing as rm -rf

			shutil.rmtree(f"gleten-projects/{project_title}")

			return "Project was deleted successfully!"

		else:
			pass

	del _confirmation




if __name__ == '__main__':
	_project_title = input("Project title that will be deleted: ")
	print(main(_project_title))