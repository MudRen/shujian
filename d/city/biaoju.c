// Room: /d/city/biaoju.c
// Date: Look 99/09/20

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIY "�����ھ�" NOR);
	set("long", @LONG
����һ���������˽���ϴ��֮�󿪵�һ���ھ֣������ʦ�����������
�������£���һ���ǰ�ʱ��ɡ����������񣬺ܶ཭�����˶�Ը����������
�¡�
LONG
	);
	set("no_fight",1);
        set("indoors", "����");

	set("exits", ([
	  "south" : __DIR__"dongmen",
	]));
//    set("objects", ([__DIR__"hubiao/biaoshi" : 1]));

	set("coor/x",130);
  set("coor/y",0);
   set("coor/z",0);
   setup();
}

