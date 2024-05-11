import sys
import os
from bs4 import BeautifulSoup

def html_to_txt(input_folder):
    for file in os.listdir(input_folder):
        if not file.startswith("in") or not file.endswith(".txt"):
            continue
        input_file = os.path.join(input_folder, file)
        
        print("Translating file", input_file)

        # Đọc nội dung của file HTML
        with open(input_file, "r") as file:
            html_content = file.read()

        # Phân tích HTML sử dụng BeautifulSoup
        soup = BeautifulSoup(html_content, "html.parser")

        # Trích xuất văn bản từ các thẻ div và ghi vào file văn bản
        with open(input_file, "w") as output:
            for div in soup.find_all("div"):
                output.write(div.text.strip() + "\n")

if __name__ == "__main__":
    # Kiểm tra số lượng tham số dòng lệnh
    if len(sys.argv) != 2:
        print("Sử dụng: python script.py input_folder")
        sys.exit(1)

    # Lấy tên thư mục đầu vào từ tham số dòng lệnh
    input_folder = sys.argv[1]

    # Chuyển đổi HTML thành văn bản
    html_to_txt(input_folder)
