// qianting.c  ��̳ǰ��
// Modify By River@SJ 99.06
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIY"��̳ǰ��"NOR);
	set("long",@LONG
������������̳��ǰ������ν֮Ϊǰ���������ƴ���ǰ��������ʯʨ��
��ʯʨ֮����ʮ�༶��бб���ϵ�ʯ�ף�ʯ�ױ�һ����ʯ���ɵ�ʯ���м������
ʯ��ƽ����ʯ�����ڵ��ϡ�ʯ���ϵ���һ���ڶ��ϵĻ��棬������ΰ׳�ۣ�ʯ
������һЩ��С����̶��ɵ����֣�������������ǧ�����ʷ��������������
���������֡����������ɼ�����ľ֧�Ŷ��𣬾��ϵ���ž������Ż������֮
���ɴ˶��Ͼ��ǹ������ˡ�
LONG);
	set("exits",([
		"southdown" : __DIR__"ljroad3",
		"north" : __DIR__"tingtang",
	]));
	set("objects",([
		__DIR__"npc/m-dizi" : 2,
		CLASS_D("mingjiao") + "/yin2" : 1,
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	if ( me->query("id") == "jiao zhong" &&  dir == "southdown" ) return 0;
	if ( me->query("id")=="leng qian" && dir =="southdown") return 0;
	if ( me->query_condition("mj_shouwei") && dir =="southdown")
		return notify_fail("�㻹�������������뿪��\n");
	if ( me->query_condition("mj_shouwei") && dir =="north")
		return notify_fail("�㻹�������������뿪��\n");
	me->delete_temp("warned");
	return ::valid_leave(me, dir);
}
