// xiongdong.c �ܶ�
// Modify By River@SJ 99.06
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIB"�ܶ�"NOR);
	set("long", @LONG
�˴�Ϊһ�ܶ������ڼ��ǿ����а˾�����м�͸��һ����⣬������
��һ�㡣�˶���ǰ�м��������ڴ˾Ӵ����������Ŵ�ɽ��ɱ�ܶ�ס�ڴ˴���
�ʴ����롢���ʯ�����־ߵ�һӦ��ȫ��
LONG);
	set("exits",([
		"out" : __DIR__"shishan",
	]));
        set("objects",([
                  "/d/mingjiao/obj/luopan" :  1,
	]));
        set("no_fight", 1);
        set("sleep_room", 1);
	setup();
}
