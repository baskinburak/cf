import argparse

parser = argparse.ArgumentParser(description = 'generate contest folder')
parser.add_argument("contestid", metavar = "C", type=int, help="id of the contest in the url")
parser.add_argument("contestname", metavar="N", type=str, help="name of the contest")
parser.add_argument("questioncount", metavar="Q", type=int, help="number of questions in the contest")
args = parser.parse_args()
print(args)

question_count = args.questioncount
contest_id = args.contestid
contest_name = args.contestname

import os
contest_folder = contest_name + "-" + str(contest_id)
os.mkdir(contest_folder, 0o755)

cpp_boilerplate = """// not yet solved
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>

using namespace std;

int main() {
    return 0;
}
"""

makefile_text = """all:
\tg++ sol.cpp --std=c++14 -o m
"""

for q in range(question_count):
    question_folder = contest_folder + "/" + chr(ord('a') + q)
    os.mkdir(question_folder, 0o755)

    cpp_file = open(question_folder + "/sol.cpp", "w")
    cpp_file.write(cpp_boilerplate)
    cpp_file.close()

    makefile_file = open(question_folder + "/Makefile", "w")
    makefile_file.write(makefile_text)
    makefile_file.close()

    input_file = open(question_folder + "/inp", "w")
    input_file.close()
