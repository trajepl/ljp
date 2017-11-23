from bs4 import BeautifulSoup
import re

special_dic = {
        'chebinbin':'车彬彬'
        }

def get_name(top, fn='comment', parse='html5lib'):
    print(special_dic.keys())
    soup = BeautifulSoup(open(fn), 'html5lib')
    list_re = soup.find_all('div', attrs={'node-type':'replywrap'})

    ret = []
    for re in list_re:
        item = re.select('div.WB_text')[0].get_text()
        item = item.strip().split('：')[-1]

        if len(item) >= 5:
            str_tmp = ''
            for char in item:
                if not char.isdigit():
                    str_tmp += char
            item = str_tmp

        if item not in special_dic.keys():
            ret.append(item.strip())
        else:
            print(item)
            ret.append(special_dic[item])
    
    ret.reverse()
    top = min(top, len(ret))

    with open('name.csv', 'w') as out_name:
        for i in range(top):
            out_name.write(ret[i] + '\n')

if __name__ == '__main__':
    get_name(130)
