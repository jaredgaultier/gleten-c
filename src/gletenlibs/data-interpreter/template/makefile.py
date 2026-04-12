def make_file_template(parameter: str) -> str:
    template = f"""
open(\"{parameter}\")"""
    
    return template