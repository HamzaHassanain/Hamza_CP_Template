import os
import sys


algos_name = "newlyAdded"
# itrate over all dirctories in alogs dircotry

# for dir in os.listdir(algos_name):
#     # itrate over all fieles in the dirctory
#     # print(dir)
#     for file in os.listdir(f"{algos_name}/{dir}"):
#         #     file_name = f"{algos_name}/{dir}/{file.split('.')[0]}"
#         #     cpp_file = f"{file_name}.cpp"
#         #     md_file = f"{file_name}.md"
#         #     docx_file = f"{file_name}.docx"
#         #     with open(cpp_file, "r") as input_file:
#         #         data = input_file.read()
#         #     with open(md_file, "w") as output_file:
#         #         data = f"```cpp\n{data}\n```"
#         #         output_file.write(data)

#         #     os.system(
#         #         f"pandoc {md_file} -f markdown -t docx -s -o {file_name}.docx")
#         #     os.system(
#         #         f"libreoffice --headless --convert-to pdf {file_name}.docx --outdir ./")
#         #     os.remove(md_file)
#         #     os.remove(docx_file)


pdfs_dir = "pdfs"


def dfs(dir):
    # if dir ends in .cpp
    if dir.endswith(".cpp"):
        file_name = f"{dir.split('.')[0]}"
        cpp_file = f"{file_name}.cpp"
        md_file = f"{file_name}.md"
        docx_file = f"{file_name}.docx"
        with open(cpp_file, "r") as input_file:
            data = input_file.read()
        with open(md_file, "w") as output_file:
            data = f"```cpp\n{data}\n```"
            output_file.write(data)

        os.system(
            f"pandoc {md_file} -f markdown -t docx -s -o {file_name}.docx")
        os.system(
            f"libreoffice --headless --convert-to pdf {file_name}.docx --outdir ./")
        os.remove(md_file)
        os.remove(docx_file)

        # move to pdfs dir
        # os.system(f"mv {file_name}.pdf {pdfs_dir}")
    else:
        for file in os.listdir(dir):
            dfs(f"{dir}/{file}")


dfs(algos_name)


# move all pdfs in current dir to pdfs dir
#
for file in os.listdir("."):
    if file.endswith(".pdf"):
        os.system(f"mv {file} {pdfs_dir}")
