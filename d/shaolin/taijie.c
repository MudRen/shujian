//taijie.c
//by bren

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "̨��");
	set("long", @LONG
������һ�����ϵ�̨�ף�ȫ������������ʯ������ɣ�̨������ķ���
�ϵ���ŷ��ϵ����Ծ��䡣����һ����Ҳû�У��Եúܼž����������е�
ɮ��Ҳ��������������
LONG
	);

	set("exits", ([
		"northup" : __DIR__"lxting",
                "south" : __DIR__"houdian",
       ]));

	set("coor/x",50);
  set("coor/y",350);
   set("coor/z",120);
   set("coor/x",50);
 set("coor/y",350);
   set("coor/z",120);
   setup();
}

 

