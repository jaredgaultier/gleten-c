
def remove_file_template(parameter: str) -> str:
    template = f"""
shutil.rmtree({parameter})"""