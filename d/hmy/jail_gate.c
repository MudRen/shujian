// jail_gate.c
// Created by Numa 19991021

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
��վ��һ�������Ĵ���ǰ�棬���Ϲ���һ�Ѵ��������ŵ�����д�š�����
��� �������������֡������Ǹ��ʵ�Χǽ��һ����ɭ�ֲ�������ֱϮ������
LONG
	);
	set("exits", ([ 
		"out" : __DIR__"andao8",
	]));
	set("item_desc",([
		"��":	"һ��ʮ���ι̵���ͭ����������������Կ�ײ��ܴ��ˡ�(unlock)",
		"lock":	"һ��ʮ���ι̵���ͭ����������������Կ�ײ��ܴ��ˡ�(unlock)",
	]));
	setup();
}
