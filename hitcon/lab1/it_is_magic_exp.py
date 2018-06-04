'''
import angr

main = 0x40088b
find = 0x400898
avoid = [0x400876, 0x4008B1]

p = angr.Project("it_is_magic_patched", auto_load_libs=False)
init = p.factory.blank_state(addr=main)
pg = p.factory.path_group(init, threads=8)
ex = pg.explore(find=find, avoid=avoid)

final = ex.found[0].state
flag = final.posix.dumps(0)
print flag
print("Flag: {0}".format(final.posix.dumps(1)))
'''

import angr
project = angr.Project("it_is_magic_patched", auto_load_libs=False)
path_group = project.factory.path_group()
path_group.explore(find=lambda path: 'Bling' in path.state.posix.dumps(1))
print path_group.found[0].state.posix.dumps(0)