inherit ROOM;
#include <ansi.h>
#include <room.h>

void create()
{
	set("short", "����");
	set("long", @LONG
����һ�����ȡ�����������������Ҳ�ò�������˸��ַ����ͼ�Σ�ÿ��
�����ĵ��ƺ�������˵һ���渶��˵Ĺ��¡�
LONG);

	set("exits", ([
		"south" : __DIR__"zhengmen",
		"north" : __DIR__"huating",
	]));

	set("coor/x",-310);
  set("coor/y",-430);
   set("coor/z",-20);
   setup();
}


