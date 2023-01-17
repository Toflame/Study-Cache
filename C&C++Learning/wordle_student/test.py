import os
import platform

tasks = [
    {
        'name': 'task1',
        'data': ['01_01_single_game', '01_02_single_game', '01_03_single_game_with_invalid_input'],
        'args': ['', '', '']
    },
    {
        'name': 'task2',
        'data': ['02_01_specify_answer'],
        'args': ['-w build']
    },
    {
        'name': 'task3',
        'data': ['03_01_difficult_mode', '03_02_difficult_mode'],
        'args': ['-D', '-D']
    },
    {
        'name': 'task4',
        'data': ['04_01_statistics_1', '04_02_statistics_2'],
        'args': ['-t', '-D -t']
    }
]

def readfile(file):
    with open(file, 'r') as f:
        return ''.join(f.readlines())    

if __name__ == '__main__':

    isWin = platform.system() == 'Windows'

    os.popen("mingw32-make").read()
    for task in tasks:
        print(f"Testing {task['name']} ...")
        for idx, case_name in enumerate(task['data']):
            case_arg = task['args'][idx]

            cmd = ""

            if isWin:
                cmd = f"type .\\cases\\{case_name}.in | .\\main.exe {case_arg} > .\\cases\\{case_name}.out"
            else:
                cmd = f"./main {case_arg} < ./cases/{case_name}.in > ./cases/{case_name}.out"
            os.popen(cmd).read()

            checker_cmd = "fc" if isWin else "diff"
            answer_file = os.path.join('cases', f'{case_name}.ans')
            output_file = os.path.join('cases', f'{case_name}.out')
            answer = readfile(answer_file)
            output = readfile(output_file)            
            if answer != output:
                print(f"Failed at {task['name']}, case: {case_name}.")
                print(f"Answer is\n{answer}\n======\n Your output is\n{output}")
                exit(1)
            else:
                print(f"Passed case: {case_name}")
        print(f"Passed {task['name']}!")
