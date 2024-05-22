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

def sort_problems(problems):
    difficulty_order = {'Easy': 0, 'Medium': 1, 'Hard': 2}
    return sorted(problems, key=lambda x: difficulty_order.get(x[1], 3))

def write_readme(problems_by_category, output_path):
    total_problems = 0
    difficulty_counts = {'Easy': 0, 'Medium': 0, 'Hard': 0}

    with open(output_path, 'w') as readme:
        readme.write("# Problem Solving Solutions\n")
        readme.write("\n")

        # Count and write the number of problems solved for each difficulty
        for category, problems in problems_by_category.items():
            total_problems += len(problems)
            for _, difficulty, _ in problems:
                if difficulty in difficulty_counts:
                    difficulty_counts[difficulty] += 1

        readme.write(f"Total problems solved: {total_problems}\n")
        readme.write(f"Easy: {difficulty_counts['Easy']}\n")
        readme.write(f"Medium: {difficulty_counts['Medium']}\n")
        readme.write(f"Hard: {difficulty_counts['Hard']}\n")
        readme.write("\n")

        for category, problems in problems_by_category.items():
            readme.write(f"## {category}\n")
            readme.write("\n")
            readme.write("| Difficulty | Problem | Link |\n")
            readme.write("|---------|------------|------|\n")
            
            # Sort the problems
            sorted_problems = sort_problems(problems)
            
            for problem, difficulty, link in sorted_problems:
                if link:
                    readme.write(f"| {difficulty} | {problem} | [Link]({link}) |\n")
                else:
                    readme.write(f"| {difficulty} | {problem} | No Link |\n")
            readme.write("\n")

def main():
    repo_path = r'C:\Users\m3ne7b\Documents\GitHub\Problem-Solving\LeetCode'  # Change this to your repo path
    o_path = r'C:\Users\m3ne7b\Documents\GitHub\Problem-Solving'
    output_path = os.path.join(o_path, 'README.md')
    problems_by_category = get_problems_by_category(repo_path)
    write_readme(problems_by_category, output_path)

if __name__ == "__main__":
    main()
