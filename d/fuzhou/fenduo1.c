// fenduo1.c ؤ�����ֶ�(�����洬)
// Modify by Looklove@SJ at 2000/9/26

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","����");
	set("long", @LONG
�����һ�����գ������ܵĴ����ص����ϵģ�����ֻ����һյ�͵ƣ�����ϡ��
������������ǣ�����ζ��ùζ����һ�飬ζ���������ˡ��������е�������Χ
���ż�������ؤ���ƺ�����������ʲô��һ�����Ǳ��ϵĲ�����֪��������ؤ��
����е�λ�����������ؤ�����ڸ��ݵĴ���ֶ档
LONG
	);
	set("exits",([
		"out" : __DIR__"yuchuan5",
	]));
	set("objects", ([
                CLASS_D("gaibang") + "/jiang" : 1,
                CLASS_D("gaibang") + "/wu" : 1,
	]));

	set("valid_startroom",1);
	setup();
	call_other("/clone/board/gb_board", "???");
}