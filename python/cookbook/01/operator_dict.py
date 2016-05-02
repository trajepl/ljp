from collections import defaultdict
from collections import OrderedDict
import json

def demo_defaultdict():
    d = defaultdict(list)
    d['a'].append(1)
    d['a'].append(2)
    d['b'].append(3)

    for key in d:
        print(key, d[key])

    d = defaultdict(set)
    d['a'].add(1)
    d['a'].add(2)
    d['b'].add(4)

    for key in d:
        print(key, d[key])

def demo_ordereddict():
    '''
    OrderedDict 内部维护了一个双向链表, 第一个加入的元素放在链表的末尾,
    之后对已存在的键重新赋值的时候, 不会改变键的顺序
    OrderedDict的大小是普通字典的两倍多
    '''
    d = OrderedDict()
    d['foo'] = 1
    d['bar'] = 2
    d['spam'] = 3
    d['grok'] = 4

    for key in d:
        print(key, d[key])

    print(json.dumps(d))


def demo_cal(prices):
    min_prices = min(zip(prices.values(), prices.keys()))
    max_prices = max(zip(prices.values(), prices.keys()))

    prices_sorted = sorted(zip(prices.values(), prices.keys()))

    # min_prices = min(prices, key = lambda k: k = prices[k])

def demo_find_common(dict1, dict2):
    common_key = dict1.keys() & dict2.keys()
    common_item = dict1.items() & dict2.items()

    dif_key = dict1.keys() - dict2.keys()

if __name__ == '__main__':
    demo_defaultdict()
    demo_ordereddict()





