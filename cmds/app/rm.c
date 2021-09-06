// rm.c

#include "/doc/help.h"

inherit F_CLEAN_UP;
int help(object me);

int main(object me, string dir)
{
	int i, j;
	mixed file;

	seteuid(geteuid(me));
	if (!dir) return notify_fail("��Ҫɾ���Ǹ�����?\n");
	dir = resolve_path(me->query("cwd"), dir);
	if (file_size(dir) == -2 && dir[<1] != '/') dir += "/";
	if (dir[<1] == '/') dir += "*";
	file = get_dir(dir, -1);
	i = sizeof(file);
	if (!i) return notify_fail("û�����������\n");
	write("rm " + dir + "\n");
	dir = implode(explode(dir, "/")[0..<2], "/") + "/";
	while (i--)
		if (file[i][1] >=0) {
			if (!rm(dir+file[i][0])) write("\n��û��ɾ�� "+dir+file[i][0]+" ��Ȩ����\n");
			else {
				write(file[i][0] + " deleted.\n");
				j++;
			}
		}
	write(j+" ���ļ���ɾ�����ˡ�\n");
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : rm <����>

��ָ�������ɾ����Ȩ�޸ĵĵ�����
HELP
	);
	return 1;
}
