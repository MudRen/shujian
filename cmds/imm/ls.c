// ls.c
// �����Ľ� YUJ@SJ 2001-0704

#include <ansi.h>
#include "/doc/help.h"

inherit F_CLEAN_UP;

private string status(string dir, string file)
{
	int *info;

	if (file[<1] == '/' || file[<2..<1] == ".o")
		return file;
	info = stat(dir + file);
	if (!info[2])
		return file;
	if (info[2] >= info[1])
		return HIG + file + NOR;
	return HIR + file + NOR;
}

private string size(int len)
{
	if (len < 0)
		return "<DIR>";
	if (len <1000000)
		return len+"";
	return len/1000+"K";
}

int sort(mixed *i1, mixed *i2)
{
	if (i1[1] == -2 && i2[1] != -2)
		return -1;
	if (i1[1] != -2 && i2[1] == -2)
		return 1;
	return strcmp(i1[0], i2[0]);
}

int main(object me, string arg)
{
	int i, j, w, col, c, x, y, z;
	string dir, pattern, ret;
	mixed *file;

	dir = resolve_path(me->query("cwd"), arg);
	if (file_size(dir)==-2 && dir[<1] != '/')
		dir += "/";
	file = get_dir(dir, -1);
	if (!sizeof(file)) {
		if (file_size(dir) == -2)
			return notify_fail("Ŀ¼�ǿյġ�\n");
		return notify_fail("û�����Ŀ¼��\n");
	}
	file = sort_array(file, (: sort :));
	w = 0;
	foreach (mixed *item in file) {
		if (item[1] == -2)
			item[0] += "/";
		if (strlen(item[0]) > w)
			w = strlen(item[0]);
	}
	if (dir[<1] != '/')
		dir = "/" + implode(explode(dir, "/")[0..<2], "/");
	if (dir[<1] != '/')
		dir += "/";
	j = sizeof(file);
	ret = "Ŀ¼��" + dir + " total " + j + "\n";
	col = 90 / (w + 10);
	if (col > 1)
		pattern = repeat_string(" ", (90 - w - 7) / (col - 1) - w - 7);
	y = (j + col - 1) / col;
	z = y * col - j;
	for (i = 0; i < y; i++) {
		for (c = 0, x = i; x < j; x += y) {
			ret += sprintf("%-*s%7s%s",
				w, status(dir, file[x][0]),
				size(file[x][1]),
				++c%col?pattern:"");
			if (j == 1)
				ret += ctime(file[x][2]);
			if (i == y - 1 && c + z == col)
				break;
			if (c + z > col)
				x--;
		}
		ret += "\n";
	}
	me->start_more(ret);
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ: ls [<·����>]

�г�Ŀ¼�����е���Ŀ¼������, ���û��ָ��Ŀ¼, ���г�����Ŀ¼�����ݣ�
���г��ĵ�������ɫ��ʾ�Ѿ�������������ɫ��ʾ��Ҫ�����¡�

������
'ls /' ���г�����λ�ڸ�Ŀ¼�µĵ�������Ŀ¼.

HELP
	);
	return 1;
}
