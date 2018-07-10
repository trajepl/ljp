import numpy as np

def alias_setup(props):
    """
    Compute utility lists for non-uniform sampling from discrete distributions
    """
    K = len(props)
    q = np.zeros(K)
    J = np.zeros(K, dtype=np.int)

    smaller = []
    larger = []

    for i, prop in enumerate(props):
        q[i] = K * prop
        if q[i] > 1.0:
            larger.append(i)
        else:
            smaller.append(i)

    while len(smaller) > 0 and len(larger) > 0:
        small = smaller.pop()
        large = larger.pop()

        J[small] = large
        print(J)
        q[large] = q[large] + q[small] - 1.0
        if q[large] >= 1.0:
            larger.append(large)
        else:
            smaller.append(large)

    return J, q


def alias_draw(J, q):
    '''
    Draw sample from a non-uniform discrete distribution using alias sampling.
    '''
    K = len(J)
    i = int(np.floor(np.random.ranf() * K))
    if q[i] > np.random.ranf():
        return i
    else:
        return J[i]


if __name__ == '__main__':
    props = [0.26, 0.23, 0.24, 0.27]
    J, q = alias_setup(props)
    print(J)
    print(q)
    print(alias_draw(J, q))
