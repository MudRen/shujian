// Modify by Lklv 2001.10.16

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","����");
	set("long",@long
����һ��ƻ�ͨ���Ĵ����̣�һ����������������ǽ�߷�����������¯
���յ������������������庺�����ͻ�����ּ�Ǯ�������ǽ����һ���Ѿ���
��Ĵ�����(sign)��
long );

	set("objects",([
		__DIR__"../npc/xue" : 1,
	]));
	set("exits",([
		"south" : __DIR__"yili2",
	]));
	set("item_desc",([
		"sign" : "�����ʽ���ȡ��շ������ƽ�
		�� make <��ɫ> <����>  �����졣
		���� : make $HIR$ ɨ����\n"
	]));
	setup();
}
