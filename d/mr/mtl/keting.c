// /u/beyond/mr/keting.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
	set("short",HIW"����"NOR);
	set("long",@long
���߽����СС������, �����������һ����̴ľ�輸�ͼ������������ӣ�
��̴ľ�Ĳ輸�ϰڷ��Ų���ͼ�ֻ���񱭣�ר���������á����̲�ס��������
���ϣ���ƣ�������ĵõ���ֵ���Ϣ��
long);
	set("exits",([
		"east" : __DIR__"cl4-4",
		"north" : __DIR__"cl4-2",
		"west" : __DIR__"yunjinlou",
	]));
	set("objects",([
		FOOD_D("putao") : 1,
		FOOD_D("guiyuan") : 1,
		FOOD_D("cha") : 2,
	]));
	setup();
}
