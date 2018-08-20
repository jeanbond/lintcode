
class test:
    def __init__(self, ins):
            self.ins = ins
            print('tis is a test for init {self.ins}'.format(self=self))
    def __str__(self):
            return 'this is a test for {self.ins}'.format(self=self)

if __name__ == '__main__':
    st = '{name}.{home}.{country}'.format(name='xuwei',home='wushan',country='china');print(st)
    st = '{0}.{1}.{0}'.format('first','second');print(st)
    test('hostname')
    p = ['his', 19]
    print('{0[0]} is {0[1]} old !'.format(p))
    p1 = {1:'his', 0:19}
    print('{0[0]} is {0[1]} old !'.format(p1))
    print('{:0<8}'.format(87))
    print('{:0>8}'.format(87))
    print('{:.2f}'.format(3.12548))
    ins = 1873
    print('erjinzhi is:{:b}'.format(ins))
    print('shijinzhi is:{:d}'.format(ins))
    print('bajinzhi is:{:o}'.format(ins))
    print('shiliujinzhi is:{:x}'.format(ins))