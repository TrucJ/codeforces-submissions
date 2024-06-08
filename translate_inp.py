import sys
import os
from bs4 import BeautifulSoup

def is_html(content):
    """
    Check if the content is HTML.
    """
    return bool(BeautifulSoup(content, "html.parser").find())

def html_to_txt(input_folder):
    """
    Convert HTML to text.
    """
    # Loop through all children in the input folder.
    for child in os.listdir(input_folder):
        path_child = os.path.join(input_folder, child)

        # If the child is a directory, recursively call html_to_txt.
        if os.path.isdir(path_child):
            html_to_txt(path_child)
            continue

        # Skip files that do not start with "in" or end with ".txt".
        if not child.endswith(".txt"):
            continue

        # Read the content of the file.
        with open(path_child, "r") as file:
            content = file.read()

        # Skip the file if the content is not HTML.
        if not is_html(content):
            continue

        print("Translating file", path_child)

        # Parse the HTML content using BeautifulSoup.
        soup = BeautifulSoup(content, "html.parser")

        # Extract text from div tags and write to the same file.
        with open(path_child, "w") as output:
            for div in soup.find_all("div"):
                output.write(div.text.strip() + "\n")

if __name__ == "__main__":
    # Check the number of command line arguments.
    if len(sys.argv) != 2:
        input_folder = "cf/contest"
    else:
        input_folder = sys.argv[1]

    # Convert HTML to text.
    html_to_txt(input_folder)
