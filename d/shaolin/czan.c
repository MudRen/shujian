//czan.c
//by bren

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", HIY"������"NOR);
	set("long", @LONG
�����ǳ����֣����Ǳ���ĩ���������е�ɮ��Ϊ�˼����Ħ���޽��ġ�
����ɽ�ţ�����ʽͥԺ��ȫ�����еĴ���ڹ����Ŵ�Ħ���棬���棬��
�棬���漰���������Ժ���м���������ɮ�˽Ӵ���ǰ���������͡�
LONG
	);

	set("exits", ([
		"north" : __DIR__"shanlu5",
                "south" : __DIR__"shanlu4",
       ]));
        set("objects",([
		__DIR__"npc/xiang-ke" : 1,
	]));

	set("coor/x",50);
  set("coor/y",480);
   set("coor/z",140);
   setup();
}


