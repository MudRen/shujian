// pingyan1.c ��Ұ
// Modify By River@SJ 99.06
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", GRN"��Ұ"NOR);
	set("long", @LONG
�����ǵ���Ķ�������Ŀ����һƬ��������ͷ�Ĵ���Ұ���ǻ��ɽ����ǧ
����Ļ�ɽ�Ҷѻ����ɣ�ƽҰ��һȺ÷��¹���ڵ�ͷ�Բݣ���ΧһƬƽ������
�޿ɲ�֮����Զ����ɽ��������ѩ��Щ��ȴ�Ǽ�Ŀ���̣����ɴ�أ��������
����������Ϊ�������ޡ�
LONG);
	set("exits",([
		"south" : __DIR__"yanshi",
		"north" : __DIR__"pingyan2",
	]));
	set("objects",([
		"/d/mingjiao/npc/lu" :  1,
	]));
	set("outdoors","����");
	setup();
}
