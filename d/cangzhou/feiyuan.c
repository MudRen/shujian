// gbfenduo3.c ؤ����ʷֶ�(����)
// by Looklove@SJ at 2001/10/03

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","��԰");
	set("long", @LONG
����һ���ķϵ�լԺ����ǰ��һ�����˼ң���������ݿգ�������ǽ��
�Ѿ�������Ժ���ﳤ�˺ܶ��Ӳݡ�������ؤ�������ڿյص��У�Χ��һ������
��ʲô��������ؤ��Ĵ��ʷֶ棬���ݸ�����ؤ�����ƽ������������롣
LONG
	);
	set("exits",([
		"west" : __DIR__"beijie3",
		"enter" : __DIR__"tingtang",
	]));
	set("objects", ([
                CLASS_D("gaibang/fang") : 1,
                CLASS_D("gaibang/jian") : 1,
                CLASS_D("gaibang/zfdizi") : 1,
	]));

	setup();
}