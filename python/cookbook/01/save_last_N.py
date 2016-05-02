from collections import deque

def search(lines, pattern, history = 5):
    pre_lines = deque(maxlen=history)
    for line in lines:
        if pattern in line:
            yield line, pre_lines
        pre_lines.append(line)

# Example use on a file
if __name__ == '__main__':
    with open('/home/ljp/ljp/161plan.txt') as f:
        for line, prelines in search(f, 'Java'):
            for pline in prelines:
                print(pline, end='')
            print(line, end='')
            print('-'*20)

