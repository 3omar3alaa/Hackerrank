import os
import re

def get_problems_by_category(repo_path):
    problems_by_category = {}

    # Traverse the directory structure
    for category in os.listdir(repo_path):
        category_path = os.path.join(repo_path, category)
        if os.path.isdir(category_path):
            problems = []
            for problem in os.listdir(category_path):
                problem_path = os.path.join(category_path, problem)
                if os.path.isdir(problem_path):
                    link_file = os.path.join(problem_path, 'link.txt')
                    link = None
                    if os.path.isfile(link_file):
                        with open(link_file, 'r') as file:
                            link = file.read().strip()
                    difficulty_match = re.match(r'\((.*?)\) (.*)', problem)
                    if difficulty_match:
                        difficulty = difficulty_match.group(1)
                        problem_name = difficulty_match.group(2)
                        problems.append((problem_name, difficulty, link))
            problems_by_category[category] = problems

    return problems_by_category

def write_readme(problems_by_category, output_path):
    with open(output_path, 'w') as readme:
        readme.write("# Problem Solving Solutions\n")
        readme.write("\n")
        for category, problems in problems_by_category.items():
            readme.write(f"## {category}\n")
            readme.write("\n")
            readme.write("| Problem | Difficulty | Link |\n")
            readme.write("|---------|------------|------|\n")
            for problem, difficulty, link in problems:
                if link:
                    readme.write(f"| {problem} | {difficulty} | [Link]({link}) |\n")
                else:
                    readme.write(f"| {problem} | {difficulty} | No Link |\n")
            readme.write("\n")

def main():
    repo_path = r'C:\Users\m3ne7b\Documents\GitHub\Problem-Solving\LeetCode'  # Change this to your repo path
    o_path = r'C:\Users\m3ne7b\Documents\GitHub\Problem-Solving'  # Change this to your repo path
    output_path = os.path.join(o_path, 'README.md')
    problems_by_category = get_problems_by_category(repo_path)
    write_readme(problems_by_category, output_path)

if __name__ == "__main__":
    main()
