// Room: junji-fang.c
// Created by Numa 1999-11-21

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"��߾�����"NOR);
	set("long", @LONG
һ����ΰ�Ĵ���Ȼ������ǰ������Ϊ�Ϻú�ľ���ɣ��������
�����ߣ�һ�ɻʼ���Ϣ���ഫ����Ϊ�س�ĩ���������Ժ�������������
����֮����
LONG);
	set("exits", ([ 
            "north" : __DIR__"junji-dian",
            "southdown" : __DIR__"shidao2",
        ]));
	set("outdoors", "��ɽ");
	set("coor/x",40);
  set("coor/y",330);
   set("coor/z",120);
   setup();
}
